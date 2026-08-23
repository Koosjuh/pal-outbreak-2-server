FUNCTION FUN_0000ad1c @ 0x0000ad1c size=1724
CALLERS (2): FUN_0000b3d8@0x0000b3d8, FUN_0000b708@0x0000b708
CALLEES (4): FUN_00001c68@0x00001c68, FUN_00001c7c@0x00001c7c, FUN_00010c38@0x00010c38, FUN_0000075c@0x0000075c

undefined4 FUN_0000ad1c(undefined4 param_1,int param_2,ushort *param_3,byte *param_4,short param_5)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  short sVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  
  uVar5 = (uint)param_4[1];
  bVar1 = *param_4;
  iVar9 = uVar5 - 2;
  uVar10 = 2;
  if (bVar1 == 3) {
    sVar4 = FUN_0000075c(param_1,&DAT_00013620,4);
    iVar7 = 0;
    if (sVar4 == 4) {
      iVar7 = FUN_00001c7c(&DAT_00013620);
    }
    *(int *)(param_3 + 0x16) = iVar7;
    iVar9 = uVar5 - 6;
    if (param_5 == 0) {
      *(int *)(param_2 + 8) = iVar7;
      *(undefined4 *)(param_2 + 0x58) = *(undefined4 *)(param_3 + 0x16);
    }
    else if (iVar7 == 0) {
      uVar10 = 3;
      *(undefined4 *)(param_2 + 0x78) = *(undefined4 *)(param_2 + 0x54);
    }
    else {
      *(int *)(param_2 + 0x54) = iVar7;
      *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(param_3 + 0x16);
    }
    goto LAB_0000b2c8;
  }
  if (3 < bVar1) {
    if (bVar1 == 0x81) {
      sVar4 = FUN_0000075c(param_1,&DAT_00013620,4);
      iVar7 = 0;
      if (sVar4 == 4) {
        iVar7 = FUN_00001c7c(&DAT_00013620);
      }
      *(int *)(param_3 + 0x1e) = iVar7;
      iVar9 = uVar5 - 6;
      if (param_5 == 0) {
        *(int *)(param_2 + 0x18) = iVar7;
        *(undefined4 *)(param_2 + 0x6c) = *(undefined4 *)(param_3 + 0x1e);
      }
      else if (iVar7 == 0) {
        uVar10 = 3;
        *(undefined4 *)(param_2 + 0x88) = *(undefined4 *)(param_2 + 100);
      }
      else {
        *(int *)(param_2 + 100) = iVar7;
        *(undefined4 *)(param_2 + 0x20) = *(undefined4 *)(param_3 + 0x1e);
      }
      goto LAB_0000b2c8;
    }
    if (bVar1 == 0x83) {
      sVar4 = FUN_0000075c(param_1,&DAT_00013620,4);
      uVar6 = 0;
      if (sVar4 == 4) {
        uVar6 = FUN_00001c7c(&DAT_00013620);
      }
      *(undefined4 *)(param_3 + 0x20) = uVar6;
      iVar9 = uVar5 - 6;
      if (param_5 == 0) {
        *(undefined4 *)(param_2 + 0x1c) = uVar6;
        *(undefined4 *)(param_2 + 0x70) = *(undefined4 *)(param_3 + 0x20);
      }
      else if (*(int *)(param_3 + 0x1e) == 0) {
        uVar10 = 3;
        *(undefined4 *)(param_2 + 0x8c) = *(undefined4 *)(param_2 + 0x68);
      }
      else {
        *(undefined4 *)(param_2 + 0x68) = uVar6;
        *(undefined4 *)(param_2 + 0x24) = *(undefined4 *)(param_3 + 0x20);
      }
      goto LAB_0000b2c8;
    }
LAB_0000b290:
    uVar10 = 4;
    if (DAT_00012efc != 0) {
      FUN_00010c38("ave-ppp %s:","ipcp_check");
      FUN_00010c38("Unsupported config request 0x%x rejected.\n",*param_4);
    }
    goto LAB_0000b2c8;
  }
  if (bVar1 == 1) {
    sVar4 = FUN_0000075c(param_1,&DAT_00013620,4);
    if (sVar4 == 4) {
      uVar6 = FUN_00001c7c(&DAT_00013620);
      *(undefined4 *)(param_3 + 0x16) = uVar6;
    }
    else {
      param_3[0x16] = 0;
      param_3[0x17] = 0;
    }
    sVar4 = FUN_0000075c(param_1,&DAT_00013620,4);
    if (sVar4 == 4) {
      uVar6 = FUN_00001c7c(&DAT_00013620);
      *(undefined4 *)(param_3 + 0x18) = uVar6;
    }
    else {
      param_3[0x18] = 0;
      param_3[0x19] = 0;
    }
    iVar9 = uVar5 - 10;
    if (param_5 == 0) {
      if (*(int *)(param_2 + 0x54) != 0) {
        *(int *)(param_2 + 0x30) = *(int *)(param_2 + 0x54);
      }
      if (*(int *)(param_2 + 8) != 0) {
        *(int *)(param_2 + 0x2c) = *(int *)(param_2 + 8);
      }
    }
    else {
      iVar7 = *(int *)(param_2 + 0x54);
      if (*(int *)(param_2 + 0x78) == iVar7) {
        if (iVar7 == 0) {
          uVar10 = 4;
        }
      }
      else if (iVar7 == 0) {
        *(int *)(param_2 + 0x30) = *(int *)(param_2 + 0x78);
      }
      else {
        *(int *)(param_2 + 0x78) = iVar7;
        uVar10 = 3;
      }
      iVar7 = *(int *)(param_2 + 8);
      if (*(int *)(param_2 + 0x7c) == iVar7) {
        if (iVar7 == 0) {
          uVar10 = 4;
        }
      }
      else if (iVar7 == 0) {
        *(int *)(param_2 + 0x2c) = *(int *)(param_2 + 0x7c);
      }
      else {
        uVar10 = 3;
        *(int *)(param_2 + 0x7c) = iVar7;
      }
    }
    goto LAB_0000b2c8;
  }
  if (bVar1 != 2) goto LAB_0000b290;
  sVar4 = FUN_0000075c(param_1,&DAT_00013620,2);
  uVar2 = 0xffff;
  if (sVar4 == 2) {
    uVar2 = FUN_00001c68(&DAT_00013620);
  }
  iVar9 = uVar5 - 4;
  param_3[0x1a] = uVar2;
  if ((*param_3 & 4) == 0) {
    if (uVar2 == 0x2d) {
      sVar4 = FUN_0000075c(param_1,&DAT_00013624,1);
      uVar2 = 0xffff;
      if (sVar4 == 1) {
        uVar2 = (ushort)DAT_00013624;
      }
      if (uVar2 == 0xffff) {
        return 0xffffffff;
      }
      param_3[0x1b] = uVar2 + 1;
      sVar4 = FUN_0000075c(param_1,&DAT_00013624,1);
      uVar2 = 0xffff;
      if (sVar4 == 1) {
        uVar2 = (ushort)DAT_00013624;
      }
      if (uVar2 == 0xffff) {
        return 0xffffffff;
      }
      *(char *)(param_3 + 0x1c) = (char)uVar2;
    }
    uVar10 = 4;
    param_3[0x14] = param_3[2] | 4;
    goto LAB_0000b2c8;
  }
  if (uVar2 != 0x2d) {
    if ((param_3[2] & 4) == 0) {
      param_3[0x1b] = 0x10;
      param_3[0x1a] = 0x2d;
      *(undefined1 *)(param_3 + 0x1c) = 1;
    }
    else {
      param_3[0x1a] = param_3[8];
      param_3[0x1b] = param_3[9];
      *(char *)(param_3 + 0x1c) = (char)param_3[10];
    }
    uVar10 = 3;
    goto LAB_0000b2c8;
  }
  sVar4 = FUN_0000075c(param_1,&DAT_00013624,1);
  uVar2 = 0xffff;
  if (sVar4 == 1) {
    uVar2 = (ushort)DAT_00013624;
  }
  uVar3 = uVar2 + 1;
  if (uVar2 == 0xffff) {
    return 0xffffffff;
  }
  param_3[0x1b] = uVar3;
  if ((short)uVar3 < 1) {
    param_3[0x1b] = 1;
LAB_0000b05c:
    uVar10 = 3;
  }
  else if (0x10 < (short)uVar3) {
    param_3[0x1b] = 0x10;
    goto LAB_0000b05c;
  }
  sVar4 = FUN_0000075c(param_1,&DAT_00013624,1);
  uVar2 = 0xffff;
  if (sVar4 == 1) {
    uVar2 = (ushort)DAT_00013624;
  }
  if (uVar2 == 0xffff) {
    return 0xffffffff;
  }
  *(char *)(param_3 + 0x1c) = (char)uVar2;
  if (1 < (uVar2 & 0xff)) {
    *(undefined1 *)(param_3 + 0x1c) = 1;
    uVar10 = 3;
  }
  iVar9 = uVar5 - 6;
LAB_0000b2c8:
  uVar8 = (uint)*param_4;
  uVar5 = (uint)(short)*param_3;
  if (uVar8 < 8) {
    uVar5 = (int)uVar5 >> (uVar8 & 0x1f) & 1;
  }
  else if ((uVar8 + 0x80 & 0xff) < 0x10) {
    uVar5 = (int)uVar5 >> (*param_4 - 0x78 & 0x1f) & 1;
  }
  else {
    uVar5 = uVar5 & 1;
  }
  if (uVar5 == 0) {
    uVar10 = 4;
  }
  uVar6 = 0xffffffff;
  if (((-1 < (short)iVar9) && (uVar6 = uVar10, param_5 == 0)) && (0 < (short)iVar9)) {
    iVar7 = iVar9 << 0x10;
    while (0 < iVar7) {
      iVar9 = iVar9 + -1;
      sVar4 = FUN_0000075c(param_1,&DAT_00013624,1);
      if (sVar4 != 1) {
        return 0xffffffff;
      }
      if (DAT_00013624 == 0xffffffff) {
        return 0xffffffff;
      }
      iVar7 = iVar9 * 0x10000;
    }
  }
  return uVar6;
}


================================================================