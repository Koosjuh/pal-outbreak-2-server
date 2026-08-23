FUNCTION FUN_00600aa0 @ 0x00600aa0  size=180
CALLERS (1): FUN_00600b60@0x00600b60
CALLEES (0): 
----------------------------------------------------------------

uint FUN_00600aa0(uint param_1,long param_2)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = 0;
  uVar3 = param_1;
  do {
    if (param_2 == 0) {
      uVar3 = uVar3 - 1;
    }
    else {
      uVar3 = uVar3 + 1;
    }
    uVar3 = uVar3 & 3;
  } while (((*(char *)(uVar3 * 0x3b0 + 0x6c7c3c) == '\0') ||
           (lVar1 = func_0x00109d70(0x6c8afc,uVar3 * 0x3b0 + 0x6c7c3c), uVar4 = uVar3, lVar1 == 0))
          && (iVar2 = iVar2 + 1, uVar4 = param_1, iVar2 < 5));
  return uVar4;
}



================================================================