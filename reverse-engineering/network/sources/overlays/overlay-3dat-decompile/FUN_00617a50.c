FUNCTION FUN_00617a50 @ 0x00617a50  size=348
CALLERS (1): FUN_005acab0@0x005acab0
CALLEES (7): FUN_005aec70@0x005aec70, FUN_005b2470@0x005b2470, FUN_005b6900@0x005b6900, FUN_005af300@0x005af300, FUN_005c0e30@0x005c0e30, FUN_005b68e0@0x005b68e0, FUN_005f6970@0x005f6970
----------------------------------------------------------------

void FUN_00617a50(undefined1 *param_1)

{
  char cVar1;
  short sVar2;
  long lVar3;
  
  lVar3 = FUN_005aec70();
  if (lVar3 == 0) {
    cVar1 = param_1[0xf];
    if (cVar1 == '\x04') {
      if (param_1[0x997] == '\x01') {
        *param_1 = 1;
        param_1[1] = 0;
        param_1[0xe] = 0;
        param_1[0xf] = 0;
        param_1[0x10] = 0;
        param_1[0x11] = 0;
        param_1[0x12] = 0;
      }
      else if (param_1[0x997] == '\x02') {
        FUN_005f6970();
      }
    }
    else if (cVar1 == '\x03') {
      sVar2 = *(short *)(param_1 + 0x16);
      *(short *)(param_1 + 0x16) = sVar2 + -1;
      if ((short)(sVar2 + -1) < 0) {
        func_0x001a6780();
        FUN_005b2470(3);
        param_1[0xf] = 0;
      }
    }
    else if (cVar1 == '\x02') {
      FUN_005af300(0,10);
      func_0x001a6910(0,0,0x10);
      param_1[0xf] = param_1[0xf] + '\x01';
      *(undefined2 *)(param_1 + 0x16) = 0x10;
    }
    else if (cVar1 == '\x01') {
      FUN_005b6900();
    }
    else if (cVar1 == '\0') {
      param_1[0xf] = 1;
      FUN_005b68e0();
      param_1[0x42b] = 0x1c;
      param_1[0x997] = 0;
      FUN_005c0e30(0,0,0,0x618130);
    }
  }
  return;
}



================================================================