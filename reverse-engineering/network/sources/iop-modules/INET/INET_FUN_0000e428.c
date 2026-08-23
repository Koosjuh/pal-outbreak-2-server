FUNCTION FUN_0000e428 @ 0x0000e428 size=192
CALLERS (1): FUN_00010fec@0x00010fec
CALLEES (3): FUN_0000d31c@0x0000d31c, FUN_0000a7e0@0x0000a7e0, FUN_0000d2c0@0x0000d2c0

undefined4 FUN_0000e428(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  
  uVar3 = FUN_0000d2c0();
  piVar4 = DAT_0001b868;
  if (DAT_0001b868 != (int *)0x0) {
    do {
      if (param_1 == piVar4[2]) break;
      piVar4 = (int *)*piVar4;
    } while (piVar4 != (int *)0x0);
    if (piVar4 != (int *)0x0) {
      piVar1 = (int *)*piVar4;
      if ((int *)piVar4[1] != (int *)0x0) {
        *(int *)piVar4[1] = *piVar4;
        piVar1 = DAT_0001b868;
      }
      DAT_0001b868 = piVar1;
      iVar2 = piVar4[1];
      if (*piVar4 != 0) {
        *(int *)(*piVar4 + 4) = piVar4[1];
        iVar2 = DAT_0001b86c;
      }
      DAT_0001b86c = iVar2;
      DAT_0001b870 = DAT_0001b870 + -1;
      FUN_0000a7e0();
    }
  }
  FUN_0000d31c(uVar3);
  return 0;
}


================================================================