FUNCTION FUN_0060c330 @ 0x0060c330  size=604
CALLERS (1): FUN_0060c6e0@0x0060c6e0
CALLEES (0): 
----------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x0060c45c) */

void FUN_0060c330(int param_1,byte *param_2,byte *param_3,int param_4)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
  if (param_4 == 4) {
    iVar4 = *(int *)(param_1 + 4);
    uVar8 = (int)(*(byte *)(param_1 + 0xb) + 7) >> 3;
    pbVar6 = param_2;
    pbVar7 = param_3;
    for (uVar9 = 0; uVar9 < uVar8; uVar9 = uVar9 + 1) {
      bVar1 = *pbVar7;
      pbVar7 = pbVar7 + 1;
      *pbVar6 = *pbVar6 + bVar1;
      pbVar6 = pbVar6 + 1;
    }
    for (uVar9 = 0; uVar9 < iVar4 - uVar8; uVar9 = uVar9 + 1) {
      bVar1 = *pbVar7;
      bVar2 = *param_3;
      bVar3 = *param_2;
      pbVar7 = pbVar7 + 1;
      iVar5 = (uint)bVar1 - (uint)bVar2;
      param_3 = param_3 + 1;
      param_2 = param_2 + 1;
      iVar12 = (uint)bVar3 - (uint)bVar2;
      iVar11 = iVar5;
      if (iVar5 < 0) {
        iVar11 = -iVar5;
      }
      iVar10 = iVar12;
      if (iVar12 < 0) {
        iVar10 = -iVar12;
      }
      iVar5 = iVar5 + iVar12;
      if (iVar5 < 0) {
        iVar5 = -iVar5;
      }
      if (((iVar10 < iVar11) || (iVar5 < iVar11)) && (bVar3 = bVar1, iVar5 < iVar10)) {
        bVar3 = bVar2;
      }
      *pbVar6 = *pbVar6 + bVar3;
      pbVar6 = pbVar6 + 1;
    }
  }
  else if (param_4 == 3) {
    iVar4 = *(int *)(param_1 + 4);
    uVar8 = (int)(*(byte *)(param_1 + 0xb) + 7) >> 3;
    pbVar6 = param_2;
    for (uVar9 = 0; uVar9 < uVar8; uVar9 = uVar9 + 1) {
      bVar1 = *param_3;
      param_3 = param_3 + 1;
      *pbVar6 = *pbVar6 + (bVar1 >> 1);
      pbVar6 = pbVar6 + 1;
    }
    for (uVar9 = 0; uVar9 < iVar4 - uVar8; uVar9 = uVar9 + 1) {
      bVar1 = *param_3;
      bVar2 = *param_2;
      param_2 = param_2 + 1;
      param_3 = param_3 + 1;
      *pbVar6 = *pbVar6 + (char)((int)((uint)bVar1 + (uint)bVar2) >> 1);
      pbVar6 = pbVar6 + 1;
    }
  }
  else if (param_4 == 2) {
    uVar8 = *(uint *)(param_1 + 4);
    for (uVar9 = 0; uVar9 < uVar8; uVar9 = uVar9 + 1) {
      bVar1 = *param_3;
      param_3 = param_3 + 1;
      *param_2 = *param_2 + bVar1;
      param_2 = param_2 + 1;
    }
  }
  else if (param_4 == 1) {
    uVar8 = *(uint *)(param_1 + 4);
    uVar9 = (int)(*(byte *)(param_1 + 0xb) + 7) >> 3;
    pbVar6 = param_2 + uVar9;
    for (; uVar9 < uVar8; uVar9 = uVar9 + 1) {
      bVar1 = *param_2;
      param_2 = param_2 + 1;
      *pbVar6 = *pbVar6 + bVar1;
      pbVar6 = pbVar6 + 1;
    }
  }
  else if (param_4 != 0) {
    *param_2 = 0;
  }
  return;
}



================================================================