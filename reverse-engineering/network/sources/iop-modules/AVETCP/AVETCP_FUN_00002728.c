FUNCTION FUN_00002728 @ 0x00002728 size=492
CALLERS (2): FUN_000029c8@0x000029c8, FUN_00002394@0x00002394
CALLEES (3): FUN_00002cb4@0x00002cb4, FUN_00011d00@0x00011d00, FUN_00002aa4@0x00002aa4

byte * FUN_00002728(int param_1,undefined2 param_2,byte param_3,undefined4 param_4,byte param_5,
                   short param_6)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  byte bVar5;
  byte bVar6;
  short sVar7;
  byte *pbVar9;
  byte *pbVar10;
  int iVar8;
  
  bVar2 = false;
  bVar6 = 0xff;
  bVar1 = false;
  pbVar9 = &DAT_000187b0;
  iVar8 = -1;
  sVar7 = -1;
  iVar4 = 0;
  if (DAT_0001618c != 0) {
    iVar3 = 0;
    pbVar10 = pbVar9;
    do {
      sVar7 = (short)iVar8;
      iVar3 = iVar3 >> 0xb;
      pbVar9 = &DAT_000187b0 + iVar3;
      bVar5 = *pbVar9;
      if (bVar5 == 0) {
        bVar2 = true;
        iVar3 = iVar8;
        pbVar10 = pbVar9;
        bVar5 = bVar6;
LAB_00002820:
        iVar8 = iVar3;
        pbVar9 = pbVar10;
        bVar6 = bVar5;
      }
      else {
        if (*(int *)((int)&DAT_000187c4 + iVar3) == param_1) {
          if ((bVar5 & 1) == 0) {
            return (byte *)0x0;
          }
          if ((bVar5 & 2) != 0) {
            return (byte *)0x0;
          }
          bVar1 = true;
          bVar2 = bVar1;
          break;
        }
        pbVar9 = pbVar10;
        if ((((bVar5 & 3) != 0) && ((bVar5 & 4) == 0)) &&
           (bVar5 = (&DAT_000187c0)[iVar3], iVar3 = iVar4, bVar5 < bVar6)) goto LAB_00002820;
      }
      sVar7 = (short)iVar8;
      iVar4 = iVar4 + 1;
      iVar3 = iVar4 * 0x10000;
      pbVar10 = pbVar9;
    } while (iVar4 * 0x10000 >> 0x10 < (int)(uint)DAT_0001618c);
  }
  if (!bVar2) {
    if (sVar7 != -1) {
      pbVar9 = &DAT_000187b0 + sVar7 * 0x20;
      FUN_00002aa4();
      bVar2 = true;
    }
    if (!bVar2) {
      return (byte *)0x0;
    }
  }
  *pbVar9 = param_5 | 2;
  *(int *)(pbVar9 + 4) = (int)param_6;
  *(undefined2 *)(pbVar9 + 2) = param_2;
  pbVar9[1] = param_3;
  pbVar9[0x10] = 0x14;
  FUN_00011d00(pbVar9 + 0x18,param_4,param_3);
  *(int *)(pbVar9 + 0x14) = param_1;
  if (bVar1) {
    *pbVar9 = *pbVar9 & 0xfe;
    FUN_00002cb4(pbVar9);
  }
  return pbVar9;
}


================================================================