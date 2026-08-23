FUNCTION FUN_00003198 @ 0x00003198 size=96
CALLERS (1): FUN_00003250@0x00003250
CALLEES (0): 

int * FUN_00003198(int param_1,short param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar1 = 0;
  while ((piVar2 = (int *)(param_1 + (iVar1 >> 0xc) + 0x10), *piVar2 == 0 ||
         ((short)piVar2[1] != param_2))) {
    iVar3 = iVar3 + 1;
    iVar1 = iVar3 * 0x10000;
    if (3 < iVar3 * 0x10000 >> 0x10) {
      return (int *)0x0;
    }
  }
  return piVar2;
}


================================================================