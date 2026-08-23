FUNCTION FUN_005bdb00 @ 0x005bdb00  size=292
CALLERS (1): FUN_005b3590@0x005b3590
CALLEES (2): FUN_005be0a0@0x005be0a0, FUN_005bf230@0x005bf230
----------------------------------------------------------------

undefined8 FUN_005bdb00(undefined8 param_1)

{
  undefined1 uVar1;
  long lVar2;
  undefined8 uVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  
  lVar2 = FUN_005be0a0(1,0,param_1);
  uRam006cbc88 = 0;
  uRam006cbc8c = 0x1000;
  uRam006cbc90 = 0x6fc8e8;
  func_0x00106b60(0x6cc668,0,0x1004);
  func_0x00106b60(0x6fc8e8,0,0x2000);
  uRam006cbc88 = 0;
  uRam006cbc8c = 0x1000;
  uRam006cbc90 = 0x6fc8e8;
  func_0x00106b60(0x6cc668,0,0x1004);
  func_0x00106b60(0x6fc8e8,0,0x2000);
  uVar3 = 0xffffffffffffffff;
  if (lVar2 != -1) {
    uRam006cbc84 = 0;
    puVar6 = (undefined1 *)0x86f860;
    puVar5 = (undefined1 *)0x6cc668;
    iVar4 = 0x802;
    do {
      iVar4 = iVar4 + -1;
      uVar1 = puVar6[1];
      *puVar5 = *puVar6;
      puVar6 = puVar6 + 2;
      puVar5[1] = uVar1;
      puVar5 = puVar5 + 2;
    } while (0 < iVar4);
    FUN_005bf230(param_1);
    uVar3 = 0;
  }
  return uVar3;
}



================================================================