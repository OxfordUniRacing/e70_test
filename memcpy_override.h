/*
 * Override memcpy to work around bug caused by unaligned access to usb sram
 *
 * Thanks to atmel for their excellent quality library
 *
 * Hours wasted: 8
 */

#ifndef _MEMCPY_OVERRIDE_H
#define _MEMCPY_OVERRIDE_H

#include <stddef.h>

void *memcpy_aligned(void *dest, const void *src, size_t len);

#define memcpy memcpy_aligned

#endif
