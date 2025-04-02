#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "lvgl.h"

void st7796_init(lv_display_t *disp, spi_inst_t *spi, int dma_channel);