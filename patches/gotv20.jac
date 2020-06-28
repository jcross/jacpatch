JACPATCH This is a patch to allow the freeware version of God of Thunder to run on a NEC v20. If you have an older version or a shareware version, you can grab the freeware version here: https://www.adeptsoftware.com/got/
GOT.EXE
389305
; JNZ 0x09 -> JMP 0x09
; This basically turns the failing conditional 286 check
; into an unconditional jump.
; Segment 0 starts at 0d 20. Our code is at seg0:00 32.
; 0d 20 + 00 32 = 0d 52
0d 52
79 09
eb 09
