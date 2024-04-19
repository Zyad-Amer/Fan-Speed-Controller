# Fan Controller System

This project aims to design a temperature-controlled fan using the ATmega32 microcontroller, where the fan is automatically turned on or off based on the temperature. 

## Specifications

1. **Microcontroller:** ATmega32 with a frequency of 1MHz.
2. **Temperature Sensor:** LM35, providing continuous analog output corresponding to the sensed temperature.
3. **Analog to Digital Conversion (ADC):** Converts the analog signal from the LM35 to digital values.
4. **Temperature Calculation:** Perform calculations in the microcontroller to derive the temperature from the ADC values.
5. **LCD Display:** Display the temperature and fan state.
6. **Fan Control Logic:** 
    - If temperature < 30°C, turn off the fan.
    - If temperature ≥ 30°C, run the fan at 25% speed.
    - If temperature ≥ 60°C, run the fan at 50% speed.
    - If temperature ≥ 90°C, run the fan at 75% speed.
    - If temperature ≥ 120°C, run the fan at 100% speed.
7. **Circuit Principle:** The circuit switches the fan (connected to a DC motor) on/off based on the temperature value. The DC motor rotates clockwise or stops based on the fan state.
8. **LCD Display Format:** Continuously display the temperature value and fan state.
9. **DC-Motor Speed Control:** Achieve speed control using PWM signal generated from Timer0.

## Implementation

1. **Hardware Setup:**
    - Connect LM35 temperature sensor to the microcontroller.
    - Connect the DC motor (fan) to the microcontroller with appropriate drive circuitry.
    - Ensure proper connections for LCD display.
2. **Firmware Development:**
    - Write code to read analog temperature values from LM35 via ADC.
    - Implement temperature calculation logic.
    - Control the fan speed based on the temperature using PWM signals.
    - Update LCD display with temperature and fan state.
3. **Testing and Calibration:**
    - Test the system under various temperature conditions to ensure accurate operation.
    - Calibrate the temperature readings if necessary for accuracy.
4. **Final Integration:**
    - Assemble all components and integrate the firmware with the hardware setup.
    - Verify the complete functionality of the temperature-controlled fan system.

## Usage

1. **Setup:**
    - Power up the system with appropriate power supply.
    - Ensure proper temperature sensing and fan connections.
2. **Operation:**
    - Monitor the LCD display for real-time temperature readings and fan state.
    - Ensure the fan responds appropriately to changes in temperature.
3. **Maintenance:**
    - Periodically check for any issues with temperature sensing or fan operation.
    - Replace components if necessary for continued functionality.

Feel free to explore the provided code and adjust it according to your specific requirements or hardware setup.
