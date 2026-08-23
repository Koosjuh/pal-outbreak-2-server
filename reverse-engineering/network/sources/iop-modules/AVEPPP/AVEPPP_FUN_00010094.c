FUNCTION FUN_00010094 @ 0x00010094 size=116
CALLERS (3): FUN_0000a8ec@0x0000a8ec, FUN_0000718c@0x0000718c, FUN_0000e460@0x0000e460
CALLEES (0): 

void FUN_00010094(int *param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = DAT_00014968;
  if (param_1 != (int *)0x0) {
    bVar1 = DAT_00014968 == (int *)0x0;
    param_1[1] = param_2;
    if (bVar1) {
      DAT_00014968 = param_1;
      *param_1 = 0;
    }
    else {
      iVar2 = *piVar3;
      while (iVar2 != 0) {
        if (piVar3 == param_1) goto LAB_000100fc;
        piVar3 = (int *)*piVar3;
        iVar2 = *piVar3;
      }
      *piVar3 = (int)param_1;
      *param_1 = 0;
    }
LAB_000100fc:
    *(undefined1 *)(param_1 + 6) = 0;
  }
  return;
}


================================================================