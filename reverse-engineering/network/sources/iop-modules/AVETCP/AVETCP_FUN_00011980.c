FUNCTION FUN_00011980 @ 0x00011980 size=52
CALLERS (1): FUN_00000ed4@0x00000ed4
CALLEES (1): FUN_00003fd0@0x00003fd0

void FUN_00011980(void)

{
  if (DAT_00016ee0 != 0) {
    DAT_00016ee0 = 0;
    FUN_00003fd0();
  }
  return;
}


================================================================