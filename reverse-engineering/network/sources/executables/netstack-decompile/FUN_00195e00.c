
undefined4 FUN_00195e00(void)

{
  undefined4 uVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  
  FUN_001a2220();
  lVar2 = FUN_00195cf0();
  if (lVar2 == 0) {
    uVar1 = 0;
  }
  else {
    FUN_00111600();
    FUN_00101f80(1);
    iVar4 = 0;
    do {
      uVar1 = FUN_00101f58(iVar4);
      iVar3 = iVar4 * 4;
      iVar4 = iVar4 + 1;
      *(undefined4 *)(iVar3 + 0x28a2f4) = uVar1;
    } while (iVar4 < 10);
    FUN_0017e3f0();
    uRam00289af0 = 1;
    FUN_00183350(0x289af0,0x1000,0x183680);
    uVar1 = 1;
  }
  return uVar1;
}

