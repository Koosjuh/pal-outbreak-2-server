FUNCTION FUN_005bd2e0 @ 0x005bd2e0  size=1024
CALLERS (1): FUN_005b25c0@0x005b25c0
CALLEES (3): FUN_005bd250@0x005bd250, FUN_005bc860@0x005bc860, FUN_005c6d60@0x005c6d60
----------------------------------------------------------------

undefined4 FUN_005bd2e0(undefined4 *param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  long lVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined1 auStack_c0 [16];
  undefined1 auStack_b0 [64];
  undefined1 auStack_70 [16];
  undefined1 auStack_60 [32];
  undefined4 auStack_40 [16];
  
  puVar7 = auStack_40;
  iVar6 = 8;
  do {
    iVar6 = iVar6 + -1;
    uVar3 = param_1[1];
    *puVar7 = *param_1;
    param_1 = param_1 + 2;
    puVar7[1] = uVar3;
    puVar7 = puVar7 + 2;
  } while (0 < iVar6);
  puVar2 = (undefined1 *)0x10;
  puVar5 = auStack_70;
  puVar1 = puVar5;
  while (puVar1 != (undefined1 *)0x0) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
    puVar2 = puVar2 + -1;
    puVar1 = puVar2;
  }
  uRam0086f7e8 = 0;
  if (cRam006cb98c == '\0') {
    puVar8 = auStack_40;
    puVar7 = (undefined4 *)0x6cbccc;
    iVar6 = 8;
    do {
      iVar6 = iVar6 + -1;
      uVar3 = puVar8[1];
      *puVar7 = *puVar8;
      puVar8 = puVar8 + 2;
      puVar7[1] = uVar3;
      puVar7 = puVar7 + 2;
    } while (0 < iVar6);
    uRam006ca964 = 0;
    uRam006ca950 = 1;
    uRam0086f7e8 = 1;
    uRam006cbcc8 = 0;
    uRam006cbcc6 = 0;
    uRam0086f7e0 = 0;
    func_0x00106b60(0x6cbd0c,0,0x114);
    func_0x00106b60(0x6cc104,0,0x450);
    func_0x00109eb8(0x6febb8,0x86f820);
    uRam006cbc88 = 0;
    uRam006cbc8c = 0x1000;
    uRam006cbc90 = 0x6fc8e8;
    func_0x00106b60(0x6cd66c,0,6);
    func_0x00106b60(0x6fc8e8,0,0x2000);
    cRam006cb98c = '\x01';
    uRam006cb988 = 0;
    uRam006cb968 = 0;
    uRam006cb96c = param_2;
    if (cRam0086f7f0 == '\0') {
      cRam0086f7f0 = '\x02';
      func_0x00109eb8(0x6febc8,0x86f810);
      uRam006febd8 = uRam0035bed8;
      uRam006febb0 = uRam0035ba98;
      uRam006febdc = (undefined2)uRam0035b9e8;
      func_0x00109728(auStack_60,0x639f30,uRam0035ba98 & 0xff,uRam0035ba98 >> 8 & 0xff,
                      uRam0035ba98 >> 0x10 & 0xff,uRam0035ba98 >> 0x18);
      uRam006febac = func_0x001d46ec(auStack_60,uRam006febdc,0x639f10);
      func_0x00109728(auStack_70,0x639f30,uRam006febd8 & 0xff,uRam006febd8 >> 8 & 0xff,
                      uRam006febd8 >> 0x10 & 0xff,uRam006febd8 >> 0x18);
      func_0x00106b60(auStack_b0,0,0x3c);
      FUN_005bd250(auStack_b0);
      func_0x00106b60(auStack_c0,0,0x10);
      func_0x00109eb8(auStack_c0,0x6febb8);
      lVar4 = func_0x001ae3e0(0x6febb8);
      if (lVar4 < 0xf) {
        auStack_c0[(int)lVar4] = 0x2d;
      }
      FUN_005bc860();
      func_0x001db7e8(uRam006febac,0x6febb8,0x6febc8,auStack_b0,auStack_c0,auStack_70,0xcaf3,0xf0);
      uRam0035b9e0 = uRam006febac;
      func_0x001ca8c0();
    }
    else {
      uRam006febac = uRam0035b9e0;
      if (cRam0086f7f0 == '\x02') {
        FUN_005c6d60(0x5bcfd0);
      }
      else {
        cRam0086f7f0 = '\x02';
        FUN_005bc860();
        func_0x001de648(uRam006febac,0xfffffffff7e00001,0x5bcee0);
      }
    }
    uVar3 = 0;
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}



================================================================