FUNCTION FUN_005ed160 @ 0x005ed160  size=52
CALLERS (4): FUN_005eacd0@0x005eacd0, FUN_005ed1f0@0x005ed1f0, FUN_005ebd20@0x005ebd20, FUN_005f2450@0x005f2450
CALLEES (0): 
----------------------------------------------------------------

void FUN_005ed160(void)

{
  ushort uVar1;
  
  uVar1 = *(ushort *)(iRam007012a0 + 0x188);
  *(ushort *)(iRam007012a0 + 0x188) = uVar1 + 1;
  if (0x3e6 < uVar1) {
    *(undefined2 *)(iRam007012a0 + 0x188) = 999;
  }
  return;
}



================================================================