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
 - remove support for relative mode (G91) for simplification the stepps/[mm | in] translation
 - send actual position to PC-Software (VB.Net [the only language i can code GUIs ;)] - has to be coded)
 
Work in proress:
--------------

 - Soft limit switch (don't leave your defined working space)

TODO:
--------------

<<<<<<< HEAD
 - add support for manual movement of X & Y (four buttons, maybe a fifth for fast move)
 - add servo for Z 
 - add button for homing (must be pressed 3sec)
 
=======
 - Soft limit switch
   - every step of the motors will counted and when the machine will move beyond its border the soft-switch will prevent further moves 
 - add support for manual movement of X & Y (four buttons, maybe a fifth for fast move)
 - add servo for Z 
 - send actual position to PC-Software (VB.Net - has to be coded)
 - add steps/mm and/or steps/inch translator
>>>>>>> parent of 9642487... Update README.md
