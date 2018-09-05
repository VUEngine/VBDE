+---------------------------------------------------------------------------------------------------------+
|                                                                                                         |
|                         ____     ____  __________    __________    ___________                          |
|                         @@@@     @@@@  @@@@@@@@@@__  @@@@@@@@@@__  @@@@@@@@@@@                          |
|                         @@@@     @@@@  @@@@    @@@@  @@@@    @@@@  @@@@                                 |
|                         @@@@     @@@@  @@@@____@@@@  @@@@    @@@@  @@@@_____                            |
|                         @@@@     @@@@  @@@@@@@@@@__  @@@@    @@@@  @@@@@@@@@                            |
|                         @@@@_   _@@@@  @@@@    @@@@  @@@@    @@@@  @@@@                                 |
|                           @@@___@@@    @@@@____@@@@  @@@@____@@@@  @@@@_______                          |
|                             @@@@@      @@@@@@@@@@    @@@@@@@@@@    @@@@@@@@@@@                          |
|                                                                                                         |
|                               VBDE - Virtual Boy Development Environment                                |
|                                   Version 1.3.0 - September 6th, 2018                                   |
|                                                                                                         |
|                                                                                                         |
+---------------------------------------------------------------------------------------------------------+

+---------------------------------------------------------------------------------------------------------+
| (00) Contents                                                                                           |
+---------------------------------------------------------------------------------------------------------+

  (01) Introduction
  (02) Usage
  (03) Bundled Libraries
  (04) Bundled Sample Projects
  (05) Bundled Tools
  (06) Changelog


+---------------------------------------------------------------------------------------------------------+
| (01) Introduction                                                                                       |
+---------------------------------------------------------------------------------------------------------+

  VBDE is a complete, portable Nintendo Virtual Boy development environment for Windows.
  Only download, unzip and start working. No installation, no hassle.


+---------------------------------------------------------------------------------------------------------+
| (02) Usage                                                                                              |
+---------------------------------------------------------------------------------------------------------+

  o Setup

    No installation or any extra steps are required. Just download, unzip and you're ready to start
    developing for the Virtual Boy.
    
    VBDE is fully portable and can run from anywhere. Just make sure the root directory is called "vbde".

    VBDE comes with a current portable version of Notepad++ that has been pre-configured with selected
    plugins and slightly modified to have a button bar on top. With these buttons, you can quickly compile
    the current project, run the compiled ROM in an emulator, convert images, etc.

    VBDE is also available as a Pro version, which comes with a copy of IntelliJ IDEA Community Edition
    that has been modified and pre-configured for VB development. Note that, for the Pro version, VBDE has
    to be located in C:/vbde for all features to work out of the box.

  o Compiling and running

    Compiling a project is as simple as opening any project file and clicking the compile button. There's
    also buttons to automatically run the resulting ROM in an emulator.

    The pre-configured emulator key mapping is as follows:

    L-Trigger: G       (G)                       (H)        R-Trigger: H
                     ________                 ________
    Left D-Pad:     /   _    \_______________/    _   \     Right D-Pad:
    E, D, S, F     /  _|E|_        _____        _|I|_  \    I, K, J, L
                  |  |S o F|  _    \|||/    _  |J o L|  |
    Select: V     |   ¯|D|¯  (V) _  ¯¯¯  _ (M)  ¯|K|¯   |   A: M
    Start: B       \    ¯     ¯ (B)     (N) ¯     ¯    /    B: N
                    |      __    ¯       ¯    __      |
                    /     /  |               |  \     \
                   |      |  |  VIRTUAL BOY  |  |      |
                   |      |  |_______________|  |      |
                   |      |  |_______________|  |      |
                   |      |                     |      |
                   |      |                     |      |
                   |      |    Low Battery: W   |      |
                    \____/   (Reality Boy only)  \____/

  o Image conversion

    VBDE allows for hassle free, on-the-fly image conversion using grit. Supported formats are:
    PNG (recommended), BMP, GIF, PCX and JPG/JPEG.

    Images should use an indexed 4-color palette in the following order: Black, Dark Red, Medium Red,
    Light Red. Example palettes in various formats can be found in {VBDE}/system/palette/.

    In order to be detected and converted by the image conversion script, you also need a *.grit file of
    the same name as the image, which contains the conversion settings. You can find a number of example
    grit files in {VBDE}/system/tools/vuengine-tools/templates/grit which you can just copy and paste
    (and rename) into your images folder.

    You can also make several files convert at once instead of having all images converted individually.
    Grit files which do not directly relate to an image file through their name, are applied to all images
    files in the current directory (not sub-directories.) This is useful for generating maps with shared
    tilesets.

    Example file structure:
    my-project/
      '- assets/
        '- images/
          |- backgrounds/
          |  |- Backgrounds.grit
          |  |- Background-1.png
          |  '- Background-2.png
          |- Font.grit
          |- Font.png
          |- Hero.grit
          '- Hero.png

    Finally, to start the image conversion, press the editor's grit button. This will convert all images
    that do not yet have a corresponding c file or are newer than their c file.

  o Stage conversion

    [tbd]

  o Custom editors

    The buttons of the VBDE default editor simply trigger a bunch of batch files, which you can just as
    well start from the command line or any other editor of choice.

    - EDIT images with ASEPRITE:
      {VBDE}/system/batch/aseprite.bat
    - Start VIDE:
      {VBDE}/system/batch/vide.bat
    - CONVERT images with GRIT:
      {VBDE}/system/batch/grit.bat {CURRENT_DIRECTORY}
    - CONVERT Tiled stages:
      {VBDE}/system/batch/tmx-converter.bat {CURRENT_DIRECTORY}
    - COMPILE with gccVB:
      {VBDE}/system/batch/build.bat {CURRENT_DIRECTORY} {CURRENT_FILENAME_WITHOUT_EXTENSION}
    - COMPILE with gccVB and RUN in Mednafen:
      {VBDE}/system/batch/build.bat {CURRENT_DIRECTORY} {CURRENT_FILENAME_WITHOUT_EXTENSION} mednafen
    - COMPILE with gccVB and RUN in Reality Boy:
      {VBDE}/system/batch/build.bat {CURRENT_DIRECTORY} {CURRENT_FILENAME_WITHOUT_EXTENSION} reality_boy
    - RUN in Mednafen:
      {VBDE}/system/batch/mednafen.bat {CURRENT_DIRECTORY}
    - RUN in Reality Boy:
      {VBDE}/system/batch/reality_boy.bat {CURRENT_DIRECTORY}
    - DEBUG with Reality Boy:
      {VBDE}/system/batch/reality_boy_debug.bat {CURRENT_DIRECTORY}
    - FLASH to FlashBoy:
      {VBDE}/system/batch/flash.bat {CURRENT_DIRECTORY}


+---------------------------------------------------------------------------------------------------------+
| (03) Bundled Libraries                                                                                  |
+---------------------------------------------------------------------------------------------------------+

  o libgccvb
    Description: The default gccVB library.
    Location: {VBDE}/libs/libgccvb/
    Authors: various

  o VUEngine
    Description: A powerful, versatile object-oriented Virtual Boy game engine.
    Location: {VBDE}/libs/vuengine/
    Authors: jorgeche, KR155E


+---------------------------------------------------------------------------------------------------------+
| (04) Bundled Sample Projects                                                                            |
+---------------------------------------------------------------------------------------------------------+

  VBDE comes with a few sample projects you can use to test VBDE functionality, for reference or as a
  boilerplate for your own project.

  o libgccvb

    - Barebone Demo
      Description: Barebone code that can be used as a starting point for your own VB project.
      Location: {VBDE}/samples/libgccvb/barebone/
      Author: KR155E

    - Beginner Samples
      Description: A total of 6 simple VB demos which introduce you to various aspects of VB development.
      Location: {VBDE}/samples/libgccvb/demos/*
      Author: Fwirt

    - Game of Life VB
      Description: A sample implementation of Conway's Game of Life.
      Location: {VBDE}/samples/libgccvb/game-of-life/
      Author: KR155E

  o VUEngine

    - VUEngine Barebone
      Description: A barebone VUEngine project that can be used as a starting point for your own project.
      Location: {VBDE}/samples/vuengine/barebone/
      Authors: jorgeche, KR155E

    - VUEngine Platformer Demo
      Description: A platform game demo which demonstrates usage and features of the VUEngine.
      Location: {VBDE}/samples/vuengine/platformer/
      Authors: jorgeche, KR155E

    - VUE-MASTER
      Description: A stereo image viewer template including a demo reel which you can replace with your
                   own images.
      Location: {VBDE}/samples/vuengine/vue-master/
      Authors: STEREO BOY, KR155E


+---------------------------------------------------------------------------------------------------------+
| (05) Bundled Tools                                                                                      |
+---------------------------------------------------------------------------------------------------------+

  o Environment

    - MSYS32

  o Editor

    - Notepad++ v6.8.8, pre-configured with several useful plugins
    - IntelliJ IDEA 2018.2.3 Community Edition, pre-configured with several useful plugins, templates,
      etc. (Pro version only)

  o Compiler

    - GCC 4.7 patched for Virtual Boy (gccVB)
      Author: ElmerPCFX, various

  o Tools

    - Audio

      - Midi2VB
        Author: thunderstruck
        Release Date: March 7th, 2012

      - Midi Converter
        Release Date: April 15th, 2013
        Author: thunderstruck

      - Virtual Boy Sound Generator
        Version: 1.1
        Author: Pat Daderko
        Release Date: February 1st, 2010

      - Virtual Boy WAV converter
        Version: 1.0
        Author: Pat Daderko
        Release Date: November 28th, 2009

    - Emulators

      - Mednafen
        Version: 1.21.3
        Author: Mednafen
        Release Date: April 29th, 2018

      - Reality Boy
        Version: 0.84
        Authors: David Tucker, Pat Daderko
        Release Date: December 9th, 2008

    - Graphics

      - Grit for VB
        Version: 0.8.6
        Author: Jasper Vijn, dasi (VB patches)
        Release Date: June 6th, 2010

      - Aseprite
        Version: 0.9.5
        Author: David Capello
        Release Date: August 25th, 2012
        Description: Animated sprite editor & pixel art tool. This is the last free version. If you like
          it, please consider buying the much improved latest version from http://www.aseprite.org.

      - Stereo Sprite Helper
        Version: 1
        Author: KR155E
        Release Date: October 20th, 2013

      - Virtual Boy multiple BMP to BGMap/charset converter
        Version: 1
        Author: Matej Horvat
        Release Date: January 26th, 2013

      - Virtual-Environment
        Version: 1.2
        Author: Alberto Covarrubias
        Release Date: January 9th, 2001

    - ROM

      - FlashBoy
        Version: 20101102 (for use with FlashBoy Plus)
        Author: Richard Hutchinson
        Release Date: November 2nd, 2010

      - Virtual Boy ROM Padder
        Version: 1.0
        Author: Pat Daderko
        Release Date: September 11th, 2007

      - VBid - The VB ROM-image Tagger
        Version: 1.0
        Author: RunnerPack
        Release Date: August 8th, 2010

  o Documentation

    - VB Sacred Tech Scroll - Virtual Boy Specifications
      Version: Version 0.91 (WIP)
      Description: The most complete and accurate Virtual Boy hardware documentation. Note that this
        document uses different terminology than libgccvb.
      Author: Guy Perfect
      Release Date: January 4th, 2013

    - VUEngine Development Manual
      Description: VUEngine Documentation.
      Authors: jorgeche, KR155E

  o Other

    - VUEngine Tools
      Description: Script that converts a Tiled (http://www.mapeditor.org/) map to a VUEngine Stage.
      Version: 0.1
      Authors: KR155E


+---------------------------------------------------------------------------------------------------------+
| (06) Changelog                                                                                          |
+---------------------------------------------------------------------------------------------------------+

  o 1.3.0, September 6th, 2018
    - [Pro] Updated IDEA to 2018.2.3
    - Updated Mednafen to 1.21.3
    - Updated VUEngine and its demo projects to version 6.0
    - [Pro] New feature: VUEngine templates (Live and Files)
    - Changed some folder names
    - New lib: VUEngine plugin library

  o 1.2.2, February 18th, 2018
    - [Pro] Updated IDEA to 2017.3.4
    - Updated Mednafen to 0.9.48
    - Updated VUEngine as well as its Barebone and Platformer Demo to v5.2
    - Added an additional VUEngine sample project: VUE-MASTER

  o 1.2.1, October 15th, 2017
    - [Pro] Updated IDEA to 2017.1
    - Condensed toolbar
    - [Pro] New toolbar button icons
    - [Pro] Made compiler output clickable
    - Bugfix: default makefile caused build folder to be nested into itself recursively
    - Bugfix: libgccvb projects were not setting up the column table and thus not ran on hardware
    - Rewrote batch files so that images and stages no longer have to reside in assets/images/ and
      assets/stages/, but can be anywhere under the project root
    - Extended conversion tools to support VUEngine's new "__ANIMATED_SINGLE_OPTIMIZED" animation type
    - Updated Mednafen to 0.9.43
    - New launcher by thunderstruck
    - Updated VUEngine as well as its Barebone and Platformer Demo to v5.1

  o 1.2.0, March 12th, 2017
    - Updated gcc to 4.7 with patches by ElmerPCFX; now using MSYS instead of Cygwin
    - [Pro] Updated IDEA to 2016.3.5
    - [Pro] Removed C/C++ IDEA plugin since it was causing slow-downs and broke auto-completion
    - The VBJaEngine has been renamed to VUEngine and updated to version 5.0, including its Barebone and
      Platformer Demo
    - Added script for converting Tiled (http://www.mapeditor.org/) maps to VUEngine stages

  o 1.1.0, March 3rd, 2016
    - Massively reduced package size by removing unneeded files from cygwin directory
    - Made VBDE fully portable by removing remaining hardcoded paths from Notepad++ directory
    - Added script to initialize user folder on first run
    - Fixed and reduced Notepad++ toolbar
    - Added Aseprite graphics editor
    - Updated VBJaEngine as well as its Barebone and Platformer Demo to v4.0 final
    - VBDE now also available as "Pro" edition, bundled with IntelliJ IDEA and Git

  o 1.0.1, January 5th, 2016
    - Updated Notepad++ from v6.8.6 Minimalist to a pre-configured v6.8.8 with several useful plugins
    - Added new button "Debug in Reality Boy"
    - Updated VBJaEngine as well as its Barebone and Platformer Demo to v4.0 beta 2

  o 1.0.0, November 29th, 2015
    Initial release


+---------------------------------------------------------------------------------------------------------+
| EOF                                                                                                     |
+---------------------------------------------------------------------------------------------------------+
