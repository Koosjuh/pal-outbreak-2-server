
int FUN_001c3590(byte *param_1,char *param_2,int param_3,int param_4)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  iVar2 = 0;
  do {
    if (param_3 < 1) {
      return iVar2;
    }
    iVar3 = param_3 + -1;
    iVar5 = 8;
    uVar6 = (uint)*param_1 << 0x10;
    pbVar1 = param_1 + 1;
    if (0 < iVar3) {
      iVar3 = param_3 + -2;
      iVar5 = 0x10;
      uVar6 = uVar6 | (uint)param_1[1] << 8;
      pbVar1 = param_1 + 2;
      if (0 < iVar3) {
        iVar5 = 0x18;
        iVar3 = param_3 + -3;
        uVar6 = uVar6 | param_1[2];
        pbVar1 = param_1 + 3;
      }
    }
    param_1 = pbVar1;
    for (uVar4 = 0x12; -1 < (int)uVar4; uVar4 = uVar4 - 6) {
      if (iVar5 < 1) {
        *param_2 = '=';
      }
      else {
        *param_2 = s_ABCDEFGHIJKLMNOPQRSTUVWXYZabcdef_002487e0[uVar6 >> (uVar4 & 0x1f) & 0x3f];
      }
      param_4 = param_4 + -1;
      iVar5 = iVar5 + -6;
      param_2 = param_2 + 1;
      iVar2 = iVar2 + 1;
      if (param_4 < 1) break;
    }
    param_3 = iVar3;
    if (param_4 < 1) {
      return iVar2;
    }
  } while( true );
}

