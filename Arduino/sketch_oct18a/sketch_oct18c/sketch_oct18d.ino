// Definição dos pinos dos LEDs
const int ledCarGreen = 2;
const int ledCarYellow = 3;
const int ledCarRed = 4;

const int ledPedGreen = 5;
const int ledPedRed = 6;

// Definição do pino do botão
const int buttonPin = 7;

// Variáveis de controle
int buttonState = 0; // Estado do botão

void setup() {
  // Configura os pinos dos LEDs como saída
  pinMode(ledCarGreen, OUTPUT);
  pinMode(ledCarYellow, OUTPUT);
  pinMode(ledCarRed, OUTPUT);
  pinMode(ledPedGreen, OUTPUT);
  pinMode(ledPedRed, OUTPUT);
  
  // Configura o pino do botão como entrada
  pinMode(buttonPin, INPUT);
  
  // Inicialmente, os carros estão com o verde aceso e os pedestres com o vermelho
  digitalWrite(ledCarGreen, HIGH);
  digitalWrite(ledCarRed, LOW);
  digitalWrite(ledPedGreen, LOW);
  digitalWrite(ledPedRed, HIGH);
}

void loop() {
  // Lê o estado do botão
  buttonState = digitalRead(buttonPin);
  
  // Verifica se o botão foi pressionado
  if (buttonState == HIGH) {
    // Desliga o verde dos carros, liga o amarelo
    digitalWrite(ledCarGreen, LOW);
    digitalWrite(ledCarYellow, HIGH);
    delay(3000); // Espera 3 segundos
    
    // Desliga o amarelo e liga o vermelho dos carros
    digitalWrite(ledCarYellow, LOW);
    digitalWrite(ledCarRed, HIGH);
    
    // Liga o verde dos pedestres
    digitalWrite(ledPedRed, LOW);
    digitalWrite(ledPedGreen, HIGH);
    delay(10000); // Espera 10 segundos para travessia
    
    // Pisca o LED verde dos pedestres 10 vezes
    for (int i = 0; i < 10; i++) {
      digitalWrite(ledPedGreen, LOW);
      delay(500);
      digitalWrite(ledPedGreen, HIGH);
      delay(500);
    }
    
    // Desliga o verde dos pedestres e liga o vermelho
    digitalWrite(ledPedGreen, LOW);
    digitalWrite(ledPedRed, HIGH);
    
    // Desliga o vermelho dos carros e liga o verde
    digitalWrite(ledCarRed, LOW);
    digitalWrite(ledCarGreen, HIGH);
  }
}
