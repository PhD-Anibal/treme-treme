#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define LED_PIN 12        // Definir o pino do LED RGB Azul
#define SERVO_PIN 22      // Define oa conexão com PWM do servo motor
#define PWM_FREQ 50       // 50Hz -> período de 20ms
#define PWM_WRAP 20000    // Tempo total em µs (20ms)

int main() {
    stdio_init_all();

    // Configuração do PWM para o servo motor
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(SERVO_PIN);
    uint channel = pwm_gpio_to_channel(SERVO_PIN);
    pwm_set_wrap(slice_num, PWM_WRAP);
    pwm_set_clkdiv(slice_num, 125.0f);  // Ajuste do clock

    // Configuração do PWM para o LED RGB Azul
    gpio_set_function(LED_PIN, GPIO_FUNC_PWM);
    uint led_slice_num = pwm_gpio_to_slice_num(LED_PIN);
    uint led_channel = pwm_gpio_to_channel(LED_PIN);
    pwm_set_wrap(led_slice_num, PWM_WRAP);
    pwm_set_clkdiv(led_slice_num, 125.0f);   // O mesmo ajuste de clock do servo

    pwm_set_enabled(slice_num, true);
    pwm_set_enabled(led_slice_num, true);

    // para a movimentação brusca acontecer só 1 vez
    // Movimentação brusca em intervalors de 5 segundos entre 0° e 180°
    pwm_set_chan_level(slice_num, channel, 2400); // 180 graus
    pwm_set_chan_level(led_slice_num, led_channel, 2400);    // LED aceso com brilho máximo
    sleep_ms(5000);

    pwm_set_chan_level(slice_num, channel, 1470); // 90 graus
    pwm_set_chan_level(led_slice_num, led_channel, 1470);    // LED com brilho moderado
    sleep_ms(5000);

    pwm_set_chan_level(slice_num, channel, 500);  // 0 graus 500
    pwm_set_chan_level(led_slice_num, led_channel, 500);     // LED com brilho bem fraco
    sleep_ms(5000);

    while (true) {
        // Movimentação suave entre 0° e 180°
        for (int duty = 500; duty <= 2400; duty += 5) {
            pwm_set_chan_level(slice_num, channel, duty);
            pwm_set_chan_level(led_slice_num, led_channel, duty); // LED segue o mesmo padrão
            sleep_ms(10);
        }

        for (int duty = 2400; duty >= 500; duty -= 5) {
            pwm_set_chan_level(slice_num, channel, duty);
            pwm_set_chan_level(led_slice_num, led_channel, duty); // LED segue o mesmo padrão
            sleep_ms(10);
        }
    }
}