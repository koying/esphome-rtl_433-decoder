#include "esphome/core/log.h"

#include "rtl_433.h"

namespace esphome {
namespace rtl_433 {

static const char *const RTAG = "RTL_433";

void RTL433Decoder::setup() {
  rd.setCallback(&RTL433Decoder::process);
  rd.rtlSetup();
  ESP_LOGD(RTAG, "rtl_433 setup done");
}

void RTL433Decoder::recv_raw(esphome::remote_base::RawTimings& rawdata) {
  ESP_LOGD(RTAG, "sending raw receive data to rtl_433 signal decoder");
  rd.processRaw(rawdata, (void *) this);
}

void RTL433Decoder::recv_rfraw(const char *p) {
  ESP_LOGD(RTAG, "sending rfraw receive data to rtl_433 signal decoder");
  rd.processRFRaw(p, (void *) this);
}

void RTL433Decoder::process(char *msg, void *ctx) {
  RTL433Decoder *objinst = (RTL433Decoder *) ctx;
  std::string s=msg; 
  free(msg); 
  ESP_LOGD(RTAG, "Received msg: %s", s.c_str());

  json::parse_json(s, [objinst](JsonObject doc) {
    for (auto *trigger : objinst->triggers_onjsonmsg_) {
      trigger->trigger(doc);
    }
    return true;
  });

}

}
}
