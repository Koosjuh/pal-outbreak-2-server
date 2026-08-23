FUNCTION FUN_0000e594 @ 0x0000e594 size=152
CALLERS (1): FUN_00001108@0x00001108
CALLEES (2): FUN_0000d31c@0x0000d31c, FUN_0000d2c0@0x0000d2c0

uint FUN_0000e594(uint param_1)

{
  undefined4 uVar1;
  int *piVar2;
  uint uVar3;
  
  uVar1 = FUN_0000d2c0();
  piVar2 = (int *)DAT_0001b868;
  do {
    uVar3 = 0;
    if (piVar2 == (int *)0x0) {
LAB_0000e60c:
      FUN_0000d31c(uVar1);
      return uVar3;
    }
    if (((piVar2[5] & 1U) != 0) && ((param_1 & piVar2[4]) == piVar2[2])) {
      uVar3 = param_1;
      if ((piVar2[5] & 4U) != 0) {
        uVar3 = piVar2[3];
      }
      goto LAB_0000e60c;
    }
    piVar2 = (int *)*piVar2;
  } while( true );
}


================================================================