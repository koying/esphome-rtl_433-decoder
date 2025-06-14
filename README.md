# RTL_433 Decoder Component for ESPHome
This ESPHome external component provides [rtl_433](https://github.com/merbanan/rtl_433) decoders for ESPHome [remote_receivers](https://esphome.io/components/remote_receiver.html).

## Basic how-to:
1.  Include what is needed for this external component via [packages](https://esphome.io/components/packages.html) directive in your esphome yaml config:
    ```yaml
    packages: 
        rtl_433: github://juanboro/esphome-rtl_433-decoder/rtl_433.yaml
    ```
2.  Add the rtl_433 config to your yaml with a remote_reciver id and an on_json_message handler...
    ```yaml
    rtl_433:
        id: my_rtl433_id
        receiver_id: rf_receiver
        on_json_message: 
            then:
                ....
    ```
    You can find example ESPHome json message trigger handling examples in the ESPhome MQTT [documentation](https://esphome.io/components/mqtt.html#on-json-message-trigger).  Examples are also included here.

3.  (optional) Alternatively to setting receier_id, you can send raw OOK/FSK pulse data to the decoder via lambdas like this:
    ```yaml
        - lambda: |-
            id(my_rtl433_id).recv_raw(rawdata);
    ```
## Working Examples
Two examples are provided:
1.  [esp32-rtl_433-decoder.yaml](https://github.com/juanboro/esphome-rtl_433-decoder/blob/main/examples/esp32-rtl_433-decoder.yaml) - MQTT relay - generates rtl_433 style MQTT messages from decoded receiver data.  Also includes example of how to generate Home Assistant API events.
1.  [esp32-rtl_433-sensors.yaml)](https://github.com/juanboro/esphome-rtl_433-decoder/blob/main/examples/esp32-rtl_433-sensors.yaml) - Example of creating specific ESPHome sensors from rtl_433 json messages.  It also shows how to limit to the component to only specific protocols, which will speed up processing and help prevent: Component remote_receiver took a long time for an operation (>30ms)

The example configurations points to a configuration with a ESP32 dev board connected to a TI-CC1101 board (both from AliExpress ~ $5 total).  However, any working way of receiving OOK on/off pulses or FSK mark/space data should be able to work.

## See Also...
Underlying library details: https://github.com/juanboro/rtl_433_Decoder_ESP

