FUNCTION FUN_0000e148 @ 0x0000e148 size=56
CALLERS (2): FUN_00004b68@0x00004b68, FUN_00004754@0x00004754
CALLEES (1): FUN_00019a94@0x00019a94

void FUN_0000e148(int param_1)

{
  if ((*(uint *)(param_1 + 0x48) & 0x20) != 0) {
    FUN_00019a94(*(undefined4 *)(param_1 + 0x4c),0x40000);
  }
  return;
}


================================================================