#include <atmel_start.h>
#include "usb_start.h"
#include <same70q21b.h>

uint8_t buf[25 * 1024];

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();

	//cdcd_acm_example();
	usbd_msc_example(buf, NULL);

	/* Replace with your application code */
	while (1) {
	}
}
