#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

// XIAO ESP32C6 on-board USER LED (yellow) is on GPIO15, active-low.
#define LED_PIN   15
#define LED_ON    0    // drive low to turn ON
#define LED_OFF   1    // drive high to turn OFF

void app_main(void)
{
    // Configure GPIO15 as output
    gpio_config_t io_conf = {
        .pin_bit_mask = 1ULL << LED_PIN,
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE
    };
    gpio_config(&io_conf);

    // Start with LED off
    gpio_set_level(LED_PIN, LED_OFF);

    while (1) {
        gpio_set_level(LED_PIN, LED_ON);
        vTaskDelay(pdMS_TO_TICKS(1000));
        gpio_set_level(LED_PIN, LED_OFF);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
