#pragma once
#include <memory>
#include "HX711-multi.h"

#include "IMultiLoadCell.h"

class Hx711MultiAdapter : public IMultiLoadCell {
 public:
  Hx711MultiAdapter(std::unique_ptr<HX711MULTI> hx711Multi);
  bool isReady() override;
  void rawValues(long* result) override;
  byte channelCount() override;

 private:
  std::unique_ptr<HX711MULTI> multi;
};