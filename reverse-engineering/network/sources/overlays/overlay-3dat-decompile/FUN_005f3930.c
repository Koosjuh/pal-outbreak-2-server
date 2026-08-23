FUNCTION FUN_005f3930 @ 0x005f3930  size=156
CALLERS (3): FUN_005f3ac0@0x005f3ac0, FUN_005f3bc0@0x005f3bc0, FUN_005f3cc0@0x005f3cc0
CALLEES (1): FUN_005f3150@0x005f3150
----------------------------------------------------------------

void FUN_005f3930(void)

{
  if (*(int *)(iRam007012a0 + 0x1c) != 0) {
    *(short *)(iRam007012a0 + 0xd8c8) =
         *(short *)(iRam007012a0 + 0xd8d2) - *(short *)(iRam007012a0 + 0xd8ce);
    *(undefined1 *)(*(int *)(iRam007012a0 + 0x1c) + iRam007012a0 + 0x20) = 0;
    FUN_005f3150();
    *(undefined2 *)(iRam007012a0 + 0xd8ce) = *(undefined2 *)(iRam007012a0 + 0xd8d2);
    *(undefined4 *)(iRam007012a0 + 0x1c) = 0;
    *(undefined1 *)(iRam007012a0 + 0x18d) = 0;
  }
  return;
}



================================================================