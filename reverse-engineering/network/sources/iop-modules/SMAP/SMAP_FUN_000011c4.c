FUNCTION FUN_000011c4 @ 0x000011c4 size=76
CALLERS (1): FUN_00001298@0x00001298
CALLEES (3): FUN_000006d8@0x000006d8, FUN_000000a0@0x000000a0, FUN_00000998@0x00000998

void FUN_000011c4(int param_1)

{
  uint uVar1;
  
  uVar1 = FUN_000000a0(*(undefined4 *)(param_1 + 4),1);
  if ((uVar1 & 4) == 0) {
    *(undefined4 *)(param_1 + 0x38) = 0;
    FUN_00000998(param_1);
    FUN_000006d8(param_1);
  }
  return;
}


================================================================