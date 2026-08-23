FUNCTION FUN_005c9c50 @ 0x005c9c50  size=1096
CALLERS (0): 
CALLEES (4): FUN_005d60a0@0x005d60a0, FUN_005cccf0@0x005cccf0, FUN_005d5640@0x005d5640, FUN_005ca6a0@0x005ca6a0
----------------------------------------------------------------

void FUN_005c9c50(void)

{
  char *pcVar1;
  char cVar2;
  long lVar3;
  uint uVar4;
  int iVar5;
  
  if (*(short *)(iRam00701070 + 0x22) == 0) {
    *(undefined2 *)(iRam00701070 + 0x22) = 1;
  }
  if (*(short *)(iRam00701070 + 0x26) == 0) {
    *(undefined2 *)(iRam00701070 + 0x26) = 1;
  }
  *(undefined2 *)(iRam00701070 + 0x24) = 0x10;
  *(undefined2 *)(iRam00701070 + 0x28) = 0x10;
  if (*(char *)(iRam00701070 + 0x30) != '\0') {
    cVar2 = FUN_005d5640();
    if (cVar2 == -9) {
      *(undefined1 *)(iRam00701070 + 0x30) = 0;
    }
    else if ((cVar2 == -2) || (cVar2 == -1)) {
      *(undefined1 *)(iRam00701068 + 0x60dc7) = 0;
      cVar2 = FUN_005d60a0();
      if (cVar2 == '\x01') {
        *(undefined1 *)(iRam00701070 + 0x30) = 0;
        *(undefined1 *)(iRam00701070 + 0x34) = 0;
        return;
      }
      *(undefined1 *)(iRam00701070 + 0x30) = 0;
      *(undefined1 *)(iRam00701070 + 0x34) = 0;
    }
    else if (cVar2 != '\x02') {
      if (cVar2 == '\x01') {
        return;
      }
      if (cVar2 == '\0') {
        return;
      }
    }
  }
  uVar4 = 0;
  *(undefined1 *)(iRam00701068 + 0x68e7e) = 3;
  while (((uVar4 < 500 &&
          (pcVar1 = *(char **)(iRam00701068 + uVar4 * 4 + 0x5ffc0), pcVar1 != (char *)0x0)) &&
         (*pcVar1 != '\0'))) {
    if ((pcVar1[2] == '\r') && (*pcVar1 == '\x01')) {
      *(undefined1 *)(iRam00701068 + 0x68e7e) = 1;
    }
    uVar4 = uVar4 + 1 & 0xffff;
  }
  cVar2 = *(char *)(iRam00701068 + 0x68e85);
  if ((cVar2 == '\x03') || (cVar2 == '\x02')) {
    *(char *)(iRam00701068 + 0x68e85) = '\x01';
  }
  FUN_005cccf0();
  lVar3 = func_0x0010a050(iRam00701070 + 0x43b);
  if (lVar3 != 0) {
    for (uVar4 = 0; uVar4 < 500; uVar4 = uVar4 + 1 & 0xffff) {
      iVar5 = uVar4 * 4;
      pcVar1 = *(char **)(iRam00701068 + iVar5 + 0x5ffc0);
      if ((pcVar1 == (char *)0x0) || (*pcVar1 == '\0')) break;
      if ((pcVar1[2] == '\x0e') &&
         (lVar3 = func_0x00109d70(*(undefined4 *)(pcVar1 + 0x60),iRam00701070 + 0x43b), lVar3 == 0))
      {
        *(int *)(iRam00701070 + 4) =
             (int)*(float *)(*(int *)(iVar5 + iRam00701068 + 0x5ffc0) + 0x34);
        *(int *)(iRam00701070 + 8) =
             (int)*(float *)(*(int *)(iVar5 + iRam00701068 + 0x5ffc0) + 0x38);
        if (*(int *)(iRam00701070 + 4) < 0) {
          *(undefined4 *)(iRam00701070 + 4) = 0;
        }
        iVar5 = *(int *)(iRam00701070 + 0xc) + -0x248;
        if (iVar5 < *(int *)(iRam00701070 + 4)) {
          *(int *)(iRam00701070 + 4) = iVar5;
        }
        else {
          *(int *)(iRam00701070 + 4) = *(int *)(iRam00701070 + 4) + -0x14;
        }
        if (*(int *)(iRam00701070 + 8) < 0) {
          *(undefined4 *)(iRam00701070 + 8) = 0;
        }
        iVar5 = *(int *)(iRam00701070 + 0x10) + -0x17c;
        if (iVar5 < *(int *)(iRam00701070 + 8)) {
          *(int *)(iRam00701070 + 8) = iVar5;
        }
        else {
          *(int *)(iRam00701070 + 8) = *(int *)(iRam00701070 + 8) + -0x28;
        }
        break;
      }
    }
  }
  FUN_005ca6a0();
  *(char *)(iRam00701070 + 2) = *(char *)(iRam00701070 + 2) + '\x01';
  *(undefined1 *)(iRam00701068 + 0x60dcb) = 0;
  if (*(char *)(iRam00701068 + 0x60dc7) == '\0') {
    *(undefined1 *)(iRam00701070 + 0x3a) = 0x10;
  }
  return;
}



================================================================