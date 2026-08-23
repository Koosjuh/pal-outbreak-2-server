FUNCTION FUN_00010bd0 @ 0x00010bd0 size=112
CALLERS (2): FUN_00010cc0@0x00010cc0, FUN_000088e8@0x000088e8
CALLEES (2): FUN_0000d31c@0x0000d31c, FUN_0000d2c0@0x0000d2c0

int FUN_00010bd0(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  
  uVar1 = FUN_0000d2c0();
  piVar2 = (int *)DAT_0001b85c;
  while ((piVar2 != (int *)0x0 && (param_1 != *(int *)(piVar2[0x68] + 4)))) {
    piVar2 = (int *)*piVar2;
  }
  FUN_0000d31c(uVar1);
  return (int)piVar2;
}


================================================================