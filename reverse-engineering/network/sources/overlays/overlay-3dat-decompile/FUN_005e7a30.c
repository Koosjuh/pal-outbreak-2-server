FUNCTION FUN_005e7a30 @ 0x005e7a30  size=1012
CALLERS (1): FUN_005e7e30@0x005e7e30
CALLEES (5): FUN_005eee00@0x005eee00, FUN_005e7070@0x005e7070, FUN_005f1570@0x005f1570, FUN_005ef040@0x005ef040, FUN_005e6d50@0x005e6d50
----------------------------------------------------------------

undefined4 FUN_005e7a30(ushort param_1)

{
  char cVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  int iVar4;
  long lVar5;
  int iVar6;
  undefined4 *puVar7;
  
  *(undefined2 *)(iRam007012a0 + 0xd968) = 0;
  do {
    puVar7 = (undefined4 *)(iRam007012a0 + 0xd964);
    if (*(char *)*puVar7 == '\0') {
      FUN_005f1570(puVar7,iRam007012a0 + 0xd8e4);
      return 0;
    }
    if (*(int *)(iRam007012a0 + 0xc) == 0) {
      iVar6 = *(int *)(iRam007012a0 + 8) * 0xc;
      iVar4 = *(int *)(iVar6 + 0x647858);
      lVar5 = FUN_005e6d50(puVar7,iVar6 + 0x647850,iRam007012a0 + 0xd8e4);
      if (lVar5 != 0) {
        if (lVar5 < 0) {
          FUN_005f1570(iRam007012a0 + 0xd964,iRam007012a0 + 0xd8e4);
          return 0xffffffff;
        }
        if ((iVar4 == 1) && (cVar1 = **(char **)(iRam007012a0 + 0xd964), cVar1 != '\r')) {
          if (*(char *)(iRam007012a0 + 0x18c) == '\0') {
            if (cVar1 != '\n') {
              if (0x7d < *(int *)(iRam007012a0 + 4)) {
                FUN_005eee00(iRam007012a0 + 0xd8e4);
              }
              uVar2 = **(undefined1 **)(iRam007012a0 + 0xd964);
              iVar4 = iRam007012a0 + *(int *)(iRam007012a0 + 4);
              *(int *)(iRam007012a0 + 4) = *(int *)(iRam007012a0 + 4) + 1;
              *(undefined1 *)(iVar4 + 0xd8e4) = uVar2;
              *(undefined1 *)(iRam007012a0 + *(int *)(iRam007012a0 + 4) + 0xd8e4) = 0;
            }
          }
          else if (cVar1 == '\n') {
            FUN_005ef040(iRam007012a0 + 0xd8e4);
          }
          else if (cVar1 == '\t') {
            if (0x7a < *(int *)(iRam007012a0 + 4)) {
              FUN_005eee00(iRam007012a0 + 0xd8e4);
            }
            iVar4 = iRam007012a0 + *(int *)(iRam007012a0 + 4);
            *(int *)(iRam007012a0 + 4) = *(int *)(iRam007012a0 + 4) + 1;
            *(undefined1 *)(iVar4 + 0xd8e4) = 7;
            iVar4 = iRam007012a0 + *(int *)(iRam007012a0 + 4);
            *(int *)(iRam007012a0 + 4) = *(int *)(iRam007012a0 + 4) + 1;
            *(undefined1 *)(iVar4 + 0xd8e4) = 7;
            iVar4 = iRam007012a0 + *(int *)(iRam007012a0 + 4);
            *(int *)(iRam007012a0 + 4) = *(int *)(iRam007012a0 + 4) + 1;
            *(undefined1 *)(iVar4 + 0xd8e4) = 7;
            iVar4 = iRam007012a0 + *(int *)(iRam007012a0 + 4);
            *(int *)(iRam007012a0 + 4) = *(int *)(iRam007012a0 + 4) + 1;
            *(undefined1 *)(iVar4 + 0xd8e4) = 7;
            *(undefined1 *)(iRam007012a0 + *(int *)(iRam007012a0 + 4) + 0xd8e4) = 0;
          }
          else {
            if (0x7d < *(int *)(iRam007012a0 + 4)) {
              FUN_005eee00(iRam007012a0 + 0xd8e4);
            }
            uVar2 = **(undefined1 **)(iRam007012a0 + 0xd964);
            iVar4 = iRam007012a0 + *(int *)(iRam007012a0 + 4);
            *(int *)(iRam007012a0 + 4) = *(int *)(iRam007012a0 + 4) + 1;
            *(undefined1 *)(iVar4 + 0xd8e4) = uVar2;
            *(undefined1 *)(iRam007012a0 + *(int *)(iRam007012a0 + 4) + 0xd8e4) = 0;
          }
        }
        *(int *)(iRam007012a0 + 0xd964) = *(int *)(iRam007012a0 + 0xd964) + 1;
      }
    }
    else {
      FUN_005e7070();
      uVar3 = func_0x0010a700(*(undefined4 *)(iRam007012a0 + 0xd964),0x6481e8);
      *(undefined4 *)(iRam007012a0 + 0xd8e0) = uVar3;
      if (*(int *)(iRam007012a0 + 0xd8e0) == 0) {
        iVar4 = func_0x0010a050(*(undefined4 *)(iRam007012a0 + 0xd964));
        *(int *)(iRam007012a0 + 0xd964) = *(int *)(iRam007012a0 + 0xd964) + iVar4;
      }
      else {
        *(undefined4 *)(iRam007012a0 + 0xc) = 0;
        *(int *)(iRam007012a0 + 0xd964) = *(int *)(iRam007012a0 + 0xd8e0) + 3;
      }
    }
  } while (*(ushort *)(iRam007012a0 + 0xd968) < param_1);
  return 1;
}



================================================================