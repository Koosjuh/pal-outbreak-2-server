FUNCTION FUN_0000663c @ 0x0000663c size=104
CALLERS (1): FUN_00005828@0x00005828
CALLEES (1): FUN_00001760@0x00001760

undefined4 FUN_0000663c(uint *param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  if (*param_1 != 0) {
    iVar2 = 8;
    do {
      FUN_00001760((int)param_1 + iVar2 + 4);
      uVar1 = uVar1 + 1;
      iVar2 = iVar2 + 0xc;
    } while (uVar1 < *param_1);
  }
  return 0;
}


================================================================