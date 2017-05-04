
#include <SPI.h>
#include <WiFi101.h>
#include <WiFiUdp.h>

int status = WL_IDLE_STATUS;
char ssid[] = "NetworkName"; //  your network SSID (name)
char pass[] = "Password";    // your network password (use for WPA, or use as key for WEP)
String DestinationIP: "192.168.1.1"; // the IP of your computer running max
int keyIndex = 0;            // your network key Index number (needed only for WEP)

WiFiUDP Udp;

void setup() {

  // Needs a moment to settle
  // (Without this, I found the sketch would not auto-start)
  delay(4000);

  
  //Initialize serial and wait for port to open:
  Serial.begin(9600);

  // Attempt to connect to WiFi network:
  while ( status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);

    // wait 10 seconds for connection:
    delay(10000);
  }
  Serial.println("Connected to wifi");
  printWiFiStatus();

  Serial.println("\nStarting connection to server...");
  // if you get a connection, report back via serial:
  Udp.begin(7777);
}

void loop() {

  //array analogs = [A0,A1,A2];

  for(int i = 0; i < 7; i = i + 1) {
  
    int sensorValue = analogRead(i);
    Serial.println(sensorValue);

    String valueString = String(sensorValue);
    String indexString = String(i);
    valueString = "A"+indexString+" "+valueString;
    char value[valueString.length()];
    valueString.toCharArray(value,valueString.length()+1);
    Serial.println(value);
  
    Udp.beginPacket(DestinationIP, 7777);
    Udp.write(value);
    Udp.endPacket();
  
  }
  
  delay(100);

  

  
}


void printWiFiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}




