FUNCTION FUN_005aeae0 @ 0x005aeae0  size=48
CALLERS (1): FUN_005ae770@0x005ae770
CALLEES (1): FUN_00617a00@0x00617a00
----------------------------------------------------------------

void FUN_005aeae0(int param_1)

{
  *(undefined1 *)(param_1 + 0x5196) = 0;
  *(undefined1 *)(param_1 + 0x5197) = 0;
  *(undefined1 *)(param_1 + 0x5198) = 0;
  if (*(char *)(param_1 + 0x51a2) != '\0') {
    *(undefined1 *)(param_1 + 0x54b4) = 0;
    *(undefined1 *)(param_1 + 0x54b5) = 0;
    *(undefined1 *)(param_1 + 0x54bc) = 0;
    *(undefined1 *)(param_1 + 0x54b8) = 0;
  }
  FUN_00617a00();
  return;
}



================================================================