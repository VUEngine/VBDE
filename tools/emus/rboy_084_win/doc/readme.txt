-------------------------
- Reality Boy emu v0.84.0 - 12/09/2008
-------------------------

----------------------
- Copyright Info/Disclaimer
----------------------
This Reality Boy emulator is copyright (C) David Tucker 1997-2008, all rights
reserved.   You may use this code as long as you make no money from the use of
this code and you acknowledge the original author (Me).  I reserve the right to
dictate who can use this code and how (Just so you don't do something stupid
with it).
   Most Importantly, this code is swap ware.  If you use It send along your new
program (with code) or some other interesting tidbits you wrote, that I might be
interested in.
   This code is in beta, there are bugs!  I am not responsible for any damage
done to your computer, reputation, ego, dog, or family life due to the use of
this code.  All source is provided as is, I make no guaranties, and am not
responsible for anything you do with the code (legal or otherwise).
   Virtual Boy is a trademark of Nintendo, and V810 is a trademark of NEC.  I am
in no way affiliated with either party and all information contained hear was
found freely through public domain sources.

--------
- Usage:
--------

 reality_boy <rom_name> [options]

 Options:
  -display (frame, WxH)
    set the screen resolution frame (window) is the default mode
  -dspmode (normal, affine, interlace, over_under, side, cscope)
    Choose normal or a 3D display mode
    Normal is default, if you want red/green glasses use affine
    and pass in rg for the palette.  Interlaced should support most
    shutter glasses, as well as I-glasses
  -frmskp (0-9)
    Number of frames to skip (not display) before refreshing the display
    hit -/= while in the game to adjust this as well
  -palette (normal, red, rb, rg, rc, yb, mg, bg)
    Red palette might be dark, so use the Brightness option to lighten it up,
    and play with the contrast and brightness knobs on your monitor
    rb, rg, rc, yb, mg, bg are the options for the Red/Blue glasses 
    (thats red-blue, red-green, red-cyan, yellow-blue, magenta-green, blue-green)
  -brite (0.1-3.0)
    Lighten or darken the display, 1.0 is default, bigger numbers brighten,
    smaller numbers darken
  -balance [r g b] (0.1-3.0)
    Lighten or darken the individual color bands, 1.0 is default, 
    bigger numbers brighten, smaller numbers darken
  -hstretch
    Double the width of the display, useful for shutter glasses that use
    line doubling instead of line blanking.
  -flip
    flip the 3D effects (you can hit ']' while in the game to do this as well)
  -ltimmer
    force a longer duration to the timer
  -vfhack
    fixes Vertical Force
  -altkbd
    Use the alternate keyboard mapping
  -pport
    Use a VB Controller wired up to a parallel port
  -joy
    Use a joystick for input, currently broken and may lock up the game
  -status
    Display FPS on screen, toggle with '0' in game
  -nothrtl
    Disable speed throttle
  -sclscr [0-4]
    Upscales the screen by the given factor, 0 forces a stretch to the
    full display.
  -debug (only works in the debug build)
    Go into debug mode, see below for more help
  -disasm (only works in the debug build)
    Generate a disassembly file of all the code that gets executed
  -stdout (only works in the debug build)
    Output debug info to the dos box instead of to a text file
  -more_ram
    Increases ram form 64K to 128k
  -nosound
    Dissables sound output (only works in Win32 for now)
  -network (<IP_ADDR>|host)
    Allow link play between two emulators.  Use host to setup the server.
    or input the ip address of the server to connect to it.
  -? or -help
    Dump the help screen

--------------------------------------------
Keyboard:
--------------------------------------------
  p           - print screen, saves the current display in a .bmp file
  ]           - flip the 3D effects
  -,=         - adjust the frame skip
  <Esc>       - quit the emu
  0           - toggle the FPS status
  ~           - Pause the emulator
  1,2         - Turn brightness down and up
  3,4         - Turn red brighness down and up
  5,6         - Turn green brightness down and up
  7,8         - Turn blue brightness down and up

 - Debugger build only -
  \           - Dump cpu cache info
  /           - Clear cpu cache info

Controller Mapping 1:
  up,down,
    left,right - (Up,Down,Left,Right) LControler
  F,V,C,B      - (Up,Down,Left,Right) RControler
  Q,W,         - (Start,Sel)
  A,S          - (L,R)
  Z,X          - (A,B)

Controller Mapping 2 (-altkbd):
  E,D,S,F      - (Up,Down,Left,Right) LControler
  V,B,N,M      - (Sel,Start,B,A)
  I,K,J,L      - (Up,Down,Left,Right) RControler
  G,H          - (L,R)

 
--------------------------------------------
Debug Usage:
--------------------------------------------
** Debug is disabled in the release build **
** use reality_boyD.exe for debug mode    **

u - unassemble the next 16 instructions
d - dump the next 16 bytes (should be words(32bits))
t - trace through next instruction
b - Run continuously, break at address
p - Run continuously, with video, break at address
w - Watch memory at address
h - Break at memory access
s - Show last 100 instructions executed
a - Start interactive dissasembler
j - Jump Straight to address
r - show Registers and next instruction (Without executing)
m - dump Memory to the hard disk
? - help
q - quit
i - Generate Interrupt # 
l - set the debug level (0<all>-10<none>)

v - Go to Video Mode (View the various screen structures...)
	On all screens!
	 q,<ESC> - quite the video mode
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
		+/- - Up/Down 1 Byte (To realign sprites
			when not on even boundary's)
		</> - Left/Right 1 char (Sprite)
		1/2 - Shrink/Expand  the # of columns displayed, helps align 
		  pictures in the rom (vBaseball, and vGolf are great
		  candidates for this)
		H - help, prints this list...
    A - Ram, view the ram graphically.  Same as (R)om but views ram memory
    S - Scale, dump current affine mode registers to log file
	P - Print the buffers to log file (So we can see the world array)
	D - Display mode, start up the Interrupts and go. Asks for Display mode 
	    (normal display or a series of 3D options)
		<ESC>     - quit....

-------------------
- Affine Mode Hints:
-------------------
 Some hints on getting Affine mode to work:
 - Use Red/Blue glasses, green bleeds to bad on all the red filters I tested.
 - Turn down the brightness on your monitor
 - '1'/'2' turn down/up the brightness in the game
 - '3'/'4', '5'/'6', '7'/'8' adjust the brightness of the red, green and blue bands
 - Double stacking (putting two glasses together) helps some what
 - The smaller the screen the less you notice 'bleading'

-----------------
- Acknowledgments:
-----------------
 Frostgiant, Parasyte, and DogP (and the rest of people that have contributed
to the VB sceen in the last five years) - There work on Red_Dragon has been a
real inspiration.  Its amazing how far they have gone with so little to start
with.

 Bob VanderClay (vandercl@umich.edu) - most of the original code is based off
of his VB disassembler.

 Ben Haynor (bch132@psu.edu) - Provided me with a much better understanding of
the VB Internals

 Joseph LoCicero, Dave Shadoff - I stole the jump table Ideas from there tg16
disassembler, thanks guys

 Neill Corlett (corlett@elwha.nrrc.ncsu.edu) - took many ideas (and some code)
from his Starscream CPU core

 Kevin Banks (kbanks@ro.com) - for donating a very nice pair of Frenzle 3D
viewers, and being an all around great guy

 Megan Tucker - For putting up with my tinkering all night, and resisting the
 urge to toss all my video games out the window 

----------------------------------------------------------------------------  
v810 is a trademark of NEC co.
Virtual Boy is a trade mark of Nintendo
Reality Boy is in no way affiliated with either of these parties

----------------------------------------------------------------------------
David Tucker
david.tucker@goliathindustries.com
http://www.goliathindustries.com/vb/
 
