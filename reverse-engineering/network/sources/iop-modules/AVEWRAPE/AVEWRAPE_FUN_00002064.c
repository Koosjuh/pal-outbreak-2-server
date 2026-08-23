FUNCTION FUN_00002064 @ 0x00002064 size=52
CALLERS (1): FUN_00002098@0x00002098
CALLEES (1): FUN_00002858@0x00002858

void FUN_00002064(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00002858(*(undefined4 *)(param_1 + 0x1c),param_1 + 0x24,
                       *(undefined4 *)(param_1 + 0x20));
  *(undefined4 *)(param_1 + 0x18) = uVar1;
  return;
}


================================================================