FUNCTION FUN_00006844 @ 0x00006844 size=308
CALLERS (1): FUN_00001930@0x00001930
CALLEES (3): FUN_00006784@0x00006784, FUN_00001760@0x00001760, FUN_000067e4@0x000067e4

void FUN_00006844(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  int iVar6;
  int iVar7;
  
  iVar6 = 0;
  iVar7 = 0;
  if (DAT_0001689c != 0) {
    iVar2 = 0;
    iVar3 = DAT_0001689c;
    do {
      if (3 < iVar2 >> 0x10) {
        return;
      }
      cVar1 = *(char *)(iVar3 + 10);
      if ((cVar1 == '\0') || (*(char *)(iVar3 + 10) = cVar1 + -1, cVar1 == '\x01')) {
        iVar2 = *(int *)(iVar3 + 0x10);
        for (sVar5 = 0; (iVar2 != 0 && (sVar5 < 0x20)); sVar5 = sVar5 + 1) {
          iVar4 = *(int *)(iVar2 + 0xc);
          FUN_00001760(iVar2);
          FUN_00006784(iVar2);
          iVar2 = iVar4;
        }
        if (iVar6 == 0) {
          DAT_0001689c = *(int *)(iVar3 + 0xc);
        }
        else {
          *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar3 + 0xc);
        }
        if (DAT_000168a0 == iVar3) {
          DAT_000168a0 = iVar6;
        }
        iVar4 = *(int *)(iVar3 + 0xc);
        FUN_000067e4(iVar3);
      }
      else {
        iVar4 = *(int *)(iVar3 + 0xc);
        iVar6 = iVar3;
      }
      iVar7 = iVar7 + 1;
      iVar2 = iVar7 * 0x10000;
      iVar3 = iVar4;
    } while (iVar4 != 0);
  }
  return;
}


================================================================