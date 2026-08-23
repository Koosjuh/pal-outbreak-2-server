FUNCTION FUN_005eced0 @ 0x005eced0  size=76
CALLERS (5): FUN_005ecf20@0x005ecf20, FUN_005ed530@0x005ed530, FUN_005ee010@0x005ee010, FUN_005ee610@0x005ee610, FUN_005ed0c0@0x005ed0c0
CALLEES (0): 
----------------------------------------------------------------

uint FUN_005eced0(ushort *param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (*(char *)(iRam007012a0 + 0x14) != '\0') {
    iVar1 = (uint)*(ushort *)(iRam007012a0 + 0x10) - (uint)*(ushort *)(iRam007012a0 + 0x12);
    if ((int)(uint)*param_1 < iVar1) {
      iVar1 = iVar1 - (uint)*param_1;
      uVar2 = iVar1 >> 1;
      if (iVar1 < 0) {
        uVar2 = iVar1 + 1 >> 1;
      }
    }
  }
  return uVar2 & 0xffff;
}



================================================================