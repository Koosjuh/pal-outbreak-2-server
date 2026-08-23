FUNCTION FUN_0000e770 @ 0x0000e770 size=216
CALLERS (2): FUN_0000eab8@0x0000eab8, FUN_00011184@0x00011184
CALLEES (3): FUN_0000d31c@0x0000d31c, FUN_0000a7e0@0x0000a7e0, FUN_0000d2c0@0x0000d2c0

undefined4 FUN_0000e770(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  
  if (param_1 == 0) {
LAB_0000e830:
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0000d2c0();
    piVar4 = DAT_0001b874;
    if (DAT_0001b874 != (int *)0x0) {
      do {
        if (param_1 == piVar4[2]) break;
        piVar4 = (int *)*piVar4;
      } while (piVar4 != (int *)0x0);
      if (piVar4 != (int *)0x0) {
        piVar1 = (int *)*piVar4;
        if ((int *)piVar4[1] != (int *)0x0) {
          *(int *)piVar4[1] = *piVar4;
          piVar1 = DAT_0001b874;
        }
        DAT_0001b874 = piVar1;
        iVar2 = piVar4[1];
        if (*piVar4 != 0) {
          *(int *)(*piVar4 + 4) = piVar4[1];
          iVar2 = DAT_0001b878;
        }
        DAT_0001b878 = iVar2;
        DAT_0001b87c = DAT_0001b87c + -1;
        FUN_0000a7e0();
        FUN_0000d31c(uVar3);
        goto LAB_0000e830;
      }
    }
    FUN_0000d31c(uVar3);
    uVar3 = 0xfffffe00;
  }
  return uVar3;
}


================================================================