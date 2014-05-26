#define LED 13
#define BUTTON 12
#define DEBOUNCE_DELAY 50

int ledState = LOW;
int previousReading = LOW;
long lastDebounce = 0;

void setup() {
    pinMode(LED, OUTPUT);
    pinMode(BUTTON, INPUT);
    digitalWrite(LED, ledState);
}

void loop() {
    int reading = digitalRead(BUTTON);

    if (reading != previousReading && millis() - lastDebounce > DEBOUNCE_DELAY) {
        lastDebounce = millis();

        if (reading == HIGH) {
            ledState = !ledState;
        }
    }

    digitalWrite(LED, ledState);

    previousReading = reading;
}
