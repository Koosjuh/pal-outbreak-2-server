FUNCTION FUN_00011e30 @ 0x00011e30 size=40
CALLERS (4): FUN_00012040@0x00012040, FUN_000120e0@0x000120e0, FUN_0001214c@0x0001214c, FUN_00011ed0@0x00011ed0
CALLEES (0): 

int FUN_00011e30(int param_1)

{
  if (param_1 < 0x10) {
    return (&DAT_000228a0)[param_1];
  }
  return param_1;
}


================================================================