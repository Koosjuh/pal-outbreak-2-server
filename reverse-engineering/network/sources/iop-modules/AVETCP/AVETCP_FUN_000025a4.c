FUNCTION FUN_000025a4 @ 0x000025a4 size=388
CALLERS (1): FUN_0000223c@0x0000223c
CALLEES (2): FUN_00004254@0x00004254, FUN_00002aa4@0x00002aa4

byte * FUN_000025a4(undefined4 param_1,short param_2)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  short sVar6;
  byte *pbVar8;
  byte bVar9;
  int iVar7;
  
  bVar2 = false;
  bVar9 = 0xff;
  pbVar8 = &DAT_000187b0;
  iVar3 = FUN_00004254((int)param_2);
  iVar7 = -1;
  sVar6 = -1;
  if (iVar3 == 0) {
    pbVar8 = (byte *)0x0;
  }
  else {
    iVar5 = 0;
    if (DAT_0001618c != 0) {
      iVar4 = 0;
      do {
        sVar6 = (short)iVar7;
        pbVar8 = &DAT_000187b0 + (iVar4 >> 0xb);
        bVar1 = *pbVar8;
        if (bVar1 == 0) {
          bVar2 = true;
          break;
        }
        if ((((bVar1 & 3) != 0) && ((bVar1 & 4) == 0)) &&
           ((byte)(&DAT_000187c0)[iVar4 >> 0xb] < bVar9)) {
          iVar7 = iVar5;
          bVar9 = (&DAT_000187c0)[iVar4 >> 0xb];
        }
        sVar6 = (short)iVar7;
        iVar5 = iVar5 + 1;
        iVar4 = iVar5 * 0x10000;
      } while (iVar5 * 0x10000 >> 0x10 < (int)(uint)DAT_0001618c);
    }
    if (!bVar2) {
      if (sVar6 != -1) {
        pbVar8 = &DAT_000187b0 + sVar6 * 0x20;
        FUN_00002aa4();
        bVar2 = true;
      }
      if (!bVar2) {
        return (byte *)0x0;
      }
    }
    *pbVar8 = 1;
    *(int *)(pbVar8 + 4) = (int)param_2;
    if (*(short *)(iVar3 + 0x14) == 1) {
      pbVar8[2] = 1;
      pbVar8[3] = 0;
    }
    else {
      pbVar8[2] = 0;
      pbVar8[3] = 0;
    }
    bVar9 = *(byte *)(iVar3 + 0x16);
    pbVar8[0x10] = 3;
    *(undefined4 *)(pbVar8 + 0x14) = param_1;
    pbVar8[1] = bVar9;
  }
  return pbVar8;
}


================================================================