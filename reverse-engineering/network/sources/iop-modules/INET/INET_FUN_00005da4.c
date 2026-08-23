FUNCTION FUN_00005da4 @ 0x00005da4 size=160
CALLERS (1): FUN_0000ec64@0x0000ec64
CALLEES (1): FUN_00004290@0x00004290

undefined4 FUN_00005da4(int param_1)

{
  int *piVar1;
  
  if (param_1 != 0) {
    if ((*(uint *)(param_1 + 0x48) & 0x20) == 0) {
      return 0;
    }
    piVar1 = DAT_0001b680;
    if (DAT_0001b680 == (int *)0x0) {
      return 0;
    }
    do {
      if (param_1 == piVar1[2]) break;
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)0x0);
    if (piVar1 != (int *)0x0) {
      if (piVar1[7] == 3) {
        FUN_00004290(piVar1,piVar1[0x12],piVar1[0x11],piVar1[8]);
        return 1;
      }
      piVar1[7] = 3;
    }
  }
  return 0;
}


================================================================