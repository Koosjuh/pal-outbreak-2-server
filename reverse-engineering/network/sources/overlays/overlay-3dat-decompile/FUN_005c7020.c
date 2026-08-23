FUNCTION FUN_005c7020 @ 0x005c7020  size=180
CALLERS (1): FUN_005af1a0@0x005af1a0
CALLEES (3): FUN_005c4f40@0x005c4f40, FUN_005c4fd0@0x005c4fd0, FUN_005c3e50@0x005c3e50
----------------------------------------------------------------

undefined8 FUN_005c7020(void)

{
  undefined8 uVar1;
  undefined1 auStack_60 [16];
  undefined1 auStack_50 [16];
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined1 *puStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined1 *puStack_2c;
  
  func_0x00106b60(&uStack_40,0,0x3c);
  uVar1 = FUN_005c4f40();
  func_0x00109eb8(auStack_50,uVar1);
  uVar1 = FUN_005c4fd0();
  func_0x00109eb8(auStack_60,uVar1);
  uStack_3c = 0x44;
  uStack_40 = 0x4e414d45;
  uStack_34 = 0x4e414d45;
  puStack_38 = auStack_50;
  puStack_2c = auStack_60;
  uStack_30 = 0x46;
  uVar1 = func_0x001e094c(uRam006febac,&uStack_40,10,0x5c3cf0);
  FUN_005c3e50(uVar1,0x5c70e0,0x700638);
  return 0;
}



================================================================