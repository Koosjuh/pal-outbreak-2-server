FUNCTION FUN_005c9690 @ 0x005c9690  size=616
CALLERS (0): 
CALLEES (9): FUN_005d5b10@0x005d5b10, FUN_005d5c20@0x005d5c20, FUN_005cc980@0x005cc980, FUN_005d6460@0x005d6460, FUN_005d7410@0x005d7410, FUN_005d5cc0@0x005d5cc0, FUN_005d5b60@0x005d5b60, FUN_005d5ba0@0x005d5ba0, FUN_005ca6a0@0x005ca6a0
----------------------------------------------------------------

void FUN_005c9690(void)

{
  char cVar1;
  undefined8 uVar2;
  long lVar3;
  
  if ((*(char *)(iRam00701070 + 0x36) == '\0') || (-1 < *(char *)(iRam00701070 + 0x3a))) {
    *(undefined1 *)(iRam00701068 + 0x68e85) = 2;
    FUN_005ca6a0();
    cVar1 = FUN_005cc980();
    if (cVar1 != '\x02') {
      if (cVar1 == '\x01') {
        *(char *)(iRam00701070 + 2) = *(char *)(iRam00701070 + 2) + '\x01';
        *(undefined1 *)(iRam00701070 + 0x2e) = 3;
      }
      else if (cVar1 == '\0') {
        if ((((int)(*(ushort *)(iRam00701070 + 0x18) & 0x20) >> 5 != 0) &&
            ((((*(ushort *)(iRam00701068 + 0x4f8a4) & 0x8000) != 0 ||
              ((*(ushort *)(iRam00701068 + 0x4f8a4) & 0x200) != 0)) &&
             (*(char *)(iRam00701068 + 0x60dcb) == '\0')))) &&
           (*(char *)(iRam00701070 + 0x34) == '\0')) {
          *(undefined1 *)(iRam00701070 + 0x2e) = 2;
          FUN_005d5c20(6);
        }
      }
      else if (cVar1 == -1) {
        if (*(char *)(iRam00701068 + 0x60dcb) != '\0') {
          uVar2 = func_0x0010a050(0x642bc8);
          lVar3 = func_0x00106910(iRam00701070 + 0x3b,0x642bc8,uVar2);
          if (lVar3 == 0) {
            FUN_005d5b60(0);
            return;
          }
        }
        if ((*(char *)(iRam00701070 + 0x30) == '\x02') || (*(char *)(iRam00701070 + 0x30) == '\x01')
           ) {
          FUN_005d6460();
        }
        else {
          uVar2 = FUN_005d7410();
          FUN_005d5cc0(uVar2);
          FUN_005d5b10();
        }
      }
      else if (cVar1 == -2) {
        *(undefined1 *)(iRam00701068 + 0x60dca) = 2;
        FUN_005d5ba0(0);
        *(undefined1 *)(iRam00701078 + 2) = 1;
        *(char *)(iRam00701070 + 2) = *(char *)(iRam00701070 + 2) + '\x01';
      }
    }
  }
  else {
    FUN_005ca6a0();
  }
  return;
}



================================================================