#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED_GPIO 2
static const char *LED_TAG = "TEST_LED";

void app_main(void)
{
    gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);
    
    uint32_t ledState = 0;

    while (1)
    {
        ledState = !ledState;
        gpio_set_level(LED_GPIO, ledState);
        ESP_LOGI(LED_TAG,"Status:%s", ledState? "ON":"OFF");
        vTaskDelay(pdMS_TO_TICKS(500));
    }

}