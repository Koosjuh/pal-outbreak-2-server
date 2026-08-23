FUNCTION FUN_00001198 @ 0x00001198 size=236
CALLERS (3): FUN_00005e78@0x00005e78, FUN_000020b0@0x000020b0, FUN_00008614@0x00008614
CALLEES (6): FUN_000092cc@0x000092cc, FUN_000094b8@0x000094b8, FUN_00008ddc@0x00008ddc, FUN_00009470@0x00009470, FUN_000091c8@0x000091c8, FUN_00009028@0x00009028

int FUN_00001198(undefined4 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = FUN_00008ddc(param_1,1,0);
  if (iVar1 < 0) {
    if (iVar1 == -5) {
      return -0x12;
    }
    return -3;
  }
  iVar2 = FUN_000092cc(iVar1);
  if (-1 < iVar2) {
    iVar3 = FUN_00009470(iVar2 + 1);
    *param_2 = iVar3;
    if (iVar3 == 0) {
      FUN_000091c8(iVar1);
      return -2;
    }
    iVar2 = FUN_00009028(iVar1,iVar3,iVar2);
    if (iVar2 < 0) {
      FUN_000094b8(*param_2);
      FUN_000091c8(iVar1);
      if (iVar2 == -5) {
        return -0x12;
      }
      return -4;
    }
    *(undefined1 *)(*param_2 + iVar2) = 0;
  }
  FUN_000091c8(iVar1);
  return iVar2;
}


================================================================