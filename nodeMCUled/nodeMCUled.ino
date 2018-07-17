#include <ESP8266WiFi.h>
 
const char* ssid = "BKGC-U2hhd24"; // ssid
const char* password = "00000000";// password
 
int led1 = 2; // D4
int led2 = 14; // D5
int led3 = 12; // D6
WiFiServer server(80);
 
void setup() {
  Serial.begin(115200);
  delay(10);
 
  pinMode(led1, OUTPUT);
  digitalWrite(led1, LOW);
  pinMode(led2, OUTPUT);
  digitalWrite(led2, LOW);
  pinMode(led3, OUTPUT);
  digitalWrite(led3, LOW);
 
  // Connection to wireless network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);
 
   while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");

}
 
void loop() {
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
 
  // engine
 

  if (request.indexOf("/c1on") != -1)  {
    digitalWrite(led1, HIGH);
    delay(2000);
  }
  if (request.indexOf("/c1off") != -1)  {
    digitalWrite(led1, LOW);
  }  
  int stat2 = 0;
  if (request.indexOf("/c2on") != -1)  {
    digitalWrite(led2, HIGH);
    delay(2000);
  }
  if (request.indexOf("/c2off") != -1)  {
    digitalWrite(led2, LOW);
  }  
 int stat3 = 0;
  if (request.indexOf("/c3on") != -1)  {
    digitalWrite(led3, HIGH);
  }
  if (request.indexOf("/c3off") != -1)  {
    digitalWrite(led3, LOW);
    stat3 = 0;
  }  

 
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
 
}
