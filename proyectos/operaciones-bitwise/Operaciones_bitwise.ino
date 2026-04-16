
const int LED_PIN = 13;

byte estadoLed = 0;
int contador = 0;


void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);

  mostrarOperacionesBitwise();
}

void loop() {
  alternarLed();
  mostrarShift();

  delay(500); // control de tiempo
}


void mostrarOperacionesBitwise() {
  Serial.println("=== Operaciones Bitwise ===");

  byte a = 5;  // 00000101
  byte b = 3;  // 00000011

  Serial.print("AND: ");
  Serial.println(a & b, BIN);

  Serial.print("OR: ");
  Serial.println(a | b, BIN);

  Serial.print("XOR: ");
  Serial.println(a ^ b, BIN);

  Serial.print("NOT a: ");
  Serial.println(~a, BIN);

  Serial.print("Shift left a: ");
  Serial.println(a << 1, BIN);

  Serial.print("Shift right a: ");
  Serial.println(a >> 1, BIN);

  // Encender bit 0 inicialmente
  estadoLed = (1 << 0);
}

void alternarLed() {
  estadoLed ^= (1 << 0);

  if (estadoLed & (1 << 0)) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}

// Muestra desplazamientos dinámicos
void mostrarShift() {
  contador = (contador + 1) % 8;

  Serial.print("Shift: ");
  Serial.println(1 << contador, BIN);
}