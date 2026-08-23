FUNCTION FUN_005c7320 @ 0x005c7320  size=256
CALLERS (1): FUN_005c72d0@0x005c72d0
CALLEES (2): FUN_005bf1e0@0x005bf1e0, FUN_005c3e50@0x005c3e50
----------------------------------------------------------------

void FUN_005c7320(int param_1)

{
  uint uVar1;
  undefined8 uVar2;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  int iStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined *puStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined *puStack_20;
  
  *(char *)(param_1 + 0x21) = *(char *)(param_1 + 0x21) + '\x01';
  func_0x00106b60(&uStack_40,0,0x3c);
  uStack_3c = 1;
  uStack_40 = 0x4c4f4944;
  uVar1 = FUN_005bf1e0(0);
  uStack_34 = 0x53544154;
  uStack_28 = 0x53544154;
  iStack_38 = ((uVar1 & 0xffff) - 1) * 0x24 + 0x6fec28;
  uStack_30 = 0x21;
  uStack_24 = 0x21;
  puStack_2c = &DAT_00640580;
  puStack_20 = &DAT_00640580 + (*(int *)(param_1 + 0xc) * 2 + 2) * 4;
  uVar2 = func_0x001e0ed8(uRam006febac,&uStack_40,uRam007006ac,0x5c3da0);
  FUN_005c3e50(uVar2,0x5c7790,0x7005f8);
  return;
}



================================================================