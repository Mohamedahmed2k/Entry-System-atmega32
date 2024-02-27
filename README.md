# Entry System with ATmega32

## Overview

This project implements an entry system using ATmega32 microcontroller along with peripherals such as LCD, keypad, and buzzer. The system allows users to enter a passcode using the keypad, and if the passcode is correct, it grants access. If the user enters a wrong passcode, the buzzer turns on to indicate an incorrect attempt.

## Features

- **Passcode Entry**: Users can input a passcode using the keypad.
- **Access Control**: Grants access upon entering the correct passcode.
- **Feedback Indicator**: Buzzer provides feedback for incorrect passcode entry.

## Components Used

- **ATmega32 Microcontroller**: Controls the system logic and interfaces with peripherals.
- **16x2 LCD**: Displays system status and prompts for passcode entry.
- **4x4 Keypad**: Allows users to input the passcode.
- **Buzzer**: Provides audible feedback for incorrect passcode entry.

## Usage

1. Set up the hardware components as per the schematic.
2. Flash the provided firmware onto the ATmega32 microcontroller.
3. Power on the system and follow the on-screen instructions displayed on the LCD.
4. Enter the passcode using the keypad.
5. If the passcode is correct, the system grants access. Otherwise, the buzzer turns on indicating an incorrect attempt.

## Hardware Setup

- Connect the LCD to the ATmega32 microcontroller according to the schematic provided.
- Connect the keypad to the appropriate GPIO pins of the ATmega32 microcontroller.
- Connect the buzzer to a GPIO pin of the ATmega32 microcontroller.

## Firmware Compilation

1. Install AVR GCC toolchain on your development environment.
2. Compile the provided firmware source code using AVR GCC.
3. Generate the HEX file for flashing onto the ATmega32 microcontroller.

## Contributing

Contributions are welcome! Feel free to open issues or submit pull requests.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
