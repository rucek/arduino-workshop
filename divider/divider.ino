#define LED 13
#define LIGHT A0

void setup() {
    pinMode(LED, OUTPUT);
    digitalWrite(LED, LOW);
    pinMode(LIGHT, INPUT);
    Serial.begin(9600);
}

void loop() {
    float reading = 100000 / analogRead(LIGHT);
    Serial.println(reading);
    blink(reading);
}

void blink(float period) {
    digitalWrite(LED, HIGH);
    delay(period);
    digitalWrite(LED, LOW);
    delay(period);
}
