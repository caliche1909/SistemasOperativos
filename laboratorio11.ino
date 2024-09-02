const int RED_LED = 12;
const int GREEN_LED = 11;
const int ORANGE_LED = 10;

bool isRedBlinking = false;
bool isGreenBlinking = false;
bool isOrangeBlinking = false;

void setup()
{
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(ORANGE_LED, OUTPUT);
  Serial.begin(9600); // Inicia la comunicación serial
}

void loop()
{
  if (Serial.available() > 0) { // Verifica si hay datos disponibles en la comunicación serial
    char input = Serial.read(); // Lee el dato recibido
    
    // Control del LED rojo
    if (input == '1') {
      isRedBlinking = true; // Comienza a parpadear el rojo
    } else if (input == '2') {
      isRedBlinking = false; // Deja de parpadear el rojo y lo apaga
      digitalWrite(RED_LED, LOW);
    }
    
    // Control del LED verde
    if (input == '3') {
      isGreenBlinking = true; // Comienza a parpadear el verde
    } else if (input == '4') {
      isGreenBlinking = false; // Deja de parpadear el verde y lo apaga
      digitalWrite(GREEN_LED, LOW);
    }
    
    // Control del LED naranja
    if (input == '5') {
      isOrangeBlinking = true; // Comienza a parpadear el naranja
    } else if (input == '6') {
      isOrangeBlinking = false; // Deja de parpadear el naranja y lo apaga
      digitalWrite(ORANGE_LED, LOW);
    }

    // Enciende todas las luces
    if (input == '7') {
      isRedBlinking = false;
      isGreenBlinking = false;
      isOrangeBlinking = false;
      digitalWrite(RED_LED, HIGH);
      digitalWrite(GREEN_LED, HIGH);
      digitalWrite(ORANGE_LED, HIGH);
    }

    // Apaga todas las luces
    if (input == '8') {
      isRedBlinking = false;
      isGreenBlinking = false;
      isOrangeBlinking = false;
      digitalWrite(RED_LED, LOW);
      digitalWrite(GREEN_LED, LOW);
      digitalWrite(ORANGE_LED, LOW);
    }
  }

  // Parpadeo del LED rojo
  if (isRedBlinking) {
    digitalWrite(RED_LED, HIGH);
    delay(1000);
    digitalWrite(RED_LED, LOW);
    delay(1000);
  }
  
  // Parpadeo del LED verde
  if (isGreenBlinking) {
    digitalWrite(GREEN_LED, HIGH);
    delay(1000);
    digitalWrite(GREEN_LED, LOW);
    delay(1000);
  }
  
  // Parpadeo del LED naranja
  if (isOrangeBlinking) {
    digitalWrite(ORANGE_LED, HIGH);
    delay(1000);
    digitalWrite(ORANGE_LED, LOW);
    delay(1000);
  }
}

