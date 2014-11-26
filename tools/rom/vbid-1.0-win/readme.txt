VBid - The VB ROM-image Tagger
Copyright (c) 2010 Amos Bieler. All rights reserved.
See "license.txt" for license information.

The author can be contacted with any questions/comments at abieler@gmx.net.

1. What does it do?

VBid is a viewer/editor for the information block (i.e. the "header") found near the end of Nintendo(r) Virtual Boy(tm) ROM images. This information includes:

Address                         Content                 Size
----------                      ----------              ----------
0x07FF FDE0 - 0x07FF FDF4       Game Title              21 bytes (NULL-terminated string)
0x07FF FDF5 - 0x07FF FDF8       Reserved                4 bytes
0x07FF FDF9 - 0x07FF FDFA       Publisher ID Code       2 bytes (see list below)
0x07FF FDFB - 0x07FF FDFE       Game ID Code            4 bytes (see list below)
0x07FF FDFF                     ROM Version             1 byte


2. How do I use it?

To display the data currently in the ROM image, run the executable and only pass the ROM file name on the command-line, like so:

        vbid.exe game.vb

To change the ROM info block, specify the new data after the input file-name as command-line parameters.

Example:
        vbid.exe game.vb "MY GAME" - ME VMGE 0 my_game.vb

The above performs the following actions:

	1. Open the ROM file "game.vb"
	2. Set the game name field to "MY GAME" (without the quotes and zero-padded to 21 bytes)
	3. Leave the "reserved" data unchanged
	4. Set the publisher ID to the two letters "ME"
	5. Assign a game ID of "VMGE"
	6. Set the version byte to 0
	7. Write the changed ROM to "my_game.vb" in the current working directory

Here are the command-line options in detail:

name:   The name of the game; up to 20 characters long. Supports 8-bit ASCII and Shift-JIS.
rsvd:   The "reserved" DWORD; a 32-bit, signed integer. Holds any integer from -2,147,483,648 to 2,147,483,647.
pid:    The publisher ID. See below for details and a list.
gid:    The game ID. See below for details and a list.
ver:    The game version/release. Valid range: 0-255, inclusive.

Notes:
    * A dash (ASCII 0x2D) used in place of any option means to leave it unchanged.
    * If no output file-name is specified, the original file will be modified in-place.
    * Files are overwritten without warning, so be careful.
    * Uses C strings along with "PATH_MAX" and related constants, so try to keep filenames/paths on the short side.


3. List of Publisher IDs

Here's a list of all currently known publisher IDs. You should probably pick your own.
See: http://www.planetvb.com/modules/dokuwiki/doku.php?id=info_at_the_end_of_the_rom
for the latest list.
 ____________________________________________________________
|  ID  | Publisher                             | Type        |
|------+---------------------------------------+-------------|
|  01  | Nintendo                              | Licensed    |
|  0B  | Coconuts                              | Licensed    |
|  18  | Hudson Soft                           | Licensed    |
|  28  | Kemco (Japan)                         | Licensed    |
|  67  | Ocean                                 | Licensed    |
|  7F  | Kemco (America)                       | Licensed    |
|  8B  | Bullet-Proof Software                 | Licensed    |
|  8F  | I'Max                                 | Licensed    |
|  99  | Pack-in-Video                         | Licensed    |
|  AB  | Amos Bieler, aka RunnerPack           | Unlicensed  |
|  AE  | Aegis Games, aka VirtualChris         | Unlicensed  |
|  AH  | J-Wing                                | Licensed    |
|  B2  | Bandai                                | Licensed    |
|  C0  | Taito                                 | Licensed    |
|  CR  | Christian Radke, aka KR155E           | Unlicensed  |
|  DA  | Dan Bergman, aka DanB                 | Unlicensed  |
|  DB  | David Tucker                          | Unlicensed  |
|  DP  | Pat Daderko, aka DogP                 | Unlicensed  |
|  DW  | David Williamson, aka LameBoyAdvance  | Unlicensed  |
|  E4  | T&E Soft                              | Licensed    |
|  E7  | Athena                                | Licensed    |
|  EB  | Atlus                                 | Licensed    |
|  JA  | Jorge Andres Eremiev                  | Unlicensed  |
|  MH  | Matej Horvat, aka HorvatM             | Unlicensed  |
|  MK  | Martin Kujaczynski                    | Unlicensed  |
|  VE  | Alberto Covarrubias, aka Virtual-E    | Unlicensed  |
'------^---------------------------------------^-------------'


4. List of Game IDs

Each of your games should have a unique ID. Here's a list of all known game IDs. Again, the wiki has the latest.
 _______________________________________________________________________
|  ID  | Game                               | Type        | Status      |
|------+------------------------------------+-------------+-------------|
|  B2  | BLOX 2                             | Unlicensed  | Released    |
|  BH  | Bound High!                        | Licensed    | Unreleased  |
|  BX  | BLOX                               | Unlicensed  | Released    |
|  CD  | Castle of Doom                     | Unlicensed  | Released    |
|  DH  | Dragon Hopper                      | Licensed    | Unreleased  |
|  G2  | GoSub 2                            | Unlicensed  | Released    |
|  GD  | Glow Demo                          | Unlicensed  | Released    |
|  GO  | GoSub                              | Unlicensed  | Released    |
|  GP  | Galactic Pinball                   | Licensed    | Released    |
|  H2  | Panic Bomber                       | Licensed    | Released    |
|  H3  | Vertical Force                     | Licensed    | Released    |
|  IC  | Insect Combat                      | Unlicensed  | Released    |
|  IM  | Insmouse No Yakata                 | Licensed    | Released    |
|  JB  | Jack Bros.                         | Licensed    | Released    |
|  JV  | Virtual Lab                        | Licensed    | Released    |
|  MC  | Mario Clash                        | Licensed    | Released    |
|  MT  | Mario's Tennis                     | Licensed    | Released    |
|  NF  | Nester's Funky Bowling             | Licensed    | Released    |
|  NM  | Nice Mice                          | Unlicensed  | Released    |
|  PB  | 3D Tetris                          | Licensed    | Released    |
|  RE  | Red Alarm                          | Licensed    | Released    |
|  SD  | SD Gundam Dimension War            | Licensed    | Released    |
|  SF  | Super Fighter Demo                 | Unlicensed  | Released    |
|  SH  | Silent Hill: Devil's Lyric         | Unlicensed  | Released    |
|  SN  | VUE Snake                          | Unlicensed  | Released    |
|  SP  | Space Invaders Virtual Collection  | Licensed    | Released    |
|  SS  | Space Squash                       | Licensed    | Released    |
|  SU  | Soviet Union 2010                  | Unlicensed  | Released    |
|  TB  | Teleroboxer                        | Licensed    | Released    |
|  TR  | V-Tetris                           | Licensed    | Released    |
|  TT  | Tic-Tac-Toe 'Ten                   | Unlicensed  | Released    |
|  VB  | Virtual Bowling                    | Licensed    | Released    |
|  VF  | Virtual Fishing                    | Licensed    | Released    |
|  VG  | Golf                               | Licensed    | Released    |
|  VP  | Virtual League Baseball            | Licensed    | Released    |
|  VR  | VB Rocks! Demo                     | Unlicensed  | Released    |
|  WC  | Virtual Boy Wario Land             | Licensed    | Released    |
|  WD  | Water Demo                         | Unlicensed  | Released    |
|  WE  | Waterworld                         | Licensed    | Released    |
'------^------------------------------------^-------------^-------------'


5. Make your game ID into a model number.

This part is optional and doesn't really have anything to do with the ROM image. But, if you really want one...

Just take "VUE-V" + your game ID + a language code + "-" + a region code.

Language codes:
        J - Japanese
        E - English
        M - Multiple languages

Region codes:
        (Note, VB systems don't enforce any kind of region lock-out.)
        JPN - Japan
        USA - The United States of America
        PD  - Public Domain (is the interwebs a region? ;)

Example:
        VUE-VGPE-USA = Galactic Pinball (US)
