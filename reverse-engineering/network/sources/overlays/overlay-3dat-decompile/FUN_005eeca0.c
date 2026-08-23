FUNCTION FUN_005eeca0 @ 0x005eeca0  size=156
CALLERS (3): FUN_005eef70@0x005eef70, FUN_005ef040@0x005ef040, FUN_005ef0e0@0x005ef0e0
CALLEES (1): FUN_005ed0c0@0x005ed0c0
----------------------------------------------------------------

void FUN_005eeca0(void)

{
  if (*(int *)(iRam007012a0 + 0x1c) != 0) {
    *(short *)(iRam007012a0 + 0xd8c8) =
         *(short *)(iRam007012a0 + 0xd8c0) - *(short *)(iRam007012a0 + 0xd8bc);
    *(undefined1 *)(*(int *)(iRam007012a0 + 0x1c) + iRam007012a0 + 0x20) = 0;
    FUN_005ed0c0();
    *(undefined2 *)(iRam007012a0 + 0xd8bc) = *(undefined2 *)(iRam007012a0 + 0xd8c0);
    *(undefined4 *)(iRam007012a0 + 0x1c) = 0;
    *(undefined1 *)(iRam007012a0 + 0x18d) = 0;
  }
  return;
}



================================================================