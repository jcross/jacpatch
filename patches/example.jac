; Comment test.
JACPATCH This is an example patch made. The first patch fixes God of Thunder to work on a NEC v20.
; Comment test.
GOT.EXE
; Comment test.
389305
; JNZ 0x09 -> JMP 0x09
; This basically turns the failing conditional 286 check
; into an unconditional jump.
; Segment 0 starts at 0d 20. Our code is at seg0:00 32.
; 0d 20 + 00 32 = 0d 52
0d 52
79 09
eb 09
; Start a new file.
JACPATCH This part of the example changes a file that says "Derp!" to say "Ferp!"
derp.txt
6
00
44
46
