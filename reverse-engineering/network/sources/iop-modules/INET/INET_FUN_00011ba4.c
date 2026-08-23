FUNCTION FUN_00011ba4 @ 0x00011ba4 size=80
CALLERS (1): FUN_0000ebe0@0x0000ebe0
CALLEES (1): FUN_00009eec@0x00009eec

void FUN_00011ba4(undefined4 param_1,undefined4 *param_2)

{
  if (DAT_0001b2f4 != 0) {
    param_2[1] = 0;
    *param_2 = 0;
    FUN_00009eec();
  }
  return;
}


================================================================