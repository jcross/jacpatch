JACPATCH This is a patch to allow the 1.4 full version of Wolfenstein 3D to run on a NEC v20. The patch is nearly identical to the shareware version except that the file size is different. This is the file size I found both in the Steam copy and in some other less reputable sources.
WOLF3D.EXE
108779
; JNZ 0x09 -> JMP 0x09
; This basically turns the failing conditional 286 check
; into an unconditional jump.
; It's pretty similar to the God of Thunder fix.
; Except that compression made it harder to find.
59
79 0a
eb 0a
