FUNCTION FUN_00000ed4 @ 0x00000ed4 size=116
CALLERS (0): 
CALLEES (5): FUN_00014e24@0x00014e24, FUN_000123f4@0x000123f4, FUN_00011980@0x00011980, FUN_00011cf0@0x00011cf0, FUN_0000e304@0x0000e304

undefined4 FUN_00000ed4(void)

{
  if (DAT_00016178 != 0) {
    FUN_00014e24("AT_disp: called.\n");
  }
  FUN_00011980();
  FUN_000123f4();
  FUN_00011cf0();
  FUN_0000e304();
  if (DAT_00016178 != 0) {
    FUN_00014e24("AT_disp: return %d\n",0);
  }
  return 0;
}


================================================================