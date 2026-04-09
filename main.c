#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

// Definição dos sensores
#define SENSOR1 13
#define SENSOR2 25

int carros1 = 0; // Contador do sensor 1
int carros2 = 0; // Contador do sensor 2

void app_main() {
    // Configura sensores como entrada
    gpio_set_direction(SENSOR1, GPIO_MODE_INPUT);
    gpio_set_direction(SENSOR2, GPIO_MODE_INPUT);

    while(1) {
        // Sensor 1 detectou carro
        if (gpio_get_level(SENSOR1) == 1) {
            carros1++;
            printf("Sensor 1 - Carros detectados: %d\n", carros1);
            
            // Espera até o sensor ficar inativo para não contar múltiplas vezes
            while (gpio_get_level(SENSOR1) == 1) {
                vTaskDelay(10 / portTICK_PERIOD_MS);
            }
        }

        // Sensor 2 detectou carro
        if (gpio_get_level(SENSOR2) == 1) {
            carros2++;
            printf("Sensor 2 - Carros detectados: %d\n", carros2);
         // Espera até o sensor ficar inativo para não contar múltiplas vezes
            while (gpio_get_level(SENSOR2) == 1) {
                vTaskDelay(10 / portTICK_PERIOD_MS);
            }
        }

        // Pequeno delay para não sobrecarregar a CPU
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}