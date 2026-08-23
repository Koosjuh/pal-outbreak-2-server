FUNCTION FUN_00637260 @ 0x00637260  size=452
CALLERS (5): FUN_00631560@0x00631560, FUN_00637430@0x00637430, FUN_00635f80@0x00635f80, FUN_00631670@0x00631670, FUN_006313a0@0x006313a0
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_00637260(uint param_1,byte *param_2,byte *param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  byte bStack_1;
  
  if (param_2 == (byte *)0x0) {
    param_2 = &bStack_1;
  }
  else if ((param_1 & 0xff) == (uint)*param_2) {
    return 0;
  }
  uVar4 = param_1 & 0xff;
  if (param_3 == (byte *)0x0) {
    param_3 = &bStack_1;
  }
  switch(uVar4) {
  case 0:
    uVar2 = uVar4 | 8;
    uVar7 = uVar4;
    uVar6 = uVar4;
    break;
  case 1:
    uVar4 = 6;
    param_1 = 0xe;
    uVar2 = 6;
    uVar7 = 0xe;
    uVar6 = 0x10;
    break;
  case 2:
    param_1 = 10;
    uVar2 = 2;
    uVar4 = 7;
    uVar7 = 0xf;
    uVar6 = 0x10;
    break;
  case 3:
    uVar7 = uVar4 + 8 & 0xff;
    uVar6 = uVar7;
    uVar2 = uVar4;
    break;
  case 4:
    if (*(int *)(*(int *)(iRam00715da8 + 0x10) + 0x20) == 0) {
      return 1;
    }
  default:
switchD_006372b0_default:
    uVar4 = param_1 & 0xff;
    uVar7 = uVar4;
    uVar6 = uVar4;
    uVar2 = uVar4;
    break;
  case 5:
    if (*(int *)(*(int *)(iRam00715da8 + 0x10) + 0x28) == 0) {
      return 1;
    }
    goto switchD_006372b0_default;
  }
  uVar3 = 1;
  uVar1 = *(uint *)(iRam00715da8 + 0x20);
  bVar5 = (byte)param_1;
  if ((uVar1 & 1 << (param_1 & 0x1f)) == 0) {
    *param_2 = bVar5;
    uVar3 = 0;
    *param_3 = bVar5;
  }
  else if ((uVar1 & 1 << (uVar2 & 0x1f)) == 0) {
    *param_2 = bVar5;
    uVar3 = 0;
    *param_3 = (byte)uVar2;
  }
  else if ((uVar1 & 1 << (uVar7 & 0x1f)) == 0) {
    *param_2 = bVar5;
    uVar3 = 0;
    *param_3 = (byte)uVar7;
  }
  else if ((uVar1 & 1 << (uVar4 & 0x1f)) == 0) {
    *param_2 = bVar5;
    uVar3 = 0;
    *param_3 = (byte)uVar4;
  }
  else if ((uVar1 & 1 << (uVar6 & 0x1f)) == 0) {
    *param_2 = bVar5;
    uVar3 = 0;
    *param_3 = (byte)uVar6;
  }
  return uVar3;
}



================================================================