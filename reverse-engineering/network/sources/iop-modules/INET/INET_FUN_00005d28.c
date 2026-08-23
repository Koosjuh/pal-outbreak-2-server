FUNCTION FUN_00005d28 @ 0x00005d28 size=124
CALLERS (1): FUN_0000ec64@0x0000ec64
CALLEES (2): FUN_00005c7c@0x00005c7c, FUN_000043a8@0x000043a8

void FUN_00005d28(int param_1)

{
  int iVar1;
  
  if ((param_1 != 0) && ((*(uint *)(param_1 + 0x48) & 0x20) != 0)) {
    *(undefined4 *)(param_1 + 0x70) = 0;
    *(undefined4 *)(param_1 + 0x74) = 0;
    *(undefined4 *)(param_1 + 0x7c) = 0;
    *(undefined4 *)(param_1 + 0x80) = 0;
    *(undefined4 *)(param_1 + 0x1b0) = 0;
    iVar1 = FUN_00005c7c();
    if (iVar1 != 0) {
      *(undefined4 *)(iVar1 + 0x1c) = 0;
      *(int *)(iVar1 + 0x80) = *(int *)(iVar1 + 0x78) / 5000;
      FUN_000043a8();
    }
  }
  return;
}


================================================================