/*
  Titre      : Conexion I2C
  Auteur     : Cedric Yonta
  Date       : 13/02/2022
  Description: communique avec un autre uC
  Droits     : ...
  Version    : 0.0.1
  Source     :https://www.instructables.com/I2C-between-Arduinos/
*/

#include <Arduino.h>

// Include the required Wire library for I2C<br>
#include <Wire.h>

int x ;
const int brocheanalog = A1; //A1 ; //4;
void setup() {

  
  // Start the I2C Bus as Master
  pinMode(brocheanalog,INPUT);
  Wire.begin(); 
}
void loop() {
  x = analogRead(brocheanalog);
  x = map(x, 0, 1023, 0, 255);
  Serial.println(x);
  

  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(x);              // sends x 
  Wire.endTransmission();    // stop transmitting
 
  
}