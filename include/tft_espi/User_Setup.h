// User_Setup.h for the 3.5" display

// TFT Driver
#define ILI9488_DRIVER
#define TFT_WIDTH 320
#define TFT HEIGHT 480
#define TFT_BACKLIGHT_ON HIGH
// SPI-Pins
#define TFT_MISO 12
#define TFT_MOSI 13
#define TFT_SCLK 14
#define TFT_CS 15
#define TFT_DC 2
#define TFT_RST -1
#define TFT_BL 27              // Color order instead of RGB BGR
#define TFT_RGB_ORDER TFT_BGR  // Colors are reversed: Black = white //
#define TFT_INVERSION OFF
#define SPI_FREQUENCY 55000000
#define SPI_READ_FREQUENCY 20000000  // Touch
#define TOUCH_CLK 14
#define TOUCH_CS 33.
#define TOUCH_MOSI 13
#define TOUCH_MISO 12
#define TOUCH_IRQ 36
#define SPI_TOUCH_FREQUENCY 2500000
// Fonts
// Font 2-4: Letters, numbers, and punctuation marks, no diacritics
#define LOAD_FONT2
#define LOAD_FONT4
// Font 6-8: Numbers .-
#define LOAD_FONT6
#define LOAD_FONT7
#define LOAD_FONT8
#define SMOOTH_FONT
#define LOAD_GFXFF
