#include "hal/gpio.h"
#include "atoi.h"
#include "hal/tasks.h"
#pragma pack(push, 1)
#include "tl_common.h"
#pragma pack(pop)

#include <stdint.h>
#include <string.h>
// hal_gpio_pin_t directly stores GPIO_PinTypeDef values

// Convert HAL pull type to Telink pull type
static GPIO_PullTypeDef hal_to_telink_pull(hal_gpio_pull_t pull) {
    switch (pull) {
    case HAL_GPIO_PULL_NONE:
        return PM_PIN_UP_DOWN_FLOAT;

    case HAL_GPIO_PULL_UP:
        return PM_PIN_PULLUP_10K;

    case HAL_GPIO_PULL_UP_1M:
        return PM_PIN_PULLUP_1M;

    case HAL_GPIO_PULL_DOWN:
        return PM_PIN_PULLDOWN_100K;

    default:
        return PM_PIN_UP_DOWN_FLOAT;
    }
}

// Diagnostic: blink each unknown pin for 10 seconds at boot
// Sequence: B5, B7, B1, C1, C2, D7, A2
// Watch green LED - note which pin number (1-7) makes it blink
static void blink_pin(GPIO_PinTypeDef pin, int seconds) {
    gpio_set_func(pin, AS_GPIO);
    gpio_set_output_en(pin, 1);
    gpio_set_input_en(pin, 0);
    gpio_setup_up_down_resistor(pin, PM_PIN_UP_DOWN_FLOAT);

    // Blink for N seconds (500ms on / 500ms off)
    for(int i = 0; i < seconds; i++) {
        gpio_write(pin, 0); // LOW
        for(volatile u32 d = 0; d < 4000000; d++) {}
        gpio_write(pin, 1); // HIGH
        for(volatile u32 d = 0; d < 4000000; d++) {}
    }
    gpio_write(pin, 0); // Leave LOW
}

void hal_gpio_debug_pb5(void) {
    // 3 second pause at start
    for(volatile u32 d = 0; d < 12000000; d++) {}

    // Pin 1: B5
    blink_pin(GPIO_PB5, 3);
    for(volatile u32 d = 0; d < 8000000; d++) {} // 2s pause

    // Pin 2: B7
    blink_pin(GPIO_PB7, 3);
    for(volatile u32 d = 0; d < 8000000; d++) {}

    // Pin 3: B1
    blink_pin(GPIO_PB1, 3);
    for(volatile u32 d = 0; d < 8000000; d++) {}

    // Pin 4: C1
    blink_pin(GPIO_PC1, 3);
    for(volatile u32 d = 0; d < 8000000; d++) {}

    // Pin 5: C2
    blink_pin(GPIO_PC2, 3);
    for(volatile u32 d = 0; d < 8000000; d++) {}

    // Pin 6: D7
    blink_pin(GPIO_PD7, 3);
    for(volatile u32 d = 0; d < 8000000; d++) {}

    // Pin 7: A2
    blink_pin(GPIO_PA2, 3);
    for(volatile u32 d = 0; d < 8000000; d++) {}
}

void hal_gpio_init(hal_gpio_pin_t gpio_pin, uint8_t is_input,
                   hal_gpio_pull_t pull) {
    GPIO_PinTypeDef telink_pin = (GPIO_PinTypeDef)gpio_pin;

    // Ensure pin is in GPIO mode (critical for analog-capable pins like PB5)
    gpio_set_func(telink_pin, AS_GPIO);

    if (is_input) {
        gpio_set_input_en(telink_pin, 1);
        gpio_set_output_en(telink_pin, 0);
    } else {
        gpio_set_output_en(telink_pin, 1);
        gpio_set_input_en(telink_pin, 0);
    }

    // Set pull resistor
    gpio_setup_up_down_resistor(telink_pin, hal_to_telink_pull(pull));
}

void hal_gpio_set(hal_gpio_pin_t gpio_pin) {
    gpio_write((GPIO_PinTypeDef)gpio_pin, 1);
}

void hal_gpio_clear(hal_gpio_pin_t gpio_pin) {
    gpio_write((GPIO_PinTypeDef)gpio_pin, 0);
}

uint8_t hal_gpio_read(hal_gpio_pin_t gpio_pin) {
    return gpio_read((GPIO_PinTypeDef)gpio_pin) ? 1 : 0;
}

hal_gpio_pin_t hal_gpio_parse_pin(const char *s) {
    if (!s || strlen(s) < 2) {
        return HAL_INVALID_PIN;
    }

    // Parse format like "A5", "B3", etc.
    char port = s[0];
    int  pin  = atoi(&s[1]);

    if (pin < 0 || pin > 7) {
        return HAL_INVALID_PIN;
    }

    // Return direct Telink GPIO_PinTypeDef values
    uint16_t port_base;
    switch (port) {
    case 'A':
    case 'a':
        port_base = GPIO_GROUPA;
        break;
    case 'B':
    case 'b':
        port_base = GPIO_GROUPB;
        break;
    case 'C':
    case 'c':
        port_base = GPIO_GROUPC;
        break;
    case 'D':
    case 'd':
        port_base = GPIO_GROUPD;
        break;
    case 'E':
    case 'e':
        port_base = GPIO_GROUPE;
        break;
    default:
        return HAL_INVALID_PIN;
    }

    return (hal_gpio_pin_t)(port_base | BIT(pin));
}

hal_gpio_pull_t hal_gpio_parse_pull(const char *pull_str) {
    if (!pull_str) {
        return HAL_GPIO_PULL_INVALID;
    }

    switch (pull_str[0]) {
    case 'u':
        return HAL_GPIO_PULL_UP;

    case 'U':
        return HAL_GPIO_PULL_UP_1M;

    case 'd':
    case 'D':
        return HAL_GPIO_PULL_DOWN;

    case 'f':
    case 'F':
    case 'n':
    case 'N':
        return HAL_GPIO_PULL_NONE;

    default:
        return HAL_GPIO_PULL_INVALID;
    }
}

// GPIO interrupt callbacks
