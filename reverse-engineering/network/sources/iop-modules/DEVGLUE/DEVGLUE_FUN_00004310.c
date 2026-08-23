FUNCTION FUN_00004310 @ 0x00004310 size=120
CALLERS (3): FUN_00003250@0x00003250, FUN_00004528@0x00004528, FUN_00007874@0x00007874
CALLEES (2): FUN_000080bc@0x000080bc, FUN_000080c4@0x000080c4

int * FUN_00004310(int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 local_18 [2];
  
  FUN_000080bc(local_18);
  piVar2 = (int *)*param_1;
  if (piVar2 != (int *)0x0) {
    iVar1 = *piVar2;
    *param_1 = iVar1;
    if (iVar1 == 0) {
      param_1[1] = 0;
    }
    else {
      *(undefined4 *)(*piVar2 + 4) = 0;
    }
    piVar2[1] = 0;
    *piVar2 = 0;
  }
  FUN_000080c4(local_18[0]);
  return piVar2;
}


================================================================