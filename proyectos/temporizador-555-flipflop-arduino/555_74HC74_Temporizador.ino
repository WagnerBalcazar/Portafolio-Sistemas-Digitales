// Pines de entrada
const int pinSenal555 = 2;
const int pinSenalFF  = 3;

// =========================
// VARIABLES CANAL 555
// =========================
int estadoActual555 = LOW;
int estadoPrevio555 = LOW;

unsigned long tiempoUltimoFlanco555 = 0;
unsigned long periodo555 = 0;

unsigned long tiempoAlto555 = 0;
unsigned long tiempoBajo555 = 0;
unsigned long tiempoUltimoCambio555 = 0;

// =========================
// VARIABLES CANAL FLIP-FLOP
// =========================
int estadoActualFF = LOW;
int estadoPrevioFF = LOW;

unsigned long tiempoUltimoFlancoFF = 0;
unsigned long periodoFF = 0;

unsigned long tiempoAltoFF = 0;
unsigned long tiempoBajoFF = 0;
unsigned long tiempoUltimoCambioFF = 0;

void setup() {
  Serial.begin(9600);

  pinMode(pinSenal555, INPUT);
  pinMode(pinSenalFF, INPUT);

  tiempoUltimoCambio555 = millis();
  tiempoUltimoCambioFF = millis();
}

void loop() {
  unsigned long tiempoActual = millis();

  // =========================
  // PROCESAMIENTO CANAL 555
  // =========================
  estadoActual555 = digitalRead(pinSenal555);

  // Detectar flanco ascendente
  if (estadoActual555 == HIGH && estadoPrevio555 == LOW) {
    periodo555 = tiempoActual - tiempoUltimoFlanco555;
    tiempoUltimoFlanco555 = tiempoActual;
  }

  // Medir tiempos HIGH y LOW
  if (estadoActual555 != estadoPrevio555) {
    if (estadoActual555 == HIGH) {
      tiempoBajo555 = tiempoActual - tiempoUltimoCambio555;
    } else {
      tiempoAlto555 = tiempoActual - tiempoUltimoCambio555;
    }
    tiempoUltimoCambio555 = tiempoActual;
  }

  estadoPrevio555 = estadoActual555;

  // =========================
  // PROCESAMIENTO CANAL FF
  // =========================
  estadoActualFF = digitalRead(pinSenalFF);

  if (estadoActualFF == HIGH && estadoPrevioFF == LOW) {
    periodoFF = tiempoActual - tiempoUltimoFlancoFF;
    tiempoUltimoFlancoFF = tiempoActual;
  }

  if (estadoActualFF != estadoPrevioFF) {
    if (estadoActualFF == HIGH) {
      tiempoBajoFF = tiempoActual - tiempoUltimoCambioFF;
    } else {
      tiempoAltoFF = tiempoActual - tiempoUltimoCambioFF;
    }
    tiempoUltimoCambioFF = tiempoActual;
  }

  estadoPrevioFF = estadoActualFF;

  // =========================
  // CÁLCULOS
  // =========================
  float frecuencia555 = (periodo555 > 0) ? 1000.0 / periodo555 : 0;
  float duty555 = (tiempoAlto555 + tiempoBajo555 > 0) ?
                  (tiempoAlto555 * 100.0) / (tiempoAlto555 + tiempoBajo555) : 0;

  float frecuenciaFF = (periodoFF > 0) ? 1000.0 / periodoFF : 0;
  float dutyFF = (tiempoAltoFF + tiempoBajoFF > 0) ?
                 (tiempoAltoFF * 100.0) / (tiempoAltoFF + tiempoBajoFF) : 0;

  // =========================
  // SALIDA
  // =========================
  Serial.print("555 -> Freq: ");
  Serial.print(frecuencia555);
  Serial.print(" Hz | Duty: ");
  Serial.print(duty555);
  Serial.print(" % || ");

  Serial.print("FF -> Freq: ");
  Serial.print(frecuenciaFF);
  Serial.print(" Hz | Duty: ");
  Serial.print(dutyFF);
  Serial.println(" %");
}