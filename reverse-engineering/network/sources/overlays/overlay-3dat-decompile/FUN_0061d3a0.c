FUNCTION FUN_0061d3a0 @ 0x0061d3a0  size=752
CALLERS (1): FUN_00619800@0x00619800
CALLEES (1): FUN_0061cc80@0x0061cc80
----------------------------------------------------------------

void FUN_0061d3a0(ulong param_1)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  short sVar4;
  int iVar5;
  short *psVar6;
  int iVar7;
  short sVar8;
  short sVar9;
  int iVar10;
  
  if (param_1 < 0x11) {
    iVar7 = (int)param_1;
    iVar5 = iVar7 * 4;
    switch(param_1) {
    default:
      iVar2 = *(int *)(*(int *)(&DAT_00665e10 + (uint)bRam0034359d * 4) + iVar5);
      for (iVar10 = 0; iVar10 < *(int *)(&DAT_006668c0 + iVar5); iVar10 = iVar10 + 1) {
        uVar3 = *(undefined4 *)(iVar2 + iVar10 * 4);
        psVar6 = (short *)((&PTR_DAT_00666870)[iVar7] + iVar10 * 8);
        sVar4 = *psVar6;
        sVar1 = psVar6[2];
        sVar8 = psVar6[3];
        sVar9 = psVar6[1];
        if (sVar4 == -1) {
          sVar4 = FUN_0061cc80(uVar3,sVar1);
        }
        func_0x001af060(sVar1,sVar1);
        func_0x001af080(sVar4,sVar9 + 1);
        func_0x001af0b0(0);
        if (4 < sVar8) {
          sVar8 = 4;
        }
        func_0x001af0c0(*(undefined4 *)(sVar8 * 4 + 0x669c00));
        func_0x001af190(uVar3);
      }
      break;
    case 1:
      iVar2 = *(int *)(*(int *)(&DAT_00665e10 + (uint)bRam0034359d * 4) + iVar5);
      for (iVar10 = 0; iVar10 < *(int *)(&DAT_006668c0 + iVar5); iVar10 = iVar10 + 1) {
        psVar6 = (short *)((&PTR_DAT_00666870)[iVar7] + iVar10 * 8);
        sVar4 = *psVar6;
        sVar1 = psVar6[1];
        sVar8 = psVar6[2];
        sVar9 = psVar6[3];
        if (iVar10 == 1) {
          if (cRam003c98a0 == '\0') {
            sVar9 = 4;
          }
        }
        else if ((iVar10 == 2) && (cRam003c9580 == '\0')) {
          sVar9 = 4;
        }
        uVar3 = *(undefined4 *)(iVar2 + iVar10 * 4);
        if (sVar4 == -1) {
          sVar4 = FUN_0061cc80(uVar3,sVar8);
        }
        func_0x001af060(sVar8,sVar8);
        func_0x001af080(sVar4,sVar1 + 1);
        func_0x001af0b0(0);
        if (4 < sVar9) {
          sVar9 = 4;
        }
        func_0x001af0c0(*(undefined4 *)(sVar9 * 4 + 0x669c00));
        func_0x001af190(uVar3);
      }
    }
  }
  return;
}



================================================================