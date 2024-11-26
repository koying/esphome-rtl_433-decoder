#pragma once

#include "esphome/core/component.h"
#include "esphome/core/automation.h"
#include "esphome/components/json/json_util.h"

#include <signalDecoder.h>

namespace esphome {
namespace rtl_433 {

class RTL433Trigger : public Trigger<JsonObjectConst> {};

class RTL433Decoder : public Component {
 public:
  RTL433Decoder() {}

  void setup() override;
  void loop() override {}
  void dump_config() override {}
  void stop() {}
  void status() {}
  void recv_raw(std::vector<int> &rawdata);
  void register_onjsonmessage_trigger(RTL433Trigger  *trig) { this->triggers_onjsonmsg_.push_back(trig); }
  rtl_433_Decoder rd;

 protected:
  std::vector<RTL433Trigger *> triggers_onjsonmsg_;

 private:
  static void process(char *msg, void *ctx);
};

}  // namespace rtl_433
}  // namespace esphome
