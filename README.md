# jacpatch
A tool for making stand-alone binary patch programs that will run under DOS on x86 CPUs.

# .jacpatch format.
The patch files should be somewhat human readable.

Fields in this format are "\n" terminated.

Lines beginning with ";" are comments.

Line 1 should begin with "JACPATCH" and then, optionally, a helpful message about the patch.

Line 2 is the name of the target file (case sensitivity?)

Example: GOT.EXE

Line 3 is the md5 hash of the target file. If the target file available does not have the same hash, it's probably not the version that this patch applies to. Whoops. If we're not particular, this line may be left blank.

Example: d53b38c29d4fb8cdbbcb54c8435e4559

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
