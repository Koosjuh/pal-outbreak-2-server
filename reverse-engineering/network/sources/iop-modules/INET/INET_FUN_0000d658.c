FUNCTION FUN_0000d658 @ 0x0000d658 size=628
CALLERS (11): FUN_000161ec@0x000161ec, FUN_000160a0@0x000160a0, FUN_00011370@0x00011370, FUN_00019204@0x00019204, FUN_00016368@0x00016368, FUN_00010220@0x00010220, FUN_0000b800@0x0000b800, FUN_000175cc@0x000175cc, FUN_000169bc@0x000169bc, FUN_00015f04@0x00015f04, FUN_000112b0@0x000112b0
CALLEES (11): FUN_0000d3d4@0x0000d3d4, FUN_0000d5e0@0x0000d5e0, FUN_0000a60c@0x0000a60c, FUN_00019aa4@0x00019aa4, FUN_00017bf4@0x00017bf4, FUN_0000a7e0@0x0000a7e0, FUN_00019a8c@0x00019a8c, FUN_0000d41c@0x0000d41c, FUN_00019a60@0x00019a60, FUN_00017ad8@0x00017ad8, FUN_00019a40@0x00019a40

int FUN_0000d658(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int *piVar5;
  int iVar6;
  uint local_38;
  int local_34;
  uint local_30;
  int local_2c;
  uint local_28;
  int local_24;
  int local_20 [2];
  
  if (param_2 == (int *)0x0) {
LAB_0000d784:
    iVar6 = -500;
  }
  else {
    iVar6 = *param_2;
    if (iVar6 == 0) {
      return -500;
    }
    piVar5 = (int *)*param_1;
    if (piVar5 != (int *)0x0) {
      do {
        if (piVar5[2] == 0) break;
        piVar5 = (int *)*piVar5;
      } while (piVar5 != (int *)0x0);
      if (piVar5 != (int *)0x0) {
        piVar5[2] = 1;
        piVar5[5] = 0;
        if (0 < iVar6) {
          FUN_00019a40(&local_38);
          iVar1 = FUN_00017ad8(FUN_0000d630,piVar5,iVar6);
          piVar5[5] = iVar1;
        }
        FUN_0000d41c();
        iVar1 = FUN_00019aa4(piVar5[3],7,0x11,&local_28);
        FUN_0000d3d4();
        piVar5[2] = 0;
        if (piVar5[5] != 0) {
          iVar2 = FUN_00017bf4();
          piVar5[5] = iVar2;
        }
        if (piVar5[4] != 0) {
          FUN_00019a8c(piVar5[3]);
          FUN_0000a7e0(piVar5);
          return -0x1f5;
        }
        if (iVar1 < 0) {
          return iVar1;
        }
        if ((local_28 & 2) == 0) {
          if ((local_28 & 4) != 0) {
            return -0x1f5;
          }
          if (iVar6 < 1) {
            return iVar1;
          }
          FUN_00019a40(&local_30);
          local_2c = local_2c - local_34;
          if (local_30 < local_38) {
            local_2c = local_2c + -1;
          }
          local_30 = local_30 - local_38;
          FUN_00019a60(&local_30,&local_24,local_20);
          iVar6 = iVar6 - (local_24 * 1000 + (local_20[0] + 500) / 1000);
          if (iVar6 < 1) {
            return -500;
          }
          *param_2 = iVar6;
          return iVar1;
        }
        goto LAB_0000d784;
      }
    }
    puVar3 = (undefined4 *)FUN_0000a60c(0x18);
    iVar6 = -1;
    if (puVar3 != (undefined4 *)0x0) {
      iVar6 = FUN_0000d5e0();
      if (iVar6 < 1) {
        FUN_0000a7e0(puVar3);
      }
      else {
        puVar3[2] = 0;
        puVar3[3] = iVar6;
        puVar3[4] = 0;
        puVar3[5] = 0;
        puVar4 = (undefined4 *)param_1[1];
        puVar3[1] = puVar4;
        if (puVar4 == (undefined4 *)0x0) {
          *param_1 = (int)puVar3;
        }
        else {
          *puVar4 = puVar3;
        }
        iVar6 = 0;
        *puVar3 = 0;
        param_1[1] = (int)puVar3;
      }
    }
  }
  return iVar6;
}


================================================================