FUNCTION FUN_000134c4 @ 0x000134c4 size=120
CALLERS (0): 
CALLEES (1): FUN_00014e24@0x00014e24

undefined4 FUN_000134c4(undefined4 *param_1)

{
  if (DAT_00016178 != 0) {
    FUN_00014e24("AT_addNdgApi: called\n");
  }
  DAT_00016f20 = *param_1;
  DAT_00016f24 = param_1[1];
  DAT_00016f28 = param_1[2];
  DAT_00016f2c = param_1[3];
  DAT_00016f30 = param_1[4];
  DAT_00016132 = 1;
  return 0;
}


================================================================