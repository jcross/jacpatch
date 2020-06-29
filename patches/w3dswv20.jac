JACPATCH This is a patch to allow the 1.4 shareware version of Wolfenstein 3D to run on a NEC v20.
WOLF3D.EXE
109959
; JNZ 0x0a -> JMP 0x0a
; This basically turns the failing conditional 286 check
; into an unconditional jump.
; It's pretty similar to the God of Thunder fix.
; Except that compression made it harder to find.
59
79 0a
eb 0a
