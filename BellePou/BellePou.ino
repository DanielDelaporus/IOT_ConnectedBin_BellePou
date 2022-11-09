using namespace std;

#include <WiFi.h>
#include <sstream>

#include <ESPAsyncWebServer.h>
#include <AsyncTCP.h>
#include <string>
//#include <AutoConnect.h> //================================>

#include <future>

#include "WebPage.h"  //Web page header file


AsyncWebServer server(80);
//AutoConnect Portal(server); //================================>

const char* APssid = "LexernIOT";     // IDENTIFIANT POUR LE MODE AP
const char* APpassword = "12345678";  // IDENTIFIANT POUR LE MODE AP

String savedSSID = "";     // EMPLACEMENT D'ENREGISTREMENT IDENTIFIANT DE LA CO QUI MARCHE 
String savedPASSWORD = ""; // EMPLACEMENT D'ENREGISTREMENT IDENTIFIANT DE LA CO QUI MARCHE
bool connected = false;    // IS IT CONNECTED


float contentMax = 15.67;  // DISTANCE MAX ET MIN DE REPLISSAGE 
float contentMin = 0.10;   // DISTANCE MAX ET MIN DE REPLISSAGE
int content_percent = 0;   // CONVERSION DU REMPLISSAGE EN %

bool callScan = false;     // DECLANCHEUR POUR LE REFRESH
bool lidOpen = false;

String wifiSpots; // JSON THAT CARRIES THE WIFI SCAN INFOS
#define TRIG_PIN 13 // PIN POUR LE CAPTEUR DE REMPLISSAGE 
#define ECHO_PIN 12 // PIN POUR LE CAPTEUR DE REMPLISSAGE

int getContentPercent()
{
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  float duration_us = pulseIn(ECHO_PIN, HIGH);
  float distance_cm = 0.017 * duration_us;


  float percent = distance_cm * 100 / (contentMax - contentMin);
  
  if (percent > 101 || percent < -1)
    return 0;

  return 100 - percent; 
}

bool connectToWifi(String wifiname, String wifipassword) {
  try {    
    Serial.println("Connected with : " + wifiname + " / " + wifipassword);
    
    WiFi.begin(wifiname.c_str(), wifipassword.c_str());

    Serial.println("Connecting to ");
    Serial.print(wifiname);

    //Wait for WiFi to connect
    while(WiFi.waitForConnectResult() != WL_CONNECTED){   
        Serial.print(".");
        delay(1000);
    }
      
    //If connection successful show IP address in serial monitor
    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(wifiname);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());  //IP address assigned to your ESP
    
    return true;
  }
  catch (string e) {
    return false;    
  }
}

String getWifiSpots()
{
  stringstream jsonSpots;
  jsonSpots << "{ \"list\":[\n";  
  int n = WiFi.scanNetworks();
  Serial.println("scan done");
  if (n == 0) {
      Serial.println("no networks found");
  } else {
      Serial.print(n);
      Serial.println(" networks found");
      for (int i = 0; i < n; ++i) {        
          jsonSpots << "\"";
          jsonSpots << WiFi.SSID(i).c_str();
          jsonSpots << "\"";
          if (i != n - 1)
            jsonSpots << ",";
          jsonSpots << "\n";
          delay(10);
      }
  }
  jsonSpots << "]}";
  String resp = jsonSpots.str().c_str();
  return resp;
}

//===============================================================
// Setup
//===============================================================

void setup(void){
  Serial.begin(115200);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  Serial.println();
  Serial.println("Booting Sketch...");

//ESP32 As access point IP: 192.168.4.1
  WiFi.mode(WIFI_AP_STA); //Access Point mode
  WiFi.softAP(APssid, APpassword);    //Password length minimum 8 char
  delay(2000);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  Serial.println(WiFi.localIP());

  wifiSpots = getWifiSpots();

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", MAIN_page);
  });

  server.on("/spots", HTTP_GET, [](AsyncWebServerRequest *request){
    callScan = true;
    //lidOpen = !lidOpen;
    request->send_P(200, "text/plain", wifiSpots.c_str());
  });

  server.on("/isconnected", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(connected).c_str());
  });

  server.on("/content", HTTP_GET, [](AsyncWebServerRequest *request){
    if (lidOpen){      
      request->send_P(200, "text/plain", "open");
    }
    else
    {
      request->send_P(200, "text/plain", String(content_percent).c_str());
    }
  });

  server.on("/connect", HTTP_POST, [](AsyncWebServerRequest *request){}, NULL,
    [](AsyncWebServerRequest * request, uint8_t *data, size_t len, size_t index, size_t total) {

    string s(data, data + len);

    unsigned first = s.find("{\"name\":\"");
    unsigned last = s.find("\",\"password\":\"");
    String name(s.substr(first + 9, last - first - 9).c_str());
    
    first = last;
    last = s.find("\"}");
    String pass(s.substr(first + 14, last - first - 14).c_str());

    savedSSID = name;
    savedPASSWORD = pass;

    request->send_P(200, "text/plain", "Connected");
  });
 
  server.begin();                // =====================================================>
  Serial.println("HTTP server started");
}

//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================
void loop(void){
  unsigned long currentMillis = millis();
  if (callScan) {
    wifiSpots = getWifiSpots();
    callScan = false;
  }
  if ((savedSSID != "" || savedPASSWORD != "") && connected == false)
  {
    bool success = connectToWifi(savedSSID, savedPASSWORD);   //Connexion
    connected = true;
  }
  if (currentMillis % 1000 == 0) {
    content_percent = getContentPercent();
  }
}