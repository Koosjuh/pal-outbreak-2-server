FUNCTION FUN_005f00b0 @ 0x005f00b0  size=212
CALLERS (3): FUN_005f0930@0x005f0930, FUN_005f0a10@0x005f0a10, FUN_005eb7d0@0x005eb7d0
CALLEES (0): 
----------------------------------------------------------------

void FUN_005f00b0(int param_1,int param_2)

{
  if (*(char *)(iRam007012a0 + 0x186) == -10) {
    *(undefined1 *)(param_1 + 0x4c) = *(undefined1 *)(param_2 + 0x4c);
    *(undefined1 *)(param_1 + 0x4d) = *(undefined1 *)(param_2 + 0x4d);
    *(undefined1 *)(param_1 + 0x45) = *(undefined1 *)(param_2 + 0x45);
    *(undefined2 *)(param_1 + 0x32) = *(undefined2 *)(param_2 + 0x32);
    *(undefined2 *)(param_1 + 0x30) = *(undefined2 *)(param_2 + 0x30);
    *(byte *)(param_1 + 0x50) = *(byte *)(param_1 + 0x50) | *(byte *)(iRam007012a0 + 0x18a);
    *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(iRam007012a0 + 0xf18);
    if (*(char *)(iRam007012a0 + 0xf16) == '\0') {
      *(undefined1 *)(param_1 + 0x4a) = *(undefined1 *)(param_2 + 0x4a);
    }
    else {
      *(char *)(param_1 + 0x4a) = *(char *)(iRam007012a0 + 0xf16);
    }
    if (*(char *)(iRam007012a0 + 0xf17) == '\0') {
      *(undefined1 *)(param_1 + 0x4b) = *(undefined1 *)(param_2 + 0x4b);
    }
    else {
      *(char *)(param_1 + 0x4b) = *(char *)(iRam007012a0 + 0xf17);
    }
    *(undefined1 *)(param_1 + 0x44) = 0;
    *(undefined2 *)(param_1 + 0x20) = *(undefined2 *)(iRam007012a0 + 0xf10);
  }
  *(char *)(param_2 + 0x4c) = *(char *)(param_2 + 0x4c) + '\x01';
  return;
}



================================================================