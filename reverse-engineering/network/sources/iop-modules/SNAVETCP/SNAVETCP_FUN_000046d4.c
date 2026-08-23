FUNCTION FUN_000046d4 @ 0x000046d4 size=264
CALLERS (1): FUN_0000f8f0@0x0000f8f0
CALLEES (4): FUN_00014e24@0x00014e24, FUN_0000405c@0x0000405c, FUN_000049c4@0x000049c4, FUN_0000414c@0x0000414c

undefined4 FUN_000046d4(uint param_1,uint param_2,uint param_3,short param_4)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 uStackX_1;
  undefined1 uStackX_2;
  
  if ((DAT_00016178 & 0x10) != 0) {
    uStackX_1 = (undefined1)(param_1 >> 8);
    uStackX_2 = (undefined1)(param_1 >> 0x10);
    FUN_00014e24("ave-tcp: IF UP addr %d.%d.%d.%d mask %d.%d.%d.%d broadcast %d.%d.%d.%d\n",
                 param_1 & 0xff,uStackX_1,uStackX_2,param_1 >> 0x18,param_2 & 0xff,
                 param_2 >> 8 & 0xff,param_2 >> 0x10 & 0xff,param_2 >> 0x18,param_3 & 0xff,
                 param_3 >> 8 & 0xff,param_3 >> 0x10 & 0xff,param_3 >> 0x18);
  }
  iVar3 = (int)param_4;
  sVar1 = FUN_0000405c(param_1,param_2,param_3,iVar3);
  uVar2 = 0xffffffff;
  if (sVar1 == 0) {
    sVar1 = FUN_000049c4(iVar3);
    uVar2 = 0;
    if (sVar1 != 0) {
      FUN_0000414c(iVar3);
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}


================================================================