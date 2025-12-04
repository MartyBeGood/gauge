#include <Arduino.h>
#include <HX711-multi.h>

// constexpr byte sharedClockPin = D5;
constexpr byte sharedClockPin = 10;
constexpr int scaleCount = 4;
byte dataPins[scaleCount] = {0, 1, 3, 4};
long results[scaleCount];
double weights[scaleCount];
float factors[scaleCount] = {4000.0, 4000.0, 4000.0, 4000.0};

HX711MULTI scales(scaleCount, dataPins, sharedClockPin);

void tare_scales() {
  Serial.print("Taring scales");
  bool success = false;
  auto start = millis();
  while (!success && millis() < (start + 4000)) {
    success = scales.tare(20, 10000);
    Serial.print(".");
  }

  Serial.println(" done.");
}

void setup() {
  Serial.begin(9600);
  Serial.println("HX711 multi demo");
  tare_scales();
  scales.set_scales(factors);
}

void printWeights() {
  for (auto& weight : weights) {
    Serial.printf("%4.1f", weight);
    Serial.print(" g | ");
  }
}

unsigned long start = 0;
unsigned long end = 0;

void loop() {
  start = millis();
  if (Serial.available()) {
    char cmd = Serial.read();
    if (cmd == 't') {
      tare_scales();
    }
  }

  scales.get_units(weights);
  printWeights();

  end = millis();
  Serial.printf(" | Loop took %10u ms\r", (unsigned int)(end - start));
}
