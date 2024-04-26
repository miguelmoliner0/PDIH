int interruptorPin = 7; // Definimos el pin del interruptor al 7

void setup() { 
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(interruptorPin, INPUT); // Configuramos el pin de entrada del interruptor
}

void loop() {
  // Lee el estado del interruptor
  int interruptorEstado = digitalRead(interruptorPin);

  // Si el interruptor está presionado (HIGH)
  if (interruptorEstado == HIGH) {
    digitalWrite(13, HIGH); // Enciende el LED rojo
    digitalWrite(12, LOW); // Apaga el LED amarillo
    digitalWrite(11, LOW); // Apaga el LED verde
    return;
    } 

    digitalWrite(13, LOW);


    // Si el interruptor no está presionado, sigue parpadeando los LEDs como antes
    digitalWrite(11, HIGH);
    delay(1000);
    digitalWrite(11, LOW);
    delay(500);

    digitalWrite(12, HIGH);
    delay(1000);
    digitalWrite(12, LOW);
    delay(500);

    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    delay(500);

}
