FUNCTION FUN_005df640 @ 0x005df640  size=192
CALLERS (1): FUN_005df340@0x005df340
CALLEES (2): FUN_005dedc0@0x005dedc0, FUN_005df600@0x005df600
----------------------------------------------------------------

int FUN_005df640(undefined8 param_1)

{
  undefined *puVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  undefined **ppuVar5;
  int iVar6;
  
  iVar6 = 0;
  ppuVar5 = &PTR_s_javascript__006465a0;
  FUN_005dedc0(iRam00701068 + 0x4d05c,param_1);
  FUN_005df600(iRam00701068 + 0x4d05c);
  puVar1 = PTR_s_javascript__006465a0;
  while (puVar1 != (undefined *)0x0) {
    uVar3 = func_0x0010a050();
    lVar4 = func_0x0010a338(iRam00701068 + 0x4d05c,*ppuVar5,uVar3);
    if (lVar4 == 0) break;
    ppuVar5 = ppuVar5 + 1;
    iVar6 = iVar6 + 1;
    puVar1 = *ppuVar5;
  }
  iVar2 = -1;
  if (*ppuVar5 != (undefined *)0x0) {
    iVar2 = iVar6;
  }
  return iVar2;
}



================================================================