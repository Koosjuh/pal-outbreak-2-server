FUNCTION FUN_0062c580 @ 0x0062c580  size=452
CALLERS (1): FUN_0062c350@0x0062c350
CALLEES (5): FUN_005b1460@0x005b1460, FUN_005b9110@0x005b9110, FUN_005b14b0@0x005b14b0, FUN_005b1420@0x005b1420, FUN_005b8cf0@0x005b8cf0
----------------------------------------------------------------

void FUN_0062c580(int param_1,undefined1 *param_2)

{
  long lVar1;
  
  if (param_2[2] == '\x01') {
    *(short *)(param_2 + 4) = *(short *)(param_2 + 4) + -1;
    if (*(short *)(param_2 + 4) < 1) {
      param_2[1] = param_2[1] + '\x01';
      param_2[2] = 0;
      *(undefined2 *)(param_2 + 4) = 0x2e;
      FUN_005b8cf0(0x34);
    }
  }
  else if (param_2[2] == '\0') {
    lVar1 = FUN_005b14b0(0x40004);
    if (((lVar1 == 0) && (cRam006c462a != 'P')) &&
       ((cRam006c462a != '+' || ((bRam006c462b & 0x22) == 0)))) {
      lVar1 = FUN_005b14b0(0x80008);
      if (((lVar1 == 0) && (cRam006c462a != 'O')) && (cRam006c462a != '+')) {
        lVar1 = FUN_005b1420();
        if (lVar1 == 0) {
          lVar1 = FUN_005b1460();
          if (lVar1 != 0) {
            if (*(char *)(param_1 + 0x43c) == '\0') {
              func_0x001b0140(2);
            }
            *(undefined1 *)(param_1 + 0x43c) = 1;
          }
        }
        else if (*(char *)(param_1 + 0x43c) == '\0') {
          param_2[2] = param_2[2] + '\x01';
          *(undefined1 *)(param_1 + 0x43f) = 1;
          *(undefined2 *)(param_2 + 4) = 8;
          func_0x001b0140();
          FUN_005b9110(0x4c);
          *(undefined1 *)(param_1 + 0x45a) = 0;
        }
        else {
          *param_2 = 1;
          param_2[1] = 0;
          param_2[2] = 0;
          func_0x001b0140(2);
          FUN_005b9110(0x4c);
        }
      }
      else {
        if (*(char *)(param_1 + 0x43c) == '\0') {
          func_0x001b0140(0);
        }
        *(undefined1 *)(param_1 + 0x43c) = 1;
      }
    }
    else {
      if (*(char *)(param_1 + 0x43c) != '\0') {
        func_0x001b0140(0);
      }
      *(undefined1 *)(param_1 + 0x43c) = 0;
    }
  }
  return;
}



================================================================