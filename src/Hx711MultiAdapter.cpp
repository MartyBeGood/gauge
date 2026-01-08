#include "Hx711MultiAdapter.h"

Hx711MultiAdapter::Hx711MultiAdapter(std::unique_ptr<HX711MULTI> hx711Multi) : multi(std::move(hx711Multi)) {}

bool Hx711MultiAdapter::isReady() {
  return multi->is_ready();
}

void Hx711MultiAdapter::rawValues(long* result) {
  multi->readRaw(result);
}

byte Hx711MultiAdapter::channelCount() {
  return multi->get_count();
}
