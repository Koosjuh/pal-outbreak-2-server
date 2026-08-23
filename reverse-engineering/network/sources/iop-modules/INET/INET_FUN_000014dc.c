FUNCTION FUN_000014dc @ 0x000014dc size=84
CALLERS (1): FUN_0000eab8@0x0000eab8
CALLEES (1): FUN_00000000@0x00000000

void FUN_000014dc(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = (int *)DAT_0001b950;
  while (piVar2 != (int *)0x0) {
    piVar1 = piVar2 + 0xb;
    piVar2 = (int *)*piVar2;
    if (param_1 == *piVar1) {
      FUN_00000000();
    }
  }
  return;
}


================================================================