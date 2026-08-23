FUNCTION FUN_00002150 @ 0x00002150 size=452
CALLERS (1): FUN_00001788@0x00001788
CALLEES (7): FUN_00001328@0x00001328, FUN_00002d04@0x00002d04, FUN_000013ec@0x000013ec, FUN_0000046c@0x0000046c, FUN_000009e4@0x000009e4, FUN_00002800@0x00002800, FUN_00000900@0x00000900

undefined4 FUN_00002150(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = FUN_00002d04();
  if (DAT_00002f7c == 0) {
    FUN_000009e4();
    sVar1 = FUN_00001328(0,0,0xffffffff);
    if (sVar1 != 0) {
      DAT_00002eb0 = 0xfffffffe;
      DAT_00002f50 = 3;
      DAT_00002f7c = 0xffffffff;
      return 0xfffffffe;
    }
    DAT_00002f84 = 1;
    iVar3 = FUN_00000900();
    if (iVar3 != 0) {
      return DAT_00002eb0;
    }
    DAT_00002f78 = DAT_000042a8;
  }
  else if (DAT_00002f7c != 1) {
    return DAT_00002eb0;
  }
  if (DAT_00002f7c == 0) {
    DAT_00002f7c = 1;
  }
  else if ((uint)(iVar2 - DAT_00002f74) < 300) {
    return DAT_00002eb0;
  }
  iVar3 = FUN_00002800(&DAT_00002f98);
  if (iVar3 < 300) {
    iVar3 = 300;
  }
  iVar3 = FUN_000013ec((int)DAT_00002f88,0xffffffff,0x4300,(int)(short)iVar3,&DAT_00002f98);
  if (iVar3 << 0x10 < 0) {
    FUN_000009e4();
    DAT_00002f7c = 0xffffffff;
    DAT_00002f50 = 5;
    DAT_00002eb0 = 0xfffffffe;
    return 0xfffffffe;
  }
  DAT_00002f78 = DAT_00002f78 + -1;
  if (DAT_00002f78 < 1) {
    DAT_00002f74 = iVar2;
    FUN_000009e4();
    DAT_00002eb0 = 0;
    DAT_00002f7c = 0;
    FUN_0000046c(0xf,0,0);
    FUN_0000046c(0xe,0,0);
    return DAT_00002eb0;
  }
  DAT_00002f74 = iVar2;
  return DAT_00002eb0;
}


================================================================