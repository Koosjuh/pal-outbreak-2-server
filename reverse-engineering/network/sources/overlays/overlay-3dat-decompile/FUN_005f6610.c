FUNCTION FUN_005f6610 @ 0x005f6610  size=312
CALLERS (0): 
CALLEES (4): FUN_005af2e0@0x005af2e0, FUN_0062fdf0@0x0062fdf0, FUN_005af2c0@0x005af2c0, FUN_005af1e0@0x005af1e0
----------------------------------------------------------------

void FUN_005f6610(int param_1)

{
  char *pcVar1;
  
  if (*(char *)(param_1 + 4) != '\x01') {
    if (*(char *)(param_1 + 4) != '\0') {
      return;
    }
    *(undefined1 *)(param_1 + 4) = 1;
    if (*(short *)(*(int *)(param_1 + 0x10) + 8) == 0) {
      *(undefined1 *)(param_1 + 1) = 0;
    }
    else {
      *(undefined1 *)(param_1 + 1) = 1;
    }
    if (*(char *)(param_1 + 2) != '\0') {
      *(ushort *)(param_1 + 0x24) = *(ushort *)(param_1 + 0x24) | 0x400;
      *(undefined4 *)(param_1 + 0x2c) = 0xff804000;
      *(undefined2 *)(param_1 + 0x3a) = 1;
    }
  }
  *(undefined2 *)(param_1 + 0x26) = 0x28;
  *(undefined2 *)(param_1 + 0x28) =
       *(undefined2 *)(&DAT_00649740 + *(short *)(*(int *)(param_1 + 0x10) + 0xc) * 2);
  if (*(char *)(param_1 + 2) == '\0') {
    pcVar1 = (char *)FUN_0062fdf0(9);
    FUN_005af2e0(pcVar1[1]);
    FUN_005af2c0(pcVar1[2]);
    while( true ) {
      FUN_005af2e0(pcVar1[1]);
      FUN_005af2c0(pcVar1[2]);
      FUN_005af1e0(*(undefined2 *)(pcVar1 + 4),*(undefined2 *)(pcVar1 + 6),pcVar1[3],
                   *(undefined4 *)(pcVar1 + 8));
      if (*pcVar1 != '\0') break;
      pcVar1 = pcVar1 + 0xc;
    }
  }
  else {
    *(undefined2 *)(param_1 + 0x42) = 0;
    *(undefined2 *)(param_1 + 0x44) = 0x40;
    *(undefined2 *)(param_1 + 0x46) = 0x40;
    *(short *)(param_1 + 0x40) = *(short *)(param_1 + 0x40) - *(short *)(param_1 + 0x3a);
    *(ushort *)(param_1 + 0x40) = *(ushort *)(param_1 + 0x40) & 0x3f;
  }
  return;
}



================================================================