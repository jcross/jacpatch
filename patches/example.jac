JACPATCH This is an example patch made by James Cross. It allows the DOS game God of Thunder to run on a NEC v20. It's largely redundant with got.jac.
GOT.EXE
389305
; JNZ 0x09 -> JMP 0x09
; This basically turns the failing conditional 286 check
; into an unconditional jump.
; Segment 0 starts at 0d 20. Our code is at seg0:00 32.
; 0d 20 + 00 32 = 0d 52
0d 52
09 79
09 eb
