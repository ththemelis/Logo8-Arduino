#include <SPI.h>
#include <Ethernet.h>
#include "MgsModbus.h" // Ίσως θα ήταν καλύτερο να χρησιμοποιηθεί η βιβλιοθήκη ArduinoModbus

MgsModbus Mb;

byte mac[] = {0x90, 0xA2, 0xDA, 0x0E, 0x94, 0xB5 }; // Ethernet MAC Address
byte ip[]={192, 168, 1, 150};
byte sub[]={255, 255, 255, 255};

int potPin0 = 0;    // Αναλογική πόρτα 0
int potPin1 = 1;    // Αναλογική πόρτα 1
int potPin2 = 2;    // Αναλογική πόρτα 2
int val0 = 0;       
int val1 = 0;       
int val2 = 0; 
int relay0 = 4;      
int relay1 = 5;
int relay2 = 6;
int relay3 = 7;

void setup(){
  Serial.begin (9600);

  pinMode(relay0, OUTPUT);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);

  digitalWrite(relay0, HIGH);
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  /*if (Ethernet.begin(mac) == 0) {
    Serial.println("Δεν ήταν δυνατή η αρχικοποίηση της σύνδεσης στο διαδίκτυο μέσω DHCP");
    if (Ethernet.hardwareStatus() == EthernetNoHardware) { // Έλεγχος ύπαρξης του Ethernet Shield
      Serial.println("Δεν υπάρχει ή δεν λειτουργεί το Ethernet Shield");
    } // Πρέπει να μπει μια σημαία που να υποδεικνύει ότι δεν υπάρχει το Ethernet Shield
    if (Ethernet.linkStatus() == LinkOFF) {
      Serial.println("Δεν είναι συνδεδεμένο το καλώδιο.");
    } // Πρέπει να μπει μια σημαία που να υποδεικνύει ότι δεν υπάρχει καλώδιο σύνδεσης στο δίκτυο
    Ethernet.begin(mac, ip); // Αρχικοποίηση της σύνδεσης στο διαδίκτυο με στατική ΙΡ
    Serial.println(Ethernet.localIP());
    Mb.remSlaveIP = (192,168,1,201);
  }*/
}

void loop(){
  //Serial.println(Mb.MbData[0]);
  //Mb.MbsRun();
  val0 = analogRead(potPin0);
  val1 = analogRead(potPin1);
  val2 = analogRead(potPin2);    
  Serial.print ("val0=");
  Serial.println (val0);
  Serial.print ("val1=");
  Serial.println (val1);
  Serial.print ("val2=");
  Serial.println (val2); 

  if (val0 >= 500){
    digitalWrite(relay1, LOW);
  }
  else {
    digitalWrite(relay1, HIGH);
  }
     
  delay (500);
}
