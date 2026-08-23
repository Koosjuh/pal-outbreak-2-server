FUNCTION FUN_005ef780 @ 0x005ef780  size=196
CALLERS (14): FUN_005f3230@0x005f3230, FUN_005f3150@0x005f3150, FUN_005f3cc0@0x005f3cc0, FUN_005f2450@0x005f2450, FUN_005f39d0@0x005f39d0, FUN_005e8c10@0x005e8c10, FUN_005ea190@0x005ea190, FUN_005e8750@0x005e8750, FUN_005ecf20@0x005ecf20, FUN_005f3bc0@0x005f3bc0, FUN_005ebd20@0x005ebd20, FUN_005f0340@0x005f0340, ...
CALLEES (0): 
----------------------------------------------------------------

void FUN_005ef780(int param_1)

{
  ushort uVar1;
  undefined2 uVar2;
  int iVar3;
  
  if ((*(byte *)(param_1 + 0x50) & 1) == 0) {
    iVar3 = iRam007012a0 + (uint)*(ushort *)(iRam007012a0 + 0x188) * 4;
    if (*(char *)(iRam007012a0 + 0x186) == '\0') {
      *(undefined2 *)(param_1 + 0x3a) = 0;
      uVar1 = *(ushort *)(iVar3 + 0x1540);
      iVar3 = (uint)*(ushort *)(iRam007012a0 + 0xd8dc) - (uint)*(ushort *)(param_1 + 0x3e);
      if ((int)(uint)uVar1 < iVar3) {
        if (((*(char *)(param_1 + 0x4a) == '\x02') || (*(char *)(param_1 + 0x51) != '\0')) ||
           (*(char *)(param_1 + 0x1b) == '\x03')) {
          iVar3 = iVar3 - (uint)uVar1;
          uVar2 = (undefined2)(iVar3 >> 1);
          if (iVar3 < 0) {
            uVar2 = (undefined2)(iVar3 + 1 >> 1);
          }
          *(undefined2 *)(param_1 + 0x3a) = uVar2;
        }
        else if (*(char *)(param_1 + 0x4a) == '\x03') {
          *(ushort *)(param_1 + 0x3a) = (short)iVar3 - uVar1;
        }
      }
    }
  }
  else {
    *(undefined2 *)(param_1 + 0x3a) = 0;
  }
  return;
}



================================================================