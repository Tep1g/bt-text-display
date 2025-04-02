#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "lvgl.h"

static struct ST7796 {
        lv_display_t *disp;
        spi_inst_t *spi;
        int dma_channel;
} st7796;

void st7796_init(lv_display_t *disp, spi_inst_t *spi, int dma_channel)
{
        st7796.disp = disp;
        st7796.spi = spi;
        st7796.dma_channel = dma_channel;
}
