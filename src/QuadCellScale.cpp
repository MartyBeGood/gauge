#include "QuadCellScale.h"
#include <numeric>  // Required for std::accumulate

QuadCellScale::QuadCellScale(std::unique_ptr<IMultiLoadCell> cells) : loadCellMulti(std::move(cells)) {}

void QuadCellScale::tare(byte times) {
  long currentValues[NUM_CELLS] = {0};
  readAverage(times, currentValues);
  for (size_t i = 0; i < NUM_CELLS; i++) {
    setTareOffset(i, currentValues[i]);
  }
}

void QuadCellScale::setTareOffset(byte cellIndex, long offset) {
  tareOffsets[cellIndex] = offset;
}

void QuadCellScale::getRawValues(long* result) {
  loadCellMulti->rawValues(result);
}

void QuadCellScale::setCalibrationFactor(size_t cellIndex, float factor) {
  calibrationFactors[cellIndex] = factor;
}

float QuadCellScale::getUnits(byte times) {
  long averageValues[NUM_CELLS] = {0};
  readAverage(times, averageValues);

  float totalUnits = 0.0f;
  for (size_t i = 0; i < NUM_CELLS; ++i) {
    float netValue = static_cast<float>(averageValues[i] - tareOffsets[i]);
    float units = netValue / calibrationFactors[i];
    totalUnits += units;
  }
  return totalUnits;
}

void QuadCellScale::readAverage(byte times, long* result) {
  long rawValues[NUM_CELLS] = {0};
  std::array<long, NUM_CELLS> sumValues = {0, 0, 0, 0};

  for (byte i = 0; i < times; i++) {
    loadCellMulti->rawValues(rawValues);
    for (size_t j = 0; j < NUM_CELLS; j++) {
      sumValues[j] += rawValues[j];
    }
  }

  for (size_t j = 0; j < NUM_CELLS; j++) {
    result[j] = sumValues[j] / times;
  }
}
