
int FUN_0017f818(undefined4 param_1,undefined4 param_2,int *param_3,undefined1 *param_4)

{
  undefined1 *puVar1;
  long lVar2;
  undefined1 *puVar3;
  int iVar4;
  
  WaitSema(uRam0027e540);
  iRam0027b008 = *param_3;
  iVar4 = 0;
  puVar1 = param_4;
  uRam0027b000 = param_1;
  uRam0027b004 = param_2;
  if (0 < *param_3) {
    do {
      puVar3 = (undefined1 *)(iVar4 + 0x27b00c);
      iVar4 = iVar4 + 1;
      *puVar3 = *puVar1;
      puVar1 = param_4 + iVar4;
    } while (iVar4 < *param_3);
  }
  lVar2 = FUN_00115c68(0x27af88,0xffffffff80001319,0,0x27b000,0x280,0x27b000,0x280,0);
  if (lVar2 < 0) {
    FUN_0017fd00(0x258b60);
    SignalSema(uRam0027e540);
    iVar4 = 0;
  }
  else {
    if (-1 < iRam0027b20c) {
      *param_3 = iRam0027b008;
    }
    SignalSema(uRam0027e540);
    iVar4 = iRam0027b20c;
  }
  return iVar4;
}

