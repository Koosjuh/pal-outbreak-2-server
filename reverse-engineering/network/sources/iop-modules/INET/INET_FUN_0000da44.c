FUNCTION FUN_0000da44 @ 0x0000da44 size=100
CALLERS (2): FUN_00006cd0@0x00006cd0, FUN_00006d5c@0x00006d5c
CALLEES (2): FUN_0000d31c@0x0000d31c, FUN_0000d2c0@0x0000d2c0

void FUN_0000da44(code *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  
  uVar1 = FUN_0000d2c0();
  for (piVar2 = (int *)DAT_0001b85c; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
    (*param_1)(piVar2);
  }
  FUN_0000d31c(uVar1);
  return;
}


================================================================