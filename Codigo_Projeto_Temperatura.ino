#define PIN_VENTILADOR 13
#define PIN_LED 12
#define PIN_SENSOR_TEMP 0
#define PIN_BUZINA 7
#define LIMITE_TEMPERATURA_VENTILADOR 30
#define LIMITE_TEMPERATURA_EMERGENCIA 50

int sensorTemperatura = 0;

void setup()
{
  pinMode(PIN_SENSOR_TEMP, INPUT);
  pinMode(PIN_VENTILADOR, OUTPUT);
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BUZINA, OUTPUT);
}

void loop()
{
  sensorTemperatura = analogRead(PIN_SENSOR_TEMP);
  if (sensorTemperatura > LIMITE_TEMPERATURA_VENTILADOR) {
    digitalWrite(PIN_VENTILADOR, HIGH);
  } else {
    digitalWrite(PIN_VENTILADOR, LOW);
  }
  
  if (sensorTemperatura > LIMITE_TEMPERATURA_EMERGENCIA) {
    digitalWrite(PIN_BUZINA, HIGH);
    digitalWrite(PIN_LED, HIGH);
  } else {
    digitalWrite(PIN_BUZINA, LOW);
    digitalWrite(PIN_LED, LOW);
  }
  
  delay(10); // Delay a little bit to improve simulation performance
}
