#ifndef ST7796_H
#define ST7796_H

#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "lvgl.h"

void st7796_init(
    uint32_t st7796_hor_res, 
    uint32_t st7796_ver_res, 
    lv_lcd_flag_t st7796_flag, 
    spi_inst_t *spi, 
    int cs_gpio, 
    int dcx_gpio, 
    int rst_gpio, 
    int dma_channel, 
    uint dma_irq_index, 
    dma_channel_config *dma_config
);

void st7796_send_color_callback(void);

#endif /*ST7796_H*/