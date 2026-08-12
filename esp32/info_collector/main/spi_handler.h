#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "driver/spi_slave.h"
#include "driver/gpio.h"
#include "esp_log.h"



/* Declaring the funtions which are used in the program */
void spi_initSlave(char**, char **);
void spi_sendData(char*, char *);