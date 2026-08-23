FUNCTION FUN_006130a0 @ 0x006130a0  size=724
CALLERS (1): FUN_00612d10@0x00612d10
CALLEES (5): FUN_0060f8b0@0x0060f8b0, FUN_006146e0@0x006146e0, FUN_0060e1c0@0x0060e1c0, FUN_00614870@0x00614870, FUN_00614720@0x00614720
----------------------------------------------------------------

void FUN_006130a0(void)

{
  char cVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined1 auStack_200 [256];
  undefined1 auStack_100 [256];
  
  iVar2 = FUN_0060f8b0();
  FUN_00614720(0xffffffff80808080);
  for (iVar5 = 0;
      (iVar5 < 2 &&
      ((long)(*(char *)(iRam0070d1c0 + 0x1e) + iVar5) < (long)*(char *)(iRam0070d1c0 + 0x24)));
      iVar5 = iVar5 + 1) {
    iVar6 = *(char *)(iRam0070d1c0 + 0x14) + iVar5;
    iVar4 = iRam0070d1c0 + iVar6 * 0x14;
    if (*(int *)(iVar4 + 0x25c) == -1) {
      FUN_00614720(0xffffffff80000080);
    }
    else {
      iVar4 = *(int *)(iVar4 + 600);
      if ((((iVar4 == 1) &&
           (iVar6 = iRam0070d1c0 + iVar6 * 0x1340, *(char *)(iVar6 + 0xb700) != '\0')) &&
          (*(int *)(iVar6 + 0xc200) == 2)) && (*(char *)(iVar6 + 0xc225) == -1)) {
        FUN_00614720(0xffffffff80000080);
      }
      else if (iVar4 == 2) {
        FUN_00614720(0xffffffff80000080);
      }
    }
    lVar3 = FUN_0060e1c0(iRam0070d1c0 + 0x1180,
                         iRam0070d1c0 + (*(char *)(iRam0070d1c0 + 0x14) + iVar5) * 0x1340 + 0xaf00);
    if (lVar3 == 0) {
      FUN_00614720(0xffffffff80000080);
      func_0x00109eb8(auStack_100,*(undefined4 *)(iVar2 + 0x28));
    }
    else {
      FUN_00614870(auStack_100,lVar3,0x2c);
    }
    func_0x00109728(auStack_200,0x6540e8,iVar5 + 1 + (int)*(char *)(iRam0070d1c0 + 0x14));
    func_0x00109ab0(auStack_200,auStack_100);
    func_0x001af080(0x2c,iVar5 * 0x1a + 0xcc);
    func_0x001af0d0(auStack_200);
    FUN_00614720(0xffffffff80808080);
  }
  if ('\x01' < *(char *)(iRam0070d1c0 + 0x10)) {
    cVar1 = *(char *)(iRam0070d1c0 + 0x13);
    iVar5 = *(int *)(cVar1 * 0x14 + iRam0070d1c0 + 600);
    if ((iVar5 == 0) ||
       (((iVar5 == 1 && (iVar5 = cVar1 * 0x1340 + iRam0070d1c0, *(char *)(iVar5 + 0xb700) != '\0'))
        && ((*(int *)(iVar5 + 0xc200) == 2 && (*(char *)(iVar5 + 0xc225) == -1)))))) {
      func_0x00109eb8(auStack_100,*(undefined4 *)(iVar2 + 0x28));
    }
    else {
      iVar5 = cVar1 * 0x14 + iRam0070d1c0;
      func_0x00109728(auStack_100,0x6540f0,*(undefined4 *)(iVar2 + 0x2c),
                      *(undefined4 *)(iVar5 + 0x260),*(undefined4 *)(iVar5 + 0x264));
    }
    FUN_006146e0(0x2c,0x109,auStack_100);
  }
  return;
}



================================================================