FUNCTION FUN_00606fc0 @ 0x00606fc0  size=660
CALLERS (1): FUN_00606cf0@0x00606cf0
CALLEES (15): FUN_005af2f0@0x005af2f0, FUN_00606e40@0x00606e40, FUN_00606f60@0x00606f60, FUN_005af300@0x005af300, FUN_005b8cf0@0x005b8cf0, FUN_00606fa0@0x00606fa0, FUN_005c78e0@0x005c78e0, FUN_005c7bd0@0x005c7bd0, FUN_00607a10@0x00607a10, FUN_005c79d0@0x005c79d0, FUN_005b9110@0x005b9110, FUN_00618b60@0x00618b60, ...
----------------------------------------------------------------

void FUN_00606fc0(undefined8 param_1)

{
  char cVar1;
  short sVar2;
  long lVar3;
  int iVar4;
  undefined1 *puVar5;
  
  if ((cRam00874f35 == '\x03') ||
     (((cRam00874f35 != '\x02' && (cRam00874f35 != '\x01')) && (cRam00874f35 != '\0')))) {
    if (cRam00870868 == '\0') {
      FUN_00606e40();
      FUN_005af300(0,1);
    }
    else if (cRam00870868 == '\x01') {
      uRam003c8a80 = 1;
      cRam00870868 = '\x02';
    }
    else if (cRam00870868 == '\x02') {
      FUN_00606e40();
      FUN_005af300(0,1);
    }
  }
  else {
    puVar5 = (undefined1 *)param_1;
    cVar1 = puVar5[1];
    if (cVar1 == '\x03') {
      sVar2 = *(short *)(puVar5 + 4);
      *(short *)(puVar5 + 4) = sVar2 + -1;
      if ((short)(sVar2 + -1) < 0) {
        FUN_00618b60();
        func_0x00106b60(0x6c5490,0,0x20);
        FUN_00607a10(0x6c5490);
        *puVar5 = 2;
        puVar5[1] = 0;
      }
    }
    else if (cVar1 == '\x02') {
      lVar3 = FUN_005c7a00();
      if (lVar3 == -1) {
        FUN_00606f60();
      }
      else if (lVar3 == 1) {
        FUN_00606e40();
      }
    }
    else {
      if (cVar1 != '\x01') {
        if (cVar1 != '\0') {
          return;
        }
        FUN_005af2f0(0);
        FUN_00618b60();
        FUN_005b8cf0(0x51);
        FUN_005c78e0();
        puVar5[1] = puVar5[1] + '\x01';
      }
      lVar3 = FUN_005c7900();
      if (lVar3 == -1) {
        FUN_00606fa0(param_1,2);
        FUN_005b9110(0x4c);
      }
      else if (lVar3 == 1) {
        FUN_005c7ba0(0x8744f8);
        for (iVar4 = 0; iVar4 < (int)(uint)bRam008744f8; iVar4 = iVar4 + 1) {
          FUN_005c7bd0(iVar4 + 1U & 0xffff,iVar4 * 0x158 + 0x70c000);
        }
        if (bRam008744f8 < 2) {
          func_0x001069a8(0x874f3c,0x70c048,0x10);
          puVar5[1] = puVar5[1] + '\x01';
          FUN_005c79d0(1);
        }
        else {
          puVar5[1] = 3;
          *(undefined2 *)(puVar5 + 4) = 8;
        }
      }
    }
  }
  return;
}



================================================================