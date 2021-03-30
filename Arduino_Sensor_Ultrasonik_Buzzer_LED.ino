/****************************************
  Aldan Rizki Santosa
  https://github.com/inialdan

  Pengukur jarak dengan sensor Ultrasonik
  Jika Jarak <= 10cm maka Buzzer dan LED Red akan aktif
  HC-SR04   |   Arduino UNO
  ---------------------------
  VCC       |   5V
  GND       |   GND
  TRIGGER   |   2
  ECHO      |   3
*****************************************/
const int pinBuzzer = 9;
int trigPIN = 2;
int echoPIN = 3;
long echoTime; 
float distance;

const int pinLED = 10;
 
void setup() {
  pinMode(pinLED, OUTPUT);
  pinMode(pinBuzzer, OUTPUT);
  Serial.begin(9600);
  pinMode(trigPIN, OUTPUT); 
  pinMode(echoPIN, INPUT);
  digitalWrite(trigPIN, LOW);  
}
 
void loop() {
  digitalWrite(trigPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPIN, LOW);
  
  echoTime = pulseIn(echoPIN, HIGH);
  distance = 0.0001 * ((float) echoTime * 340.0) / 2.0;
  
  Serial.print("Jarak : ");
  Serial.print(distance);
  Serial.println(" cm");
  
  if(distance <= 10){
    digitalWrite(pinBuzzer, HIGH);
    digitalWrite(pinLED,HIGH);
  }else{
    digitalWrite(pinBuzzer, LOW);
    digitalWrite(pinLED, LOW);
  }
  
  delay(100);
}
