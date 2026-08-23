FUNCTION FUN_005f8060 @ 0x005f8060  size=308
CALLERS (2): FUN_005f8030@0x005f8030, FUN_005fb710@0x005fb710
CALLEES (5): FUN_005b6900@0x005b6900, FUN_005c0e30@0x005c0e30, FUN_005b68e0@0x005b68e0, FUN_005f6970@0x005f6970, FUN_005b9060@0x005b9060
----------------------------------------------------------------

void FUN_005f8060(undefined1 *param_1)

{
  char cVar1;
  short sVar2;
  
  cVar1 = param_1[0x10];
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
    FUN_005b6900();
  }
  else if (cVar1 == '\x02') {
    param_1[0x10] = 3;
    FUN_005b68e0();
    param_1[0x42b] = 8;
    param_1[0x997] = 0;
    FUN_005c0e30(0,0,0,0x5f81a0);
  }
  else if (cVar1 == '\x01') {
    sVar2 = *(short *)(param_1 + 0x16);
    *(short *)(param_1 + 0x16) = sVar2 + -1;
    if ((short)(sVar2 + -1) < 0) {
      param_1[0x10] = param_1[0x10] + '\x01';
    }
  }
  else if (cVar1 == '\0') {
    param_1[0x10] = 1;
    FUN_005b9060(0x14,param_1 + 0x5ec);
    *(undefined2 *)(param_1 + 0x16) = 0x2e;
  }
  return;
}



================================================================