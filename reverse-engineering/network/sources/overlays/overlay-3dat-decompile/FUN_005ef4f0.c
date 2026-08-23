FUNCTION FUN_005ef4f0 @ 0x005ef4f0  size=92
CALLERS (1): FUN_005e8510@0x005e8510
CALLEES (1): FUN_005d8b00@0x005d8b00
----------------------------------------------------------------

void FUN_005ef4f0(undefined1 *param_1)

{
  if ((*(char *)(iRam007012a0 + 0x186) == '\0') && (*(char *)(iRam007012a0 + 0xe96b) == '\0')) {
    FUN_005d8b00();
  }
  *(undefined4 *)(iRam007012a0 + 4) = 0;
  *param_1 = 0;
  return;
}



================================================================