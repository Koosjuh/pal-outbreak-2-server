
undefined8 FUN_001c2f80(void)

{
  undefined4 uVar1;
  int iVar2;
  long lVar3;
  
  FUN_001c2da0(0);
  FUN_00106b60(0x368420,0,0x74);
  FUN_00106b60(0x365e00,0,0x2620);
  iRam0035ccc0 = iRam003435fc + 0x3000;
  iRam0035ccc8 = iRam003435fc;
  iRam0035ccb8 = iRam003435fc + 0x4000;
  FUN_00106b60(iRam003435fc,0,0x3000);
  FUN_00106b60(iRam0035ccc0,0,0x1000);
  FUN_00106b60(iRam0035ccb8,0,0x1000);
  uRam00365df0 = 0x702140;
  iRam003684a8 = func_0x0061c8e0();
  pcRam003684a0 = (char *)func_0x0061c900();
  puRam00368498 = (undefined4 *)func_0x0061c920();
  uRam00368474 = 0x361a70;
  uRam00368478 = 0x363a70;
  uRam00365e14 = 0x35ccd0;
  sRam00365cf0 = (short)*pcRam003684a0;
  for (lVar3 = 0; lVar3 < *pcRam003684a0; lVar3 = (long)((int)lVar3 + 1)) {
    iVar2 = (int)lVar3 * 4;
    *(undefined4 *)(iVar2 + 0x365d34) = *(undefined4 *)(iRam003684a8 + iVar2);
    uVar1 = FUN_0010a050(*(undefined4 *)(iVar2 + 0x365d34));
    *(undefined4 *)(iVar2 + 0x365cf4) = uVar1;
  }
  uRam00365c20 = 1;
  uRam00365c64 = *puRam00368498;
  uRam00365c24 = FUN_0010a050(uRam00365c64);
  FUN_0010a4f0(0x35b8e0,0x248760,0x100);
  uRam0035b9e8 = 100;
  FUN_0010a4f0(0x35bee0,0x248790,0x100);
  return 0;
}

