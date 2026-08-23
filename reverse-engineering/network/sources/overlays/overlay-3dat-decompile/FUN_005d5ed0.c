FUNCTION FUN_005d5ed0 @ 0x005d5ed0  size=108
CALLERS (2): FUN_005cf140@0x005cf140, FUN_005cf010@0x005cf010
CALLEES (2): FUN_0061e740@0x0061e740, FUN_0061e730@0x0061e730
----------------------------------------------------------------

void FUN_005d5ed0(char param_1)

{
  if (param_1 == '\x01') {
    FUN_0061e730();
  }
  else if (param_1 == '\0') {
    FUN_0061e740();
  }
  *(undefined1 *)(iRam00701078 + 1) = 0;
  *(undefined1 *)(iRam00701068 + 0x68e85) = 1;
  return;
}



================================================================