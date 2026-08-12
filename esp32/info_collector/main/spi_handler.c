#include "spi_handler.h"



/* Defining pins for ESP32 which uses MISO, MOSI, CS, SCLK */
#define ESP_HOST    SPI3_HOST                              
#define GPIO_MISO   GPIO_NUM_19                            
#define GPIO_MOSI   GPIO_NUM_23                            
#define GPIO_SCLK   GPIO_NUM_18                            
#define GPIO_CS     GPIO_NUM_5                             
#define SPI_TAG "spi_protocol"

esp_err_t ret;
spi_slave_transaction_t t = {0};


void spi_initSlave(char **sendbuf, char **recvbuf){
    spi_bus_config_t buscfg = {                                         
        .miso_io_num = GPIO_MISO,
        .mosi_io_num = GPIO_MOSI,
        .sclk_io_num = GPIO_SCLK,
        .quadwp_io_num = -1,
        .quadhd_io_num = -1,
        .max_transfer_sz = 512 * 8                                     
    };

    spi_slave_interface_config_t slvcfg = {
        .mode = 0,
        .spics_io_num = GPIO_CS,
        .queue_size = 3,
        .flags = 0
    };

    ret = spi_slave_initialize(ESP_HOST, &buscfg, &slvcfg, SPI_DMA_CH_AUTO);       
    assert(ret == ESP_OK);

    *sendbuf = spi_bus_dma_memory_alloc(ESP_HOST, 128, 0);
    *recvbuf = spi_bus_dma_memory_alloc(ESP_HOST, 128, 0);
    assert(sendbuf && recvbuf);

    printf("SPI Initialization: Done.\n");
    printf("Sendbuf: %p, Recvbuf: %p. \n", sendbuf, recvbuf);
}

void spi_sendData(char *sendbuf, char *recvbuf)
{
    printf("SPI send data: Initiated.\n");
    int n = 0;
    while (1) {
        //Clear receive buffer, set send buffer to something sane
        
        memset(recvbuf, 0xA5, 128);
        sprintf(sendbuf, "This is the receiver, sending data for transmission number %04d.", n);
        // printf("SPI send data: Inside while loop.\n");

        //Set up a transaction of 128 bytes to send/receive
        t.length = 128 * 8;
        t.tx_buffer = sendbuf;
        t.rx_buffer = recvbuf;
 
        ret = spi_slave_transmit(ESP_HOST, &t, portMAX_DELAY);

        //spi_slave_transmit does not return until the master has done a transmission, so by here we have sent our data and
        //received data from the master. Print it.
        printf("Received: %s\n", recvbuf);

        //pause the slave to save power, transaction will also be paused
        ret = spi_slave_disable(ESP_HOST);
        if (ret == ESP_OK) {
            printf("slave paused ...\n");
        }
        vTaskDelay(100);    //now is able to sleep or do something to save power, any following transaction will be ignored
        ret = spi_slave_enable(ESP_HOST);
        if (ret == ESP_OK) {
            printf("slave ready !\n");
        }
        n++;
    }
}

int app_main(void)
{
    char *sendbuf = NULL;
    char *recvbuf = NULL;
    spi_initSlave(&sendbuf, &recvbuf); 
    spi_sendData(sendbuf, recvbuf);

    return 0;
}