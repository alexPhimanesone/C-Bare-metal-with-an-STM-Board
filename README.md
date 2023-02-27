# C-Bare-metal-with-an-STM-Board

This is a school project. We try to use an STM32 board and its peripherals without an OS (bare metal programming). The steps of the project are the following.
1. Create a simple executable
2. Control the GPIO to make the LEDs of the board blink
3. Retrieve streams on the UART serial port
4. Control the LED array, display dynamic images, display a picture from a .raw file
5. Use interruptions and exceptions to trigger a LED when a button is pressed
6. Display images sent by a computer using the UART, IRQ and the LED array
7. Get timers to generate interruptions
8. Move the executable into the flash memory so the board can operate by itself
