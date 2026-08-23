FUNCTION FUN_005fec10 @ 0x005fec10  size=20
CALLERS (1): FUN_005fe730@0x005fe730
CALLEES (0): 
----------------------------------------------------------------

void FUN_005fec10(int param_1)

{
  *(char *)(param_1 + 0xf) = *(char *)(param_1 + 0xf) + '\x01';
  *(undefined1 *)(param_1 + 0x10) = 0;
  return;
}



================================================================