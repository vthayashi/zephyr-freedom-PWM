#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>

#define SLEEP_TIME_MS 1000

#define LED0_NODE DT_ALIAS(led0)

static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);

void main(void)
{
    
    gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
   
    while (1) {
            gpio_pin_set_dt(&led, 1);   
            k_msleep(SLEEP_TIME_MS);
            gpio_pin_set_dt(&led, 0);   
            k_msleep(SLEEP_TIME_MS);
    }
}
