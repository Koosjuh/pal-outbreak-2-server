FUNCTION FUN_00002d98 @ 0x00002d98 size=520
CALLERS (3): FUN_00002900@0x00002900, FUN_00010914@0x00010914, FUN_00002bf0@0x00002bf0
CALLEES (2): FUN_000063b0@0x000063b0, FUN_0000fe20@0x0000fe20

int FUN_00002d98(uint *param_1)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  sVar1 = FUN_0000fe20();
  if (sVar1 == 0) {
    uVar3 = *param_1;
    uVar2 = param_1[1];
    *param_1 = uVar3 >> 0x18 | uVar3 >> 8 & 0xff00 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
    param_1[1] = uVar2 >> 0x18 | uVar2 >> 8 & 0xff00 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
    if ((DAT_000132b4 & 0x8000) != 0) {
      FUN_000063b0(param_1 + 6,param_1 + 5,param_1 + 9,param_1 + 10,param_1 + 7,param_1 + 8);
      uVar2 = param_1[5];
      uVar3 = param_1[6];
      uVar5 = param_1[9];
      param_1[5] = uVar2 >> 0x18 | uVar2 >> 8 & 0xff00 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
      uVar2 = param_1[7];
      uVar4 = param_1[8];
      param_1[6] = uVar3 >> 0x18 | uVar3 >> 8 & 0xff00 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
      param_1[7] = uVar2 >> 0x18 | uVar2 >> 8 & 0xff00 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
      param_1[8] = uVar4 >> 0x18 | uVar4 >> 8 & 0xff00 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18;
      uVar2 = param_1[10];
      param_1[9] = uVar5 >> 0x18 | uVar5 >> 8 & 0xff00 | (uVar5 & 0xff00) << 8 | uVar5 << 0x18;
      param_1[10] = uVar2 >> 0x18 | uVar2 >> 8 & 0xff00 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
    }
  }
  return (int)sVar1;
}


================================================================