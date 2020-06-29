# jacpatch
A tool for making stand-alone binary patch programs that will run under 16-bit DOS or most Linux environments.

# Existing patches.
Pre-made 16-bit DOS binaries live [here](https://github.com/jcross/jacpatch/releases/tag/DOSBinaries/) for your convenience.

* [**gotv20.jac**](https://github.com/jcross/jacpatch/blob/master/patches/gotv20.jac) - Patches the freeware version of Adept Software's God of Thunder to run on a NEC v20. Performance is reasonable at 9.55 MHz but does bog down a bit on very active screens. If you don't have a copy, you can grab one for free from Adept Software [here](https://www.adeptsoftware.com/got/).
* [**w3dflv20.jac**](https://github.com/jcross/jacpatch/blob/master/patches/w3dflv20.jac) - Patches the 1.4 full version of Wolfenstein 3D to run on a NEC v20. Even at 9.55 MHZ with a 2MB EMS card, performance is pretty bad unless you shrink the size of the viewport quite a lot. Choose between a slideshow and postage stamp.
* [**w3dswv20.jac**](https://github.com/jcross/jacpatch/blob/master/patches/w3dswv20.jac) - Patches the 1.4 shareware version of Wolfenstein 3D to run on a NEC v20. The situation is similar to the full patch above.

# .jac format.
The patch files should be somewhat human readable.

Lines in this format are "\n" terminated.

Lines beginning with ";" are comments.

Line 1 should begin with "JACPATCH" and then, optionally, a helpful message about the patch.

Line 2 is the name of the target file (case sensitivity?)

Example: GOT.EXE

Line 3 is the size of target file. If the target file available does not have the same size, it's probably not the version that this patch applies to. Whoops. If we're not particular, this line may be left blank.

Example: 389305

Remaining lines should come in triplets (excluding comment lines) that define how the file should be modified while also doing some sanity checking.

Triplet[0] indicates a HEX offset in the file. Spaces between bytes are optional. Offsets are in specified using network byte order (Big Endian).

Example:
00 C4

Triplet[1] indicates what HEX bytes are expected at the offset. We should at least warn if we don't fine what we want. This line may be left blank if you like to live dangerously. The bytes provided do not need to be as long as the bytes being inserted for replacement.

Example:
79 09


Triplet[2] indicates the new bytes to be inserted at the offset specified in Triplet[0] in HEX format..

Example:
78 09

Triplets continue until either the end of the file or a new "JACPATCH" line is encountered. A new "JACPATCH" line indicates that we need to move on to a new file to modify.

See example.jac in the patches directory for a full example.
