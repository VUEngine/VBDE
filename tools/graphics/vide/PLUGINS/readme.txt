Advanced map editor for VIDE
============================
Created by DanB
Released on May 13 2008

While waiting for the all new VIDE version, and to help kicking off the coding competition on vr32.de,
I'm releasing my latest creation: The "Advanced map editor" plugin for VIDE 1.2.

It fixes most of the issues I've personally had with the built-in editor, and adds some new
features I thought up along the way ;)

Here's what it does:
--------------------

  -Select/copy/paste/flip large areas at once
  -Fill large areas with a single tile, or with a repeating pattern of tiles
  -Delete cells on the map
  -Remembers the flip state when copy/pasting a tile (major flaw in the original editor :P)
  -Set the palette to be used for individual map cells
  -Play around with the different palette configurations to see the effect it will have
  -Keyboard hotkeys for all (most) options
  -Set the unused bit 11 of each map cell. I figured it can be used as a flag for starting positions
   of objects/enemies or for map collision detection or whatever. Even if it's unreliable after copied
   to bg ram, you can still always read it from your rom map...
  -Options to easily see which cells are flipped/have a different palette/are flagged
  -As you move around the map, the current tile can be highlighted in the charmap below, so you can
   easily find which char is used.
  -'Replace all' option. Copy and paste a single tile, and all other cells using that same tile will be
   modyfied as well.
  -Unlimited undo steps for all map modifications
  -Animation preview. Set up a sub-sequence of tiles for any char on the charmap, adjust the
   timer interval in ms, and watch the action as it would look on the VB!
  -Complete source code (ugly, but well-commented) is included as a Visual Studio 2008 project
  -I'm also including all source code for my previous VIDE plugins (*AS IS*)

Notes on usage:
---------------

To "install", just copy advmap.vpg to your VIDE/plugins folder.

Since the VIDE plugin system only allows access to either a charset or a charmap (not both) at one time,
you have to first run the plugin on the charset you're using, and then on the map you want to edit.

The paste tool
--------------

You can copy and paste an area of the map of any size. No matter how small the selection is that you
paste into, the entire clip you copied will be pasted in its full at that location. (There is no floating selection, sorry :P)

However, if you paste your clip into a selection that is both wider and taller than the source clip,
the pattern will be repeated to completly fill out the new selection. You can use this as a "fill" tool
to quickly fill an area with a single tile, or a pattern of tiles.

The replace all tool
--------------------
This tool is useful if you need to move around tiles in a charset but don't want to break an existing map.
First copy a single tile (or if a larger selection, the tile in the top-left corner will be used).

Then place the cursor on another single tile you want to replace (again, top-left corner if larger selection).
Now when pasting, all tiles on the entire map that uses the same tile as the one you selected will be replaced
by the tile that you paste.

Animation preview
-----------------

The animation preview is accomplished in the same way that is most common and effective to use in an actual game;
Don't edit the map data itself, but instead just update the underlying tiles. That way, you only have to update
a single flower tile to animate a whole field of flowers, for instance :)

So, simply click on a tile on the map. The tile in use will be automatically selected in the charset below
(unless you've turned off the "follow map" option).

Now the animation sequence for that tile will be shown in the list to the left. Simply right-click on other
tiles in the charset to add them to the animation. Double-clicks in the list will remove them again.

Other notes
-----------
The charset is in black and white partly to illustrate that it cant be edited (this is a map editor, dummy!),
but also to illustrate that a char in itself never contains any color shades, they are merely indexes to the palettes
you define. (Click on the palettes to see the effect of this)

To copy graphics between two maps, don't start two instances of this plugin from the same VIDE, you will get
unexpected results since they will use the same memory space. Instead open your project in two instances of VIDE
with one map editor in each, and it will work just fine. (If anyone knows how to fix this, source is included.)

Happy Designing!

/DanB

