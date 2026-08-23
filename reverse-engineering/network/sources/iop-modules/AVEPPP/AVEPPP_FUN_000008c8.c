FUNCTION FUN_000008c8 @ 0x000008c8 size=96
CALLERS (3): FUN_00006aec@0x00006aec, FUN_0000dcfc@0x0000dcfc, FUN_000067bc@0x000067bc
CALLEES (1): FUN_00010b3c@0x00010b3c

void FUN_000008c8(undefined4 param_1,undefined4 param_2)

{
  DAT_000180f4 = (int)&DAT_000180f4 + (DAT_00016fc0 + 0x83U & 0xfffffffc);
  FUN_00010b3c(DAT_000180f4,param_1,param_2);
  DAT_000180f8 = (short)param_2;
  return;
}


================================================================