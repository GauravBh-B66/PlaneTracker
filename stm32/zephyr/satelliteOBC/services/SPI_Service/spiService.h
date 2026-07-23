#include <stdint.h>
#include <stddef.h>


uint32_t spiInit(struct device*, struct spi_config, struct gpio_dt_spec);
uint32_t spiTransceive(struct device *, struct spi_config , struct gpio_dt_spec,  uint8_t *, uint8_t *, size_t);
