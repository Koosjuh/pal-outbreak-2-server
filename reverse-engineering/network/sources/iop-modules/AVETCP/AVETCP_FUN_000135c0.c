FUNCTION FUN_000135c0 @ 0x000135c0 size=140
CALLERS (1): FUN_00014d48@0x00014d48
CALLEES (1): FUN_00014e24@0x00014e24

undefined4 FUN_000135c0(undefined4 *param_1)

{
  if (DAT_00016178 != 0) {
    FUN_00014e24("AT_addDnsApi: called\n");
  }
  DAT_00016f68 = *param_1;
  DAT_00016f6c = param_1[1];
  DAT_00016f70 = param_1[2];
  DAT_00016f74 = param_1[3];
  DAT_00016f78 = param_1[4];
  DAT_00016f7c = param_1[5];
  DAT_00016f80 = param_1[6];
  DAT_00016136 = 1;
  return 0;
}


================================================================