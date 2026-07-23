#include <zephyr/drivers/spi.h>
#include <zephyr/kernel.h>

#include "spiService.h"


uint32_t spiInit(struct device *spiDevice, struct spi_config spiConfig, struct gpio_dt_spec csPin){
    if (!device_is_ready(spiDevice)){
		printk("%s: Device not ready.\n", spiDevice->name);
		return -1;
	}
    
    if(gpio_pin_configure_dt(&csPin, GPIO_OUTPUT_ACTIVE)){
        printk("%s: CS pin not ready.\n", csPin.port->name);
        return -1;
    }

    return 0;
}

uint32_t spiTransceive(struct device *spiDevice, struct spi_config spiConfig, 
                        struct gpio_dt_spec csPin, uint8_t *txBuffer, 
                        uint8_t *rxBuffer, size_t bufLen){
    struct spi_buf dataTrans_buff = {
        .buf = txBuffer,
        .len = bufLen
    };

    struct spi_buf dataRec_buff = {
        .buf = rxBuffer,
        .len = bufLen
    };
    
	struct spi_buf_set tx_set = { .buffers = &dataTrans_buff, .count = 1 };
	struct spi_buf_set rx_set = { .buffers = &dataRec_buff, .count = 1 };

    gpio_pin_set_dt(&csPin, 0);
    if (spi_transceive(spiDevice, &spiConfig, &tx_set, &rx_set)){
        printk("Data tranceive error.\n");
    };
    gpio_pin_set_dt(&csPin, 1);
    k_sleep(K_MSEC(1000));
    
    
    return 0;
}0
0



int libCheck(void){
    return 1;
}