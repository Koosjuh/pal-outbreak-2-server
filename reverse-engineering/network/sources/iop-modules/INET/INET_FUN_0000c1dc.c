FUNCTION FUN_0000c1dc @ 0x0000c1dc size=220
CALLERS (2): FUN_0000c444@0x0000c444, FUN_0000c1dc@0x0000c1dc
CALLEES (1): FUN_0000c1dc@0x0000c1dc

byte * FUN_0000c1dc(byte *param_1,int param_2,byte *param_3,byte *param_4)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  byte *pbVar4;
  
  bVar2 = param_3 < param_4;
  while( true ) {
    if (!bVar2) {
      return (byte *)0x0;
    }
    uVar3 = (uint)*param_3;
    pbVar4 = param_3 + 1;
    if (uVar3 == 0) {
      *param_1 = 0;
      return pbVar4;
    }
    if ((uVar3 & 0xc0) == 0xc0) {
      if (param_4 <= pbVar4) {
        return (byte *)0x0;
      }
      FUN_0000c1dc(param_1,param_2,param_2 + ((uVar3 & 0xffffff3f) << 8 | (uint)*pbVar4));
      return param_3 + 2;
    }
    if (param_4 <= pbVar4 + uVar3) break;
    if (uVar3 != 0) {
      do {
        uVar3 = uVar3 - 1;
        bVar1 = *pbVar4;
        pbVar4 = pbVar4 + 1;
        *param_1 = bVar1;
        param_1 = param_1 + 1;
      } while (0 < (int)uVar3);
    }
    bVar2 = pbVar4 < param_4;
    param_3 = pbVar4;
    if (*pbVar4 != 0) {
      *param_1 = 0x2e;
      param_1 = param_1 + 1;
    }
  }
  return (byte *)0x0;
}


================================================================