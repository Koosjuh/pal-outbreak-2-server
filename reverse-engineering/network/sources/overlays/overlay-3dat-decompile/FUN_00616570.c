FUNCTION FUN_00616570 @ 0x00616570  size=380
CALLERS (2): FUN_006140d0@0x006140d0, FUN_00613600@0x00613600
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_00616570(char *param_1,long param_2,undefined8 param_3)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  long lVar4;
  char *pcVar5;
  char cVar6;
  char *pcVar7;
  char *pcVar8;
  int iVar9;
  int iVar10;
  
  bVar1 = false;
  iVar9 = 0;
  func_0x00102790(param_2,param_3);
  if (param_1 == (char *)0x0) {
    return 0xffffff9b;
  }
  if (param_2 == 0) {
    return 0xffffff9b;
  }
  lVar4 = func_0x0010a338(param_1,0x693930,7);
  iVar10 = (int)param_3 + -1;
  pcVar3 = param_1;
  if (lVar4 == 0) {
    while( true ) {
      lVar4 = func_0x00109be0(pcVar3,0x2e);
      if (lVar4 == 0) break;
      iVar9 = iVar9 + 1;
      pcVar3 = (char *)((int)lVar4 + 1);
    }
    bVar1 = iVar9 == 5;
  }
  pcVar3 = (char *)param_2;
  if (bVar1) {
    iVar2 = func_0x00109be0(param_1,0x2e);
    iVar9 = 0;
    iVar2 = func_0x00109be0(iVar2 + 1,0x2e);
    pcVar8 = (char *)(iVar2 + 1);
    if ((0 < iVar10) && (*pcVar8 != '\0')) {
      pcVar7 = pcVar8;
      pcVar5 = pcVar3;
      if (*pcVar8 != '.') {
        do {
          iVar9 = iVar9 + 1;
          *pcVar5 = *pcVar7;
          if (iVar10 <= iVar9) goto LAB_006166c4;
          cVar6 = pcVar8[iVar9];
          if (cVar6 == '\0') goto LAB_006166c4;
          pcVar7 = pcVar8 + iVar9;
          pcVar5 = pcVar3 + iVar9;
        } while (cVar6 != '.');
        pcVar3 = pcVar3 + iVar9;
      }
      goto LAB_006166c8;
    }
  }
  else {
    iVar9 = 0;
    if ((0 < iVar10) && (*param_1 != '\0')) {
      cVar6 = *param_1;
      while( true ) {
        pcVar8 = pcVar3 + iVar9;
        iVar9 = iVar9 + 1;
        *pcVar8 = cVar6;
        if ((iVar10 <= iVar9) || (param_1[iVar9] == '\0')) break;
        cVar6 = param_1[iVar9];
      }
    }
  }
LAB_006166c4:
  pcVar3 = pcVar3 + iVar9;
LAB_006166c8:
  *pcVar3 = '\0';
  return 0;
}



================================================================