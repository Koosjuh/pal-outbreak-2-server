FUNCTION FUN_005d5640 @ 0x005d5640  size=700
CALLERS (2): FUN_005c9c50@0x005c9c50, FUN_005d6460@0x005d6460
CALLEES (6): FUN_005d7540@0x005d7540, FUN_005d5a40@0x005d5a40, FUN_005d5cc0@0x005d5cc0, FUN_005d5b60@0x005d5b60, FUN_005d74a0@0x005d74a0, FUN_005d7690@0x005d7690
----------------------------------------------------------------

undefined4 FUN_005d5640(void)

{
  undefined4 uVar1;
  long lVar2;
  int iVar3;
  char cVar4;
  
  cVar4 = *(char *)(iRam00701070 + 0x30);
  if (cVar4 == '\x05') {
    func_0x0010a338(iRam00701080 + 0x21e,0x642fc0,2);
  }
  else if ((((cVar4 == '\x04') || (cVar4 == '\x02')) || (cVar4 == '\x01')) &&
          (lVar2 = func_0x0010a338(iRam00701080 + 0x21e,0x642fc0,2), lVar2 != 0)) {
    return 0xffffffff;
  }
  switch(*(undefined1 *)(iRam00701070 + 0x30)) {
  default:
    uVar1 = 0xfffffff7;
    break;
  case 1:
  case 2:
    FUN_005d7690();
    lVar2 = FUN_005d7540(0x642c28,iRam00701080 + 0x11);
    if (lVar2 < 0) {
      uVar1 = 0xfffffffe;
    }
    else {
      if (*(char *)(iRam00701070 + 0x30) == '\x02') {
        lVar2 = FUN_005d7540(0x642c20,iRam00701080);
        if (lVar2 < 0) {
          return 0xfffffffe;
        }
      }
      else if (*(char *)(iRam00701070 + 0x30) == '\x01') {
        if ((*(char *)(iRam00701070 + 0x55d) == '\0') ||
           (lVar2 = func_0x00109d70(iRam00701070 + 0x55d,iRam00701080), lVar2 == 0)) {
          lVar2 = FUN_005d7540(0x642c20,iRam00701080);
        }
        else {
          lVar2 = FUN_005d7540(0x642c20,iRam00701070 + 0x55d);
        }
        if (lVar2 < 0) {
          return 0xfffffffe;
        }
      }
      FUN_005d5cc0(iRam00701080 + 0x1c);
      FUN_005d74a0(iRam00701068 + 0x4f97c);
      uRam00700fe8 = 1;
      *(char *)(iRam00701068 + 0x60dcd) = *(char *)(iRam00701068 + 0x60dcd) + '\x01';
      FUN_005d5a40();
      uVar1 = 1;
      *(undefined4 *)(iRam00701070 + 0x14) = 0xff000000;
    }
    break;
  case 4:
  case 5:
    if ((*(char *)(iRam00701070 + 0x55d) != '\0') &&
       (lVar2 = func_0x00109d70(iRam00701070 + 0x55d,iRam00701080), lVar2 != 0)) {
      func_0x00109eb8(iRam00701080,iRam00701070 + 0x55d);
    }
    cVar4 = '\0';
    do {
      iVar3 = (int)cVar4;
      if ('\t' < cVar4) break;
      cVar4 = cVar4 + '\x01';
    } while (*(char *)(iRam00701080 + iVar3 * 0x62 + 0x22f) != '\0');
    FUN_005d5b60(5);
    uVar1 = 0;
    break;
  case 6:
  case 7:
    uVar1 = 2;
  }
  return uVar1;
}



================================================================