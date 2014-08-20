GCodeAFMotorV2
==============

Arduino GCode Interpreter for Adafruits Motor Shield Version 2

--------------

Based on GcodeCNCDemo by Dan Royer at MarginallyClever.
You can find his great works on https://github.com/MarginallyClever/
and https://www.marginallyclever.com

What i have done:

 - Remove the compatibility with Adafruids Motor Shield Version 1
 - Split the functions into files.
 - Add a new G-Command (G28 - do homing)
 - Add support for limit switches (X-Home, X-End, Y-Home, Y-End)
 - steps/[mm | in] translator
 - send actual position to PC-Software (see https://github.com/hirnwunde/hwCNC)
 - Soft limit switch (don't leave your defined working space)
 
TODO:
--------------

 - add support for manual movement of X & Y (four buttons, maybe a fifth for fast move)
 - add servo for Z 
 - add button for homing (must be pressed 3sec)
 - add option for more HardwareEndSwitches (0 = no switches, 1 = Home- and End-Switches, 2 = only Home-Switches, 3 = only End-Switches)


You can send commands to GCodeAFMotorV2 over Serial or with PC-Software hwCNC (see https://github.com/hirnwunde/hwCNC)
