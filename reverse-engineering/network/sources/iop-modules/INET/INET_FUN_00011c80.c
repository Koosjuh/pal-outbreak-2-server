FUNCTION FUN_00011c80 @ 0x00011c80 size=160
CALLERS (1): FUN_0000ebe0@0x0000ebe0
CALLEES (2): FUN_0000d3b4@0x0000d3b4, FUN_0000d390@0x0000d390

int * FUN_00011c80(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)0x0;
  if (DAT_0001b2f4 != 0) {
    uVar1 = FUN_0000d390();
    piVar3 = (int *)*param_1;
    if (piVar3 != (int *)0x0) {
      iVar2 = *piVar3;
      *param_1 = iVar2;
      if (iVar2 == 0) {
        param_1[1] = 0;
      }
      else {
        *(undefined4 *)(*piVar3 + 4) = 0;
      }
      piVar3[1] = 0;
      *piVar3 = 0;
    }
    FUN_0000d3b4(uVar1);
  }
  return piVar3;
}


================================================================