FUNCTION FUN_005efa60 @ 0x005efa60  size=116
CALLERS (2): FUN_005ea900@0x005ea900, FUN_005eb7d0@0x005eb7d0
CALLEES (0): 
----------------------------------------------------------------

void FUN_005efa60(undefined8 param_1)

{
  byte bVar1;
  
  if (*(char *)(iRam007012a0 + 0x186) == '\0') {
    func_0x001069a8(iRam007012a0 + (uint)*(byte *)(iRam007012a0 + 0xe96a) * 0x100 + 0xd96a,param_1,
                    0x100);
    bVar1 = *(byte *)(iRam007012a0 + 0xe96a);
    if (bVar1 < 0xf) {
      *(byte *)(iRam007012a0 + 0xe96a) = bVar1 + 1;
    }
  }
  return;
}



================================================================