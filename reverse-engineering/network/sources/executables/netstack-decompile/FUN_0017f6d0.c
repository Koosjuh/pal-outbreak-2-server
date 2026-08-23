
int FUN_0017f6d0(undefined4 param_1,undefined4 param_2,int *param_3,undefined1 *param_4,int *param_5
                ,int param_6)

{
  undefined1 *puVar1;
  long lVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iRam0027b008 = *param_3;
  iRam0027b00c = *param_5;
  iVar4 = 0;
  puVar1 = param_4;
  uRam0027b000 = param_1;
  uRam0027b004 = param_2;
  if (0 < *param_3) {
    do {
      puVar3 = (undefined1 *)(iVar4 + 0x27b010);
      iVar4 = iVar4 + 1;
      *puVar3 = *puVar1;
      puVar1 = param_4 + iVar4;
    } while (iVar4 < *param_3);
  }
  lVar2 = FUN_00115c68(0x27af88,0xffffffff80001318,0,0x27b000,0x280,0x27b000,0x280,0);
  if (lVar2 < 0) {
    FUN_0017fd00(0x258b40);
    iVar4 = 0;
  }
  else {
    iVar4 = iRam0027b410;
    if (-1 < iRam0027b410) {
      *param_3 = iRam0027b008;
      *param_5 = iRam0027b00c;
      iVar4 = iRam0027b410;
      if (0 < iRam0027b00c) {
        puVar1 = (undefined1 *)0x27b210;
        iVar5 = 0;
        do {
          iVar6 = iVar5 + 1;
          *(undefined1 *)(param_6 + iVar5) = *puVar1;
          puVar1 = (undefined1 *)(iVar5 + 0x27b211);
          iVar4 = iRam0027b410;
          iVar5 = iVar6;
        } while (iVar6 < iRam0027b00c);
      }
    }
  }
  return iVar4;
}
