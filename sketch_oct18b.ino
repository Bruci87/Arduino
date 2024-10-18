#include <Servo.h>
#define SERVO 6
Servo S;
byte pot=A0;
int valor;
void setup()
{
 
S.attach(SERVO);
  S.write(0);
}

void loop()
{
  valor=analogRead(pot);
  valor=map(valor, 0, 1023, 0, 178);
  S.write(valor);
  delay(15);
   
  delay(1000);
  
}