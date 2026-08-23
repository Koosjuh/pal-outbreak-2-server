FUNCTION FUN_00000750 @ 0x00000750 size=584
CALLERS (1): FUN_00001298@0x00001298
CALLEES (4): FUN_000029f4@0x000029f4, FUN_000029ec@0x000029ec, FUN_00000214@0x00000214, FUN_00002a04@0x00002a04

int FUN_00000750(int *param_1)

{
  short sVar1;
  bool bVar2;
  int iVar3;
  undefined4 *puVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  int iVar9;
  int iVar10;
  
  iVar10 = 0;
  iVar9 = *param_1;
  while( true ) {
    iVar6 = param_1[7];
    if (iVar6 == 0) {
      iVar6 = FUN_000029ec(param_1 + 0x65);
      if (iVar6 == 0) {
        return iVar10;
      }
      param_1[7] = iVar6;
    }
    if (0x3f < param_1[3]) break;
    iVar7 = *(int *)(iVar6 + 0x14) - *(uint *)(iVar6 + 0x10);
    if ((iVar7 < 1) || ((*(uint *)(iVar6 + 0x10) & 3) != 0)) {
      FUN_000029f4("smap: dropped\n");
      param_1[0x39] = param_1[0x39] + 1;
    }
    else {
      if (param_1[2] < (int)(iVar7 + 3U & 0xfffffffc)) {
        return iVar10;
      }
      pbVar5 = *(byte **)(iVar6 + 0x10);
      DAT_00003288 = DAT_00003288 + 1;
      if ((*pbVar5 & 1) != 0) {
        if ((*(int *)pbVar5 == -1) && (*(short *)(pbVar5 + 4) == -1)) {
          param_1[0x3b] = param_1[0x3b] + 1;
          param_1[0x3d] = param_1[0x3d] + iVar7;
        }
        else {
          param_1[0x3f] = param_1[0x3f] + 1;
          param_1[0x41] = param_1[0x41] + iVar7;
        }
      }
      sVar1 = *(short *)(iVar9 + 0xf04);
      pcVar8 = "smap: StartThread -> %d\n" + iVar9 + (param_1[4] & 0x3fU) * 8 + 4;
      iVar3 = FUN_00000214(iVar9,*(undefined4 *)(iVar6 + 0x10),iVar7,1);
      if (iVar3 < 1) goto LAB_000008ec;
      puVar4 = (undefined4 *)(*(int *)(iVar6 + 0x10) + iVar3);
      while( true ) {
        *(undefined4 **)(iVar6 + 0x10) = puVar4;
LAB_000008ec:
        bVar2 = iVar7 <= iVar3;
        iVar3 = iVar3 + 4;
        if (bVar2) break;
        puVar4 = *(undefined4 **)(iVar6 + 0x10) + 1;
        *(undefined4 *)(iVar9 + 0x1000) = **(undefined4 **)(iVar6 + 0x10);
      }
      iVar10 = iVar10 + 1;
      *(short *)(pcVar8 + 4) = (short)iVar7;
      *(short *)(pcVar8 + 6) = sVar1 + 0x1000;
      *(undefined1 *)(iVar9 + 0xf10) = 0;
      pcVar8[0] = '\0';
      pcVar8[1] = -0x7d;
      param_1[4] = param_1[4] + 1;
      param_1[3] = param_1[3] + 1;
      param_1[2] = param_1[2] - (iVar7 + 3U & 0xfffffffc);
      param_1[0x35] = param_1[0x35] + iVar7;
      param_1[0x33] = param_1[0x33] + 1;
    }
    param_1[7] = 0;
    FUN_00002a04(param_1 + 0x4f,iVar6);
  }
  return iVar10;
}


================================================================