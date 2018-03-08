#include "hal.h"
#include "led.h"

void led_set(uint8_t usb_led){
    if (usb_led & USB_LED_CAPS_LOCK)
        palSetLine(LINE_LED1);
    else
        palClearLine(LINE_LED1);

    if (usb_led & USB_LED_SCROLL_LOCK)
        palSetLine(LINE_LED2);
    else
        palClearLine(LINE_LED2);
}
