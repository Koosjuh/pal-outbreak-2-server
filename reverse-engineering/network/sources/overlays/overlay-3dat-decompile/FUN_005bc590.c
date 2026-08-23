FUNCTION FUN_005bc590 @ 0x005bc590  size=500
CALLERS (0): 
CALLEES (3): FUN_005c7d00@0x005c7d00, FUN_005c7e30@0x005c7e30, FUN_005bdf90@0x005bdf90
----------------------------------------------------------------

void FUN_005bc590(undefined8 param_1,undefined1 *param_2)

{
  char cVar1;
  byte bVar2;
  long lVar3;
  undefined1 auStack_20 [32];
  
  FUN_005c7d00();
  func_0x00106b60(0x6fc05a,0,0x128);
  cVar1 = param_2[1];
  if (cVar1 == '\0') {
    uRam006fc17e = *param_2;
    bVar2 = param_2[2];
    func_0x001069a8(0x6fc06a,param_2 + 6,bVar2);
    uRam006fc180 = param_2[4];
    uRam006fc181 = param_2[5];
    func_0x001069a8(0x6fc07e,param_2 + bVar2 + 6,param_2[3]);
    FUN_005bdf90(5,0);
  }
  else if (cVar1 == '\x02') {
    func_0x00106b60(auStack_20,0,0x20);
    func_0x001069a8(auStack_20,param_2 + 6,param_2[3]);
    lVar3 = func_0x0010a338(0x36842c,auStack_20,0x20);
    if (lVar3 < 0) {
      if (cRam00700680 == '\0') {
        cRam00700680 = '\x01';
        uRam007006a7 = 1;
        FUN_005c7e30(4);
        FUN_005bdf90(0x2b,0);
      }
    }
    else {
      sRam00700682 = 0;
    }
  }
  else if (cVar1 == '\x01') {
    func_0x00106b60(auStack_20,0,0x20);
    func_0x001069a8(auStack_20,param_2 + 6,param_2[3]);
    lVar3 = func_0x0010a338(0x36842c,auStack_20,0x20);
    if (lVar3 < 0) {
      if (cRam00700680 == '\0') {
        cRam00700680 = '\x01';
        uRam007006a7 = 1;
        FUN_005c7e30(4);
        FUN_005bdf90(0x2b,0);
      }
    }
    else if (0 < lVar3) {
      sRam00700682 = ((ushort)uRam006febb4 & 0xf) * 0x1e;
    }
  }
  return;
}



================================================================