-===============================================================================-
-										-
-    		  PROGRAMMING THINGS - Assignment 1 (Zumo Robot)		-
-		            ARAN WILKINSON (B7025268)				-
-										-
-===============================================================================-

Hello, this is a brief explanation of everything that is included in this 
repository. If you have any further questions, please email me on either my 
university email (b7025268@my.shu.ac.uk) or my personal email
(aran.wilkinson101@gmail.com). I will respond to either as soon as possible.

I would like to add that in the video footage the robot does not turn well.
This is due to the fact that I had to record it on my bed (an uneven and soft
surface) because of limitations to the space in which I was working. It works
with perfect accuracy on solid and even ground. I will include a video of this
in the final submission aswell to prove it.

		The git repository can be found at the link below:
	https://github.com/AranWilkinson/PROGRAMMING-THINGS-Coursework-1
      It should be visible to you but please contact me if you have issues.

-===============================================================================-
-    				FILE STRUCTURE					-
-===============================================================================-

Folders are shown with '[' and ']' brackets

- [PROGRAMMING THINGS Coursework1]
   - README.txt			(This file)
   - [Coursework1]
	- Coursework1.ino	(The arduino project file)
	- Turnsensor.cpp		(The code file for the gyro)
	- Turnsensor.h		(The header file for the gyro)
   - [Processing_GUI]
	- Processing_GUI.pde	(The GUI file used with G4P)
	- gui.pde		(The auto generated file created by the G4P GUI 
				builder using processing)
   - ExampleVideo.wvm 		(A video file of the robot/GUI running my code)

-===============================================================================-
-    				  REPORT					-
-===============================================================================-
I decided to use G4P and processing to create my UI as I have worked a lot with
java2D before in other projects and have a good understanding of how it works. 
The G4P form creator is easy to use and allows for in depth events to be utilised, 
this enabled me to create a nice user friend GUI in a short time frame. The GUI 
itself is relatively simple but I tried to follow a consistent approach in the 
looks and layout as to not confuse the user.

I looked at example gyroscope code online by pvcraven:
https://github.com/pvcraven/zumo_32u4_examples/tree/master/GyroSensorExample
This showed an example of how to use the built in gyroscope on the zumo. I used 
this code as the base for my gyroscope code.

-===============================================================================-
-    				FINAL NOTES					-
-===============================================================================-

Thanks for reading this file. Again if you have any questions or issues please
contact me via the email's in the introduction section above.
-Aran Wilkinson (B7025268)