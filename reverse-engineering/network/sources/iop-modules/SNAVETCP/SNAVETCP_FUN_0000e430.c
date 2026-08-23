FUNCTION FUN_0000e430 @ 0x0000e430 size=120
CALLERS (1): FUN_0000e318@0x0000e318
CALLEES (0): 

int FUN_0000e430(int param_1,int param_2,short param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (((param_1 != 0) && (param_2 != 0)) && (iVar1 = (int)param_3, 0 < iVar1)) {
    iVar3 = 0;
    if (0 < iVar1) {
      iVar2 = 0;
      do {
        iVar3 = iVar3 + 1;
        if (*(int *)((iVar2 >> 0x10) * 4 + param_2) == param_1) {
          return iVar2 >> 0x10;
        }
        iVar2 = iVar3 * 0x10000;
      } while (iVar3 * 0x10000 >> 0x10 < iVar1);
    }
    return -1;
  }
  return -1;
}


================================================================