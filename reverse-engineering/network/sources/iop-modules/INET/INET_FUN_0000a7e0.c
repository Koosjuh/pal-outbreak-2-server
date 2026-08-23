FUNCTION FUN_0000a7e0 @ 0x0000a7e0 size=480
CALLERS (23): FUN_00008d64@0x00008d64, FUN_000078f0@0x000078f0, FUN_00011abc@0x00011abc, FUN_0000d508@0x0000d508, FUN_000183f0@0x000183f0, FUN_00005e44@0x00005e44, FUN_00009eec@0x00009eec, FUN_00008cfc@0x00008cfc, FUN_0000d658@0x0000d658, FUN_00011794@0x00011794, FUN_00000000@0x00000000, FUN_0000e770@0x0000e770, FUN_00000344@0x00000344, FUN_00008bb8@0x00008bb8, FUN_00012c60@0x00012c60, FUN_0000b198@0x0000b198, FUN_00019204@0x00019204, FUN_0000cdd4@0x0000cdd4, FUN_0000e428@0x0000e428, FUN_00008930@0x00008930, FUN_00012e20@0x00012e20, FUN_00017e68@0x00017e68, FUN_00019520@0x00019520
CALLEES (2): FUN_0000d390@0x0000d390, FUN_0000d3b4@0x0000d3b4

undefined4 FUN_0000a7e0(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  uint *puVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  uint *puVar8;
  uint uVar9;
  uint *puVar10;
  
  if (param_1 != 0) {
    uVar2 = FUN_0000d390();
    puVar10 = (uint *)(param_1 + -0xc);
    uVar1 = *(undefined4 *)(param_1 + -8);
    if (*(int *)(param_1 + -0xc) != 0) {
      *(undefined4 *)(*(int *)(param_1 + -0xc) + 4) = *(undefined4 *)(param_1 + -8);
      uVar1 = DAT_0001b96c;
    }
    DAT_0001b96c = uVar1;
    uVar9 = *puVar10;
    if (*(uint **)(param_1 + -8) != (uint *)0x0) {
      **(uint **)(param_1 + -8) = *puVar10;
      uVar9 = DAT_0001b968;
    }
    DAT_0001b968 = uVar9;
    DAT_0001b9d4 = DAT_0001b9d4 + 0xc + *(int *)(param_1 + -4);
    puVar8 = puVar10;
    if (*puVar10 == (int)puVar10 + *(int *)(param_1 + -4) + 0xc) {
      do {
        puVar8 = (uint *)*puVar8;
      } while (*puVar8 == (int)puVar8 + puVar8[2] + 0xc);
    }
    uVar9 = (int)puVar8 + puVar8[2] + 0xc;
    if (uVar9 < DAT_0001b97c) {
      puVar3 = *(undefined4 **)(uVar9 + 4);
      *(undefined4 **)(param_1 + -8) = puVar3;
      puVar8 = puVar10;
      if (puVar3 != (undefined4 *)0x0) {
        *puVar3 = puVar10;
        puVar8 = DAT_0001b970;
      }
      DAT_0001b970 = puVar8;
      *puVar10 = uVar9;
      *(uint **)(uVar9 + 4) = puVar10;
      puVar8 = DAT_0001b970;
      puVar6 = DAT_0001b974;
    }
    else {
      *puVar10 = 0;
      *(uint **)(param_1 + -8) = DAT_0001b974;
      puVar8 = puVar10;
      puVar6 = puVar10;
      if (DAT_0001b974 != (uint *)0x0) {
        *DAT_0001b974 = (uint)puVar10;
        puVar8 = DAT_0001b970;
      }
    }
    DAT_0001b974 = puVar6;
    DAT_0001b970 = puVar8;
    iVar5 = *(int *)(param_1 + -8);
    puVar8 = DAT_0001b974;
    if ((iVar5 != 0) && (iVar7 = *(int *)(iVar5 + 8) + 0xc, (uint *)(iVar5 + iVar7) == puVar10)) {
      *(int *)(iVar5 + 8) = iVar7 + *(int *)(param_1 + -4);
      puVar10 = *(uint **)(param_1 + -8);
      uVar9 = *(uint *)*puVar10;
      *puVar10 = uVar9;
      puVar8 = puVar10;
      if (uVar9 != 0) {
        *(uint **)(uVar9 + 4) = puVar10;
        puVar8 = DAT_0001b974;
      }
    }
    DAT_0001b974 = puVar8;
    puVar6 = (uint *)*puVar10;
    puVar8 = DAT_0001b974;
    if (puVar6 != (uint *)0x0) {
      puVar4 = (uint *)((int)puVar10 + puVar10[2] + 0xc);
      if (puVar4 == puVar6) {
        puVar10[2] = puVar10[2] + 0xc + puVar4[2];
        uVar9 = *puVar6;
        *puVar10 = uVar9;
        puVar8 = puVar10;
        if (uVar9 != 0) {
          *(uint **)(uVar9 + 4) = puVar10;
          puVar8 = DAT_0001b974;
        }
      }
    }
    DAT_0001b974 = puVar8;
    FUN_0000d3b4(uVar2);
  }
  return 0;
}


================================================================