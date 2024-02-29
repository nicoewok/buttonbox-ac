# Buttonbox for Assetto Corsa
DIY button box used for Assetto Corsa with custom 3D printed box. Contains 5 switches (traction-control, brake-balance ABS, turbo and wipers) and 3 buttons (hazard lights, change camera perspective and lights).
![picture of finished box](/pictures/front.jpg)


## What you need
- Arduino Pro Micro + soldering equipment + [Arduino IDE](https://www.arduino.cc/en/software)
- [Joystick library](https://github.com/MHeironimus/ArduinoJoystickLibrary) and the ```Keypad library``` (Sketch->Include library->Manage libraries->Keypad created by Mark Stanley) for the Arduino IDE.
- Switches and buttons (I used 5 on-off-on switches and 3 buttons)
- Wires and soldering equipment
- 3D printer (if you want to print this model or create your own) or plastic box

## Instructions
1. 3D print [the box](/3d_print/) or use any box and drill holes to fit the buttons/switches
2. Insert buttons and switches into the box and fixate them
3. Solder the switches and buttons according to the [wiring diagram](/wiring_diagram.png)
4. Solder final wires onto the arduino. I used pins 14-16 for the rows and 5-9 for the columns.
5. Add [Joystick library](https://github.com/MHeironimus/ArduinoJoystickLibrary) to the IDE by downloading the zip and in the Arduino IDE click *Sketch* -> *Include Library* -> *Add .ZIP Library* -> select downloaded zip.\
Basically follow the ```Installation Instructions``` of the github project.
6. Add the ```Keypad library``` (*Sketch* -> *Include library* -> *Manage libraries* -> *Keypad* created by Mark Stanley) to the IDE
7. Upload the [code](/arduino-code/arduino-code.ino) to your Arduino Micro
8. In Assetto Corsa you should now see the Arduino Micro in the settings for binding inputs
9. _(Optional)_ If you want to rename your board (I named mine *Button Box*) you can go to ```AppData/Local/Arduino15/packages/arduino/hardware/avr/[yourversion]/boards.txt``` and change the values of lines ```micro.build.vid``` and ```micro.build.pid``` and change ```micro.build.usb_product``` to your preferred name for the USB device. Restart the Arduino IDE and upload the sketch again.

## Resources
- 3D modeling using [Tinkercad](https://www.tinkercad.com)
- Drawing wiring diagram using [draw.io](https://app.diagrams.net/)
- Inspired by [this Instructable](https://www.instructables.com/Sim-Racing-Button-Box/) and [this project](https://www.simracinghub.nl/en_us/make-your-own-diy-button-box-in-these-8-simple-steps/)