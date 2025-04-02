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

/* Send short command to the LCD. This function shall wait until the transaction finishes. */
static int32_t st7796_send_cmd(lv_display_t *disp, const uint8_t *cmd, size_t cmd_size, const uint8_t *param, size_t param_size)
{
        // UNIMPLEMENTED
        return 0;
}

/* Send large array of pixel data to the LCD. If necessary, this function has to do the byte-swapping. This function can do the transfer in the background. */
static int32_t st7796_send_color(lv_display_t *disp, const uint8_t *cmd, size_t cmd_size, uint8_t *param, size_t param_size)
{
        // UNIMPLEMENTED
        return 0;
}