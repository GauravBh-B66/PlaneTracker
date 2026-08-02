#include "spi_handler.h"

/* Defining pins for ESP32 which uses MISO, MOSI, CS, SCLK */
#define ESP_HOST    SPI3_HOST                              // Selecting host(ESP32) to work in VSPI mode
#define GPIO_MISO   GPIO_NUM_38                            // MISO pin is present at GPIO_NUM_32
#define GPIO_MOSI   GPIO_NUM_23                            // MOSI pin is present at GPIO_NUM_23
#define GPIO_SCLK   GPIO_NUM_18                            // SCLK pin is present at GPIO_NUM_18
#define GPIO_CS     GPIO_NUM_5                             // CS' pin is present at GPIO_NUM_5
#define SPI_TAG "spi_protocol"

esp_err_t ret;
spi_device_handle_t spi;

void spi_initSlave(char *sendbuf, char *recvbuf)
{
    // Setting the CS' pin to work in OUTPUT mode

    spi_bus_config_t buscfg = {                                         // Provide details to the SPI_bus_sturcture of pins and maximum data size
        .miso_io_num = GPIO_MISO,
        .mosi_io_num = GPIO_MOSI,
        .sclk_io_num = GPIO_SCLK,
        .quadwp_io_num = -1,
        .quadhd_io_num = -1,
        .max_transfer_sz = 512 * 8                                      // 4095 bytes is the max size of data that can be sent because of hardware limitations
    };

    spi_slave_interface_config_t slvcfg = {
        .mode = 0,
        .spics_io_num = GPIO_CS,
        .queue_size = 3,
        .flags = 0
    };

    ret = spi_slave_initialize(ESP_HOST, &buscfg, &slvcfg, SPI_DMA_CH_AUTO);       // Initialize the SPI bus
    assert(ret == ESP_OK);

    sendbuf = spi_bus_dma_memory_alloc(RCV_HOST, 129, 0);
    recvbuf = spi_bus_dma_memory_alloc(RCV_HOST, 129, 0);
    assert(sendbuf && recvbuf);
    spi_slave_transaction_t t = {0};
}

void spi_sendData(void)     // Function to write data at given address
{
    while (1) {
        //Clear receive buffer, set send buffer to something sane
        memset(recvbuf, 0xA5, 129);
        sprintf(sendbuf, "This is the receiver, sending data for transmission number %04d.", n);

        //Set up a transaction of 128 bytes to send/receive
        t.length = 128 * 8;
        t.tx_buffer = sendbuf;
        t.rx_buffer = recvbuf;
        /* This call enables the SPI slave interface to send/receive to the sendbuf and recvbuf. The transaction is
        initialized by the SPI master, however, so it will not actually happen until the master starts a hardware transaction
        by pulling CS low and pulsing the clock etc. In this specific example, we use the handshake line, pulled up by the
        .post_setup_cb callback that is called as soon as a transaction is ready, to let the master know it is free to transfer
        data.
        */
        ret = spi_slave_transmit(RCV_HOST, &t, portMAX_DELAY);

        //spi_slave_transmit does not return until the master has done a transmission, so by here we have sent our data and
        //received data from the master. Print it.
        printf("Received: %s\n", recvbuf);

        //pause the slave to save power, transaction will also be paused
        ret = spi_slave_disable(RCV_HOST);
        if (ret == ESP_OK) {
            printf("slave paused ...\n");
        }
        vTaskDelay(100);    //now is able to sleep or do something to save power, any following transaction will be ignored
        ret = spi_slave_enable(RCV_HOST);
        if (ret == ESP_OK) {
            printf("slave ready !\n");
        }
        n++;
    }
}

int app_main(void)
{
    vSpiInit();

    uint8_t addr = 0x22; // address = 0x22
    uint8_t data = 0xAA; // data = 0xAA

    spi_read_data(addr); // Read the value present at address (0x22)
    spi_write_data(addr, data); // Write the value '0xAA' at the location 0x22
    spi_read_data(addr);
    
    return 0;
}