#include "atmel_start.h"
#include "usb_drive.h"
#include "usb_init.h"

int main(void) {
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();

	NVIC_SetPriority(HSMCI_IRQn, configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY);
	NVIC_SetPriority(USBHS_IRQn, configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY);

	usb_drive_init();

	usb_start();

	vTaskStartScheduler();
}
