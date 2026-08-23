FUNCTION FUN_0062b020 @ 0x0062b020  size=664
CALLERS (1): FUN_0062a5e0@0x0062a5e0
CALLEES (5): FUN_005b1460@0x005b1460, FUN_005b9110@0x005b9110, FUN_005b14b0@0x005b14b0, FUN_005b1420@0x005b1420, FUN_005b8da0@0x005b8da0
----------------------------------------------------------------

undefined8 FUN_0062b020(int param_1,undefined1 *param_2)

{
  short sVar1;
  long lVar2;
  
  switch(param_2[1]) {
  case 0:
    param_2[1] = param_2[1] + '\x01';
    *(undefined1 *)(param_1 + 0x43c) = 1;
    *(undefined1 *)(param_1 + 0x43f) = 0;
    *(undefined2 *)(param_2 + 4) = 0x10;
    FUN_005b8da0(0xffffffffffffff88,param_1 + 0x43c);
    break;
  case 1:
    sVar1 = *(short *)(param_2 + 4);
    *(short *)(param_2 + 4) = sVar1 + -1;
    if ((short)(sVar1 + -1) < 1) {
      param_2[1] = param_2[1] + '\x01';
    }
    break;
  case 2:
    lVar2 = FUN_005b14b0(0x40004);
    if (((lVar2 == 0) && (cRam006c462a != 'P')) &&
       ((cRam006c462a != '+' || ((bRam006c462b & 0x22) == 0)))) {
      lVar2 = FUN_005b14b0(0x80008);
      if (((lVar2 == 0) && (cRam006c462a != 'O')) && (cRam006c462a != '+')) {
        lVar2 = FUN_005b1420();
        if (lVar2 == 0) {
          lVar2 = FUN_005b1460();
          if (lVar2 != 0) {
            *param_2 = 1;
            param_2[1] = 0;
            func_0x001b0140(2);
            FUN_005b9110(0x4c);
          }
        }
        else {
          param_2[1] = param_2[1] + '\x01';
          *(undefined1 *)(param_1 + 0x43f) = 1;
          *(undefined2 *)(param_2 + 4) = 8;
          func_0x001b0140();
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
    break;
  case 3:
    sVar1 = *(short *)(param_2 + 4);
    *(short *)(param_2 + 4) = sVar1 + -1;
    if ((short)(sVar1 + -1) < 0) {
      param_2[1] = param_2[1] + '\x01';
      *(undefined1 *)(param_1 + 0x43f) = 0;
      *(undefined2 *)(param_2 + 4) = 6;
      FUN_005b9110(0x4c);
    }
    break;
  case 4:
    sVar1 = *(short *)(param_2 + 4);
    *(short *)(param_2 + 4) = sVar1 + -1;
    if ((short)(sVar1 + -1) < 0) {
      if (*(char *)(param_1 + 0x43c) == '\0') {
        param_2[1] = param_2[1] + '\x01';
        param_2[2] = 0;
        *(undefined2 *)(param_2 + 6) = 0;
        *(undefined2 *)(param_2 + 4) = 0x10;
      }
      else {
        *param_2 = 1;
        param_2[1] = 0;
        param_2[2] = 0;
      }
    }
    break;
  case 5:
    func_0x00106b60(param_1 + *(short *)(param_2 + 10) * 0x24 + (int)*(short *)(param_2 + 10) +
                    0x1044,0,0x25);
    *param_2 = 1;
    param_2[1] = 0;
    param_2[2] = 0;
  }
  return 0;
}



================================================================