+====================================================================+
|  ____     ____  __________    __________    ___________            |
|  @@@@     @@@@  @@@@@@@@@@__  @@@@@@@@@@__  @@@@@@@@@@@            |
|  @@@@     @@@@  @@@@    @@@@  @@@@    @@@@  @@@@                   |
|  @@@@     @@@@  @@@@____@@@@  @@@@    @@@@  @@@@_____              |
|  @@@@     @@@@  @@@@@@@@@@__  @@@@    @@@@  @@@@@@@@@              |
|  @@@@_   _@@@@  @@@@    @@@@  @@@@    @@@@  @@@@                   |
|    @@@___@@@    @@@@____@@@@  @@@@____@@@@  @@@@_______            |
|      @@@@@      @@@@@@@@@@    @@@@@@@@@@    @@@@@@@@@@@            |
|                                                                    |
|  VBDE - Virtual Boy Development Environment                        |
|  Preview 5 - December 21st, 2014                                   |
|                                                                    |
+====================================================================+

+--------------------------------------------------------------------+
| (00) Contents                                                      |
+--------------------------------------------------------------------+

(01) Introduction
(02) Usage
(03) Bundled Libraries
(04) Bundled Sample Projects
(05) Bundled Tools'n'Stuff


+--------------------------------------------------------------------+
| (01) Introduction                                                  |
+--------------------------------------------------------------------+

Blah


+--------------------------------------------------------------------+
| (02) Usage                                                         |
+--------------------------------------------------------------------+

No installation or any extra steps are required. Just download, unzip
and you're ready to start developing for the Virtual Boy.

(Note: Previous versions needed to be placed in C:/vbde/. This is no 
longer necessary.)

VBDE comes with a current portable version of Notepad++ that has 
been slightly modified to have a button bar on top. With these, you
can quickly compile the current project, start it in an emulator, et
cetera. 

These buttons simply trigger a bunch of batch file, which you can just 
as well start from the command line or any other editor of choice. See
editors/npp.6.5.bin.minimalist/shortcuts.xml for how to call these.


+--------------------------------------------------------------------+
| (03) Bundled Libraries                                             |
+--------------------------------------------------------------------+

* libgccvb
  Description: The default gccVB library.
  Author: various

* VBJaEngine
  Description: A highly advanced Virtual Boy game engine.
  Author: jorgeche


+--------------------------------------------------------------------+
| (04) Bundled Sample Projects                                       |
+--------------------------------------------------------------------+

VBDE comes with a few sample projects you can use to test VBDE 
functionality, as reference or as a boilerplate for your own project.

* Barebone Demo
  Description: Barebone code that can be used as a starting point for 
    your VB project. Included features:
    - [...]
  Location: samples/barebone/
  Author: KR155E

* Beginner Samples
  Description: A total of 6 simple Virtual Boy demos which introduce
    you to various aspects of Virtual Boy development.
  Location: samples/demos/*
  Author: Fwirt

* Game of Life
  Description: A sample implementation of Conway's Game of Life.
  Location: samples/game-of-life/
  Author: KR155E

* VBJaEngine Platformer Demo
  Description: A multilevel platformer demo which demonstrates usage
    and features of the VBJaEngine
  Location: samples/vbjaengine/platformer/
  Author: jorgeche, KR155E

* VBJaEngine Skeleton
  Description: A barebone VBJaEngine project that can be used as a 
    starting point for your VB project.
  Location: samples/vbjaengine/skeleton/
  Author: jorgeche, KR155E


+--------------------------------------------------------------------+
| (05) Bundled Tools'n'Stuff                                         |
+--------------------------------------------------------------------+

### Environment

* Cygwin

### Editors

* Notepad++ v6.5 Minimalist with Customize Toolbar v3.4 plugin

### gccVB 

* v810-gcc-4.4.2 patched for VB

### Tools 

#### Audio

* Midi2VB

* Midi Converter
  Author: thunderstruck
  Release Date: April 15th, 2013

* Virtual Boy Sound Generator
  Version: 1.1
  Author: Pat Daderko
  Release Date: February 1st, 2010

* Virtual Boy WAV converter
  Version: 1.0
  Author: Pat Daderko
  Release Date: November 28th, 2009

#### Emulators

* Mednafen 
  Version: 0.9.31 WIP
  Author: Mednafen

* Reality Boy
  Version: 0.84
  Author: David Tucker, Pat Daderko
  Release Date: December 9th, 2008

#### Graphics

* Grit for VB
  Version: 0.8.6
  Author: cearn, dasi (VB patches)
  Release Date: June 6th, 2010

* Stereo Sprite Helper
  Version: 1
  Author: KR155E
  Release Date: October 20th, 2013

* Virtual Boy multiple BMP to BGMap/charset converter
  Version: 1
  Author: Matej Horvat
  Release Date: January 26th, 2013

* Virtual-Environment
  Version: 1.2
  Author: Alberto Covarrubias
  Release Date: January 9th, 2001

#### ROM

* FlashBoy
  Version: 20101102 (for use with FlashBoy Plus)
  Author: Richard Hutchinson
  Release Date: November 2nd, 2010

* Virtual Boy ROM Padder
  Version: 1.0
  Author: Pat Daderko
  Release Date: September 11th, 2007

* VBid - The VB ROM-image Tagger
  Version: 1.0
  Author: Runnerpack
  Release Date: August 8th, 2010

### Documentation

* VB Sacred Tech Scroll - Virtual Boy Specifications

* VBJaEngine Development Manual


// EOF