FUNCTION FUN_0000a60c @ 0x0000a60c size=468
CALLERS (22): FUN_0000e6ac@0x0000e6ac, FUN_00005c7c@0x00005c7c, FUN_00008d64@0x00008d64, FUN_000183f0@0x000183f0, FUN_0000d658@0x0000d658, FUN_00011a20@0x00011a20, FUN_00008a8c@0x00008a8c, FUN_00017ad8@0x00017ad8, FUN_0000797c@0x0000797c, FUN_0000b100@0x0000b100, FUN_00012eb0@0x00012eb0, FUN_000114dc@0x000114dc, FUN_00009e60@0x00009e60, FUN_0000e1c8@0x0000e1c8, FUN_0000cdd4@0x0000cdd4, FUN_00008930@0x00008930, FUN_00017da0@0x00017da0, FUN_00001108@0x00001108, FUN_00000160@0x00000160, FUN_00012ac8@0x00012ac8, FUN_000179cc@0x000179cc, FUN_0000e62c@0x0000e62c
CALLEES (2): FUN_0000d390@0x0000d390, FUN_0000d3b4@0x0000d3b4

uint * FUN_0000a60c(int param_1)

{
  uint *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  uint *puVar7;
  uint uVar8;
  
  uVar2 = FUN_0000d390();
  uVar4 = param_1 + 3U & 0xfffffffc;
  puVar6 = DAT_0001b970;
  if (DAT_0001b970 != (uint *)0x0) {
    do {
      if ((int)uVar4 <= (int)puVar6[2]) break;
      puVar6 = (uint *)*puVar6;
    } while (puVar6 != (uint *)0x0);
    if (puVar6 != (uint *)0x0) {
      uVar8 = (puVar6[2] - 0xc) - uVar4;
      if ((int)uVar8 < 1) {
        puVar7 = (uint *)puVar6[1];
        if (*puVar6 != 0) {
          *(uint **)(*puVar6 + 4) = (uint *)puVar6[1];
          puVar7 = DAT_0001b974;
        }
        DAT_0001b974 = puVar7;
        puVar7 = puVar6;
        puVar1 = (uint *)*puVar6;
        if ((undefined4 *)puVar6[1] != (undefined4 *)0x0) {
          *(undefined4 *)puVar6[1] = (uint *)*puVar6;
          puVar1 = DAT_0001b970;
        }
      }
      else {
        puVar7 = (uint *)((int)puVar6 + uVar4 + 0xc);
        puVar6[2] = uVar4;
        puVar7[2] = uVar8;
        uVar4 = *puVar6;
        *puVar7 = uVar4;
        puVar1 = puVar7;
        if (uVar4 != 0) {
          *(uint **)(uVar4 + 4) = puVar7;
          puVar1 = DAT_0001b974;
        }
        DAT_0001b974 = puVar1;
        puVar3 = (undefined4 *)puVar6[1];
        puVar7[1] = (uint)puVar3;
        puVar1 = puVar7;
        if (puVar3 != (undefined4 *)0x0) {
          *puVar3 = puVar7;
          puVar1 = DAT_0001b970;
        }
      }
      DAT_0001b970 = puVar1;
      puVar1 = DAT_0001b96c;
      uVar4 = (int)puVar7 + puVar7[2] + 0xc;
      if (DAT_0001b968 == (uint *)0x0) {
        puVar6[1] = 0;
        *puVar6 = 0;
        DAT_0001b968 = puVar6;
        DAT_0001b96c = puVar6;
      }
      else if (uVar4 < DAT_0001b97c) {
        puVar3 = *(undefined4 **)(uVar4 + 4);
        puVar6[1] = (uint)puVar3;
        puVar7 = puVar6;
        if (puVar3 != (undefined4 *)0x0) {
          *puVar3 = puVar6;
          puVar7 = DAT_0001b968;
        }
        DAT_0001b968 = puVar7;
        *puVar6 = uVar4;
        *(uint **)(uVar4 + 4) = puVar6;
      }
      else {
        *puVar6 = 0;
        puVar7 = puVar6;
        puVar6[1] = (uint)DAT_0001b96c;
        DAT_0001b96c = puVar7;
        *puVar1 = (uint)puVar6;
      }
      DAT_0001b9d4 = (DAT_0001b9d4 + -0xc) - puVar6[2];
      iVar5 = DAT_0001b9d4;
      if (DAT_0001b9d8 < DAT_0001b9d4) {
        iVar5 = DAT_0001b9d8;
      }
      DAT_0001b9d8 = iVar5;
      FUN_0000d3b4(uVar2);
      return puVar6 + 3;
    }
  }
  FUN_0000d3b4(uVar2);
  return (uint *)0x0;
}


================================================================