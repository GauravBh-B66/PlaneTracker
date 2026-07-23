#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(service1, LOG_LEVEL_DBG);


#include <stdio.h>
#include <string.h>
#include <zephyr/device.h>
#include <zephyr/kernel.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/spi.h>
#include <zephyr/drivers/gpio.h>

#include "spiService.h"



#define SPI_NODE DT_NODELABEL(spi1)
#define SPI_BUS_FREQUENCY 1000000
#define BUFFER_LENGTH 8
// #define CS_NODE DT_ALIAS(gpiob)

static struct device *spiDevice = DEVICE_DT_GET(SPI_NODE);
static struct gpio_dt_spec csPin = GPIO_DT_SPEC_GET(SPI_NODE, cs_gpios);

static struct spi_config spiConfig = {
    .frequency = SPI_BUS_FREQUENCY,
    .operation = SPI_OP_MODE_MASTER | SPI_WORD_SET(8),
    .slave = 0,
};

int main(void){
    int ret = 0;

    if (spiInit(spiDevice, spiConfig, csPin)){
        return -1;
    }

    uint8_t dataTrasmitBuffer[BUFFER_LENGTH] = {0x01, 0x02, 0x03, 0x04, 0x05};
    uint8_t dataReceiveBuffer[BUFFER_LENGTH] = {0};
    
    
    while(1){
        ret = spiTransceive(spiDevice, spiConfig, csPin, dataTrasmitBuffer, dataReceiveBuffer, BUFFER_LENGTH);
    }

    return 0;
}

