#define CHARGE_PIN 13
#define DISCHARGE_PIN 12
#define CHARGE_INDICATOR 11
#define VOLTAGE_PIN A0
#define R 10000.0F

void setup() {
    pinMode(CHARGE_PIN, OUTPUT);
    digitalWrite(CHARGE_PIN, LOW);
    pinMode(CHARGE_INDICATOR, OUTPUT);
    digitalWrite(CHARGE_INDICATOR, LOW);
    Serial.begin(9600);
}

void loop() {
    // start charging
    digitalWrite(CHARGE_PIN, HIGH);
    digitalWrite(CHARGE_INDICATOR, HIGH);
    long startTime = millis();

    // wait until the capacitor charges to 63.2% of the maximum voltage
    while (analogRead(VOLTAGE_PIN) < 648) {
        // just wait
    }
    digitalWrite(CHARGE_INDICATOR, LOW);

    long elapsedTime = millis() - startTime;
    
    // ms -> s *10^-3, F -> uF *10^6 => *10^3
    float uF = (float(elapsedTime) / R) * 1000;

    if (uF > 1) {
        Serial.print(uF);
        Serial.println(" uF");
    } else {
        // convert to nF
        float nF = uF * 1000;
        Serial.print(nF);
        Serial.println(" nF");
    }

    // start discharging
    digitalWrite(CHARGE_PIN, LOW);
    pinMode(DISCHARGE_PIN, OUTPUT);
    digitalWrite(DISCHARGE_PIN, LOW);

    // wait until discharged
    while (analogRead(VOLTAGE_PIN) > 0) {
        // just wait
    }

    pinMode(DISCHARGE_PIN, INPUT);

    delay(500);
}