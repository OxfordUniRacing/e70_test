#include "atmel_start.h"
#include "usb_drive.h"

//static void usb_msc_task(void) {
//	static uint8_t buf[2048];
//	//SDMMC_ACCESS_0_example();
//	usbd_msc_run(NULL, buf);
//}

static uint8_t single_desc_bytes[] = { MSC_DESCES_LS_FS };
static struct usbd_descriptors single_desc[]
    = {{single_desc_bytes, single_desc_bytes + sizeof(single_desc_bytes)}};

TaskHandle_t h_task_msc;

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();

	NVIC_SetPriority(HSMCI_IRQn, configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY);
	NVIC_SetPriority(USBHS_IRQn, configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY);

	usb_drive_init();

	usbdc_start(single_desc);
	usbdc_attach();

	vTaskStartScheduler();
}
