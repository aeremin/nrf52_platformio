#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include <drivers/gpio.h>
#include "led.h"
#include <vector>

/* 1000 msec = 1 sec */
#define SLEEP_TIME	1000

void main(void)
{
	init();
	bool on = true;

	while (1) {
		set(on);
		on = !on;
		k_sleep(SLEEP_TIME);
	}
}