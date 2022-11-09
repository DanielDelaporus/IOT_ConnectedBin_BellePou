const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en" >
<head>
  <meta charset="UTF-8">
  <title>BellePou</title>
<style>
body {
  background: #f2f2f2;
}
.animate {
  -webkit-transition: all 0.3s linear;
  transition: all 0.3s linear;
}
.text-center {
  text-align: center;
}
.container-dailies {
  display: grid; 
  grid-template-columns: 1fr 1fr 1fr 1fr 1fr 1fr 1fr; 
  grid-template-rows: 1fr; 
  gap: 2% 2%; 
  grid-template-areas: 
    ". . . . . . ."; 
}
.pull-left {
  float: left;
}
.horr {
 vertical-align: top;
}
.pull-right {
  float: right;
}
.clearfix:after {
  visibility: hidden;
  display: block;
  font-size: 0;
  content: " ";
  clear: both;
  height: 0;
}
.clearfix {
  display: inline-block;
}
/* start commented backslash hack \*/
* html .clearfix {
  height: 1%;
}
.clearfix {
  display: block;
}
/* close commented backslash hack */
a {
  color: #00A885;
}
a:hover,
a:focus {
  color: #00755d;
  -webkit-transition: all 0.3s linear;
  transition: all 0.3s linear;
}
.text-primary {
  color: #00A885;
}
input:-webkit-autofill {
  box-shadow: 0 0 0 1000px white inset !important;
}
.logo h1 {
  color: #00A885;
  margin-bottom: -12px;
}
input[type="checkbox"] {
  width: auto;
}
button {
  cursor: pointer;
  background: #00A885;
  width: 100%;
  border: 0;
  padding: 10px 15px;
  color: #fff;
  font-size: 20px;
  -webkit-transition: 0.3s linear;
  transition: 0.3s linear;
}
span.validate-tooltip {
  background: #D91717;
  width: 100%;
  display: block;
  padding: 5px;
  color: #fff;
  box-sizing: border-box;
  font-size: 14px;
  margin-top: -28px;
  -webkit-transition: all 0.3s ease-in-out;
  transition: all 0.3s ease-in-out;
  -webkit-animation: tooltipanimation 0.3s 1;
  animation: tooltipanimation 0.3s 1;
}
.current {
    background-color: #00A885;
    color: black;
    padding: 1%;
    text-align: left;
    width: 60%;  
    font-size: 20px;
        border-radius: 15px;
}
.daily {
    background-color: #00A885;
    color: black;
    padding: 1%;
    text-align: left;
    width:  20%;  
    font-size: 20px;
        border-radius: 15px;
}
.input-group {
  position: relative;
  margin-bottom: 20px;
}
.input-group label {
  position: absolute;
  top: 9px;
  left: 10px;
  font-size: 16px;
  color: #cdcdcd;
  font-weight: normal;
  padding: 2px 5px;
  z-index: 5;
  -webkit-transition: all 0.3s linear;
  transition: all 0.3s linear;
}
.input-group input {
  outline: none;
  display: block;
  width: 100%;
  height: 40px;
  position: relative;
  z-index: 3;
  border: 1px solid #d9d9d9;
  padding: 10px 10px;
  background: #ffffff;
  box-sizing: border-box;
  font-weight: 400;
  -webkit-transition: 0.3s ease;
  transition: 0.3s ease;
}
.input-group select {
  outline: none;
  display: block;
  width: 100%;
  height: 40px;
  position: relative;
  z-index: 3;
  border: 1px solid #d9d9d9;
  padding: 10px 10px;
  background: #ffffff;
  box-sizing: border-box;
  font-weight: 400;
  -webkit-transition: 0.3s ease;
  transition: 0.3s ease;
}
.input-group .lighting {
  background: #00A885;
  width: 0;
  height: 2px;
  display: inline-block;
  position: absolute;
  top: 40px;
  left: 0;
  -webkit-transition: all 0.3s linear;
  transition: all 0.3s linear;
}
.input-group.focused .lighting {
  width: 100%;
}
.input-group.focused label {
  background: #fff;
  font-size: 12px;
  top: -8px;
  left: 5px;
  color: #00A885;
}
.input-group span.validate-tooltip {
  margin-top: 0;
}
.wrapper {
  width: 320px;
  background: #fff;
  margin: 20px auto;
  min-height: 200px;
  border: 1px solid #f3f3f3;
}
.wrapper .inner-warpper {
  padding: 50px 30px 60px;
  box-shadow: 1px 1.732px 10px 0px rgba(0, 0, 0, 0.063);
}
.wrapper .title {
  margin-top: 0;
}
.wrapper .supporter {
  margin-top: 10px;
  font-size: 14px;
  color: #8E8E8E;
  cursor: pointer;
}
.wrapper .remember-me {
  cursor: pointer;
}
.wrapper input[type="checkbox"] {
  float: left;
  margin-right: 5px;
  margin-top: 2px;
  cursor: pointer;
}
.wrapper label[for="rememberMe"] {
  cursor: pointer;
}
.wrapper .signup-wrapper {
  padding: 10px;
  font-size: 14px;
  background: #EBEAEA;
}
.wrapper .signup-wrapper a {
  text-decoration: none;
  color: #7F7F7F;
}
.wrapper .signup-wrapper a:hover {
  text-decoration: underline;
}
@-webkit-keyframes tooltipanimation {
  from {
    margin-top: -28px;
  }
  to {
    margin-top: 0;
  }
}
@keyframes tooltipanimation {
  from {
    margin-top: -28px;
  }
  to {
    margin-top: 0;
  }
}
.direction {
  width: 200px;
  position: fixed;
  top: 120px;
  left: 20px;
  font-size: 14px;
  line-height: 1.2;
  text-align: center;
  background: #9365B8;
  padding: 10px;
  color: #fff;
}
@media (max-width: 480px) {
  .direction {
    position: static;
  }
}

  </style> 
</head>
<body>
<!-- partial:index.partial.html -->
<div class="logo text-center">
  <h1>BellePou</h1>
</div>
<div class="wrapper">
  <div class="inner-warpper text-center">
    <h2 class="title">Connection à l'appareil</h2>
    <form action="" id="formvalidate">
      <div class="input-group">
        <select name="spotName" id="spotName">
        </select>
        <span class="lighting"></span>
      </div>
      <div class="input-group">
        <input class="form-control" name="userPassword" id="userPassword" type="password" placeholder="Password" />
        <span class="lighting"></span>
      </div>
    </form>
    </br>
    <button id="login" onclick="postingCredentials()">Login</button>
    </br>
    </br>
    <button type="refresh" id="refresh" onclick="refresh()">Refresh</button>
  </div>
  </br>
  <div class="horr">
  
    <div class="inner-warpper">
      <h2 class="title">Remplissage de la BellePou :</h2>
      </br>
      <div class="container">
          <div class="current" id="contentBar">0%</div>
      </div>
    </div>
    
    </br>
    
    <div class="inner-warpper">
      <h2 class="title">Remplissage dans la semaine :</h2>
      </br>
        <div class="container">
          <div class="daily" id="dailyLundi" onclick="changeDaily('Lundi')">L:0%</div>
          <div class="daily" id="dailyMardi" onclick="changeDaily('Mardi')">M:0%</div>
          <div class="daily" id="dailyMercredi" onclick="changeDaily('Mercredi')">M:0%</div>
          <div class="daily" id="dailyJeudi" onclick="changeDaily('Jeudi')">J:0%</div>
          <div class="daily" id="dailyVendredi" onclick="changeDaily('Vendredi')">V:0%</div>
          <div class="daily" id="dailySamedi" onclick="changeDaily('Samedi')">S:0%</div>
          <div class="daily" id="dailyDimanche" onclick="changeDaily('Dimanche')">D:0%</div>
        </div>
    </div>
    <div class="inner-warpper">
      <h2 class="title">Status de Connection</h2>
      <h1 style="text-align:center;color=#A80022;font-size: 160px;margin-top: 1%;margin-bottom: 1%;" id="arobase">@</h1>
    </div>
  </div>
</div>

<script>

const dailies = {                             // VALEUR DU TABLEAU JOURNALIER
  "Lundi" :    "28%",
  "Mardi" :    "64%",
  "Mercredi" : "98%",
  "Jeudi" :    "14%",
  "Vendredi" : "57%",
  "Samedi" :   "82%",
  "Dimanche" : "11%",
}

function changeDaily(day) {                    // CHANGE LA VALEUR DES DONNEES DU JOUR SPECIFIE PAR LA VALEUR DU CAPTEUR
  switch(day) {
    case "Lundi":
      dailies.Lundi = document.getElementById("contentBar").style.width;  
      break;
    
    case "Mardi":
      dailies.Mardi = document.getElementById("contentBar").style.width;  
      break;
    
    case "Mercredi":
      dailies.Mercredi = document.getElementById("contentBar").style.width;  
      break;
    
    case "Jeudi":
      dailies.Jeudi = document.getElementById("contentBar").style.width;  
      break;
    
    case "Vendredi":
      dailies.Vendredi = document.getElementById("contentBar").style.width;  
      break;
    
    case "Samedi":
      dailies.Samedi = document.getElementById("contentBar").style.width;  
      break;
    
    case "Dimanche":
      dailies.Dimanche = document.getElementById("contentBar").style.width;  
      break;
    
    default:
      break;
  }
  actualizeDailies();
}

function actualizeDailies() {                              // FONCTION QUI ACTUALISE L'AFFICHAGE DES DONNEES JOURNALIERES
  document.getElementById("dailyLundi").innerHTML = "L:" + dailies.Lundi;
  document.getElementById("dailyLundi").style.width = dailies.Lundi;
  
  document.getElementById("dailyMardi").innerHTML = "M:" + dailies.Mardi;
  document.getElementById("dailyMardi").style.width = dailies.Mardi;

  document.getElementById("dailyMercredi").innerHTML = "M:" + dailies.Mercredi;
  document.getElementById("dailyMercredi").style.width = dailies.Mercredi;

  document.getElementById("dailyJeudi").innerHTML = "J:" + dailies.Jeudi;
  document.getElementById("dailyJeudi").style.width = dailies.Jeudi;

  document.getElementById("dailyVendredi").innerHTML = "V:" + dailies.Vendredi;
  document.getElementById("dailyVendredi").style.width = dailies.Vendredi;

  document.getElementById("dailySamedi").innerHTML = "S:" + dailies.Samedi;
  document.getElementById("dailySamedi").style.width = dailies.Samedi;

  document.getElementById("dailyDimanche").innerHTML = "D:" + dailies.Dimanche;
  document.getElementById("dailyDimanche").style.width = dailies.Dimanche;
}

function refresh() {                                                  // LE BOUTON REFRESH LANCE LE SCAN DES WIFIS AUTOUR DE SOI ET LES AJOUTES DANS LE SELECTEUR
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("spotName").innerHTML = "";
      console.log(this.responseText);
      var spotList = JSON.parse(this.responseText).list;
      spotList.forEach( (spot) => {
        var opt = document.createElement("option");
        opt.text = spot;
        document.getElementById("spotName").add(opt);
      });
    };      
  };
  actualizeDailies();

  xhttp.open("GET", "/spots", true);
  xhttp.send();
};

function  postingCredentials() {                                       // LES CREDENTIALS ENTREES DANS L'INTERFACE SONT ENVOYES AU "BellePou.ino" POUR LANCER LA CONNECTION
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("tests").innerHTML = "Connected";
    }
    else if (this.status == 300) {
      document.getElementById("tests").innerHTML = "Wrong Password";      
    };      
  };


  xhttp.open("POST", "/connect", true);
  
  xhttp.setRequestHeader("Content-Type", "application/json");

  const ssid = document.getElementById("spotName").selectedOptions[0].text;
  const pass = document.getElementById("userPassword").value;

  var body = JSON.stringify({"name":ssid,"password":pass});
  
  xhttp.send(body);
};

setInterval(function ( ) {                                       // RECUPERE LA VALEUR EN POURCENT DONNEE PAR LE CAPTEUR DE REMPLISSAGE DE LA POUBELLE
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      if (this.responseText == "open") {
        document.getElementById("contentBar").innerHTML = "Couvercle Ouvert";
        document.getElementById("contentBar").style.width = "100%";
        document.getElementById("contentBar").style.color = "#A80022";
      }
      else {
        document.getElementById("contentBar").innerHTML = this.responseText + "%";
        document.getElementById("contentBar").style.width = this.responseText + "%";
        document.getElementById("contentBar").style.backgroundColor = "#00A885";
      }
    }
  };
  xhttp.open("GET", "/content", true);
  xhttp.send();
}, 1000);


setInterval(function ( ) {                                       // CHECK LA VALEUR DU BOOLEEN "connected" DANS "BellePou.ino" ET CHANGE LA COULEUR DU SIGNAL AROBAZE 
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      if (this.responseText == "1") {
        document.getElementById("arobase").style.color = "#00A885";
      }
      else {
        document.getElementById("arobase").style.color = "#A80022";
      }
    }
  };
  xhttp.open("GET", "/isconnected", true);
  xhttp.send();
}, 1000);


setInterval(function ( ) {                                      // ACTUALISATION DE DONNEES TOUTES LES 10 SECONDES (C'est plus pour la première fois que c'est important)
  actualizeDailies();
}, 10000);

setInterval(function ( ) {                                      // CETTE FONCTION CHANGE LES DONNEES DE LA JOURNEE A 23H PAR LA VALEUR ENREGISTREE
  let current = new Date();
  let day = current.getDay();

  let used = -1;

  if (current.getHours() == 23 && used != day)
  {
    used = day;

    switch(day) {
      case 0:
        changeDaily("Dimanche");
        break;
      
      case 1:
        changeDaily("Lundi");
        break;
      
      case 2:
        changeDaily("Mardi"); 
        break;
      
      case 3:
        changeDaily("Mercredi");
        break;
      
      case 4:
        changeDaily("Jeudi"); 
        break;
      
      case 5:
        changeDaily("Vendredi");
        break;
      
      case 6:
        changeDaily("Samedi");
        break;
      
      default:
        break;
    }    
  }
}, 1000);

</script>
)=====";