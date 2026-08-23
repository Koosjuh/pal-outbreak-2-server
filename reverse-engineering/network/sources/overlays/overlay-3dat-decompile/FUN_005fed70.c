FUNCTION FUN_005fed70 @ 0x005fed70  size=100
CALLERS (1): FUN_005fe730@0x005fe730
CALLEES (1): FUN_005b6900@0x005b6900
----------------------------------------------------------------

void FUN_005fed70(int param_1)

{
  if (*(char *)(param_1 + 0x10) == '\x01') {
    *(char *)(param_1 + 0xf) = *(char *)(param_1 + 0xf) + '\x01';
    *(undefined1 *)(param_1 + 0x10) = 0;
    *(undefined1 *)(param_1 + 0x9cc) = 0;
    *(undefined1 *)(param_1 + 0x9cb) = 0;
    *(undefined1 *)(param_1 + 0x9ab) = 0;
    *(undefined1 *)(param_1 + 0x9aa) = 0;
  }
  else if (*(char *)(param_1 + 0x10) == '\0') {
    FUN_005b6900();
  }
  return;
}



================================================================