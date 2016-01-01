f0dder's Notepad++ plugins, released as part of the DonationCoder.com NANY 2009
challenge (see http://www.donationcoder.com/Forums/bb/index.php?board=273.0).

Version 1.1, released Januray 14th, 2009
Contact: http://f0dder.dcmembers.com/npp_plugins/ - <f0dder@flork.dk>

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Included plugins
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
GuidGuard: a plugin that generates C++ style header include guards, using GUIDs
for the guard identifier - this ensures you won't have identifier clashes even
in larger projects, which traditional filename-based guards theoretically risk.

Switcher: a plugin to switch between 'associated' files. Currently it handles
switching between asm<>inc, cpp<>h, cc<>h and c<>h. Useful when assigned to a
hotkey. Can also be used to open file based on the current word the cursor is
located at in editor (no support for C/C++-style <filename> %INCLUDE% searching
yet, though).

RegRexPlace: a plugin to do "regular regular-expression replaces". Useful when
you have often-used regex replacements. I personally use this when writing posts
on forums, so I can use my own simplified markup and automatically generated
BBCode markup from that. A sample .ini file is included.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Installation information
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Copy the desired plugin DLLs to your Notepad++ plugins folder - plugins are
supplied in both ANSI and UNICODE builds. Create (or copy the supplied version)
RegRexPlace.ini to your Notepad++ config folder.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
TODO
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Switcher currently has hardcoded file extensions, this needs to be user
configurable. The switching logic also needs to be improved, to better handle
the cases where multiple file extensions share a common "switch-to" extension,
ie., .h<>{.c, .cc, .cpp} - currently .cpp is preferred, which will result in a
"file doesn't exist, create?" even if a .c or .cc fiel exists.

RegRexPlace needs some revamping as well - it needs a GUI for configuration, as
well as being able to handle multiple substitution groups (right now all items
from the config file are blindly applied). Ultimately, I want to handle a list
of {regex, replacement} pairs, as well as a list of groups that can reference
one or more of the pairs.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
HISTORY
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Version 1.1, released Januray 14th, 2009
	+ switcher now has "open file from word in editor" function
Version 1.0, released December 31st, 2008
	- initial release
