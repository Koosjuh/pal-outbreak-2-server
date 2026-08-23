
void FUN_001d0510(int param_1,int param_2,int param_3,uint *param_4,int param_5,int param_6)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  ushort uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  undefined1 auStack_20 [32];
  
  uVar8 = 0;
  uVar2 = param_4[1];
  param_5 = iRam003435bc + param_5;
  for (; (uVar8 < 8 && (param_4 < (uint *)(uVar2 + param_1))); param_4 = param_4 + 2) {
    uVar3 = *param_4;
    if (uVar3 != 0) {
      uVar4 = param_4[1];
      for (uVar7 = 0; uVar7 < uVar3; uVar7 = uVar7 + 1 & 0xffff) {
        iVar6 = *(int *)(uVar4 + param_1 + uVar7 * 4);
        piVar9 = (int *)(param_1 + iVar6);
        if (iVar6 != -1) {
          if (*piVar9 == -1) {
            *(short *)(param_2 + (param_6 + uVar7 + uVar8 * param_3) * 2 + 4) = (short)piVar9[1];
          }
          else {
            thunk_FUN_00198d30(auStack_20,param_5 + 0x3fU & 0xffffffc0,piVar9);
            uVar5 = FUN_00188a30(auStack_20);
            iVar6 = param_2 + (param_6 + uVar7 + uVar8 * param_3) * 2;
            sVar1 = *(short *)(iVar6 + 4);
            if (sVar1 != 0) {
              FUN_00188ad0(sVar1);
            }
            *(ushort *)(iVar6 + 4) = uVar5;
            *piVar9 = -1;
            piVar9[1] = (uint)uVar5;
          }
        }
      }
    }
    uVar8 = uVar8 + 1 & 0xffff;
  }
  return;
}

