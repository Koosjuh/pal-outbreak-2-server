FUNCTION FUN_00605690 @ 0x00605690  size=248
CALLERS (0): 
CALLEES (4): FUN_005af2e0@0x005af2e0, FUN_0062fdf0@0x0062fdf0, FUN_005af2c0@0x005af2c0, FUN_005af1e0@0x005af1e0
----------------------------------------------------------------

void FUN_00605690(int param_1)

{
  char *pcVar1;
  
  if (*(char *)(param_1 + 4) != '\x01') {
    if (*(char *)(param_1 + 4) != '\0') {
      return;
    }
    *(undefined1 *)(param_1 + 4) = 1;
    if (*(char *)(param_1 + 3) != '\0') {
      *(ushort *)(param_1 + 0x24) = *(ushort *)(param_1 + 0x24) | 0x400;
      *(undefined4 *)(param_1 + 0x2c) = 0xff804000;
      *(undefined2 *)(param_1 + 0x3a) = 1;
    }
  }
  pcVar1 = (char *)FUN_0062fdf0(*(byte *)(param_1 + 2) + 6);
  while( true ) {
    FUN_005af2e0(pcVar1[1]);
    FUN_005af2c0(pcVar1[2]);
    FUN_005af1e0(*(undefined2 *)(pcVar1 + 4),*(undefined2 *)(pcVar1 + 6),pcVar1[3],
                 *(undefined4 *)(pcVar1 + 8));
    if (*pcVar1 != '\0') break;
    pcVar1 = pcVar1 + 0xc;
  }
  if (*(char *)(param_1 + 3) != '\0') {
    *(undefined2 *)(param_1 + 0x42) = 0;
    *(undefined2 *)(param_1 + 0x44) = 0x40;
    *(undefined2 *)(param_1 + 0x46) = 0x40;
    *(short *)(param_1 + 0x40) = *(short *)(param_1 + 0x40) - *(short *)(param_1 + 0x3a);
    *(ushort *)(param_1 + 0x40) = *(ushort *)(param_1 + 0x40) & 0x3f;
  }
  return;
}



================================================================