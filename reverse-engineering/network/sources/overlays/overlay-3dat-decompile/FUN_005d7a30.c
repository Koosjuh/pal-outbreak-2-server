FUNCTION FUN_005d7a30 @ 0x005d7a30  size=304
CALLERS (1): FUN_005d8340@0x005d8340
CALLEES (6): FUN_0060dea0@0x0060dea0, FUN_005d6ce0@0x005d6ce0, FUN_005df7b0@0x005df7b0, FUN_0060d4f0@0x0060d4f0, FUN_005d6b40@0x005d6b40, FUN_005d7310@0x005d7310
----------------------------------------------------------------

undefined4 FUN_005d7a30(int param_1)

{
  char cVar1;
  byte *pbVar2;
  ulong uVar3;
  long lVar4;
  
  while( true ) {
    lVar4 = -3;
    cVar1 = FUN_005df7b0(param_1 + 4);
    if (cVar1 == '\x03') {
      lVar4 = FUN_0060dea0(*(undefined4 *)(param_1 + 0x10c),4,param_1 + 0x118,param_1 + 0x11a);
    }
    else if (cVar1 == '\x02') {
      lVar4 = FUN_0060d4f0(*(undefined4 *)(param_1 + 0x10c),*(undefined4 *)(param_1 + 0x110),4,
                           param_1 + 0x118,param_1 + 0x11a);
    }
    if ((lVar4 == -3) || (lVar4 == -2)) {
      *(undefined4 *)(param_1 + 0x104) = 6;
      *(undefined4 *)(param_1 + 0x114) = 0;
      return 6;
    }
    if (lVar4 != -1) {
      *(int *)(param_1 + 0x114) = (int)lVar4;
      return 0;
    }
    lVar4 = FUN_005d6b40(iRam00701068 + 0x4f47c);
    if (lVar4 == 0) break;
    uVar3 = (ulong)*(byte *)((int)lVar4 + 0x108);
    pbVar2 = (byte *)FUN_005d7310();
    if (uVar3 == *pbVar2) {
      *(undefined4 *)(param_1 + 0x104) = 6;
      *(undefined4 *)(param_1 + 0x114) = 0;
      return 6;
    }
    FUN_005d6ce0();
  }
  *(undefined4 *)(param_1 + 0x104) = 6;
  *(undefined4 *)(param_1 + 0x114) = 0;
  return 6;
}



================================================================