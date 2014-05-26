#define LED0 13
#define LED1 12
#define LED2 11
#define BUTTON 10
#define DEBOUNCE_DELAY 50

int ledState = LOW;
int previousReading = LOW;
long lastDebounce = 0;
int counter = 0;

void setup() {
    initializeLed(LED0);
    initializeLed(LED1);
    initializeLed(LED2);
    pinMode(BUTTON, INPUT);
}

void initializeLed(int pin) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
}

void loop() {
    int reading = digitalRead(BUTTON);

    if (reading != previousReading && millis() - lastDebounce > DEBOUNCE_DELAY) {
        lastDebounce = millis();

        if (reading == HIGH) {
            counter++;
            displayCounterValue();
        }
    }

    previousReading = reading;
}

void displayCounterValue() {
    digitalWrite(LED0, bitRead(counter, 0));
    digitalWrite(LED1, bitRead(counter, 1));
    digitalWrite(LED2, bitRead(counter, 2));
}
