int trig = 11;
int echo = 12;
 
void setup() {
 
  Serial.begin(9600);      
  
  //초음파
  pinMode(trig, OUTPUT);  
  pinMode(echo, INPUT);
 
}
  
void loop() {
  float Length, distance;
  digitalWrite(trig, LOW);
  delay(1000);
  digitalWrite(trig, HIGH);
  delay(1000);
  digitalWrite(trig, LOW);
  Length = pulseIn(echo, HIGH);
  distance = ((float)(340 * Length) / 10000) / 2;
  int cnt = 0;
  if(distance<10.0){
    Serial.println(" 착륙 ✅ ");
    delay(8000);
    Serial.println(" 💊 1차 구급상자 전달 ");
    delay(7000);
    Serial.println(" 🚑 2차 구조 지원 바람");
    delay(10000);
    Serial.println(" 🚀 이륙 ");
    delay(10000);
  }
  else if (distance <100.0){
    Serial.println("고도 1m 이하 ⬇ ⬇");
    Serial.println(distance);
    delay(1000);
  }
  else if (distance >100.0){
    Serial.println(" 📌 안전 운항 거리 ");
    Serial.println(distance);
    delay(5000);
  }

}