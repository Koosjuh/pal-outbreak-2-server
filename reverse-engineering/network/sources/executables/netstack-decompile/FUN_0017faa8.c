
undefined4
FUN_0017faa8(undefined4 param_1,undefined4 param_2,int *param_3,undefined1 *param_4,
            undefined8 param_5)

{
  undefined1 *puVar1;
  long lVar2;
  undefined1 *puVar3;
  int iVar4;
  
  if (*param_3 < 0x2081) {
    WaitSema(uRam0027e540);
    iRam0027c388 = *param_3;
    iVar4 = 0;
    puVar1 = param_4;
    uRam0027c380 = param_1;
    uRam0027c384 = param_2;
    if (0 < *param_3) {
      do {
        puVar3 = (undefined1 *)(iVar4 + 0x27c38c);
        iVar4 = iVar4 + 1;
        *puVar3 = *puVar1;
        puVar1 = param_4 + iVar4;
      } while (iVar4 < *param_3);
    }
    lVar2 = FUN_00115e60(0x27afd8);
    if (lVar2 == 1) {
      FUN_0017fd00(0x258c18);
    }
    else {
      lVar2 = FUN_00115c68(0x27afd8,0xffffffff8000131c,1,0x27c380,0x2090,0x27c380,0x2090,param_5);
      if (-1 < lVar2) {
        SignalSema(uRam0027e540);
        return 1;
      }
    }
    SignalSema(uRam0027e540);
  }
  else {
    FUN_0017fd00(0x258bf0);
  }
  return 0;
}

