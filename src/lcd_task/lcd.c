#include "lcd.h"
#include "pico/stdlib.h"
#include "hardware/dma.h"
#include "hardware/irq.h"
#include "hardware/spi.h"
#include "st7796.h"

#define ST7796_SPI_SCK 2
#define ST7796_SPI_MOSI 3
#define ST7796_SPI_MISO 4
#define ST7796_SPI_CS 5
#define ST7796_SPI_DCX 6
#define ST7796_SPI_RST 7

const uint32_t st7796_hor_res = 320;
const uint32_t st7796_ver_res = 480;
const lv_lcd_flag_t st7796_flag = LV_LCD_FLAG_NONE;
const uint st7796_dma_irq_index = 0;

void lcd_task(void *pvParameters) {
    lv_init();

    spi_init(spi0, 40000000);
    spi_set_slave(spi0, false);
    gpio_set_function(ST7796_SPI_SCK, GPIO_FUNC_SPI);
    gpio_set_function(ST7796_SPI_MOSI, GPIO_FUNC_SPI);
    gpio_set_function(ST7796_SPI_MISO, GPIO_FUNC_SPI);
    gpio_set_dir(ST7796_SPI_CS, GPIO_OUT);
    gpio_set_dir(ST7796_SPI_DCX, GPIO_OUT);
    gpio_set_dir(ST7796_SPI_RST, GPIO_OUT);
    spi_set_format(spi0, 8, SPI_CPOL_0, SPI_CPHA_0, SPI_MSB_FIRST);

    const int st7796_dma_channel = dma_claim_unused_channel(true);
    dma_channel_config st7796_dma_config = dma_channel_get_default_config(st7796_dma_channel);
    channel_config_set_transfer_data_size(&st7796_dma_config, DMA_SIZE_8);
    channel_config_set_dreq(&st7796_dma_config, spi_get_dreq(spi0, true));
    channel_config_set_read_increment(&st7796_dma_config, true);
    channel_config_set_write_increment(&st7796_dma_config, false);

    dma_channel_set_irq0_enabled(st7796_dma_channel, true);
    irq_set_exclusive_handler(DMA_IRQ_0, st7796_send_color_callback);
    irq_set_enabled(DMA_IRQ_0, true);

    lv_disp_t *lv_st7796 = st7796_init(
        st7796_hor_res, 
        st7796_ver_res, 
        st7796_flag, 
        spi0, 
        ST7796_SPI_CS, 
        ST7796_SPI_DCX, 
        ST7796_SPI_RST, 
        st7796_dma_channel, 
        st7796_dma_irq_index, 
        &st7796_dma_config
    );
    
    while (1) {
        // Main loop for the LCD task
    }
}