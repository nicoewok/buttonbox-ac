# Buttonbox for Assetto Corsa (in progress)
DIY button box used for Assetto Corsa


## What you need
- Arduino Pro Micro + soldering equipment + [Arduino IDE](https://www.arduino.cc/en/software)
- Switches and buttons (I used 5 on-off-on switches and 3 buttons)
- wires and soldering equipment
- 3D printer (if you want to print this model or create your own) or plastic box

## Instructions
1. 3D print [the box](/3d_print/) or use any box and drill holes to fit the buttons/switches
2. Insert buttons and switches into the box and fixate them
3. Solder the switches and buttons according to the [wiring diagram](/wiring_diagram.png)
4. Solder final wires onto the arduino
5. Add [Joystick library](https://github.com/MHeironimus/ArduinoJoystickLibrary) and the ```Keypad library``` (Sketch->Include library->Manage libraries->Keypad created by Mark Stanley)
6. Upload the [code](/arduino-code/arduino-code.ino) to your Arduino Micro
7. In Assetto Corsa you should now see the Arduino Micro in the settings for binding inputs

## Resources
- 3D modeling using [Tinkercad](https://www.tinkercad.com)
- Drawing wiring diagram using [draw.io](https://app.diagrams.net/)
- Inspired by [this Instructable](https://www.instructables.com/Sim-Racing-Button-Box/) and [this project](https://www.simracinghub.nl/en_us/make-your-own-diy-button-box-in-these-8-simple-steps/)