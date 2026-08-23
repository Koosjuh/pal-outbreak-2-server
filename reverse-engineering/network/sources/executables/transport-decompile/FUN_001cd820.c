
void FUN_001cd820(undefined8 param_1,undefined2 param_2,undefined2 *param_3)

{
  char cVar1;
  undefined4 uVar2;
  undefined2 uVar3;
  char *pcVar4;
  int iVar5;
  long lVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  char acStack_300 [256];
  undefined1 auStack_200 [256];
  undefined1 auStack_100 [256];
  
  *param_3 = 0xffff;
  uVar2 = DAT_0024c7f8;
  lVar6 = FUN_001cc170(DAT_0024c7f8,param_2,0,0);
  if (lVar6 != 0) {
    if (cRam00343577 == '\0') {
      FUN_00109eb8(auStack_100,lVar6);
      iVar5 = FUN_0010a6b0(auStack_100,0x5c);
      *(undefined1 *)(iVar5 + 1) = 0;
      pcVar4 = pcRam0036b9c0;
      iVar5 = FUN_001cb360(lVar6,pcRam0036b9c0,1,0);
      iVar9 = 0;
      if (0 < iVar5) {
        iVar8 = 0;
        do {
          FUN_00109eb8(auStack_200,auStack_100);
          pcVar7 = acStack_300;
          while ((cVar1 = *pcVar4, cVar1 != '\n' && (cVar1 != '\0'))) {
            iVar9 = iVar9 + 1;
            *pcVar7 = cVar1;
            pcVar4 = pcVar4 + 1;
            pcVar7 = pcVar7 + 1;
            if (iVar5 <= iVar9) goto LAB_001cda58;
          }
          *pcVar7 = '\0';
          pcVar4 = pcVar4 + 1;
          iVar9 = iVar9 + 1;
          lVar6 = FUN_0010a6b0(acStack_300,0x2e);
          if (lVar6 == 0) {
            lVar6 = FUN_0010a6b0(acStack_300,0x2c);
            if (lVar6 != 0) {
              *(undefined1 *)lVar6 = 0;
            }
          }
          else {
            *(undefined1 *)lVar6 = 0;
          }
          lVar6 = FUN_0010a050(acStack_300);
          if (lVar6 == 0) break;
          lVar6 = FUN_0010a6b0(acStack_300,0x2f);
          if (lVar6 == 0) {
            FUN_00109ab0(auStack_200,acStack_300);
          }
          else {
            FUN_00109ab0(auStack_200,(int)lVar6 + 1);
          }
          FUN_00109ab0(auStack_200,0x24c9b0);
          uVar3 = FUN_001cb7f0(auStack_200,uVar2,4);
          iVar8 = iVar8 + 1;
          *param_3 = uVar3;
          param_3 = param_3 + 1;
        } while (iVar8 < 7);
LAB_001cda58:
        if (iVar8 < 7) {
          *param_3 = 0xffff;
        }
      }
    }
    else {
      lVar6 = FUN_0010a6b0(lVar6,0x5c);
      pcVar4 = (char *)0x0;
      if (lVar6 != 0) {
        pcVar4 = (char *)((int)lVar6 + 1);
      }
      pcVar7 = pcVar4;
      if (*pcVar4 == 'H') {
        pcVar7 = pcVar4 + 1;
      }
      if (*pcVar7 == 'E') {
        FUN_00109728(auStack_200,0x24ca58,pcVar4);
      }
      else {
        FUN_00109728(auStack_200,0x24ca60,pcVar4);
      }
      lVar6 = FUN_0010a6b0(auStack_200,0x2e);
      if (lVar6 != 0) {
        *(undefined1 *)lVar6 = 0;
      }
      FUN_001a19a0(auStack_200,param_3,uVar2,0);
    }
  }
  return;
}

