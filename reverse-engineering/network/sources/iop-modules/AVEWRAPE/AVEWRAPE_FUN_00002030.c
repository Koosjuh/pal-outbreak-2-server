FUNCTION FUN_00002030 @ 0x00002030 size=52
CALLERS (1): FUN_00002098@0x00002098
CALLEES (1): FUN_00002850@0x00002850

void FUN_00002030(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00002850(*(undefined4 *)(param_1 + 0x1c),param_1 + 0x24,
                       *(undefined4 *)(param_1 + 0x20));
  *(undefined4 *)(param_1 + 0x18) = uVar1;
  return;
}


================================================================