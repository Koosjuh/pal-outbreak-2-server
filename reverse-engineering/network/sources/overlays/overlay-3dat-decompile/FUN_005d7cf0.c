FUNCTION FUN_005d7cf0 @ 0x005d7cf0  size=260
CALLERS (2): FUN_005d7e00@0x005d7e00, FUN_005d7f80@0x005d7f80
CALLEES (1): FUN_005df780@0x005df780
----------------------------------------------------------------

void FUN_005d7cf0(undefined1 *param_1,undefined4 param_2,undefined1 param_3,undefined4 param_4,
                 undefined4 param_5,undefined1 param_6,undefined4 param_7,undefined4 param_8,
                 int param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
                 undefined4 param_13,char param_14,undefined4 param_15,undefined1 param_16)

{
  char cVar1;
  
  *param_1 = 1;
  *(undefined4 *)(param_1 + 4) = param_2;
  param_1[1] = param_3;
  *(undefined4 *)(param_1 + 8) = param_4;
  *(undefined4 *)(param_1 + 0xc) = param_5;
  param_1[2] = param_6;
  *(undefined4 *)(param_1 + 0x10) = param_7;
  *(undefined4 *)(param_1 + 0x14) = param_8;
  if (param_9 == 0) {
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  else {
    cVar1 = FUN_005df780();
    if (((cVar1 == '\x05') || (cVar1 == '\x04')) || (cVar1 == '\x01')) {
      *(undefined4 *)(param_1 + 0x18) = 0;
    }
    else if ((cVar1 == '\x03') || (cVar1 == '\x02')) {
      *(int *)(param_1 + 0x18) = param_9;
    }
    else {
      *(undefined4 *)(param_1 + 0x18) = 0;
    }
  }
  *(undefined4 *)(param_1 + 0x1c) = param_10;
  *(undefined4 *)(param_1 + 0x20) = param_11;
  *(undefined4 *)(param_1 + 0x24) = param_12;
  *(undefined4 *)(param_1 + 0x28) = param_13;
  if (param_14 == '\0') {
    param_1[0x2c] = 1;
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  else {
    param_1[0x2c] = 2;
    *(undefined4 *)(param_1 + 0x30) = param_15;
  }
  param_1[0x34] = param_16;
  param_1[0x35] = 0;
  return;
}



================================================================