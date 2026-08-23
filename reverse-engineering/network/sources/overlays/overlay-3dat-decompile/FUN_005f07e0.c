FUNCTION FUN_005f07e0 @ 0x005f07e0  size=220
CALLERS (1): FUN_005f0a10@0x005f0a10
CALLEES (0): 
----------------------------------------------------------------

int FUN_005f07e0(int *param_1)

{
  ushort uVar1;
  int iVar2;
  
  if (*(char *)(iRam007012a0 + 0x186) == -10) {
    iVar2 = *param_1;
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else if (*(char *)(iVar2 + 0x4d) == '\0') {
      iVar2 = 0;
    }
    else if (*(int *)(iVar2 + 4) == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(*(int *)(iVar2 + 4) + 0xc);
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else {
        do {
          if (*(char *)(iVar2 + 0x4c) == (char)param_1[0x13]) {
            if (1 < *(byte *)(iVar2 + 0x48)) {
              return iVar2;
            }
            return 0;
          }
          iVar2 = *(int *)(iVar2 + 8);
        } while (iVar2 != 0);
        iVar2 = 0;
      }
    }
  }
  else {
    uVar1 = *(ushort *)((int)param_1 + 0x36);
    if (uVar1 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = iRam007012a0 + ((uint)uVar1 * 0x18 - (uint)uVar1) * 4 + 0x24e0;
    }
  }
  return iVar2;
}



================================================================