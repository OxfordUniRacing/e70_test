/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file or main.c
 * to avoid loosing it when reconfiguring.
 */
#include "atmel_start.h"
#include "usb_start.h"

/* Max LUN number */
#define CONF_USB_MSC_MAX_LUN 0

#if CONF_USBD_HS_SP
static uint8_t single_desc_bytes[] = {
    /* Device descriptors and Configuration descriptors list. */
    MSC_HS_DESCES_LS_FS};
static uint8_t single_desc_bytes_hs[] = {
    /* Device descriptors and Configuration descriptors list. */
    MSC_HS_DESCES_HS};
#else
static uint8_t single_desc_bytes[] = {
    /* Device descriptors and Configuration descriptors list. */
    MSC_DESCES_LS_FS};
#endif

static struct usbd_descriptors single_desc[]
    = {{single_desc_bytes, single_desc_bytes + sizeof(single_desc_bytes)}
#if CONF_USBD_HS_SP
       ,
       {single_desc_bytes_hs, single_desc_bytes_hs + sizeof(single_desc_bytes_hs)}
#endif
};

/* Ctrl endpoint buffer */
static uint8_t ctrl_buffer[64];

/**
 * \brief USB MSC Init
 */
void usbd_msc_init(void)
{
	/* usb stack init */
	usbdc_init(ctrl_buffer);

	/* usbdc_register_funcion inside */
	mscdf_init(CONF_USB_MSC_MAX_LUN);
}

/**
 * \brief Example of using MSC Function.
 * \param[in] ramd_buf Pointer to the memory block for RAM Disk. Size of the
 *            disk is defined by \ref CONF_USB_MSC_LUN0_CAPACITY in KB.
 * \param[in] usbdisk_buf Pointer to the buffer for disk read/write,
 *            e.g., during reading from SD/MMC, data is read to the buffer and
 *            then sent to host from the buffer. Size of the buffer is defined
 *            by \ref CONF_USB_MSC_LUN_BUF_SECTORS in number of sectors.
 * \note
 * In this example, we will use a PC as a USB host:
 * - Connect the DEBUG USB on XPLAINED board to PC for program download.
 * - Connect the TARGET USB on XPLAINED board to PC for running program.
 * The application will behave as a massive storage device which can be
 * recognized by PC. Only one logic unit is supported in this example.
 */
void usbd_msc_example(uint8_t *ramd_buf, uint8_t *usbdisk_buf)
{

	usbdc_start(single_desc);
	usbdc_attach();

	while (!mscdf_is_enabled()) {
		/* wait massive storage to be installed */
	};

	while (1) {
	}
}

void usb_init(void)
{

	usbd_msc_init();
}
