add_executable(app main.c)

# pull in common dependencies
target_link_libraries(app pico_stdlib FreeRTOS-Kernel FreeRTOS-Kernel-Heap4 freertos_config lvgl)

# create map/bin/hex/uf2 file etc.
pico_add_extra_outputs(app)

# enable usb output, disable uart output
pico_enable_stdio_usb(app 1)
pico_enable_stdio_uart(app 1)