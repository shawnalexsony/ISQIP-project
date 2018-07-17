
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
 
const char* ssid = "BKGC-U2hhd24";
const char* password = "00000000";
//IPAddress ip(192, 168, 0, 107); //set static ip
//IPAddress gateway(192, 168, 43, 1); //set getteway
//IPAddress subnet(255, 255, 255, 0);//set subnet

 

// defines pins numbers

const int trigPin1 = 16;  //D0
const int echoPin1 = 5;  //D1
const int trigPin2 = 4;  //D2
const int echoPin2 = 0;  //D3
const int trigPin3 = 2;  //D4
const int echoPin3 = 14;  //D5

// defines variables
long duration;
int distance;
int trigPin;
int echoPin;
int s1;
int s2;
int s3;

void setup() {


Serial.begin(115200);
WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
 
    delay(1000);
    Serial.print("Connecting..");
 
  }

  
pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin2, INPUT); // Sets the echoPin as an Input
pinMode(trigPin3, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin3, INPUT); // Sets the echoPin as an Input
}

void loop() {
digitalWrite(trigPin1, LOW);
delayMicroseconds(2);
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);
duration = pulseIn(echoPin1, HIGH);
distance= duration*0.034/2;
if(distance<=30)
{s1=1;}
else
{s1=0;}

digitalWrite(trigPin2, LOW);
delayMicroseconds(2);
digitalWrite(trigPin2, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin2, LOW);
duration = pulseIn(echoPin2, HIGH);
distance= duration*0.034/2;
if(distance<=30)
{s2=1;}
else
{s2=0;}

digitalWrite(trigPin3, LOW);
delayMicroseconds(2);
digitalWrite(trigPin3, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin3, LOW);
duration = pulseIn(echoPin3, HIGH);
distance= duration*0.034/2;
if(distance<=30)
{s3=1;}
else
{s3=0;}

 if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
 
    HTTPClient http;  //Declare an object of class HTTPClient

   if(s1==1){
    http.begin("http://localhost:8080/s1on");      
    int httpCode = http.GET();
   }
   if(s2==1){
    http.begin("http://localhost:8080/s2on");      
    int httpCode = http.GET();
   }
   if(s3==1){
    http.begin("http://localhost:8080/s3on");      
    int httpCode = http.GET();
   }
    if(s1==0){
    http.begin("http://localhost:8080/s1off");      
    int httpCode = http.GET();
   }
   if(s2==0){
    http.begin("http://localhost:8080/s2off");      
    int httpCode = http.GET();
   }
   if(s3==0){
    http.begin("http://localhost:8080/s3off");      
    int httpCode = http.GET();
   }
      
    http.end();   //Close connection
 
  }
 
  delay(5000);


}
