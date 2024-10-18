const byte led = 2;
const byte  ldr = A5;
int estado = 0;
void setup(){
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}
void loop(){
  estado = analogRead(ldr);
  Serial.println(estado);
  if(estado > 800){
    digitalWrite(led, HIGH);
  }else{
    digitalWrite(led, LOW);
  }
}