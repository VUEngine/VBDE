Virtual Boy multiple BMP to BGMap/charset converter
Version 1

by Matej Horvat
January 26, 2013

*** Introduction ***

  There have been many utilities written over time to convert graphics to the
  charset and BGMap formats used on the Virtual Boy. However, they are either
  poorly documented and hard to use or they have little or no support for
  BGMaps, forcing programmers to use inefficient ways of storing graphics,
  like having a separate charset for each BGMap.

  This program, however, can take multiple BMP files at once and convert them
  to BGMaps that all share the same charset, with the charset only containing
  as many characters as needed to conserve space and the BGMaps only
  containing as many tiles as needed, not all 64 by 64.

  Currently, only 24-bit BMP files are supported, but other than that, it
  can take nearly any graphic with little or no adjustments.

*** General usage ***

  VBIMGC is a Windows command line program. The command line parameters are
  specified as follows:

    VBIMGC options outChrFile bmpFiles

  Valid options are:
    /C r0 r1 r2 r3
      Defines the red component of the color values. The green and blue
      components are ignored. If a pixel's red component is not one of those
      values, the first smaller value will be used. The default color values
      are 0, 128, 192, and 255.

    /EC
      Specifies that the generated charset is to be stored efficiently (see
      "Efficient storage"). By default, all 2048 characters will be stored,
      even if not all of them are used.

    /EM
      Specified that the generated BGMaps are to be stored efficiently (see
      "Efficient storage"). By default, all 4096 cells will be stored, even
      if the BMPs are smaller than 512 by 512 pixels.

    /XC chrNamePrefix bgmNamePrefix
      Specifies that the BMPs are to be converted to C header files. After
      this option, a charset name prefix and a BGMap name prefix must follow.
      For example, if a BMP's file name is "Test.bmp" and the charset and
      BGMap name prefixes are "kChr_" and "kBGM_" respectively, the generated
      array in "Test.h" that contains the BGMap will be named "kBGM_Test" and
      the charset it uses will be named "kChr_" followed by the charset's
      filename.

    /XB
      Specifies that the BMPs are to be converted to raw binary files.

  The options are followed by the filename of the charset that will be
  generated, and then a list of BMP files to convert, separated by spaces.
               
  For example, executing

    VBIMGC /EC /EM /XC kChr_ kBGM_ Test Test1 Test2

  will convert the files Test1.bmp and Test2.bmp to Test1.h and Test2.h with
  the charset Test.h. The charset array in Test.h will be named kChr_Test and
  the BGMaps arrays in Test1.h and Test2.h will be named kBGM_Test1 and
  kBGM_Test2. The charset and both BGMaps will be stored efficiently.

  The character indexes in the BGMap cells always begin at 0.

*** Efficient storage ***

  The "efficient" charset/BGMap format simply stores only as much data as
  needs to be stored. For simplicity, it does not use any actual compression.

  An efficient charset begins with a halfword (16-bit integer) that tells how
  many characters are to be loaded, followed by the actual character data.
  Here is a C function to load an efficiently stored charset:

    void LoadEfficientCharset (const u16* Src, u16* Dst)
    {
      u16 i;
      u16 Length;
    
      Length = Src[0] << 4;  // multiply by 16
      for(i = 0; i < Length; i++)
        Dst[i] = Src[i + 1];
    }

  An efficient BGMap begins with a halfword whose lower byte is the width of
  the BGMap and the higher byte is the height of the BGMap, followed by the
  actual BGMap character cells. Here is a C function to load an efficiently
  stored BGMap:

    void LoadEfficientBGMap (const u16* Src, u8 BGMap, u16 CharIndexBase)
    {
      u8 X;
      u8 Y;
      u8 Width;
      u8 Height;
      u16 Index;
    
      Width = Src[0] & 0x00FF;
      Height = Src[0] >> 8;
    
      Index = 1;
      for(Y = 0; Y < Height; Y++)
        for(X = 0; X < Width; X++)
          BGM_CSET(BGMap, X, Y, Src[Index++] + CharIndexBase);
    }

*** Credits ***

  The program was written by Matej Horvat ("HorvatM" on Planet Virtual Boy).

  Electronic mail: matej.horvat@guest.arnes.si
  Web site:        http://matejhorvat.si/
