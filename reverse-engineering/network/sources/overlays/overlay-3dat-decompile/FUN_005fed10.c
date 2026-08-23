FUNCTION FUN_005fed10 @ 0x005fed10  size=84
CALLERS (1): FUN_005fe730@0x005fe730
CALLEES (2): FUN_005b68e0@0x005b68e0, FUN_005c44a0@0x005c44a0
----------------------------------------------------------------

void FUN_005fed10(int param_1)

{
  *(char *)(param_1 + 0xf) = *(char *)(param_1 + 0xf) + '\x01';
  *(undefined1 *)(param_1 + 0x10) = 0;
  *(undefined1 *)(param_1 + 0x443) = 2;
  FUN_005b68e0();
  *(undefined1 *)(param_1 + 0x42b) = 0x17;
  FUN_005c44a0(1,0x601300);
  return;
}



================================================================