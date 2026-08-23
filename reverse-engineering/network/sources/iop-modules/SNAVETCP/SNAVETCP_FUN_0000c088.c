FUNCTION FUN_0000c088 @ 0x0000c088 size=876
CALLERS (1): FUN_0000bf04@0x0000bf04
CALLEES (7): FUN_0000ad44@0x0000ad44, FUN_0000c428@0x0000c428, FUN_0000b3d4@0x0000b3d4, FUN_00014e24@0x00014e24, FUN_0000be4c@0x0000be4c, FUN_00001080@0x00001080, FUN_0000af84@0x0000af84

undefined4 FUN_0000c088(int param_1,short param_2)

{
  ushort uVar1;
  short sVar2;
  undefined2 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  
  if (param_2 == 1) {
    FUN_0000be4c(param_1);
    *(undefined1 *)(param_1 + 0x140) = 1;
    FUN_0000b3d4(param_1);
    *(undefined1 *)(param_1 + 0x140) = 0;
    return 0;
  }
  if (param_2 < 2) {
    if (param_2 != 0) {
      return 0;
    }
    sVar2 = *(short *)(param_1 + 0x122) + 1;
    *(short *)(param_1 + 0x122) = sVar2;
    uVar7 = DAT_00016178;
    if (sVar2 < 0xd) {
      sVar2 = (short)(((int)((uint)*(ushort *)(param_1 + 0x118) << 0x10) >> 0x12) +
                      (int)*(short *)(param_1 + 0x11a) >> 1) *
              *(short *)((int)&PTR_DAT_0001575c + sVar2 * 2);
      *(short *)(param_1 + 0x120) = sVar2;
      uVar3 = 2;
      if ((sVar2 < 2) || (uVar3 = 0x80, 0x80 < sVar2)) {
        *(undefined2 *)(param_1 + 0x120) = uVar3;
      }
      *(undefined2 *)(param_1 + 0x124) = *(undefined2 *)(param_1 + 0x120);
      if (3 < *(short *)(param_1 + 0x122)) {
        sVar2 = *(short *)(param_1 + 0x118);
        *(undefined2 *)(param_1 + 0x118) = 0;
        *(short *)(param_1 + 0x11a) = *(short *)(param_1 + 0x11a) + (sVar2 >> 2);
      }
      uVar7 = (uint)*(ushort *)(param_1 + 300);
      *(undefined2 *)(param_1 + 0x112) = 0;
      *(undefined4 *)(param_1 + 0xe0) = *(undefined4 *)(param_1 + 0xdc);
      if (*(ushort *)(param_1 + 0xf4) < *(ushort *)(param_1 + 0x10c)) {
        uVar1 = *(ushort *)(param_1 + 0xf4);
      }
      else {
        uVar1 = *(ushort *)(param_1 + 0x10c);
      }
      uVar9 = (uint)((int)(uint)uVar1 >> 1) / uVar7;
      sVar2 = (short)uVar9;
      if (uVar7 == 0) {
        trap(0x1c00);
      }
      if ((uVar7 == 0xffffffff) && ((int)(uint)uVar1 >> 1 == 0x80000000)) {
        trap(0x1800);
      }
      if (uVar9 < 2) {
        sVar2 = 2;
      }
      *(undefined2 *)(param_1 + 0x10c) = *(undefined2 *)(param_1 + 300);
      *(short *)(param_1 + 0x10e) = sVar2 * *(short *)(param_1 + 300);
      FUN_0000b3d4();
      return 0;
    }
    *(undefined2 *)(param_1 + 0x122) = 0xc;
  }
  else {
    if (param_2 != 2) {
      if (param_2 != 3) {
        return 0;
      }
      if ((*(short *)(param_1 + 0x13a) != 10) && (*(short *)(param_1 + 0x110) <= DAT_00016168)) {
        *(undefined2 *)(param_1 + 0x12a) = 0x96;
        return 0;
      }
      if ((DAT_00016178 & 2) != 0) {
        FUN_00014e24("ave-tcp: delete tcp nh %d. (2MSL expired)\n",
                     (param_1 - DAT_00016180) * -0x2b1da461 >> 2);
      }
      FUN_0000ad44(param_1);
      return 0;
    }
    uVar7 = DAT_00016178;
    if (3 < *(short *)(param_1 + 0x13a)) {
      iVar8 = (int)*(short *)(param_1 + 0x16c);
      uVar3 = *(undefined2 *)(param_1 + 0x16c);
      if (iVar8 == 0) {
        *(undefined2 *)(param_1 + 0x128) = 0x3840;
        return 0;
      }
      if (*(short *)(param_1 + 0x13a) < 6) {
        iVar4 = iVar8 * 9;
        if ((int)DAT_00016168 < iVar8 * 8) {
          iVar4 = iVar8 + DAT_00016168;
        }
        if (iVar4 <= *(short *)(param_1 + 0x110)) goto LAB_0000c39c;
        uVar5 = FUN_00001080(*(int *)(param_1 + 0xdc) + -1);
        uVar6 = FUN_00001080(*(undefined4 *)(param_1 + 0xf8));
        FUN_0000af84(*(undefined4 *)(param_1 + 0x158),*(undefined2 *)(param_1 + 0x144),
                     *(undefined2 *)(param_1 + 0x146),uVar5,uVar6,0x10);
        uVar3 = *(undefined2 *)(param_1 + 0x16c);
        if (0x96 < *(short *)(param_1 + 0x16c)) {
          uVar3 = 0x96;
        }
      }
      *(undefined2 *)(param_1 + 0x128) = uVar3;
      return 0;
    }
  }
LAB_0000c39c:
  if ((uVar7 & 2) != 0) {
    FUN_00014e24("ave-tcp: drop tcp nh %d. (REXMT timeout)\n",
                 (param_1 - DAT_00016180) * -0x2b1da461 >> 2);
  }
  FUN_0000c428(param_1,4);
  return 0;
}


================================================================