Virtual Boy Sound Generator v1.1
by Pat Daderko (DogP)
www.projectvb.com

This application takes an input file of Virtual Boy sound register values
and creates a wav file to allow accurate sound development and testing on
a PC without requiring the use of Virtual Boy hardware.  It optionally
outputs C code from the register values entered.

The goal of this application is to create 100% accurate sound emulation
(or very close to it), which is done by cycle accurately emulating the
actions of the VSU at 5MHz, and then resampling the output at ~41.7KHz,
as done on real hardware.  This is still a work in progress, but hopefully
it'll be close enough to be useful, and please report any bugs, suspicious
behavior, or incorrect sound handling.

usage: vb_snd_gen <infile> <wav_out> [code_out]

The arguments are:
  infile - register input file
  wav_out - wav output file
  code_out - optional C code output of input sequence
  
Details on the format for the input file (see example.txt):
  waveform RAM is WAVERAMx= where x = 1 to 5, and 32 numbers in Hexadecimal (just characters, no 0x or $), seperated by a comma
  modulation RAM is MODRAM= and 32 signed decimal integer numbers, seperated by a comma
  registers are Sx<regname>=<value>, where x=1 to 6, regname= one of (INT,LRV,FQL,FQH,EV0,EV1,RAM,SWP) where appropriate, and value is again in Hexadecimal (just characters, no 0x or $)
  all stop register is SSTOP=<value> where value is 0 or 1
  to create sound, you must give the WAIT=<time in seconds>.  All register changes happen instantly, WAIT allows the sound to be generated for the entered length of time (floating point number)
  comments for the input file are lines that start with a "%"
  comments which should be included in C code are lines that start with "%%"
  blank lines are ignored
  
The output file is a 16-bit stereo wav file at 41.666KHz.  The Virtual Boy
hardware is sampled at 41.7KHz, but the difference shouldn't be noticeable
since the time is still the same, and the sample rate is close enough to
give very similar sound quality (and should alias similarly) to the hardware.
This program initializes all registers and memory to 0, though it appears the
Virtual Boy hardware does not, so for accurate results, be sure to initialize
all registers and memory related to sounds you want to use.

The optionally generated code output file is C code which should be able to
be pasted directly into your existing C code, which will create (hopefully)
the same sounds as the wav file generated.  A delay function is provided and
used to give an approximately correct delay on hardware, though it's likely
that you will want to do something else while the sound is playing.