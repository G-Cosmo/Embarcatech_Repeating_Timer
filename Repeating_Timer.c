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
        gpio_put(rgb[i], false); //garante que os leds comecem apagados
    }
}

bool repeating_timer_callback(struct repeating_timer *t)
{
        if(gpio_get(rgb_led[0]) && !gpio_get(rgb_led[1]))  //se apenas vermelho estiver ligado
        {   
            gpio_put(rgb_led[1], true); //liga amarelo (vermelho + verde)
        }else if(gpio_get(rgb_led[0]) && gpio_get(rgb_led[1]))  //se amarelo estiver ligado (vermelho e verde)
        {
            gpio_put(rgb_led[0], false);    //liga verde (desliga o canal vermelho)
        }else if(gpio_get(rgb_led[1]) && !gpio_get(rgb_led[0]))    //se apenas verde estiver ligado
        {
            gpio_put(rgb_led[1], false);    //desliga verde
            gpio_put(rgb_led[0], true);     //liga vermelho
        }
}

int main()
{
    stdio_init_all();
    init_rgb(rgb_led);

    struct repeating_timer timer;
    
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    gpio_put(rgb_led[0], true);


    while (true) {
        
        printf("\nLaço principal.");
        sleep_ms(1000);
    }
}
