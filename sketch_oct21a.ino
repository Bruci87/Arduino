const byte button = 2;
const byte led = 0;
void setup(){
  pinMode(led, OUTPUT);
    attachInterrupt(0,algoaconteceu, FALLING);
}
void loop(){
  
  
}
void algoaconteceu(){
    digitalWrite(led, HIGH);
  }