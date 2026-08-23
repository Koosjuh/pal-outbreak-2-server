FUNCTION FUN_00001ff4 @ 0x00001ff4 size=72
CALLERS (1): FUN_0000203c@0x0000203c
CALLEES (0): 

void FUN_00001ff4(int param_1)

{
  int *piVar1;
  
  for (piVar1 = (int *)DAT_000046ec; piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
    if (param_1 == piVar1[2]) {
      piVar1[3] = piVar1[3] & 0xfffffeff;
    }
  }
  return;
}


================================================================