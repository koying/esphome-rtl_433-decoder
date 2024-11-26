# RTL_433 Decoder Component for ESPHome
This ESPHome external component provides [rtl_433](https://github.com/merbanan/rtl_433) decoders for ESPHome [remote_receivers](https://esphome.io/components/remote_receiver.html).

## Examples
Two examples are provided:
1.  [esp32-rtl_433-decoder-mqtt.yaml](https://github.com/juanboro/esphome-rtl_433-decoder/blob/main/esp32-rtl_433-decoder-mqtt.yaml) - MQTT relay - generates rtl_433 style MQTT messages from decoded receiver data.
1.  [esp32-rtl_433-decoder.yaml](https://github.com/juanboro/esphome-rtl_433-decoder/blob/main/esp32-rtl_433-decoder.yaml) - Example of decoding JSON messages directly with ESPHome into sensors.

The example configurations points to a configuration with a ESP32 dev board connected to a TI-CC1101 board (both from AliExpress ~ $5 total).  However, any working way of receiving OOK on/off pulses or FSK mark/space data should be able to work.
