// GPIO pins for ESP32
const int fsrPin1 = 34; // ADC1 channel
const int fsrPin2 = 35; // ADC1 channel
const int TriggerPin1 = 25;
const int TriggerPin2 = 26;

// Constants
const unsigned long monitorDuration = 10000; 
const float thresholdPressure = 4400.0;       
const float area_m2 = 0.045 * 0.045;   
// Variables      
unsigned long startTime;
float averagePressure1 = 0;
float averagePressure2 = 0;
float currentPressure1 = 0;
float currentPressure2 = 0;
int samples = 0;

void setup() {
  Serial.begin(9600);
  pinMode(TriggerPin1, OUTPUT);
  pinMode(TriggerPin2, OUTPUT);
  digitalWrite(TriggerPin1, LOW);
  digitalWrite(TriggerPin2, LOW);

  startTime = millis();
}

void loop() {
  if (millis() - startTime <= monitorDuration) {
    int fsrValue1 = analogRead(fsrPin1);
    float force1 = (fsrValue1) * 0.025; 
    if (force1 < 0) force1 = 0;
    currentPressure1 = force1 / area_m2;

    int fsrValue2 = analogRead(fsrPin2);
    float force2 = (fsrValue2) * 0.025;
    if (force2 < 0) force2 = 0;
    currentPressure2 = force2 / area_m2;

    averagePressure1 += currentPressure1;
    averagePressure2 += currentPressure2;
    samples++;

    Serial.print("FSR1: ");
    Serial.print(fsrValue1);
    Serial.print(" | P1: ");
    Serial.print(currentPressure1);
    Serial.print(" Pa | FSR2: ");
    Serial.print(fsrValue2);
    Serial.print(" | P2: ");
    Serial.print(currentPressure2);
    Serial.println(" Pa");

    delay(1000);
  } else {
    // Calculate averages
    float avgP1 = (samples > 0) ? averagePressure1 / samples : 0;
    float avgP2 = (samples > 0) ? averagePressure2 / samples : 0;

    // Activate Vibration Motors if needed
    if (avgP1 > thresholdPressure) {
      digitalWrite(TriggerPin1, HIGH);
      delay(5000);
      digitalWrite(TriggerPin1, LOW);
    } else {
      digitalWrite(TriggerPin1, LOW);
    }

    if (avgP2 > thresholdPressure) {
      digitalWrite(TriggerPin2, HIGH);
      delay(5000);
      digitalWrite(TriggerPin2, LOW);
    } else {
      digitalWrite(TriggerPin2, LOW);
    }

    // Serial Output
    Serial.println(" ------ ");
    Serial.print("Avg P1: ");
    Serial.print(avgP1);
    Serial.print(" | Avg P2: ");
    Serial.println(avgP2);

    // Reset for next monitoring cycle
    startTime = millis();
    averagePressure1 = 0;
    averagePressure2 = 0;
    samples = 0;
  }
}

