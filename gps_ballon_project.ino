
#include <TinyGPS++.h>
#include <SoftwareSerial.h>
static const int RXPin = 13, TXPin = 14;
static const uint32_t GPSBaud = 9600;
// The TinyGPS++ object
TinyGPSPlus gps;
// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);
void setup(){

 Serial.begin(9600);
 ss.begin(9600);
//GPSBaud

     

    Serial.println ("                     GPS                   ");
  
   gps.encode(ss.read());
   if (gps.location.isUpdated()){
     Serial.print("Latitude= "); 
     Serial.print(gps.location.lat(), 6);
     Serial.print(" Longitude= "); 
     Serial.println(gps.location.lng(), 6);


   }
 
 
}
void loop(){
 // This sketch displays information every time a new sentence is correctly encoded.
 while (ss.available() > 0){
   gps.encode(ss.read());
   if (gps.location.isUpdated()){
     Serial.print("Latitude= "); 
     Serial.print(gps.location.lat(), 6);
     Serial.print(" Longitude= "); 
     Serial.println(gps.location.lng(), 6);
 Serial.print("altitude= ");
 Serial.print(gps.altitude.meters(), 6);

     
   }
 }
}
