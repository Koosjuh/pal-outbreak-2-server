FUNCTION FUN_005ec6d0 @ 0x005ec6d0  size=304
CALLERS (3): FUN_005eba50@0x005eba50, FUN_005e9bd0@0x005e9bd0, FUN_005eaad0@0x005eaad0
CALLEES (0): 
----------------------------------------------------------------

int FUN_005ec6d0(byte *param_1,long param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = func_0x0010a050();
  iVar4 = 0;
  if (param_1[iVar2 + -1] == 0x25) {
    for (iVar3 = 0; iVar3 < iVar2 + -1; iVar3 = iVar3 + 1) {
      bVar1 = *param_1;
      if ((bVar1 < 0x3a) && (0x2f < bVar1)) {
        iVar4 = iVar4 * 10 + (bVar1 - 0x30);
      }
      param_1 = param_1 + 1;
    }
    if (param_2 == 0) {
      iVar4 = iVar4 * 0x248;
    }
    else {
      iVar4 = (int)param_2 * iVar4;
    }
    iVar4 = iVar4 / 100;
  }
  else {
    for (iVar3 = 0; iVar3 < iVar2; iVar3 = iVar3 + 1) {
      bVar1 = *param_1;
      if ((bVar1 < 0x3a) && (0x2f < bVar1)) {
        iVar4 = iVar4 * 10 + (bVar1 - 0x30);
      }
      param_1 = param_1 + 1;
    }
  }
  return iVar4;
}



================================================================