FUNCTION FUN_00001a94 @ 0x00001a94 size=676
CALLERS (1): FUN_00001788@0x00001788
CALLEES (7): FUN_00002314@0x00002314, FUN_000009e4@0x000009e4, FUN_00002d04@0x00002d04, FUN_000013ec@0x000013ec, FUN_00001364@0x00001364, FUN_00001394@0x00001394, FUN_00001328@0x00001328

undefined4 FUN_00001a94(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = FUN_00002d04();
  if (DAT_00002f7c != 1) {
    if (1 < DAT_00002f7c) {
      if (DAT_00002f7c != 2) {
        return DAT_00002eb0;
      }
      if (DAT_00002f80 != 0) {
        DAT_00002eb0 = DAT_00002f7c;
        DAT_00002f7c = 0;
        return 2;
      }
      if ((uint)(iVar2 - DAT_00002f60) < 3000) {
        return DAT_00002eb0;
      }
      DAT_00002f64 = DAT_00002f64 + -1;
      if (DAT_00002f64 < 1) {
        FUN_000009e4();
        DAT_00002eb0 = 0xffffffff;
        DAT_00002f50 = 6;
        DAT_00002f7c = 0xffffffff;
        return 0xffffffff;
      }
      DAT_00002f7c = 1;
      return DAT_00002eb0;
    }
    if (DAT_00002f7c != 0) {
      return DAT_00002eb0;
    }
    FUN_000009e4();
    sVar1 = FUN_00001328(0,0,0xffffffff);
    if (sVar1 != 0) {
      FUN_00001364(0);
      sVar1 = FUN_00001328(0,0,0xffffffff);
      if (sVar1 != 0) {
        DAT_00002eb0 = 0xfffffffe;
        DAT_00002f50 = 3;
        DAT_00002f7c = 0xffffffff;
        return 0xfffffffe;
      }
    }
    DAT_00002f84 = 1;
    DAT_00002f88 = FUN_00001394(0,0x4300,0x4400,0xe10);
    if ((int)((uint)DAT_00002f88 << 0x10) < 0) {
      FUN_00001364();
      DAT_00002eb0 = 0xfffffffe;
      DAT_00002f50 = 4;
      DAT_00002f7c = 0xffffffff;
      DAT_00002f84 = 0;
      return 0xfffffffe;
    }
    DAT_00002f7c = 1;
    DAT_00002f64 = DAT_000042a8;
  }
  iVar3 = FUN_00002314(&DAT_00002f98);
  DAT_00002f80 = 0;
  if (iVar3 < 300) {
    iVar3 = 300;
  }
  iVar3 = FUN_000013ec((int)(short)DAT_00002f88,0xffffffff,0x4300,(int)(short)iVar3,&DAT_00002f98);
  if (iVar3 << 0x10 < 0) {
    FUN_000009e4();
    DAT_00002f50 = 5;
    DAT_00002f7c = 0xffffffff;
    DAT_00002eb0 = 0xfffffffe;
  }
  else {
    DAT_00002f7c = 2;
    DAT_00002f60 = iVar2;
  }
  return DAT_00002eb0;
}


================================================================