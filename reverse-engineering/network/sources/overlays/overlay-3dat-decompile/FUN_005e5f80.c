FUNCTION FUN_005e5f80 @ 0x005e5f80  size=312
CALLERS (1): FUN_005e7070@0x005e7070
CALLEES (0): 
----------------------------------------------------------------

undefined1 FUN_005e5f80(int param_1,int param_2,uint param_3)

{
  byte bVar1;
  uint uVar2;
  long lVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined1 auStack_30 [48];
  
  for (uVar7 = 0; uVar7 < 0x1e; uVar7 = uVar7 + 1 & 0xffff) {
    bVar1 = *(byte *)(param_1 + uVar7);
    uVar5 = (uint)bVar1;
    if (uVar5 == 0) break;
    if ((bVar1 & 0x80) == 0) {
      if (uVar5 == 0x3e) break;
      auStack_30[uVar7] = (&DAT_00648090)[bVar1];
    }
    else {
      do {
        uVar6 = uVar7 + 1 & 0xffff;
        uVar2 = uVar5 << 1;
        uVar5 = uVar2 & 0xff;
        auStack_30[uVar7] = *(undefined1 *)(param_1 + uVar7);
        uVar7 = uVar6;
      } while ((uVar2 & 0x80) != 0);
      uVar7 = uVar6 - 1 & 0xffff;
    }
  }
  auStack_30[uVar7] = 0;
  uVar7 = 0;
  while( true ) {
    if ((param_3 >> 3 & 0xffff) <= uVar7) {
      return 0;
    }
    puVar4 = (undefined4 *)(param_2 + uVar7 * 8);
    lVar3 = func_0x0010a338(auStack_30,*puVar4,*(byte *)(puVar4 + 1) - 1);
    if (lVar3 == 0) break;
    uVar7 = uVar7 + 1 & 0xffff;
  }
  return *(undefined1 *)(uVar7 * 8 + param_2 + 5);
}



================================================================