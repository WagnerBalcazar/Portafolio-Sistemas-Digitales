
const int LED_PINS[] = {2, 3, 4, 5, 6, 7};
const int NUM_LEDS = 6;

const int BOTON_PIN = 8;

int patronActual = 0;
bool estadoBotonAnterior = HIGH;

// Control de tiempo
unsigned long tiempoAnterior = 0;
const int intervalo = 120;

// Variables de estado
int indice = 0;
int direccion = 1;


void setup() {

  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(LED_PINS[i], OUTPUT);
    digitalWrite(LED_PINS[i], LOW);
  }

  pinMode(BOTON_PIN, INPUT_PULLUP);

  randomSeed(analogRead(0));
}

void loop() {

  leerBoton();

  unsigned long tiempoActual = millis();

  if (tiempoActual - tiempoAnterior >= intervalo) {
    tiempoAnterior = tiempoActual;

    switch (patronActual) {
      case 0:
        patronSecuencia();
        break;

      case 1:
        patronPersecucion();
        break;

      case 2:
        patronParpadeo();
        break;

      case 3:
        patronAleatorio();
        break;

      case 4:
        patronOnda();
        break;
    }
  }
}

void leerBoton() {

  bool estadoBoton = digitalRead(BOTON_PIN);

  if (estadoBoton == LOW && estadoBotonAnterior == HIGH) {
    patronActual++;

    if (patronActual > 4) {
      patronActual = 0;
    }

    indice = 0;
    direccion = 1;
  }

  estadoBotonAnterior = estadoBoton;
}

// ================== PATRONES ==================

// 1. Secuencia
void patronSecuencia() {

  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(LED_PINS[i], LOW);
  }

  digitalWrite(LED_PINS[indice], HIGH);

  indice++;
  if (indice >= NUM_LEDS) {
    indice = 0;
  }
}

// 2. Persecución
void patronPersecucion() {

  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(LED_PINS[i], LOW);
  }

  digitalWrite(LED_PINS[indice], HIGH);

  indice += direccion;

  if (indice == NUM_LEDS - 1 || indice == 0) {
    direccion *= -1;
  }
}

// 3. Parpadeo
void patronParpadeo() {

  static bool estado = false;
  estado = !estado;

  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(LED_PINS[i], estado);
  }
}

// 4. Aleatorio
void patronAleatorio() {

  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(LED_PINS[i], LOW);
  }

  int led = random(NUM_LEDS);
  digitalWrite(LED_PINS[led], HIGH);
}

// 5. Onda
void patronOnda() {

  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(LED_PINS[i], LOW);
  }

  digitalWrite(LED_PINS[indice], HIGH);

  indice++;
  if (indice >= NUM_LEDS) {
    indice = 0;
  }
}
