#include "atmel_start.h"

void vApplicationStackOverflowHook( TaskHandle_t xTask,
                                    signed char *pcTaskName ) {
    __BKPT(0);
    while (1);
}

void vApplicationMallocFailedHook( void ) {
	__BKPT(0);
    while (1);
}
