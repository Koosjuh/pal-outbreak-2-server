FUNCTION FUN_000130cc @ 0x000130cc size=80
CALLERS (5): FUN_00015158@0x00015158, FUN_00013b50@0x00013b50, FUN_00015290@0x00015290, FUN_00014eb8@0x00014eb8, FUN_00014fd8@0x00014fd8
CALLEES (2): FUN_00012ab0@0x00012ab0, FUN_00012bc0@0x00012bc0

void FUN_000130cc(int param_1)

{
  DAT_0001b8e0 = *(undefined4 *)(param_1 + 0x3c);
  FUN_00012ab0();
  *(undefined4 *)(param_1 + 0x28) = 10;
  FUN_00012bc0(param_1);
  *(undefined **)(param_1 + 0xb8) = &DAT_0001d4c0;
  return;
}


================================================================