FUNCTION FUN_005d5a40 @ 0x005d5a40  size=208
CALLERS (8): FUN_005d3930@0x005d3930, FUN_005d47f0@0x005d47f0, FUN_005d09d0@0x005d09d0, FUN_005ca380@0x005ca380, FUN_005d5640@0x005d5640, FUN_005d0960@0x005d0960, FUN_005d0a40@0x005d0a40, FUN_005d6390@0x005d6390
CALLEES (0): 
----------------------------------------------------------------

void FUN_005d5a40(void)

{
  *(undefined1 *)(iRam00701070 + 0x2c) = 0;
  *(undefined1 *)(iRam00701070 + 0x2e) = 1;
  *(undefined4 *)(iRam00701078 + 0x20) = 0;
  *(undefined4 *)(iRam00701068 + 0x69014) = 0;
  *(undefined1 *)(iRam00701070 + 1) = 1;
  *(undefined1 *)(iRam00701070 + 2) = 1;
  *(undefined1 *)(iRam00701070 + 3) = 0;
  if (*(char *)(iRam00701068 + 0x60dc7) == '\0') {
    *(undefined1 *)(iRam00701070 + 0x3a) = 0xf0;
  }
  if (*(int *)(iRam00701068 + 0x5ffc0) == 0) {
    *(undefined1 *)(iRam00701070 + 0x3a) = 0;
    if (*(char *)(iRam00701070 + 0x36) != '\0') {
      *(undefined4 *)(iRam00701070 + 0x14) = 0xff000000;
    }
  }
  return;
}



================================================================