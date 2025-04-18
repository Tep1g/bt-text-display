#include "pico/stdlib.h"
#include "FreeRTOS.h"
#include "task.h"
#include "lcd.h"

void main() {
    stdio_init_all();

    xTaskCreate(lcd_task, "LCD Task", 2048, NULL, 1, NULL);
    vTaskStartScheduler();

    while (1) {
        // Infinite loop to prevent returning from main
    }
}