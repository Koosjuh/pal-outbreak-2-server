FUNCTION FUN_005c9a00 @ 0x005c9a00  size=580
CALLERS (0): 
CALLEES (4): FUN_005d6460@0x005d6460, FUN_005de170@0x005de170, FUN_005ca6a0@0x005ca6a0, FUN_005de160@0x005de160
----------------------------------------------------------------

void FUN_005c9a00(void)

{
  char cVar1;
  short sVar2;
  long lVar3;
  
  FUN_005ca6a0();
  lVar3 = FUN_005de170(0);
  if (lVar3 != 0) {
    sVar2 = *(short *)lVar3;
    if (sVar2 == 3) {
      *(undefined1 *)(iRam00701070 + 0x2e) = 6;
      *(undefined1 *)(iRam00701068 + 0x68e85) = 2;
      *(char *)(iRam00701070 + 2) = *(char *)(iRam00701070 + 2) + '\x01';
    }
    else if (sVar2 == 2) {
      *(undefined1 *)(iRam00701070 + 0x2e) = 6;
      cVar1 = *(char *)(iRam00701068 + 0x68e85);
      if ((((cVar1 == '\f') || (cVar1 == '\x03')) || (cVar1 == '\x02')) ||
         ((cVar1 == '\x01' || (cVar1 == '\0')))) {
        *(char *)(iRam00701068 + 0x68e85) = '\x02';
      }
      if (((*(char *)(iRam00701070 + 0x2f) == '\x01') && (*(char *)(iRam00701070 + 0x30) == '\x01'))
         || ((*(char *)(iRam00701070 + 0x2f) == '\x02' && (*(char *)(iRam00701070 + 0x30) == '\x02')
             ))) {
        FUN_005d6460();
      }
      else {
        *(undefined1 *)(iRam00701068 + 0x60dcc) = 0;
        *(char *)(iRam00701070 + 2) = *(char *)(iRam00701070 + 2) + '\x01';
      }
    }
    else if (sVar2 == 1) {
      *(undefined1 *)(iRam00701070 + 0x2e) = 5;
      *(undefined1 *)(iRam00701068 + 0x68e85) = 3;
    }
    else if (sVar2 == 0) {
      *(undefined1 *)(iRam00701070 + 0x2e) = 3;
      *(undefined1 *)(iRam00701068 + 0x68e85) = 2;
      if ((((*(char *)(iRam00701070 + 0x37) != '\0') &&
           ((int)(*(ushort *)(iRam00701070 + 0x18) & 0x20) >> 5 != 0)) &&
          ((*(ushort *)(iRam00701068 + 0x4f8a4) & 0x8000) != 0)) &&
         ((*(char *)(iRam00701068 + 0x60dcb) == '\0' && (*(char *)(iRam00701070 + 0x34) == '\0'))))
      {
        *(undefined1 *)(iRam00701070 + 0x2e) = 4;
        FUN_005de160();
        *(undefined1 *)(iRam00701070 + 1) = 1;
        *(undefined1 *)(iRam00701070 + 2) = 6;
      }
    }
  }
  return;
}



================================================================