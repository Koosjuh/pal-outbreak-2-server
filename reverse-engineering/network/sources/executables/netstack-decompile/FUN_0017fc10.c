
int FUN_0017fc10(undefined4 param_1,undefined4 param_2,int *param_3,int param_4)

{
  undefined1 *puVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  
  iRam0027b008 = *param_3;
  uRam0027b000 = param_1;
  uRam0027b004 = param_2;
  lVar3 = FUN_00115c68(0x27af88,0xffffffff8000131a,0,0x27b000,0x280,0x27b000,0x280,0);
  if (lVar3 < 0) {
    FUN_0017fd00(0x258c38);
    iVar2 = 0;
  }
  else {
    iVar2 = iRam0027b20c;
    if (-1 < iRam0027b20c) {
      *param_3 = iRam0027b008;
      iVar2 = iRam0027b20c;
      if (0 < iRam0027b008) {
        puVar1 = (undefined1 *)0x27b00c;
        iVar4 = 0;
        do {
          iVar5 = iVar4 + 1;
          *(undefined1 *)(param_4 + iVar4) = *puVar1;
          puVar1 = (undefined1 *)(iVar4 + 0x27b00d);
          iVar2 = iRam0027b20c;
          iVar4 = iVar5;
        } while (iVar5 < iRam0027b008);
      }
    }
  }
  return iVar2;
}

