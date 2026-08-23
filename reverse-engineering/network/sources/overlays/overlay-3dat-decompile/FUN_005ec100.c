FUNCTION FUN_005ec100 @ 0x005ec100  size=100
CALLERS (10): FUN_005ef220@0x005ef220, FUN_005ef380@0x005ef380, FUN_005ef3f0@0x005ef3f0, FUN_005e8600@0x005e8600, FUN_005e8580@0x005e8580, FUN_005ebd20@0x005ebd20, FUN_005eb5a0@0x005eb5a0, FUN_005eb640@0x005eb640, FUN_005ea900@0x005ea900, FUN_005e7710@0x005e7710
CALLEES (0): 
----------------------------------------------------------------

void FUN_005ec100(uint param_1)

{
  int iVar1;
  
  iVar1 = (param_1 & 0xff) * 8;
  *(undefined1 *)(iRam007012a0 + 0x180) =
       *(undefined1 *)
        ((uint)*(byte *)(*(short *)(iRam007012a0 + 0x124) + iRam007012a0 + 0x168) + iVar1 + 0x6494c0
        );
  *(undefined1 *)(iRam007012a0 + 0x181) =
       *(undefined1 *)
        ((uint)*(byte *)(*(short *)(iRam007012a0 + 0x124) + iRam007012a0 + 0x168) + iVar1 + 0x6494d0
        );
  return;
}



================================================================