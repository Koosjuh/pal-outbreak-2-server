
void FUN_001ccb80(undefined8 param_1,int param_2)

{
  char cVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  char acStack_300 [256];
  undefined1 auStack_200 [256];
  undefined1 auStack_100 [256];
  
  if (((param_2 != -1) || (param_2 = DAT_0024c7f8, DAT_0024c7f8 != -1)) &&
     (lVar4 = FUN_001cc170(param_2,param_1,0,0), lVar4 != 0)) {
    lVar2 = FUN_0010a050(lVar4);
    if (lVar2 != 0) {
      FUN_00109eb8(auStack_100,lVar4);
      iVar3 = FUN_0010a6b0(auStack_100,0x5c);
      *(undefined1 *)(iVar3 + 1) = 0;
      pcVar6 = pcRam0036b9c0;
      iVar3 = FUN_001cb360(lVar4,pcRam0036b9c0,1,0);
      iVar7 = 0;
      if (iVar3 != 0) {
        while( true ) {
          FUN_00109eb8(auStack_200,auStack_100);
          pcVar5 = acStack_300;
          while ((cVar1 = *pcVar6, cVar1 != '\n' && (cVar1 != '\0'))) {
            iVar7 = iVar7 + 1;
            *pcVar5 = cVar1;
            pcVar6 = pcVar6 + 1;
            pcVar5 = pcVar5 + 1;
            if (iVar3 <= iVar7) {
              return;
            }
          }
          *pcVar5 = '\0';
          pcVar6 = pcVar6 + 1;
          iVar7 = iVar7 + 1;
          lVar4 = FUN_0010a6b0(acStack_300,0x2e);
          if (lVar4 == 0) {
            lVar4 = FUN_0010a6b0(acStack_300,0x2c);
            if (lVar4 != 0) {
              *(undefined1 *)lVar4 = 0;
            }
          }
          else {
            *(undefined1 *)lVar4 = 0;
          }
          lVar4 = FUN_0010a050(acStack_300);
          if (lVar4 == 0) break;
          lVar4 = FUN_0010a6b0(acStack_300,0x2f);
          if (lVar4 == 0) {
            FUN_00109ab0(auStack_200,acStack_300);
          }
          else {
            FUN_00109ab0(auStack_200,(int)lVar4 + 1);
          }
          FUN_00109ab0(auStack_200,0x24c9b0);
          lVar4 = FUN_001ccb10(auStack_200);
          if (lVar4 < 0) {
            FUN_001cb7f0(auStack_200,param_2,1);
          }
          else {
            FUN_001cb750(0xff0,lVar4,lVar4);
          }
          param_2 = param_2 + 1;
        }
      }
    }
  }
  return;
}

