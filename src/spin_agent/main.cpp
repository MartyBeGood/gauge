#include <HX711-multi.h>

#include "Hx711MultiAdapter.h"
#include "QuadCellScale.h"

// constexpr byte sharedClockPin = D5;
constexpr byte sharedClockPin = 10;
constexpr int scaleCount = 4;
byte dataPins[scaleCount] = {0, 1, 3, 4};
long results[scaleCount];
double weights[scaleCount];
float factors[scaleCount] = {4000.0, 4000.0, 4000.0, 4000.0};

auto multi = std::make_unique<HX711MULTI>(scaleCount, dataPins, sharedClockPin);
auto adapter = std::make_unique<Hx711MultiAdapter>(std::move(multi));
QuadCellScale scales(std::move(adapter));

void tareScales() {
  Serial.print("Taring scales");
  scales.tare();
  Serial.println(" done.");
}

void setup() {
  Serial.begin(9600);
  Serial.println("HX711 multi demo");
  tareScales();
  for (int i = 0; i < scaleCount; i++) {
    scales.setCalibrationFactor(i, 6000.0);
  }
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
      tareScales();
    }
  }

  // scales.getUnits(weights);
  // printWeights();

  end = millis();
  Serial.printf(" | Loop took %10u ms\r", (unsigned int)(end - start));
}
