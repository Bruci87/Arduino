// Definindo os pinos
const int ledPin = 9;        // Pino PWM para o LED
const int potPin = A0;       // Pino para o potenciômetro
const int ldrPin = A1;       // Pino para o LDR
const int buttonPin = 2;     // Pino para o botão

int modo = 0;                // Variável para alternar entre os modos
int buttonState = 0;         // Estado atual do botão
int lastButtonState = 0;     // Último estado do botão

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); // Usando resistor pull-up interno
  Serial.begin(9600);               // Para depuração, se necessário
}

void loop() {
  // Leitura do estado do botão
  buttonState = digitalRead(buttonPin);

  // Verifica se o botão foi pressionado (transição LOW para HIGH)
  if (buttonState == LOW && lastButtonState == HIGH) {
    modo = !modo; // Alterna entre 0 e 1
    delay(200);   // Debouncing para evitar múltiplas leituras
  }

  // Atualiza o último estado do botão
  lastButtonState = buttonState;

  if (modo == 1) {
    // Controle do LED via potenciômetro
    int potValue = analogRead(potPin);     // Lê o valor do potenciômetro
    int brightness = map(potValue, 0, 255, 0, 255);
    analogWrite(ledPin, brightness);
     // Ajusta o brilho do LED
    Serial.println("Controle: Potenciômetro");
  } else {
    // Controle do LED via LDR
    int ldrValue = analogRead(ldrPin);     // Lê o valor do LDR
    int brightness = map(ldrValue, 0, 1023,0, 255); // Converte para 0-255
    analogWrite(ledPin, brightness);       // Ajusta o brilho do LED
    Serial.println("Controle: LDR");
  }

  delay(50); // Pequeno atraso para evitar leituras rápidas demais
}
