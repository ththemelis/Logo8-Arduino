#include <SPI.h>
#include <Ethernet.h>
#include "MgsModbus.h"

MgsModbus Mb;

byte mac[] = {0x90, 0xA2, 0xDA, 0x0E, 0x94, 0xB5 }; // Ethernet MAC Address
byte ip[] = {192, 168, 1, 150};
byte sub[] = {255, 255, 255, 255};

int potPin0 = 0;    // Αναλογική πόρτα 0
int potPin1 = 1;    // Αναλογική πόρτα 1
int potPin2 = 2;    // Αναλογική πόρτα 1

int relay0 = 4;
int relay1 = 5;
int relay2 = 6;
int relay3 = 7;
int relay4 = 8;
int relay5 = 9;

void setup(){
  Serial.begin (9600);

  pinMode(potPin0, INPUT);
  pinMode(potPin1, INPUT);
  pinMode(potPin2, INPUT);
  pinMode(relay0, OUTPUT);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  pinMode(relay5, OUTPUT);
  Mb.remSlaveIP = (192,168,1,201);
  Ethernet.begin(mac, ip, sub);
}

void loop(){
  Serial.print ("ModBus[0]: ");
  Serial.println(Mb.MbData[0]); // Ανάγνωση από τον δίαυλο ModBus. Τα δεδομένα έρχονται σε δυαδική μορφή
  Serial.print ("Bit[0]: ");
  Serial.println(bitRead(Mb.MbData[0],0));
  Serial.print ("Bit[2]: ");
  Serial.println(bitRead(Mb.MbData[0],3));  

  if (bitRead(Mb.MbData[0],0) == 1){
    digitalWrite(relay0, LOW);
  }
  else {
    digitalWrite(relay0, HIGH);
  }

  if (bitRead(Mb.MbData[0],1) == 1){
    digitalWrite(relay1, LOW);
  }
  else {
    digitalWrite(relay1, HIGH);
  }

  if (bitRead(Mb.MbData[0],2) == 1){
    digitalWrite(relay2, LOW);
  }
  else {
    digitalWrite(relay2, HIGH);
  }

  if (bitRead(Mb.MbData[0],3) == 1){
    digitalWrite(relay3, LOW);
  }
  else {
    digitalWrite(relay3, HIGH);
  }      

  if (bitRead(Mb.MbData[0],4) == 1){
    digitalWrite(relay4, LOW);
  }
  else {
    digitalWrite(relay4, HIGH);
  }

  if (bitRead(Mb.MbData[0],5) == 1){
    digitalWrite(relay5, LOW);
  }
  else {
    digitalWrite(relay5, HIGH);
  }

  Mb.MbData[4] = analogRead (potPin0); // Εγγραφή στην θέση 5 του ModBus Address
  Mb.MbData[5] = analogRead (potPin1); // Εγγραφή στην θέση 6 του ModBus Address
  Mb.MbData[6] = analogRead (potPin2); // Εγγραφή στην θέση 7 του ModBus Address
  
  Mb.MbsRun(); // Λειτουργία του Arduino σε Slave mode
  delay (100);
}
