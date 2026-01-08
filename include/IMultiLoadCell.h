#pragma once
#include "ArduinoOrTypes.h"

class IMultiLoadCell {
 public:
  virtual bool isReady() = 0;
  virtual void rawValues(long* result) = 0;
  virtual byte channelCount() = 0;
  virtual ~IMultiLoadCell() = default;
};
