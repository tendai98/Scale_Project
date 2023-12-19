# Loadcell Project 🧾

Project using an HX711 load cell amplifier, an OLED display and Arduino Nanao to measure weight and display the readings.

## Project Overview 📝

### Loadcell
The code initializes and reads values from the load cell:

- **Loadcell Pins:**
  - **DOUT_PIN:** 2
  - **SCK_PIN:** 3

The project uses the `HX711` library to calibrate and read values from the load cell. `calibrateScale` sets up calibration, while `getAverageValue` reads the weight value.

### OLED Display
It also involves an OLED display to show the weight readings:

- **OLED Display:**
  - **128x32 pixels**

The `U8G2lib` library manages the display. Functions like `initOLED`, `printChar`, `printString`, and `clearScreen` control the display content.

## How It Works ℹ️

1. **Initialization:** Initializes the OLED display and load cell.
2. **Calibration:** Runs a calibration routine to zero the load cell and calibrate it with a known weight.
3. **Weight Display:** Continuously measures the weight using the load cell and displays it on the OLED display.
