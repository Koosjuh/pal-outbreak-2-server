
/* WARNING: Removing unreachable block (ram,0x001e20fc) */

undefined4 FUN_001e20a0(int *param_1)

{
  short sVar1;
  short sVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  ushort uStack_88;
  undefined1 auStack_80 [4];
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_6c;
  int iStack_60;
  long lStack_50;
  long lStack_48;
  long lStack_40;
  long lStack_38;
  long lStack_30;
  long lStack_28;
  
  puVar3 = (undefined4 *)FUN_00103de8();
  *puVar3 = 0;
  FUN_001e41fc(&lStack_40,0);
  lStack_50 = (long)*param_1;
  lStack_48 = (long)(param_1[1] / 1000);
  uStack_78 = 0;
  uStack_7c = 1;
  uStack_6c = 0;
  iRam0025b800 = CreateSema(auStack_80);
  if (iRam0025b800 < 0) {
    puVar3 = (undefined4 *)FUN_00103de8();
    *puVar3 = 0xe;
    uVar4 = 0xffffffff;
  }
  else {
    while ((-1 < lStack_50 && (-1 < lStack_48))) {
      if (lStack_50 < 4) {
        sVar1 = (short)lStack_50;
        sVar2 = FUN_0010ea10(lStack_48,0x3f);
        uStack_88 = sVar1 * 0x3da4 + sVar2;
      }
      else {
        uStack_88 = 0xb8ec;
      }
      if (1 < uStack_88) {
        iStack_60 = SetAlarm(uStack_88,0x1e2058,0x25b800);
        if (iStack_60 < 0) {
          puVar3 = (undefined4 *)FUN_00103de8();
          *puVar3 = 0xe;
          return 0xffffffff;
        }
        WaitSema(iRam0025b800);
      }
      FUN_001e41fc(&lStack_30,0);
      lStack_50 = lStack_50 - (lStack_30 - lStack_40);
      for (lStack_48 = lStack_48 - (lStack_28 - lStack_38); lStack_48 < 0;
          lStack_48 = lStack_48 + 1000000) {
        lStack_50 = lStack_50 + -1;
      }
      lStack_40 = lStack_30;
      lStack_38 = lStack_28;
    }
    DeleteSema(iRam0025b800);
    uVar4 = 0;
  }
  return uVar4;
}

