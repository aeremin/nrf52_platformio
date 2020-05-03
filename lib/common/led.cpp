#include "led.h"

#include <device.h>
#include <devicetree.h>
#include <drivers/gpio.h>

namespace {
device* led = device_get_binding(DT_ALIAS_LED0_GPIOS_CONTROLLER);
}

void init() {
  gpio_pin_configure(led, DT_ALIAS_LED0_GPIOS_PIN, GPIO_OUTPUT_ACTIVE);
}

void on() {
  set(true);
}

void off() {
  set(false);
}

void set(bool on) {
  gpio_pin_set(led, DT_ALIAS_LED0_GPIOS_PIN, on);
}