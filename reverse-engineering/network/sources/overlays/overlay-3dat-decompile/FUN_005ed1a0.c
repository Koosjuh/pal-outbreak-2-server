FUNCTION FUN_005ed1a0 @ 0x005ed1a0  size=68
CALLERS (6): FUN_005f39d0@0x005f39d0, FUN_005eed40@0x005eed40, FUN_005ed460@0x005ed460, FUN_005ee840@0x005ee840, FUN_005f3230@0x005f3230, FUN_005f3310@0x005f3310
CALLEES (0): 
----------------------------------------------------------------

void FUN_005ed1a0(int *param_1)

{
  ushort uVar1;
  
  uVar1 = *(ushort *)(iRam007012a0 + 0x188);
  *(ushort *)(iRam007012a0 + 0x188) = uVar1 + 1;
  if (uVar1 < 999) {
    *param_1 = *param_1 + 4;
  }
  else {
    *(undefined2 *)(iRam007012a0 + 0x188) = 999;
  }
  return;
}



================================================================