JACPATCH This is a patch to allow the September 3 1993 1.4 full version of Wolfenstein 3D to run on a NEC v20. It uses the same Borland check as the shareware version and God of Thunder. Unlike the shareware version we patch, however, this version of Wolfenstein 3D does not have a packed executable. Sadly, this specific version of Wolfenstein 3D is hard to find now. The versions you can buy from Steam and Good Old Games won't even run on actual 286 because they include 386 instructions. Shame on them!
WOLF3D.EXE
259310
; JNZ 0x0a -> JMP 0x0a
; This basically turns the failing conditional 286 check
; into an unconditional jump.
; It's pretty similar to the God of Thunder fix.
; Except that compression made it harder to find.
2c 32
79 0a
eb 0a
