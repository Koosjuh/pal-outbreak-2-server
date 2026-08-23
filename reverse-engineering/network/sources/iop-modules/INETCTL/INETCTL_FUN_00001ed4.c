FUNCTION FUN_00001ed4 @ 0x00001ed4 size=144
CALLERS (1): FUN_0000203c@0x0000203c
CALLEES (2): FUN_00000148@0x00000148, FUN_00000104@0x00000104

void FUN_00001ed4(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int *piVar2;
  
  FUN_00000148();
  piVar2 = (int *)DAT_000046f8;
  while (piVar1 = piVar2, piVar1 != (int *)0x0) {
    piVar2 = (int *)*piVar1;
    if (piVar1[2] != 0) {
      (*(code *)piVar1[2])(param_1,param_2,piVar1[3]);
    }
  }
  FUN_00000104();
  return;
}


================================================================