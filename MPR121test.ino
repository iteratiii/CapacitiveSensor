/*********************************************************
This is a library for the MPR121 12-channel Capacitive touch sensor

Designed specifically to work with the MPR121 Breakout in the Adafruit shop 
  ----> https://www.adafruit.com/products/

These sensors use I2C communicate, at least 2 pins are required 
to interface

Adafruit invests time and resources providing this open source code, 
please support Adafruit and open-source hardware by purchasing 
products from Adafruit!

Written by Limor Fried/Ladyada for Adafruit Industries.  
BSD license, all text above must be included in any redistribution
**********************************************************/

#include <Wire.h>
#include "Adafruit_MPR121.h"
#include <PCM.h>

#define fx0 13
#define fx1 12
#define fx2 11
#define fx3 10
#define fx4 9
#define fx5 8
#define fx6 7
#define fx7 6

#ifndef _BV
#define _BV(bit) (1 << (bit)) 
#endif

// You can have up to 4 on one i2c bus but one is enough for testing!
Adafruit_MPR121 cap = Adafruit_MPR121();

// Keeps track of the last pins touched
// so we know when buttons are 'released'
uint16_t lasttouched = 8;
uint16_t currtouched = 8;

// #include <PCM.h>

void setup() {
  Serial.begin(9600);
  pinMode(fx0, OUTPUT);
  pinMode(fx1, OUTPUT);
  pinMode(fx2, OUTPUT);
  pinMode(fx3, OUTPUT);
  pinMode(fx4, OUTPUT);
  pinMode(fx5, OUTPUT);
  pinMode(fx6, OUTPUT);
  pinMode(fx7, OUTPUT);

  digitalWrite(fx0,HIGH);
  digitalWrite(fx1,HIGH);
  digitalWrite(fx2,HIGH);
  digitalWrite(fx3,HIGH);
  digitalWrite(fx4,HIGH);
  digitalWrite(fx5,HIGH);
  digitalWrite(fx6,HIGH);
  digitalWrite(fx7,HIGH);


  while (!Serial) { // needed to keep leonardo/micro from starting too fast!
    delay(1000);
  }
  
  Serial.println("Adafruit MPR121 Capacitive Touch sensor test"); 
  
  // Default address is 0x5A, if tied to 3.3V its 0x5B
  // If tied to SDA its 0x5C and if SCL then 0x5D
  if (!cap.begin(0x5A)) {
    Serial.println("MPR121 not found, check wiring?");
    while (1);
  }
  Serial.println("MPR121 found!");
}

void loop() {
  // Get the currently touched pads
  currtouched = cap.touched();

  // if(currtouched == 0){
  //     digitalWrite(fx0,LOW);
  //     Serial.println("0 touched");
  //     digitalWrite(fx0,HIGH);
  //     delay(200);
  // }
  // if(currtouched == 1){
  //     digitalWrite(fx1,LOW);
  //     Serial.println("1 touched");
  //     digitalWrite(fx1,HIGH);          
  //     delay(200);      
  // }
  // if(currtouched == 2){
  //     digitalWrite(fx2,LOW);
  //     Serial.println("2 touched");
  //     // delay(1000);
  //     digitalWrite(fx2,HIGH);
  //     delay(200);
  // }
  // if(currtouched == 3){
  //     digitalWrite(fx3,LOW);
  //     Serial.println("3 touched");
  //     // delay(1000);
  //     digitalWrite(fx3,HIGH);
  //     delay(200);
  // }
  // if(currtouched == 4){
  //     digitalWrite(fx4,LOW);
  //     Serial.println("4 touched");
  //     // delay(1000);
  //     digitalWrite(fx4,HIGH);
  //     delay(200);
  // }
  // if(currtouched == 5){
  //     digitalWrite(fx5,LOW);
  //     delay(200);
  //     // delay(1000);
  //     digitalWrite(fx5,HIGH);
  //     delay(200);
  // }
  // if(currtouched == 6){
  //     digitalWrite(fx6,LOW);
  //     Serial.println("6 touched");
  //     // delay(1000);
  //     digitalWrite(fx6,HIGH);
  //     delay(200);
  // }
  // if(currtouched == 7){
  //     digitalWrite(fx7,LOW);
  //     Serial.println("7 touched");
  //     // delay(1000);
  //     digitalWrite(fx7,HIGH);
  //     delay(200);
  // }



  for (uint8_t i=0; i<12; i++) {
    // it if *is* touched and *wasnt* touched before, alert!
    if ((currtouched & _BV(i)) && !(lasttouched & _BV(i)) ) {
      Serial.print(i); Serial.println(" touched");
      // tone(8, 10+(i*100), 500);
      // digitalWrite(fx1,LOW);

      switch(i) {
        case 0:
          digitalWrite(fx0,LOW);
          delay(100);
          // digitalWrite(fx0,HIGH);
          // delay(100);
          break;          
        case 1:
          digitalWrite(fx1,LOW);
          delay(100);
          // digitalWrite(fx1,HIGH);
          // delay(100);
          break;
        case 2:
          digitalWrite(fx2,LOW);
          delay(100);
          // digitalWrite(fx2,HIGH);
          // delay(100);
          break;
        case 3:
          digitalWrite(fx3,LOW);
          delay(100);
          // digitalWrite(fx3,HIGH);
          // delay(100);
          break;
        case 4:
          digitalWrite(fx4,LOW);
          delay(100);
          // digitalWrite(fx4,HIGH);
          // delay(100);
          break;
        case 5:
          digitalWrite(fx5,LOW);
          delay(100);
          // digitalWrite(fx5,HIGH);
          // delay(100);
          break;
        case 6:
          digitalWrite(fx6,LOW);
          delay(100);
          // digitalWrite(fx6,HIGH);
          // delay(100);
          break;
        case 7:
          digitalWrite(fx7,LOW);
          delay(100);
          // digitalWrite(fx7,HIGH);
          // delay(100);
          break;
      }

      delay(100);
    }
    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched & _BV(i)) && (lasttouched & _BV(i)) ) {
      Serial.print(i); Serial.println(" released");
      switch(i) {
        case 0:
          digitalWrite(fx0,HIGH);
          Serial.println("case 0");
          delay(100);
          break;
        case 1:
          digitalWrite(fx1,HIGH);          
          delay(100);
          break;
        case 2:
          digitalWrite(fx2,HIGH);
          delay(100);
          break;
        case 3:
          digitalWrite(fx3,HIGH);
          delay(100);
          break;
        case 4:
          digitalWrite(fx4,HIGH);
          delay(100);
          break;
        case 5:
          digitalWrite(fx5,HIGH);
          delay(100);
          break;
        case 6:
          digitalWrite(fx6,HIGH);
          delay(100);
          break;
        case 7:
          digitalWrite(fx7,HIGH);
          delay(100);
          break;
      }      
    }
  }

  // reset our state
  lasttouched = currtouched;

  // comment out this line for detailed data from the sensor!
  return;
  
  // debugging info, what
  Serial.print("\t\t\t\t\t\t\t\t\t\t\t\t\t 0x"); Serial.println(cap.touched(), HEX);
  Serial.print("Filt: ");
  for (uint8_t i=0; i<12; i++) {
    Serial.print(cap.filteredData(i)); Serial.print("\t");
  }
  Serial.println();
  Serial.print("Base: ");
  for (uint8_t i=0; i<12; i++) {
    Serial.print(cap.baselineData(i)); Serial.print("\t");
  }
  Serial.println();
  
  // put a delay so it isn't overwhelming
  delay(200);
}
