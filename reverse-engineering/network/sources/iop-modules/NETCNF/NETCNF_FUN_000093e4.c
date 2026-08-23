FUNCTION FUN_000093e4 @ 0x000093e4 size=128
CALLERS (1): FUN_00000c30@0x00000c30
CALLEES (2): FUN_00008bb4@0x00008bb4, FUN_00009608@0x00009608

void FUN_000093e4(undefined4 *param_1)

{
  if (param_1 == (undefined4 *)0x0) {
    FUN_00009608(&DAT_0000c210,0,0x10);
  }
  else {
    DAT_0000c210 = *param_1;
    DAT_0000c214 = param_1[1];
    DAT_0000c218 = param_1[2];
    DAT_0000c21c = param_1[3];
  }
  DAT_0000afd0 = (uint)(param_1 != (undefined4 *)0x0);
  FUN_00008bb4();
  return;
}


================================================================