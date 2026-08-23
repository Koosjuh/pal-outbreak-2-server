FUNCTION FUN_005b8a10 @ 0x005b8a10  size=324
CALLERS (0): 
CALLEES (1): FUN_00618c20@0x00618c20
----------------------------------------------------------------

void FUN_005b8a10(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 4);
  if (cVar1 == '\x02') {
    FUN_00618c20();
    return;
  }
  if (cVar1 == '\x01') goto LAB_005b8ab8;
  if (cVar1 != '\0') {
    return;
  }
  *(undefined1 *)(param_1 + 4) = 1;
  *(undefined1 *)(param_1 + 1) = 0;
  *(ushort *)(param_1 + 0x24) = *(ushort *)(param_1 + 0x24) | 0x400;
  cVar1 = *(char *)(param_1 + 2);
  if ((((cVar1 == '\x16') || (cVar1 == '\x17')) || (cVar1 == '\v')) || (cVar1 == '\0')) {
LAB_005b8aa0:
    *(undefined4 *)(param_1 + 0x34) = 0xffffffe6;
  }
  else if (cVar1 == '\x19') {
    *(undefined4 *)(param_1 + 0x30) = 0;
    goto LAB_005b8aa0;
  }
  *(undefined4 *)(param_1 + 0x2c) = 0xff804000;
  *(undefined2 *)(param_1 + 0x3a) = 1;
LAB_005b8ab8:
  if (cRam006c4fd3 == '\x02') {
    *(undefined1 *)(param_1 + 4) = 2;
    *(undefined1 *)(param_1 + 5) = 0;
  }
  else if (cRam006c4fd3 == '\x01') {
    FUN_00618c20();
  }
  else {
    if (**(char **)(param_1 + 0x10) == *(char *)(param_1 + 3)) {
      *(undefined1 *)(param_1 + 1) = 1;
    }
    else {
      *(undefined1 *)(param_1 + 1) = 0;
      *(undefined2 *)(param_1 + 0x40) = 0;
    }
    *(undefined2 *)(param_1 + 0x42) = 0;
    *(undefined2 *)(param_1 + 0x44) = 0x40;
    *(undefined2 *)(param_1 + 0x46) = 0x40;
    *(short *)(param_1 + 0x40) = *(short *)(param_1 + 0x40) - *(short *)(param_1 + 0x3a);
    *(ushort *)(param_1 + 0x40) = *(ushort *)(param_1 + 0x40) & 0x3f;
  }
  return;
}



================================================================