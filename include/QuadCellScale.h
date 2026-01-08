#pragma once
#include <array>
#include <memory>
#include "IMultiLoadCell.h"

class QuadCellScale {
 public:
  static constexpr size_t NUM_CELLS = 4;
  QuadCellScale(std::unique_ptr<IMultiLoadCell> loadCellMulti);

  void tare(byte times = 10);
  void setCalibrationFactor(size_t cellIndex, float factor);
  void setTareOffset(byte cellIndex, long offset);
  void getRawValues(long* result);
  float getUnits(byte times = 1);

 private:
  void readAverage(byte times, long* result);
  std::unique_ptr<IMultiLoadCell> loadCellMulti;
  std::array<long, NUM_CELLS> tareOffsets = {0, 0, 0, 0};
  std::array<float, NUM_CELLS> calibrationFactors = {1.0, 1.0, 1.0, 1.0};  // This many raw reading values per unit
};
