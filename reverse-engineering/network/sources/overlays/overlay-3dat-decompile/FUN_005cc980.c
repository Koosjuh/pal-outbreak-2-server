FUNCTION FUN_005cc980 @ 0x005cc980  size=880
CALLERS (2): FUN_005ca1a0@0x005ca1a0, FUN_005c9690@0x005c9690
CALLEES (5): FUN_005d8340@0x005d8340, FUN_005d59f0@0x005d59f0, FUN_005d7410@0x005d7410, FUN_005d5cc0@0x005d5cc0, FUN_005d6390@0x005d6390
----------------------------------------------------------------

undefined4 FUN_005cc980(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  long lVar3;
  undefined8 uVar4;
  
  lVar3 = FUN_005d8340(iRam00701068 + 0x4f97c);
  if (lVar3 == 0) {
    uVar2 = 0;
  }
  else {
    uRam00700fe8 = 0;
    *(undefined1 *)(iRam00701070 + 0x39) = 0;
    puVar1 = (undefined4 *)lVar3;
    switch(*(undefined1 *)(puVar1 + 1)) {
    case 0:
      *(undefined4 *)(iRam00701068 + 0x68dd0) = *puVar1;
      if (*(char *)((int)puVar1 + 5) == '\t') {
        *(undefined1 *)(iRam00701070 + 0x39) = 1;
      }
      func_0x00106b60(iRam00701070 + 0x33b,0,0x100);
      lVar3 = func_0x0010a050(*(undefined4 *)(iRam00701068 + 0x68dd0));
      if (lVar3 == 0) {
        uVar2 = 0xfffffffe;
        *(undefined1 *)(iRam00701068 + 0x60dcc) = 2;
        *(undefined1 *)(iRam00701070 + 0x30) = 0;
      }
      else {
        if ((*(char *)(iRam00701068 + 0x60dc7) != '\0') &&
           ((cRam003c8a80 == '\x02' || (cRam003c8a80 == '\x01')))) {
          *(undefined4 *)(iRam00701070 + 0x14) = 0xff000000;
          *(undefined1 *)(iRam00701070 + 0x34) = 1;
        }
        uVar2 = 1;
        if (1 < *(byte *)(iRam00701068 + 0x60dcd)) {
          uVar2 = 0xfffffffe;
          *(undefined1 *)(iRam00701068 + 0x60dcc) = 2;
          *(undefined1 *)(iRam00701070 + 0x30) = 0;
        }
      }
      break;
    case 1:
      uVar2 = 0xffffffff;
      if (*(char *)(iRam00701068 + 0x60dcb) != '\0') {
        uVar2 = 0xfffffffe;
        *(undefined1 *)(iRam00701068 + 0x60dcc) = 2;
      }
      break;
    case 2:
      *(undefined4 *)(iRam00701068 + 0x68dd0) = *puVar1;
      lVar3 = FUN_005d6390();
      if (lVar3 == 0) {
        uVar4 = FUN_005d7410();
        lVar3 = func_0x00109d70(uVar4,iRam00701080 + 0x1c);
        if ((lVar3 == 0) &&
           (lVar3 = func_0x00109d70(iRam00701068 + 0x4f7a0,iRam00701080 + 0x1c), lVar3 != 0)) {
          uVar2 = 0xfffffffe;
          *(undefined1 *)(iRam00701068 + 0x60dcc) = 2;
          *(undefined1 *)(iRam00701070 + 0x30) = 0;
        }
        else {
          uVar2 = 0xffffffff;
          *(undefined1 *)(iRam00701070 + 0x34) = 0;
          *(undefined1 *)(iRam00701070 + 0x39) = 1;
        }
      }
      else {
        uVar2 = 2;
      }
      break;
    case 3:
      uVar2 = 0xffffffff;
      break;
    case 4:
      *(undefined4 *)(iRam00701068 + 0x68dd0) = *puVar1;
      lVar3 = FUN_005d6390();
      uVar2 = 2;
      if (lVar3 == 0) {
        uVar2 = 0xfffffffe;
      }
      break;
    case 5:
      uVar2 = 0xffffffff;
      break;
    case 6:
      uVar2 = 0xffffffff;
      break;
    case 7:
      uVar2 = 0xffffffff;
      break;
    case 8:
      uVar2 = 1;
      *(undefined4 *)(iRam00701068 + 0x68dd0) = *puVar1;
      break;
    case 9:
      *(undefined1 *)(iRam00701068 + 0x60dcc) = 0;
      FUN_005d5cc0(*puVar1);
      FUN_005d59f0();
      uVar2 = 2;
      break;
    case 10:
      uVar2 = 0xffffffff;
      break;
    case 0xb:
      uVar2 = 0xffffffff;
      break;
    default:
      uVar2 = 0;
    }
  }
  return uVar2;
}



================================================================