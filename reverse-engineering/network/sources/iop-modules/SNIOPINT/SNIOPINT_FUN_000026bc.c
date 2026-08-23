FUNCTION FUN_000026bc @ 0x000026bc size=68
CALLERS (1): FUN_00002858@0x00002858
CALLEES (1): FUN_00003648@0x00003648

void FUN_000026bc(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00003648(param_1 + 0x20,*(int *)(param_1 + 0x1c) * 0x30c);
  *(undefined4 *)(param_1 + 0x18) = uVar1;
  return;
}


================================================================