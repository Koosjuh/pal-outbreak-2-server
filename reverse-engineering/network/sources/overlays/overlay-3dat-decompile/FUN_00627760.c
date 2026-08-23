FUNCTION FUN_00627760 @ 0x00627760  size=60
CALLERS (2): FUN_005b1a30@0x005b1a30, FUN_005f7f30@0x005f7f30
CALLEES (1): FUN_0062b9e0@0x0062b9e0
----------------------------------------------------------------

void FUN_00627760(int param_1)

{
  FUN_0062b9e0();
  *(undefined1 *)(param_1 + 1) = 2;
  *(undefined1 *)(param_1 + 0xe) = 0;
  *(undefined1 *)(param_1 + 0xf) = 0;
  *(undefined1 *)(param_1 + 0x10) = 0;
  *(undefined1 *)(param_1 + 0x11) = 0;
  return;
}



================================================================