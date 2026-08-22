#include "https_handler.h"
#include "spi_handler.h"


static const char *TAG = "Info Collector";

/* Timer interval once every day (24 Hours) */
#define TIME_PERIOD (86400000000ULL)

static void spi_dataShare_task(void *pvparameters)
{
    //if CE interrrupt is received, start sending the data.
    vTaskDelete(NULL);
}
static void https_request_task(void *pvparameters)
{
    ESP_LOGI(TAG, "Start OpenSky Engine");
#if CONFIG_MBEDTLS_CERTIFICATE_BUNDLE && CONFIG_EXAMPLE_USING_ESP_TLS_MBEDTLS
    https_get_request_using_crt_bundle();
#endif
    ESP_LOGI(TAG, "Minimum free heap size: %" PRIu32 " bytes", esp_get_minimum_free_heap_size());
    https_get_request_using_cacert_buf();
    ESP_LOGI(TAG, "Finish https_request example");
    vTaskDelete(NULL);
}

void app_main(void)
{
    ESP_ERROR_CHECK(nvs_flash_init());
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());

    /* This helper function configures Wi-Fi or Ethernet, as selected in menuconfig.
     * Read "Establishing Wi-Fi or Ethernet Connection" section in
     * examples/protocols/README.md for more information about this function.
     */
    ESP_ERROR_CHECK(example_connect());

    if (esp_reset_reason() == ESP_RST_POWERON) {
        ESP_LOGI(TAG, "Updating time from NVS");
        ESP_ERROR_CHECK(update_time_from_nvs());
    }

    const esp_timer_create_args_t nvs_update_timer_args = {
            .callback = (void *)&fetch_and_store_time_in_nvs,
    };

    esp_timer_handle_t nvs_update_timer;
    ESP_ERROR_CHECK(esp_timer_create(&nvs_update_timer_args, &nvs_update_timer));
    ESP_ERROR_CHECK(esp_timer_start_periodic(nvs_update_timer, TIME_PERIOD));

    xTaskCreate(&https_request_task, "https_get_task", 8192, NULL, 5, NULL);
}