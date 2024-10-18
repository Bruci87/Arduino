
const byte led = 4;
const byte button = 2;
const byte button2 = 3;
bool button_status ;
bool status;
void setup()
{
  pinMode(led, OUTPUT);
  pinMode (button, INPUT);
  pinMode (button2, INPUT);
}

void loop()
{
  button_status = digitalRead(button);
  status = digitalRead(button2);
  if(button_status){
    digitalWrite(led, HIGH);
    
  }else{
    if(status){ 
      digitalWrite(led, LOW);
    }
   
  }
}