#include <SoftwareSerial.h>
#include <Servo.h>

Servo servomotor;
 

SoftwareSerial BTSerial(8,7);

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600); 
  Serial.println("Servor Mortor");
  servomotor.attach(9);
  
}

void loop() {
//char car = Serial.read(); 
char car = BTSerial.read();

if(car == 'F'){
Serial.println(" 📦 구급상자 하강");
forward();
}
else if(car == 'B'){
Serial.println("🔋 이륙");
Back();
}
else if(car == 'S'){
Serial.println("🚫 정지");
STOP();
}
}
void forward(){
  servomotor.write(120);
  delay(1000);
  Serial.print("speed : ");
  Serial.println("MAXL");
}

void Back(){
  servomotor.write(0);
  delay(1000);    
  Serial.print("speed : ");
  Serial.println("MAXR");
  
}

void STOP(){
  servomotor.write(92);
  delay(1000);
  Serial.print("speed : ");
  Serial.println("STOP");
}