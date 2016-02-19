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
|  Version 1.1.0 - February 21st, 2016                               |
|                                                                    |
+====================================================================+

+--------------------------------------------------------------------+
| (00) Contents                                                      |
+--------------------------------------------------------------------+

  (01) Introduction
  (02) Usage
  (03) Bundled Libraries
  (04) Bundled Sample Projects
  (05) Bundled Tools
  (06) Changelog


+--------------------------------------------------------------------+
| (01) Introduction                                                  |
+--------------------------------------------------------------------+

  VBDE is a complete, portable Virtual Boy development environment for
  Windows. Only download, unzip and start working. No installation,
  no hassle.


+--------------------------------------------------------------------+
| (02) Usage                                                         |
+--------------------------------------------------------------------+

  o Setup

    No installation or any extra steps are required. Just download,
    unzip and you're ready to start developing for the Virtual Boy.

    Note: Previous versions needed to be placed in C:/vbde/. This is
    no longer necessary.

    VBDE comes with a current portable version of Notepad++ that has
    been pre-configured with selected plugins and slightly modified
    to have a button bar on top. With these buttons, you can quickly
    compile the current project, run the compiled ROM in an emulator,
    convert images, etc.

    VBDE is also available in a Pro edition, which comes with a copy
    of IntelliJ IDEA Community Edition, which has been modified and
    pre-configured for VB development.

  o Compiling and running

    Compiling a project is as simple as opening any project file and
    clicking the compile button. There's also buttons to automatically
    run the resulting ROM in an emulator.

    The key mapping is as follows:

    Left D-Pad (U, D, L, R): E, D, S, F
    Right D-Pad (U, D, L, R): I, K, J, L
    Left Trigger: G
    Right Trigger: H
    Select: V
    Start: B
    B: N
    A: M

    In addition, you can trigger a low battery signal by holding W
    (Reality Boy only).

  o Image conversion

    VBDE allows for hassle free, on-the-fly image conversion using
    grit. To use it, create a folder called "assets" in the root
    folder of your project, with a contained "images" folder. This
    folder will hold all your images in any of the supported
    formats: png, bmp, gif, pcx or jpg/jpeg (I recommend png.)

    Images should use an indexed 4-color palette in the following
    order: Black, Dark Red, Medium Red, Light Red. An example palette
    for Photoshop can be found in {VBDE}/system/grit/.

    In order to be detected and converted by the image conversion
    script, you also need a *.grit file of the same name as the
    graphic, which contains the conversion settings. You can find
    a number of example grit files in {VBDE}/system/grit/ which you
    can just copy and paste (and rename) into your images folder.

    You can also make several files convert at once instead of
    having all images converted individually. Grit files which do not
    directly relate to an image file through their name, are applied
    to all images files in the current directory (not sub-directories.)
    This is useful for generating maps with shared tilesets.

    Example file structure:
    my-project/
      '- assets/
        '- images/
          |- backgrounds/
          |  |- Backgrounds.grit
          |  |- Background-1.png
          |  '- Background-2.png
          |- Font.grit
          '- Font.png
          |- Hero.grit
          '- Hero.png

    Finally, to start the image conversion, press the editor's
    grit button while having any project file opened. This will
    convert all images that do not yet have a corresponding c file
    or are newer than their c file.

  o Custom editors

    The buttons of the VBDE default editor simply trigger a bunch of
    batch files, which you can just as well start from the command
    line or any other editor of choice.
    See {VBDE}/editors/npp/shortcuts.xml for how to call these.


+--------------------------------------------------------------------+
| (03) Bundled Libraries                                             |
+--------------------------------------------------------------------+

  o libgccvb
    Description: The default gccVB library.
    Authors: various

  o VBJaEngine
    Description: An advanced, object-oriented Virtual Boy game engine.
    Authors: jorgeche, KR155E


+--------------------------------------------------------------------+
| (04) Bundled Sample Projects                                       |
+--------------------------------------------------------------------+

  VBDE comes with a few sample projects you can use to test VBDE
  functionality, for reference or as a boilerplate for your own
  project.

  o libgccvb

    - Barebone Demo
      Description: Barebone code that can be used as a starting point
        for your own VB project.
      Location: {VBDE}/samples/libgccvb/barebone/
      Author: KR155E

    - Beginner Samples
      Description: A total of 6 simple Virtual Boy demos which
        introduce you to various aspects of Virtual Boy development.
      Location: {VBDE}/samples/libgccvb/demos/*
      Author: Fwirt

    - Game of Life VB
      Description: A sample implementation of Conway's Game of Life.
      Location: {VBDE}/samples/libgccvb/game-of-life/
      Author: KR155E

  o VBJaEngine

    - VBJaEngine Barebone
      Description: A barebone VBJaEngine project that can be used as a
        starting point for your own project.
      Location: {VBDE}/samples/vbjaengine/vbjaengine-barebone/
      Authors: jorgeche, KR155E

    - VBJaEngine Platformer Demo
      Description: A platform game demo which demonstrates usage and
        features of the VBJaEngine.
      Location: {VBDE}/samples/vbjaengine/vbjaengine-platformer-demo/
      Authors: jorgeche, KR155E


+--------------------------------------------------------------------+
| (05) Bundled Tools                                                 |
+--------------------------------------------------------------------+

  o Environment

    - Cygwin

  o Editor

    - Notepad++ v6.8.8, pre-configured with several useful plugins
    - IntelliJ IDEA 15.0.3 Community Edition, pre-configured with
      several useful plugins, templates, etc. (Pro version only)

  o Compiler

    - v810-gcc-4.4.2 patched for Virtual Boy (gccVB)

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
        Version: 0.9.38.7
        Author: Mednafen
        Release Date: October 1st, 2015

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
        Description: Animated sprite editor & pixel art tool.
          This is the last free version. If you like it, please
          consider buying the much improved latest version from
          http://www.aseprite.org.

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
      Description: The most complete and accurate Virtual Boy hardware
        documentation. Note that this document uses different
        terminology than libgccvb.
      Author: Guy Perfect
      Release Date: January 4th, 2013

    - VBJaEngine Development Manual
      Description: VBJaEngine Documentation. Note that this is a very
        incomplete WIP.
      Authors: jorgeche, KR155E


+--------------------------------------------------------------------+
| (06) Changelog                                                     |
+--------------------------------------------------------------------+

  o 1.1.0, February 21st, 2016
    - Massively reduced package size by removing unneeded files from
      cygwin directory
    - Made VBDE fully portable by removing remaining hardcoded paths
      from Notepad++ directory
    - Added script to initialize user folder on first run
    - Fixed and reduced Notepad++ toolbar
    - Added Aseprite graphics editor
    - Updated VBJaEngine as well as its Barebone and Platformer Demo
      to v4.0 final
    - VBDE now also available as "Pro" edition, bundled with IntelliJ
      IDEA and (Portable)GIT

  o 1.0.1, January 5th, 2016
    - Updated Notepad++ from v6.8.6 Minimalist to a pre-configured
      v6.8.8 with several useful plugins
    - Added new button "Debug in Reality Boy"
    - Updated VBJaEngine as well as its Barebone and Platformer Demo
      to v4.0 beta 2

  o 1.0.0, November 29th, 2015
    Initial release


+--------------------------------------------------------------------+
| EOF                                                                |
+--------------------------------------------------------------------+
