FUNCTION FUN_0000c4b0 @ 0x0000c4b0 size=156
CALLERS (2): FUN_0000cc4c@0x0000cc4c, FUN_0000c54c@0x0000c54c
CALLEES (1): FUN_0000c298@0x0000c298

void FUN_0000c4b0(undefined4 param_1,undefined4 param_2,short param_3)

{
  uint uVar1;
  
  uVar1 = 1;
  do {
    if (((int)param_3 >> ((int)(short)uVar1 & 0x1fU) & 1U) != 0) {
      FUN_0000c298(param_1,param_2,uVar1 & 0xff,(&UNK_0001280c)[(short)uVar1],0);
    }
    uVar1 = uVar1 + 1;
  } while ((int)(uVar1 * 0x10000) >> 0x10 < 9);
  return;
}


================================================================