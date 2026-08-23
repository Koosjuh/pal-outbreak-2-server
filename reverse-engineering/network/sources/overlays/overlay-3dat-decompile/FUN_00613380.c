FUNCTION FUN_00613380 @ 0x00613380  size=292
CALLERS (1): FUN_00612d10@0x00612d10
CALLEES (2): FUN_006146e0@0x006146e0, FUN_00614720@0x00614720
----------------------------------------------------------------

void FUN_00613380(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  long lVar4;
  short sVar5;
  int iVar6;
  undefined1 auStack_100 [256];
  
  sVar5 = 0;
  lVar4 = 0;
  FUN_00614720(0xffffffff80808080);
  iVar6 = 0;
  iVar1 = 0;
  do {
    iVar1 = (iVar1 - iVar6) * 4;
    piVar3 = (int *)(iVar1 + 0x35c000);
    if (*piVar3 != -1) {
      if (*(int *)(iVar1 + 0x35c008) == 1) {
        FUN_00614720(0xffffffff80808080);
        iVar2 = *piVar3;
      }
      else {
        FUN_00614720(0xffffffff80404040);
        iVar2 = *piVar3;
      }
      if ((iVar2 == 1) && (*(char *)(iRam0070d1c0 + 0x1d) <= lVar4)) {
        func_0x00109728(auStack_100,0x6540f8,*(undefined4 *)(iVar1 + 0x35c014),
                        *(undefined4 *)(iVar1 + 0x35c018));
        FUN_006146e0(0x65,sVar5 * 0x1c + 0xc4,auStack_100);
        sVar5 = sVar5 + 1;
      }
      lVar4 = (long)((int)lVar4 + 1);
    }
    iVar6 = iVar6 + 1;
    iVar1 = iVar6 * 8;
  } while (iVar6 < 0x23);
  FUN_00614720(0xffffffff80808080);
  return;
}



================================================================