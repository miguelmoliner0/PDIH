//configuramos las variables de los pins utilizados para los LEDS y el numero de pins
const int ledPins[] = {13, 12, 11, 10};
const int numLeds = 4;

void setup() {
  // configuramos los pines de los LEDS 
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // bucle para encender los LEDS de manera ascendente
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(100);
    digitalWrite(ledPins[i], LOW);
  }
  
  // bucle para apagar los LEDS de manera descendente
  for (int i = numLeds - 1; i >= 0; i--) {
    digitalWrite(ledPins[i], HIGH);
    delay(100); 
    digitalWrite(ledPins[i], LOW);
  }
}
