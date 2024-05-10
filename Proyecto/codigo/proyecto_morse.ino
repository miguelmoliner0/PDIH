#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7); // inicializamo el LCD

#define buzzerPin 8 
#define ledPin 9    

void setup() {
  Serial.begin(9600); 
  lcd.begin(16, 2);   
  
  pinMode(buzzerPin, OUTPUT); 
  pinMode(ledPin, OUTPUT);    
}

void punto() {
  tone(8, 1047, 300); // activamos el buffer 300 ms a un tono de 1047Hz
  digitalWrite(ledPin, HIGH);    // Enciendemos el LED
  delay(300);                     // Duración del punto en Morse
  digitalWrite(buzzerPin, LOW);  // Apagamos el buzzer
  digitalWrite(ledPin, LOW);     // Apagamos el LED
  delay(300);                     
}

void linea() {
  tone(8, 1047, 800); // activamos el buzzer ahora durante 800ms
  digitalWrite(ledPin, HIGH);    // Enciendemos el LED
  delay(800);                     // Duración de la raya en Morse
  digitalWrite(buzzerPin, LOW);  // Apagamos el buzzer
  digitalWrite(ledPin, LOW);     // Apagamos el LED
  delay(300);                     
}

void loop() {
  char mensaje[100]; 
  int i = 0;
  
  lcd.clear(); 
  lcd.setCursor(0, 0); // nos situamos en la primera fila de la pantalla LCD
  
  lcd.print("Introduce texto: ");
  while (Serial.available() == 0) {
    
  }
  
  while (Serial.available() > 0) {
    mensaje[i++] = Serial.read(); // leemos el mensaje introducido por terminal
    lcd.write(mensaje[i - 1]); // mostramos el texto en la LCD
    delay(100); 
  }
  
  mensaje[i] = '\0'; // añadimos el caracter nulo al final de nuestro mensaje
  
  // codificación en codigo morse de nuestro mensaje
  lcd.setCursor(0, 1); // nos situamos en la segunda fila de la pantalla LCD
  lcd.print("Morse: ");
  for (int j = 0; mensaje[j] != '\0'; j++) {
    switch (mensaje[j]) {
      case 'a':
      case 'A':
        lcd.print(".- ");
        punto();
        linea();
        delay(750);
        break;
      case 'b':
      case 'B':
        lcd.print("-... ");
        linea();
        punto();
        punto();
        punto();
        delay(750);
        break;
      case 'c':
      case 'C':
        lcd.print("-.-. ");
        linea();
        punto();
        linea();
        punto();
        delay(750);
        break;
      case 'd':
      case 'D':
        lcd.print("-.. ");
        linea();
        punto();
        punto();
        delay(750);
        break;
      case 'e':
      case 'E':
        lcd.print(". ");
        punto();
        delay(750);
        break;
      case 'f':
      case 'F':
        lcd.print("..-. ");
        punto();
        punto();
        linea();
        punto();
        delay(750);
        break;
      case 'g':
      case 'G':
        lcd.print("--. ");
        linea();
        linea();
        punto();
        delay(750);
        break;
      case 'h':
      case 'H':
        lcd.print(".... ");
        punto();
        punto();
        punto();
        punto();
        delay(750);
        break;
      case 'i':
      case 'I':
        lcd.print(".. ");
        punto();
        punto();
        delay(750);
        break;
      case 'j':
      case 'J':
        lcd.print(".--- ");
        punto();
        linea();
        linea();
        linea();
        delay(750);
        break;
      case 'k':
      case 'K':
        lcd.print("-.- ");
        linea();
        punto();
        linea();
        delay(750);
        break;
      case 'l':
      case 'L':
        lcd.print(".-.. ");
        punto();
        linea();
        punto();
        punto();
        delay(750);
        break;
      case 'm':
      case 'M':
        lcd.print("-- ");
        linea();
        linea();
        delay(750);
        break;
      case 'n':
      case 'N':
        lcd.print("-. ");
        linea();
        punto();
        delay(750);
        break;
      case 'o':
      case 'O':
        lcd.print("--- ");
        linea();
        linea();
        linea();
        delay(750);
        break;
      case 'p':
      case 'P':
        lcd.print(".--. ");
        punto();
        linea();
        linea();
        punto();
        delay(750);
        break;
      case 'q':
      case 'Q':
        lcd.print("--.- ");
        linea();
        linea();
        punto();
        linea();
        delay(750);
        break;
      case 'r':
      case 'R':
        lcd.print(".-. ");
        punto();
        linea();
        punto();
        delay(750);
        break;
      case 's':
      case 'S':
        lcd.print("... ");
        punto();
        punto();
        punto();
        delay(750);
        break;
      case 't':
      case 'T':
        lcd.print("- ");
        linea();
        delay(750);
        break;
      case 'u':
      case 'U':
        lcd.print("..- ");
        punto();
        punto();
        linea();
        delay(750);
        break;
      case 'v':
      case 'V':
        lcd.print("...- ");
        punto();
        punto();
        punto();
        linea();
        delay(750);
        break;
      case 'w':
      case 'W':
        lcd.print(".-- ");
        punto();
        linea();
        linea();
        delay(750);
        break;
      case 'x':
      case 'X':
        lcd.print("-..- ");
        linea();
        punto();
        punto();
        linea();
        delay(750);
        break;
      case 'y':
      case 'Y':
        lcd.print("-.-- ");
        linea();
        punto();
        linea();
        linea();
        delay(750);
        break;
      case 'z':
      case 'Z':
        lcd.print("--.. ");
        linea();
        linea();
        punto();
        punto();
        delay(750);
        break;
      case '1':
        lcd.print(".----");
        punto();
        linea();
        linea();
        linea();
        linea();
        delay(750);
        break;
      case '2':
        lcd.print("..---");
        punto();
        punto();
        linea();
        linea();
        linea();
        delay(750);
        break;
      case '3':
        lcd.print("...--");
        punto();
        punto();
        punto();
        linea();
        linea();
        delay(750);
        break;
      case '4':
        lcd.print("....-");
        punto();
        punto();
        punto();
        punto();
        linea();
        delay(750);
        break;
      case '5':
        lcd.print(".....");
        punto();
        punto();
        punto();
        punto();
        punto();
        delay(750);
        break;
      case '6':
        lcd.print("-....");
        linea();
        punto();
        punto();
        punto();
        punto();
        delay(750);
        break;
      case '7':
        lcd.print("--...");
        linea();
        linea();
        punto();
        punto();
        punto();
        delay(750);
        break;
      case '8':
        lcd.print("---..");
        linea();
        linea();
        linea();
        punto();
        punto();
        delay(750);
        break;
      case '9':
        lcd.print("----.");
        linea();
        linea();
        linea();
        linea();
        punto();
        delay(750);
        break;
      case '0':
        lcd.print("-----");
        linea();
        linea();
        linea();
        linea();
        linea();
        delay(750);
        break;
      
      case ' ':
        lcd.print("  "); // espacio enrtre palabras
        break;
      default:
        lcd.print("? "); // para un caracter desconocido
    }
  }
}