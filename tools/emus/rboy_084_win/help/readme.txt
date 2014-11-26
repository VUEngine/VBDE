-------------------------
- Reality Boy emu Frontend v0.82.2 - 07/27/2005
-------------------------

----------------------
- Copyright Info/Disclaimer
----------------------
This Reality Boy emu frontend is Copyright (C) David Tucker 
1997-2005, all rights reserved.
   You may use this code as long as you make no money from the use 
of this code and you acknowledge the original author (Me).  I reserve
the right to dictate who can use this code and how (Just so you don't
do something stupid with it).
   Most Importantly, this code is swap ware.  If you use It send along
your new program (W/code) or some other Interesting tidbits you wrote,
that I might be Interested in.
   This code is In beta, there are bugs!  I am not responsible for any
damage done to your Computer, reputation, ego, dog or Family Life due
to the use of this code.  All source is provided as is, I make no
guaranties, and am not responsible for anything you do with the code
(Legal or otherwise).
   Virtual Boy is a trademark of Nintendo, and V810 is a Trademark of
NEC.  I am in no way affiliated with Either party and all Information
contained hear was found freely through Public Domain sources.

--------
- History:
--------
07/27/05 - Added support for more graphic modes.

06/15/05 - Fixed a recursive dive in Win98, added brightness and 
 Horizontal 2x optoins.  Need to fix frame skip, it no longer loads
 its saved value form the ini file.

05/18/05 - Added support for joystick.

04/14/05 - Added support for the pport option and reworked zoom as a dropdown.

03/03/05 - Fixed it so that spaces in the rom path were ok.
 Updated documentation to handle the 2/24 updates
 Fixed settings.h so we no longer incude useles headers (oops)

02/24/05 - Added in switches to enable/disable the folowing:
 Disasembly during debug
 Debug message dump to the console instead of a file
 Turn off speed throttling
 Turn on a status line, currenly only shows FPS

02/21/05 - Finished first build

--------
- Usage:
--------

 rboy_front.exe is a simple progrem that can be used to pass arguments
to the reality_boy emulator.  Here is a rundown of the various options
and there ramifications.

Emulator Path: The path to the reality_boy executable

Rom Path: The path to the rom to run in the emulator

Display mode: set the screen resolution frame (window) is the 
  default mode

3D Mode:
    Choos normal or a 3D display mode
    Red Blue is analgraph mode
    Interlaced should support most shuter glasses, as well as I-glasses

Zoom: Set the level of zoom on the display (1x-6x) or stretch to fill
    the window in full screen mode.

Palette: Select the apropriet palette

Brightness: Brighten or darken the screen based on a multiplicitive factor, 
    range from [0.1-3.0]. Values in the [0.7-1.3] range produce the best results.

Frame Skip: Number of frames to skip before refreshing the display
    hit -/= while in the game to adjust this as well

Key map: Select standard or alternate keyboard mapping

VB Controller: Select the paralel port that your VB controller is hooked up to.

Joy: Enable joystick support (dissabled).

Swap Display: flip the 3D efects (you can hit ']' while in 
    the game to do this as well)

Horizontal 2x: Doubles the width of the display for shutter glasses that
   use line doubleing to block alternate lines.

No Throttle: turn off all speed throtling

Status Line: display the FPS during emulation, press '0' to togle in game

Long Timmer Hack: Force a longer duration to the timmer

Vertical Force hack: Fixes Vertical Force, game won't run without this

Debug: starts the interactive debugger, currently only works in the
    debug build

Dissasembly: generate disasembler dump of all code executed during emulation

Console Output: dump debug messages to the console instead of to a file

--------------------------------------------
Keyboard:
--------------------------------------------
  'p'          - printscreen, saves the current display in a .bmp file
  ']'          - flip the 3D efects
  '-'-'='      - adjust the frame skip
  '0'          - toggle fps status indicator
  <Esc>        - quit the emu

Controller Maping 1:
  up,down,
    left,right - (Up,Down,Left,Right) LControler
  F,V,C,B      - (Up,Down,Left,Right) RControler
  Q,W,         - (Start,Sel)
  A,S          - (L,R)
  Z,X          - (A,B)

Controller Maping 2:
  E,D,S,F      - (Up,Down,Left,Right) LControler
  V,B,N,M      - (Sel,Start,B,A)
  I,K,J,L      - (Up,Down,Left,Right) RControler
  G,H          - (L,R)

 
--------------------------------------------
Debug Usage:
--------------------------------------------
***** Debug is currently disabled in the release build*****

u - unassemble the next 16 instructions
d - dump the next 16 bytes (should be words(32bits))
t - trace through next instruction
b - Run continusly, break at address
j - Jump Straight to address
r - show Registers and next instruction (Without executing)
v - Go to Video Mode (View the various screen structures...)
	On all screens!
	 q,<ESC> - quite the video mode (Fast)
	 p - print the virtual screen to a .bmp file

	C - chr ram
	O - Obj map
	B - Bgmap (hit any key to cycle through all 14 bg maps,
             <esc> to exit early)
	W - World (Hit any key to Cycle through all 32 World Maps,
             <esc> to exit early)
	R - Rom, view the rom graphically like VB_View.exe
		u/d - Up/Down 1 line
		U/D - Up/Down 1 page (Screen)
		+/- - Up/Down 1 Byte (To realign sprites when not
                  on even boundary's)
		</> - Left/Right 1 char (Sprite)
		1/2 - Shrink/Expand  the # of columns displayed,
                  helps align pictures in the rom (vBaseball,
                  and vGolf are great candidates for this
		H - help, prints this list...
	P - Print the buffers to err.txt (So we can see the world array)
	D - Display mode, start up the Interrupts and go.
            Asks for Display mode 
	    (normal display or a series of 3D options)
		<ESC>     - quit....
		E,C,S,F   - (Up,Down,Left,Right) LControler
		V,B,N,M   - (Sel,Start,B,A)
		I,'<',J,L - (Up,Down,Left,Right) RControler
		G,H       - (L,R)
		0-9       - Frame Skip
		[,]       - 3D orientation...

m - dump Memory to the hard disk
? - help
q - quit
i - Generate Interrupt # 
l - set the debug level (0<all>-10<none>)


--------
- too do:
--------
* Open dialog at last screen position
* List all roms in a directory complete with extracted titles
   and known good dump status
* Need to redo fskip code to corectly handle spin controll, limit
   range to 0-9 frames, and save default fskip value and load
   from file, also limit range on Brightness to [0.1-3.0]
* Need to verify that Emulator path and Rom path point to a valid file
   before launching.  If not pull up a message box with instructions.

---------------------------------------------  
v810 is a trademark of NEC co.
Virtual Boy is a trade mark of Nintendo
I amd in no way affiliated with either of these parties
---------------------------------------------
David Tucker
david.tucker@goliathindustries.com
http://www.goliathindustries.com/vb/
 
