FUNCTION FUN_005bf470 @ 0x005bf470  size=708
CALLERS (0): 
CALLEES (2): FUN_005bf1e0@0x005bf1e0, FUN_005c3e50@0x005c3e50
----------------------------------------------------------------

void FUN_005bf470(void)

{
  long lVar1;
  undefined8 uVar2;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  int iStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined *puStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined *puStack_30;
  undefined1 auStack_10 [16];
  
  if (cRam006cbc34 != '\0') {
    switch(cRam006cbc30) {
    case '\0':
      uRam006cbc18 = 1;
      uRam006cbc1c = 0;
      cRam006cbc35 = '\0';
      lVar1 = FUN_005bf1e0(0);
      if (lVar1 == 0) {
        cRam006cbc30 = '\x03';
      }
      else {
        cRam006cbc30 = cRam006cbc30 + '\x01';
        *(undefined2 *)(iRam006cbc24 * 0x144 + 0x6ce49c) = 0;
        func_0x00106b60(0x7006b0,0,0x10);
      }
      break;
    case '\x01':
      cRam006cbc30 = cRam006cbc30 + '\x01';
      func_0x00106b60(&uStack_50,0,0x3c);
      uStack_4c = 1;
      uStack_50 = 0x4c4f4944;
      uStack_44 = 0x53544154;
      uStack_38 = 0x53544154;
      uStack_40 = 0x21;
      uStack_34 = 0x21;
      puStack_3c = &DAT_00640500;
      iStack_48 = (iRam006cbc24 + -1) * 0x24 + 0x6fec28;
      puStack_30 = &DAT_00640500 + (uRam006cbc1c * 2 + 2) * 4;
      uVar2 = func_0x001e0ed8(uRam006febac,&uStack_50,uRam007006ac,0x5c3da0);
      FUN_005c3e50(uVar2,0x5bf830,0x7005e0);
      break;
    case '\x02':
      if (cRam006cbc35 == '\x01') {
        cRam006cbc35 = '\0';
        uRam006cbc1c = uRam006cbc1c + 1;
        if (uRam006cbc1c < 4) {
          cRam006cbc30 = '\x01';
        }
        else {
          cRam006cbc30 = '\x03';
        }
      }
      else if (cRam006cbc35 == '\x02') {
        cRam006cbc30 = '\x03';
      }
      break;
    case '\x03':
      cRam006cbc30 = cRam006cbc30 + '\x01';
      func_0x001dd840(uRam006febac,*(undefined4 *)(iRam006cbc24 * 0x24 + 0x6fec04),0x55534552,
                      0x5bf740);
      break;
    case '\x04':
      if (cRam006cbc35 == '\x01') {
        cRam006cbc35 = '\0';
        cRam006cbc30 = '\x05';
      }
      else if (cRam006cbc35 == '\x02') {
        cRam006cbc30 = '\x06';
      }
      break;
    case '\x05':
      auStack_10[0] = 0;
      cRam006cbc34 = '\0';
      cRam006cbc30 = '\0';
      (*pcRam006cbc14)(auStack_10,auStack_10);
      break;
    case '\x06':
      auStack_10[0] = 0xff;
      cRam006cbc34 = '\0';
      cRam006cbc30 = '\0';
      (*pcRam006cbc14)(auStack_10,auStack_10);
    }
  }
  return;
}



================================================================