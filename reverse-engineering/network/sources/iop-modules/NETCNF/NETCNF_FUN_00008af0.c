FUNCTION FUN_00008af0 @ 0x00008af0 size=124
CALLERS (1): FUN_000092cc@0x000092cc
CALLEES (1): FUN_000096a4@0x000096a4

int FUN_00008af0(undefined4 param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = FUN_000096a4(param_1,0,2);
  if (iVar2 < 0) {
    bVar1 = iVar2 != -5;
    iVar2 = -0x12;
    if (bVar1) {
      iVar2 = -6;
    }
  }
  else {
    iVar3 = FUN_000096a4(param_1,0,0);
    if ((iVar3 < 0) && (iVar2 = -0x12, iVar3 != -5)) {
      iVar2 = -6;
    }
  }
  return iVar2;
}


================================================================