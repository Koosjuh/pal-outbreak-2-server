FUNCTION FUN_00010000 @ 0x00010000 size=112
CALLERS (1): FUN_00009024@0x00009024
CALLEES (2): FUN_00010070@0x00010070, FUN_000103cc@0x000103cc

void FUN_00010000(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    if (*(char *)(param_1 + 0x18) == '\x01') {
      FUN_00010070();
    }
    if (*(int *)(param_1 + 4) != 0) {
      *(int *)(param_1 + 8) = *(int *)(param_1 + 4);
      uVar1 = FUN_000103cc();
      *(undefined4 *)(param_1 + 0xc) = uVar1;
      if (*(int *)(param_1 + 0x10) != 0) {
        *(undefined1 *)(param_1 + 0x18) = 1;
      }
    }
  }
  return;
}


================================================================