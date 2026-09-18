#include <WiFi.h>
#include <ESPping.h>
#include <WebServer.h>

// ==================================================
// ESP32 MINI IDS
// Part 1 - WiFi Baseline
// Part 2 - Network Connectivity Monitoring
// Part 3 - Device Discovery
// Part 4 - Unknown Device Detection
// Part 5 - Security Alert
// Part 6 - Web Dashboard
// Part 7 - Final Integration
// ==================================================


// ==================================================
// Wi-Fi Settings
// ==================================================

const char* ssid = "Infinix HOT 40 Pro";
const char* password = "12345678";


// ==================================================
// Known Devices
// Add trusted IP addresses here
// ==================================================

const char* knownDevices[] = {
  "10.239.161.159"
};

const int knownDeviceCount = 1;


// ==================================================
// Web Server
// ==================================================

WebServer server(80);


// ==================================================
// Wi-Fi State
// ==================================================

bool previousWiFiState = false;


// ==================================================
// IDS Variables
// ==================================================

int activeDeviceCount = 0;
int unknownDeviceCount = 0;

String lastUnknownIP = "None";

bool gatewayOnline = false;
bool internetOnline = false;


// ==================================================
// Timing
// ==================================================

unsigned long lastNetworkCheck = 0;
unsigned long lastScan = 0;

const unsigned long networkCheckInterval = 5000;
const unsigned long scanInterval = 30000;


// ==================================================
// Check Known Device
// ==================================================

bool isKnownDevice(IPAddress ip) {

  String currentIP = ip.toString();

  for (int i = 0; i < knownDeviceCount; i++) {

    if (currentIP == String(knownDevices[i])) {
      return true;
    }
  }

  return false;
}


// ==================================================
// Network Device Discovery
// ==================================================

void scanNetwork() {

  if (WiFi.status() != WL_CONNECTED) {
    return;
  }

  IPAddress localIP = WiFi.localIP();

  activeDeviceCount = 0;
  unknownDeviceCount = 0;

  lastUnknownIP = "None";


  Serial.println();
  Serial.println("========================================");
  Serial.println("       ESP32 MINI IDS - SCAN");
  Serial.println("========================================");


  int deviceNo = 0;


  // Scan local network
  for (int i = 1; i <= 254; i++) {

    IPAddress target = localIP;

    // Change last octet
    target[3] = i;


    // Skip ESP32 own IP
    if (target == localIP) {
      continue;
    }


    // Ping device
    if (Ping.ping(target, 1)) {

      deviceNo++;
      activeDeviceCount++;


      Serial.println();
      Serial.print("Device No : ");
      Serial.println(deviceNo);

      Serial.print("IP Address: ");
      Serial.println(target);


      // ==========================================
      // Known Device
      // ==========================================

      if (isKnownDevice(target)) {

        Serial.println("Status    : KNOWN");
      }


      // ==========================================
      // Unknown Device
      // ==========================================

      else {

        unknownDeviceCount++;

        lastUnknownIP = target.toString();


        Serial.println("Status    : UNKNOWN");


        // ========================================
        // Security Alert
        // ========================================

        unsigned long alertTime = millis() / 1000;


        Serial.println();
        Serial.println("========================================");
        Serial.println("          SECURITY ALERT");
        Serial.println("========================================");

        Serial.println("Alert Type : UNKNOWN DEVICE");

        Serial.print("IP Address : ");
        Serial.println(target);

        Serial.print("Time       : ");
        Serial.print(alertTime);
        Serial.println(" sec");

        Serial.println("Severity   : MEDIUM");

        Serial.println("Status     : DETECTED");

        Serial.println("========================================");
      }


      Serial.println("----------------------------------------");
    }
  }


  Serial.println();

  Serial.print("Total Active Devices : ");
  Serial.println(activeDeviceCount);

  Serial.print("Unknown Devices      : ");
  Serial.println(unknownDeviceCount);

  Serial.println("========================================");
}


// ==================================================
// Network Connectivity Check
// ==================================================

void checkNetworkStatus() {

  if (WiFi.status() != WL_CONNECTED) {

    gatewayOnline = false;
    internetOnline = false;

    return;
  }


  // ================================================
  // Gateway Check
  // ================================================

  IPAddress gateway = WiFi.gatewayIP();

  gatewayOnline = Ping.ping(gateway, 3);


  // ================================================
  // Internet Check
  // ================================================

  IPAddress internetIP(8, 8, 8, 8);

  internetOnline = Ping.ping(internetIP, 3);


  // ================================================
  // Serial Output
  // ================================================

  Serial.println();
  Serial.println("========================================");

  Serial.print("WiFi Status     : ");

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("CONNECTED");
  }
  else {
    Serial.println("DISCONNECTED");
  }


  Serial.print("Gateway Status  : ");

  if (gatewayOnline) {
    Serial.println("ONLINE");
  }
  else {
    Serial.println("OFFLINE");
  }


  Serial.print("Internet Status : ");

  if (internetOnline) {
    Serial.println("ONLINE");
  }
  else {
    Serial.println("OFFLINE");
  }


  Serial.println("========================================");
}


// ==================================================
// Web Dashboard
// ==================================================

void handleRoot() {

  String html = "";

  html += "<!DOCTYPE html>";
  html += "<html>";
  html += "<head>";

  html += "<meta name='viewport' content='width=device-width, initial-scale=1'>";

  html += "<meta http-equiv='refresh' content='10'>";

  html += "<title>ESP32 Mini IDS</title>";


  // ================================================
  // CSS
  // ================================================

  html += "<style>";

  html += "body{";
  html += "font-family:Arial;";
  html += "background:#f2f2f2;";
  html += "margin:0;";
  html += "padding:20px;";
  html += "}";


  html += ".container{";
  html += "max-width:700px;";
  html += "margin:auto;";
  html += "}";


  html += "h1{";
  html += "text-align:center;";
  html += "}";


  html += ".card{";
  html += "background:white;";
  html += "padding:20px;";
  html += "margin:15px 0;";
  html += "border-radius:10px;";
  html += "box-shadow:0 2px 8px rgba(0,0,0,0.15);";
  html += "}";


  html += ".status{";
  html += "font-size:22px;";
  html += "font-weight:bold;";
  html += "}";


  html += ".online{";
  html += "color:green;";
  html += "}";


  html += ".offline{";
  html += "color:red;";
  html += "}";


  html += ".alert{";
  html += "background:#fff3cd;";
  html += "padding:15px;";
  html += "border-radius:8px;";
  html += "}";


  html += ".danger{";
  html += "color:red;";
  html += "font-weight:bold;";
  html += "}";


  html += "</style>";

  html += "</head>";


  // ================================================
  // Body
  // ================================================

  html += "<body>";

  html += "<div class='container'>";


  html += "<h1>ESP32 MINI IDS</h1>";

  html += "<p style='text-align:center;'>Network Intrusion Detection Monitor</p>";


  // ================================================
  // IDS Status
  // ================================================

  html += "<div class='card'>";

  html += "<h2>IDS Status</h2>";

  html += "<p class='status online'>MONITORING</p>";

  html += "</div>";


  // ================================================
  // Wi-Fi Information
  // ================================================

  html += "<div class='card'>";

  html += "<h2>Wi-Fi Information</h2>";


  html += "<p><b>SSID:</b> ";
  html += WiFi.SSID();
  html += "</p>";


  html += "<p><b>IP Address:</b> ";
  html += WiFi.localIP().toString();
  html += "</p>";


  html += "<p><b>Gateway:</b> ";
  html += WiFi.gatewayIP().toString();
  html += "</p>";


  html += "<p><b>Subnet Mask:</b> ";
  html += WiFi.subnetMask().toString();
  html += "</p>";


  html += "<p><b>RSSI:</b> ";
  html += String(WiFi.RSSI());
  html += " dBm</p>";


  html += "</div>";


  // ================================================
  // Network Status
  // ================================================

  html += "<div class='card'>";

  html += "<h2>Network Status</h2>";


  html += "<p><b>Wi-Fi:</b> ";

  if (WiFi.status() == WL_CONNECTED) {
    html += "<span class='online'>CONNECTED</span>";
  }
  else {
    html += "<span class='offline'>DISCONNECTED</span>";
  }

  html += "</p>";


  html += "<p><b>Gateway:</b> ";

  if (gatewayOnline) {
    html += "<span class='online'>ONLINE</span>";
  }
  else {
    html += "<span class='offline'>OFFLINE</span>";
  }

  html += "</p>";


  html += "<p><b>Internet:</b> ";

  if (internetOnline) {
    html += "<span class='online'>ONLINE</span>";
  }
  else {
    html += "<span class='offline'>OFFLINE</span>";
  }

  html += "</p>";


  html += "</div>";


  // ================================================
  // Device Information
  // ================================================

  html += "<div class='card'>";

  html += "<h2>Device Monitoring</h2>";


  html += "<p><b>Active Devices:</b> ";
  html += String(activeDeviceCount);
  html += "</p>";


  html += "<p><b>Unknown Devices:</b> ";
  html += String(unknownDeviceCount);
  html += "</p>";


  html += "<p><b>Last Unknown IP:</b> ";
  html += lastUnknownIP;
  html += "</p>";


  html += "</div>";


  // ================================================
  // Security Alert
  // ================================================

  if (unknownDeviceCount > 0) {

    html += "<div class='card alert'>";

    html += "<h2>Security Alert</h2>";

    html += "<p class='danger'>UNKNOWN DEVICE DETECTED</p>";

    html += "<p><b>IP Address:</b> ";
    html += lastUnknownIP;
    html += "</p>";

    html += "<p><b>Severity:</b> MEDIUM</p>";

    html += "</div>";
  }


  else {

    html += "<div class='card'>";

    html += "<h2>Security Status</h2>";

    html += "<p class='online'>No Unknown Devices Detected</p>";

    html += "</div>";
  }


  // ================================================
  // Footer
  // ================================================

  html += "<p style='text-align:center;'>ESP32 Mini IDS | Sasidu-Tech</p>";


  html += "</div>";

  html += "</body>";

  html += "</html>";


  server.send(200, "text/html", html);
}


// ==================================================
// Setup
// ==================================================

void setup() {

  Serial.begin(115200);

  delay(1000);


  Serial.println();

  Serial.println("========================================");

  Serial.println("          ESP32 MINI IDS");

  Serial.println("========================================");


  // ================================================
  // Connect Wi-Fi
  // ================================================

  WiFi.begin(ssid, password);


  Serial.print("Connecting to WiFi");


  while (WiFi.status() != WL_CONNECTED) {

    delay(500);

    Serial.print(".");
  }


  Serial.println();

  Serial.println();


  // ================================================
  // Wi-Fi Information
  // ================================================

  Serial.println("WiFi Status : CONNECTED");


  Serial.print("SSID        : ");
  Serial.println(WiFi.SSID());


  Serial.print("IP Address  : ");
  Serial.println(WiFi.localIP());


  Serial.print("Gateway     : ");
  Serial.println(WiFi.gatewayIP());


  Serial.print("Subnet Mask : ");
  Serial.println(WiFi.subnetMask());


  Serial.print("RSSI        : ");
  Serial.print(WiFi.RSSI());
  Serial.println(" dBm");


  Serial.print("MAC Address : ");
  Serial.println(WiFi.macAddress());


  Serial.println();


  // ================================================
  // Start Web Server
  // ================================================

  server.on("/", handleRoot);

  server.begin();


  Serial.println("Web Server  : STARTED");


  Serial.print("Dashboard   : http://");

  Serial.println(WiFi.localIP());


  Serial.println();


  Serial.println("IDS Status  : MONITORING...");


  Serial.println("========================================");


  // ================================================
  // Initial Network Check
  // ================================================

  checkNetworkStatus();


  // ================================================
  // Initial Device Scan
  // ================================================

  scanNetwork();


  previousWiFiState = true;


  lastNetworkCheck = millis();

  lastScan = millis();
}


// ==================================================
// Loop
// ==================================================

void loop() {


  // ================================================
  // Handle Web Server
  // ================================================

  server.handleClient();


  // ================================================
  // Wi-Fi State Monitoring
  // ================================================

  bool currentWiFiState =
    (WiFi.status() == WL_CONNECTED);


  // ================================================
  // Wi-Fi Connection Lost
  // ================================================

  if (previousWiFiState == true &&
      currentWiFiState == false) {

    Serial.println();

    Serial.println("========================================");

    Serial.println("🚨 ALERT: WiFi CONNECTION LOST!");

    Serial.println("========================================");
  }


  // ================================================
  // Wi-Fi Connection Restored
  // ================================================

  if (previousWiFiState == false &&
      currentWiFiState == true) {

    Serial.println();

    Serial.println("========================================");

    Serial.println("✅ ALERT: WiFi CONNECTION RESTORED!");

    Serial.println("========================================");
  }


  previousWiFiState = currentWiFiState;


  // ================================================
  // Network Status Check
  // Every 5 seconds
  // ================================================

  if (millis() - lastNetworkCheck >=
      networkCheckInterval) {

    lastNetworkCheck = millis();

    checkNetworkStatus();
  }


  // ================================================
  // Network Device Scan
  // Every 30 seconds
  // ================================================

  if (millis() - lastScan >= scanInterval) {

    lastScan = millis();

    scanNetwork();
  }


  delay(10);
}
