#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "hardware/clocks.h"

const uint rgb_led[3] = {13,11,12};
// int64_t alarm_callback(alarm_id_t id, void *user_data) {
//     // Put your timeout handler code in here
//     return 0;
// }

void init_rgb(const uint *rgb)
{
    for(int i =0; i<3; i++)
    {
        gpio_init(rgb[i]);
        gpio_set_dir(rgb[i], GPIO_OUT);
    }
}


int main()
{
    stdio_init_all();
    init_rgb(rgb_led);

    // // Timer example code - This example fires off the callback after 2000ms
    // add_alarm_in_ms(2000, alarm_callback, NULL, false);
    // // For more examples of timer use see https://github.com/raspberrypi/pico-examples/tree/master/timer

    // printf("System Clock Frequency is %d Hz\n", clock_get_hz(clk_sys));
    // printf("USB Clock Frequency is %d Hz\n", clock_get_hz(clk_usb));
    // // For more examples of clocks use see https://github.com/raspberrypi/pico-examples/tree/master/clocks

    while (true) {
        
        gpio_put(rgb_led[0], true);
        sleep_ms(400);
        gpio_put(rgb_led[0], false);
        sleep_ms(400);
        gpio_put(rgb_led[1], true);
        sleep_ms(400);
        gpio_put(rgb_led[1], false);
        sleep_ms(400);
        gpio_put(rgb_led[2], true);
        sleep_ms(400);
        gpio_put(rgb_led[2], false);
        sleep_ms(400);
    }
}
