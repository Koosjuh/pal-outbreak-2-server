FUNCTION FUN_00607b10 @ 0x00607b10  size=188
CALLERS (1): FUN_00607a10@0x00607a10
CALLEES (1): FUN_005b7fd0@0x005b7fd0
----------------------------------------------------------------

undefined4 FUN_00607b10(int param_1,char *param_2)

{
  if (param_2[1] == '\x01') {
    *(short *)(param_2 + 0x14) = *(short *)(param_2 + 0x14) + 1;
    if (*(short *)(param_2 + 0x16) == 0) {
      *(undefined1 *)(param_1 + 0x454) = 1;
      if (param_2[4] == '\0') {
        *param_2 = *param_2 + '\x01';
        param_2[1] = '\0';
      }
      else {
        *param_2 = '\x03';
        param_2[1] = '\0';
        param_2[4] = '\0';
      }
    }
    else {
      *(short *)(param_2 + 0x16) = *(short *)(param_2 + 0x16) + -1;
    }
  }
  else if (param_2[1] == '\0') {
    param_2[1] = '\x01';
    param_2[0x14] = '\0';
    param_2[0x15] = '\0';
    param_2[0x16] = '\x15';
    param_2[0x17] = '\0';
    FUN_005b7fd0(0x20,0,param_2 + 7,uRam008744f8);
  }
  return 0xffffffff;
}



================================================================