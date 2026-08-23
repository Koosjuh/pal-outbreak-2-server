FUNCTION FUN_0000353c @ 0x0000353c size=772
CALLERS (2): FUN_00010e10@0x00010e10, FUN_00010f40@0x00010f40
CALLEES (10): FUN_000010a8@0x000010a8, FUN_0000139c@0x0000139c, FUN_00014e24@0x00014e24, FUN_0000f228@0x0000f228, FUN_0000f308@0x0000f308, FUN_00001454@0x00001454, FUN_00012608@0x00012608, FUN_00004ec4@0x00004ec4, FUN_00004610@0x00004610, FUN_00003b30@0x00003b30

undefined4
FUN_0000353c(int *param_1,undefined4 param_2,undefined2 param_3,short param_4,char param_5,
            undefined1 param_6,undefined4 param_7,undefined4 param_8)

{
  undefined1 uVar1;
  undefined1 uVar2;
  short sVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 local_40;
  undefined4 local_3c;
  undefined1 local_38;
  undefined1 local_37;
  undefined2 local_36;
  undefined4 local_30;
  undefined4 local_2c;
  
  local_30 = param_7;
  local_2c = param_8;
  sVar3 = FUN_00004610();
  if (sVar3 != -1) {
    iVar9 = (int)param_4;
    if (*(char *)(DAT_000161a0 + iVar9 * 0x30 + 0xb) != '\0') {
      param_1[1] = param_1[1] + -0x2a;
      *(short *)(param_1 + (*param_1 + -1) * 3 + 2) =
           (short)param_1[(*param_1 + -1) * 3 + 2] + -0x2a;
      FUN_00001454(param_1 + *param_1 * 3,0x2a);
    }
    if ((int)(uint)DAT_0001617e <= iVar9) {
      return 0xffffffff;
    }
    if (iVar9 < 0) {
      return 0xffffffff;
    }
    iVar9 = iVar9 * 0x30 + DAT_000161a0;
    if (*(short *)(iVar9 + 8) != 0) {
      if (*(char *)(iVar9 + 0x14) == '\0') {
        *(undefined4 *)(iVar9 + 0x18) = param_2;
      }
      uVar10 = *(undefined4 *)(iVar9 + 0x18);
      if (*(char *)(iVar9 + 0x15) == '\0') {
        *(undefined2 *)(iVar9 + 0xe) = param_3;
      }
      iVar6 = FUN_0000f228(uVar10);
      if (iVar6 != 0) {
        uVar4 = FUN_000010a8((int)((*(ushort *)(param_1 + 1) + 8) * 0x10000) >> 0x10);
        *(undefined2 *)(iVar9 + 0x10) = uVar4;
        iVar7 = *param_1;
        *(undefined2 *)(param_1 + iVar7 * 3 + 2) = 8;
        param_1[1] = param_1[1] + 8;
        FUN_0000139c(param_1 + iVar7 * 3 + 3,iVar9 + 0xc);
        *param_1 = *param_1 + 1;
        local_40 = FUN_0000f308(iVar6);
        local_38 = 0;
        local_37 = 0x11;
        local_3c = uVar10;
        local_36 = FUN_000010a8((int)(short)param_1[1]);
        *(undefined2 *)(iVar9 + 0x12) = 0;
        uVar4 = FUN_00003b30(&local_40,param_1,1);
        *(char *)(iVar9 + 0x13) = (char)uVar4;
        *(char *)(iVar9 + 0x12) = (char)((ushort)uVar4 >> 8);
        if (param_5 == '\0') {
          param_6 = *(undefined1 *)(iVar9 + 0x2e);
          uVar1 = *(undefined1 *)(iVar9 + 0x2c);
          uVar2 = *(undefined1 *)(iVar9 + 0x2d);
        }
        else {
          uVar1 = (undefined1)local_30;
          uVar2 = (undefined1)local_2c;
        }
        if ((DAT_00016178 & 4) != 0) {
          uVar8 = FUN_00012608();
          uVar4 = FUN_000010a8((int)*(short *)(iVar9 + 0xc));
          uVar5 = FUN_000010a8((int)*(short *)(iVar9 + 0xe));
          FUN_00014e24("UDP SEND: %u SP %d DP %d\n",uVar8,uVar4,uVar5);
        }
        sVar3 = FUN_00004ec4(param_1,uVar10,*(undefined1 *)(iVar9 + 0xb),param_6,uVar1,uVar2,0,0,
                             0x11,0);
        if (sVar3 != 0) {
          return 0xffffffff;
        }
        return 0;
      }
    }
  }
  return 0xffffffff;
}


================================================================