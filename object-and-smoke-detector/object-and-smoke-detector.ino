#include <LiquidCrystal.h> // includes the LiquidCrystal Library
const int rs = 4, en = 5, d4 = 6, d5 = 7, d6 = 8, d7 = 9;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int trigPin = 11;
const int echoPin = 12;
long duration;
int distanceCm, distanceInch;

int LED = 13; 
int gasSensor; 
int piezo = 10; 

void setup() {
  lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(A0,INPUT); 
  pinMode(LED,OUTPUT); 
  pinMode(piezo,OUTPUT); 
  Serial.begin(9600); 
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceCm= duration*0.034/2;
  distanceInch = duration*0.0133/2;
  lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
  lcd.print("Distance: "); // Prints string "Distance" on the LCD
  Serial.println(distanceCm);
  lcd.print(distanceCm); // Prints the distance value from the sensor
//  lcd.clear();
  lcd.print(" cm  ");
  lcd.setCursor(0,1);
  lcd.print("Distance: ");
  lcd.print(distanceInch);
  lcd.print(" inch");

  gasSensor=analogRead(A0);
  Serial.println(gasSensor);
  if (gasSensor>=500) 
  { 
    digitalWrite(piezo,HIGH); 
  } 
  else 
  { 
    digitalWrite(piezo,LOW); 
  } 

   delay(1000);
}
