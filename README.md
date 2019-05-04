# SAME70 (VCU) usb/sd/other test

Experiments to test out usb (and sd card) functionality of the same70,
intended for use in the VCU

## Todo

- [ ] Handle usb disconnect

## Status

- [x] USB works
- [x] SD card works

Maximum transfer speed achieved: 2.5MB/s

## Thanks atmel

Driver bugs encountered: 3

1. usb: Misuse of memcpy for sram that requires 4 byte alignment
2. sdmmc: Not waiting for XFRDONE before sending another command
3. can: Not setting CAN0DMABA to base address of can buffers
