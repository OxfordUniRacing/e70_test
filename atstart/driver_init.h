/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */
#ifndef DRIVER_INIT_H_INCLUDED
#define DRIVER_INIT_H_INCLUDED

#include "atmel_start_pins.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <hal_atomic.h>
#include <hal_delay.h>
#include <hal_gpio.h>
#include <hal_init.h>
#include <hal_io.h>
#include <hal_sleep.h>

#include <hal_mci_os.h>

#include "hal_usb_device.h"

#include <hal_can_async.h>

extern struct mci_os_desc IO_BUS;

extern struct can_async_descriptor CAN_0;

void IO_BUS_PORT_init(void);
void IO_BUS_CLOCK_init(void);
void IO_BUS_init(void);

void USB_DEVICE_INSTANCE_CLOCK_init(void);
void USB_DEVICE_INSTANCE_init(void);

void CAN_0_PORT_init(void);
void CAN_0_CLOCK_init(void);
void CAN_0_init(void);
void CAN_0_example(void);

/**
 * \brief Perform system initialization, initialize pins and clocks for
 * peripherals
 */
void system_init(void);

#ifdef __cplusplus
}
#endif
#endif // DRIVER_INIT_H_INCLUDED
