// Autogenerated C header file for LED
#ifndef _JACDAC_SPEC_LED_H
#define _JACDAC_SPEC_LED_H 1

#define JD_SERVICE_CLASS_LED  0x1e3048f8

// enum Variant (uint32_t)
#define JD_LED_VARIANT_THROUGH_HOLE 0x1
#define JD_LED_VARIANT_SMD 0x2
#define JD_LED_VARIANT_POWER 0x3
#define JD_LED_VARIANT_BEAD 0x4

/**
 * Read-write ratio u0.16 (uint16_t). Set the luminosity of the strip. The value is used to scale `value` in `steps` register.
 * At `0` the power to the strip is completely shut down.
 */
#define JD_LED_REG_BRIGHTNESS JD_REG_INTENSITY

/**
 * Animations are described using pairs of color description and duration, 
 * similarly to the `status_light` register in the control service.
 * They repeat indefinitely until another animation is specified.
 * For monochrome LEDs, the hue and saturation are ignored.
 * A specification `(red, 80ms), (blue, 40ms), (blue, 0ms), (yellow, 80ms)`
 * means to start with red, cross-fade to blue over 80ms, stay blue for 40ms,
 * change to yellow, and cross-fade back to red in 80ms.
 */
#define JD_LED_REG_STEPS 0x82
typedef struct jd_led_steps {
    uint8_t hue;
    uint8_t saturation;
    uint8_t value;
    uint8_t duration; // 8ms
} jd_led_steps_t;


/**
 * Read-write mA uint16_t. Limit the power drawn by the light-strip (and controller).
 */
#define JD_LED_REG_MAX_POWER JD_REG_MAX_POWER

/**
 * Constant uint16_t. If known, specifies the number of LEDs in parallel on this device.
 */
#define JD_LED_REG_LED_COUNT 0x180

/**
 * Constant nm uint16_t. If monochrome LED, specifies the wave length of the LED.
 */
#define JD_LED_REG_WAVE_LENGTH 0x181

/**
 * Constant mcd uint16_t. The luminous intensity of the LED, at full value, in micro candella.
 */
#define JD_LED_REG_LUMINOUS_INTENSITY 0x182

/**
 * Constant Variant (uint32_t). The physical type of LED.
 */
#define JD_LED_REG_VARIANT JD_REG_VARIANT

#endif
