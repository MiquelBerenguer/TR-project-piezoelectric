#include <Wire.h> 
#include <LiquidCrystal_I2C.h> 

[cite_start]// Configuració LCD I2C (Adreça 0x3F segons el codi original) [cite: 180, 476]
LiquidCrystal_I2C lcd(0x3F, 16, 2); 

// Pins de control
const int pinBateria = A0;    [cite_start]// Entrada per llegir el voltatge [cite: 181, 477]
const int transistorPin = 2;  [cite_start]// Pin que activa el relé (pila 9V) [cite: 155, 493]

[cite_start]// Pins del Semàfor [cite: 303, 305, 306, 494, 495, 496]
const int ledVermell = 11; 
const int ledGroc = 12;    
const int ledVerd = 13;    

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2); 
  lcd.backlight(); 
  
  pinMode(transistorPin, OUTPUT);
  pinMode(ledVermell, OUTPUT);
  pinMode(ledGroc, OUTPUT);
  pinMode(ledVerd, OUTPUT);
  
  digitalWrite(transistorPin, LOW); [cite_start]// Comença amb bateria pròpia [cite: 161, 503]
}

void loop() {
  [cite_start]// 1. Lectura i càlcul de bateria [cite: 27, 105, 528]
  int medida = analogRead(pinBateria);
  float voltaje = (medida * 4.2) / 860.0; [cite_start]// Basat en la teva regla de tres [cite: 105]
  int porcent = ((voltaje * 100) - 320); [cite_start]// Ajust per a la bateria de liti [cite: 532]
  if (porcent < 0) porcent = 0;

  [cite_start]// 2. Lògica del Relé (Canvi de xarxa al 40%) [cite: 171, 537, 542]
  if (porcent < 40) {
    digitalWrite(transistorPin, HIGH); // Activa pila 9V (Xarxa municipal)
  } else if (porcent > 50) {
    digitalWrite(transistorPin, LOW);  // Torna a bateria piezoelèctrica
  }

  // 3. Cicle del Semàfor (Temps segons memòria del TR)
  // Vermell (10s)
  digitalWrite(ledVermell, HIGH);
  delay(10000); 
  digitalWrite(ledVermell, LOW);
  
  // Àmbar (5s)
  digitalWrite(ledGroc, HIGH);
  delay(5000);
  digitalWrite(ledGroc, LOW);
  
  // Verd (5s)
  digitalWrite(ledVerd, HIGH);
  delay(5000);
  digitalWrite(ledVerd, LOW);
}