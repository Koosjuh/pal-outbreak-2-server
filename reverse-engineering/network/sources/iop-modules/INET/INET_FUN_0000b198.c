FUNCTION FUN_0000b198 @ 0x0000b198 size=136
CALLERS (1): FUN_0000b590@0x0000b590
CALLEES (3): FUN_0000d508@0x0000d508, FUN_00009eec@0x00009eec, FUN_0000a7e0@0x0000a7e0

void FUN_0000b198(undefined4 *param_1)

{
  undefined4 uVar1;
  
  FUN_0000d508(param_1 + 10,0);
  FUN_00009eec(param_1[8]);
  uVar1 = param_1[2];
  if (param_1[1] != 0) {
    *(undefined4 *)(param_1[1] + 8) = param_1[2];
    uVar1 = DAT_0001b988;
  }
  DAT_0001b988 = uVar1;
  uVar1 = param_1[1];
  if (param_1[2] != 0) {
    *(undefined4 *)(param_1[2] + 4) = param_1[1];
    uVar1 = DAT_0001b984;
  }
  DAT_0001b984 = uVar1;
  *param_1 = 0;
  FUN_0000a7e0();
  DAT_0001b810 = DAT_0001b810 + -1;
  return;
}


================================================================