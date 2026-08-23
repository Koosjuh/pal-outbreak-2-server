FUNCTION FUN_00010c40 @ 0x00010c40 size=128
CALLERS (1): FUN_000088e8@0x000088e8
CALLEES (2): FUN_0000d31c@0x0000d31c, FUN_0000d2c0@0x0000d2c0

int * FUN_00010c40(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  
  uVar1 = FUN_0000d2c0();
  piVar2 = DAT_0001b85c;
  if (DAT_0001b85c != (int *)0x0) {
    if (DAT_0001b85c != (int *)0x0) goto LAB_00010c80;
    if (param_1 != 0) {
      do {
        piVar2 = (int *)*piVar2;
        if (piVar2 == (int *)0x0) break;
LAB_00010c80:
      } while (param_1 != piVar2[0x1c]);
    }
  }
  FUN_0000d31c(uVar1);
  return piVar2;
}


================================================================