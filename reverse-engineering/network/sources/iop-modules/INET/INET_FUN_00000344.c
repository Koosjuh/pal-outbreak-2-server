FUNCTION FUN_00000344 @ 0x00000344 size=568
CALLERS (1): FUN_00000cc8@0x00000cc8
CALLEES (6): FUN_00000238@0x00000238, FUN_00006ea8@0x00006ea8, FUN_0000df10@0x0000df10, FUN_00017ad8@0x00017ad8, FUN_0000a7e0@0x0000a7e0, FUN_00017bf4@0x00017bf4

void FUN_00000344(int param_1,int param_2,short *param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  short *psVar4;
  code *pcVar5;
  undefined4 uVar6;
  short sVar7;
  
  if ((param_1 != 0) && (iVar3 = FUN_00006ea8(), iVar3 == 0)) {
    sVar7 = *param_3;
    if (sVar7 == DAT_0001b3e0) {
      if ((param_3[1] == DAT_0001b3e2) && (param_3[2] == DAT_0001b3e4)) {
        return;
      }
      sVar7 = *param_3;
    }
    if (((sVar7 != DAT_0001b3e8) || (param_3[1] != DAT_0001b3ea)) || (param_3[2] != DAT_0001b3ec)) {
      psVar4 = (short *)0x0;
      if (param_1 != 0) {
        psVar4 = (short *)(param_1 + 0x88);
      }
      piVar1 = DAT_0001b950;
      if (*param_3 == *psVar4) {
        pcVar5 = (code *)0x2;
        if (param_1 != 0) {
          pcVar5 = (code *)(param_1 + 0x8a);
        }
        if (param_3[1] == *(short *)pcVar5) {
          psVar4 = (short *)0x4;
          if (param_1 != 0) {
            psVar4 = (short *)(param_1 + 0x8c);
          }
          if (param_3[2] == *psVar4) {
            return;
          }
        }
      }
      for (; piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
        if (param_2 == piVar1[4]) {
          if ((piVar1[2] & 1U) == 0) {
            piVar1[2] = piVar1[2] | 1;
            piVar2 = (int *)piVar1[9];
            while (piVar2 != (int *)0x0) {
              iVar3 = *piVar2;
              psVar4 = *(short **)(piVar2[2] + 0x10);
              *psVar4 = *param_3;
              psVar4[1] = param_3[1];
              psVar4[2] = param_3[2];
              FUN_0000df10(param_1,piVar2[2]);
              FUN_0000a7e0(piVar2);
              piVar2 = (int *)iVar3;
            }
            piVar1[10] = 0;
            piVar1[9] = 0;
            FUN_00017bf4(piVar1[7]);
            uVar6 = FUN_00017ad8(0xc4,piVar1,1200000);
            piVar1[7] = uVar6;
          }
          *(short *)(piVar1 + 5) = *param_3;
          piVar2 = DAT_0001b950;
          *(short *)((int)piVar1 + 0x16) = param_3[1];
          *(short *)(piVar1 + 6) = param_3[2];
          if (piVar1 == piVar2) {
            return;
          }
          FUN_00000238(piVar1);
          return;
        }
      }
    }
  }
  return;
}


================================================================