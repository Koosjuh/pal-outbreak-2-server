FUNCTION FUN_00013264 @ 0x00013264 size=1248
CALLERS (7): FUN_00013f78@0x00013f78, FUN_00016d00@0x00016d00, FUN_000137c8@0x000137c8, FUN_00013744@0x00013744, FUN_00013b50@0x00013b50, FUN_0001380c@0x0001380c, FUN_00015f04@0x00015f04
CALLEES (7): FUN_00006200@0x00006200, FUN_0000709c@0x0000709c, FUN_0000a9c0@0x0000a9c0, FUN_00017bf4@0x00017bf4, FUN_0001311c@0x0001311c, FUN_00009f70@0x00009f70, FUN_00009e60@0x00009e60

int FUN_00013264(int param_1,byte param_2,int param_3,undefined4 param_4,int param_5)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  bool bVar6;
  ushort *puVar7;
  int iVar8;
  undefined2 local_40;
  undefined2 local_3e;
  undefined2 local_3c;
  undefined2 local_3a;
  undefined2 local_38;
  undefined2 local_36;
  undefined1 local_34;
  byte local_33;
  ushort local_32;
  undefined2 local_30;
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  undefined1 local_29;
  byte local_28 [8];
  
  iVar8 = 0x14;
  if ((param_2 & 2) != 0) {
    iVar8 = 0x18;
  }
  local_40 = *(undefined2 *)(param_1 + 0x1a);
  local_3e = *(undefined2 *)(param_1 + 0x18);
  local_3c = (undefined2)param_3;
  local_38 = (undefined2)param_4;
  local_3a = (undefined2)((uint)param_3 >> 0x10);
  local_36 = (undefined2)((uint)param_4 >> 0x10);
  local_34 = (undefined1)(iVar8 << 2);
  if ((param_2 & 2) != 0) {
    if (*(int *)(param_1 + 0xc) == 0) {
      iVar2 = -0x28;
    }
    else {
      iVar2 = *(int *)(*(int *)(param_1 + 0xc) + 0x84) + -0x28;
    }
    *(int *)(param_1 + 0x78) = iVar2;
    if (iVar2 < 1) {
      *(undefined4 *)(param_1 + 0x78) = 0x5b4;
    }
    local_2c = 2;
    local_2b = 4;
    local_2a = (undefined1)((ushort)*(undefined2 *)(param_1 + 0x78) >> 8);
    local_29 = (undefined1)*(undefined2 *)(param_1 + 0x78);
  }
  local_32 = 0;
  if ((param_2 & 4) == 0) {
    uVar3 = *(int *)(param_1 + 0x90) - *(int *)(param_1 + 0x94);
    if ((int)uVar3 < 1) {
      uVar3 = 0;
    }
    local_32 = (ushort)uVar3;
    if (3 < *(int *)(param_1 + 0x28)) {
      if (((int)((uVar3 & 0xffff) << 2) < *(int *)(param_1 + 0x90)) ||
         ((int)(uVar3 & 0xffff) < *(int *)(param_1 + 0x78))) {
        local_32 = 0;
      }
      uVar3 = *(int *)(param_1 + 0x74) - *(int *)(param_1 + 0x70);
      if ((int)uVar3 <= (int)(uint)local_32) {
        uVar3 = (uint)local_32;
      }
      local_32 = (ushort)uVar3;
      *(uint *)(param_1 + 0x74) = *(int *)(param_1 + 0x70) + (uVar3 & 0xffff);
    }
  }
  local_30 = 0;
  local_33 = param_2;
  if (((param_2 & 2) == 0) &&
     (iVar2 = FUN_0001311c(param_1,param_3 - *(int *)(param_1 + 0x38),param_5,local_28), iVar2 != 0)
     ) {
    iVar8 = *(int *)(iVar2 + 0x10) + -0x14;
    *(int *)(iVar2 + 0x10) = iVar8;
    FUN_0000a9c0(&local_40,iVar8,0x14);
    puVar7 = *(ushort **)(iVar2 + 0x10);
  }
  else {
    iVar2 = FUN_00009e60(0,*(int *)(param_1 + 0xd4) + iVar8 + param_5);
    if (iVar2 == 0) {
      iVar8 = *(int *)(*(int *)(param_1 + 0xc) + 0x1a0);
      *(int *)(iVar8 + 0x38) = *(int *)(iVar8 + 0x38) + 1;
      return -1;
    }
    *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + *(int *)(param_1 + 0xd4);
    iVar4 = *(int *)(iVar2 + 0x14) + *(int *)(param_1 + 0xd4);
    *(int *)(iVar2 + 0x14) = iVar4;
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(param_1 + 0xd8);
    FUN_0000a9c0(&local_40,iVar4,iVar8);
    puVar7 = *(ushort **)(iVar2 + 0x14);
    *(int *)(iVar2 + 0x14) = (int)puVar7 + iVar8;
    if (param_5 < 1) goto LAB_0001350c;
    param_5 = FUN_00009f70(param_1 + 0x84,param_3 - *(int *)(param_1 + 0x38),
                           *(undefined4 *)(iVar2 + 0x14),param_5,local_28);
    *(int *)(iVar2 + 0x14) = *(int *)(iVar2 + 0x14) + param_5;
  }
  *(byte *)((int)puVar7 + 0xd) = *(byte *)((int)puVar7 + 0xd) | local_28[0] & 0x28;
LAB_0001350c:
  if ((*(byte *)((int)puVar7 + 0xd) & 0x20) == 0) {
    puVar7[9] = 0;
  }
  else {
    puVar7[9] = (ushort)param_5;
    if ((*(uint *)(param_1 + 0x2c) & 0x80000) != 0) {
      puVar7[9] = (ushort)param_5 - 1;
    }
  }
  *puVar7 = *puVar7 << 8 | *puVar7 >> 8;
  puVar7[1] = puVar7[1] << 8 | puVar7[1] >> 8;
  uVar5 = *(undefined4 *)(puVar7 + 2);
  *(char *)(puVar7 + 2) = (char)((uint)uVar5 >> 0x18);
  *(char *)((int)puVar7 + 5) = (char)((uint)uVar5 >> 0x10);
  *(char *)(puVar7 + 3) = (char)((uint)uVar5 >> 8);
  *(char *)((int)puVar7 + 7) = (char)uVar5;
  uVar5 = *(undefined4 *)(puVar7 + 4);
  *(char *)(puVar7 + 4) = (char)((uint)uVar5 >> 0x18);
  *(char *)((int)puVar7 + 9) = (char)((uint)uVar5 >> 0x10);
  *(char *)(puVar7 + 5) = (char)((uint)uVar5 >> 8);
  *(char *)((int)puVar7 + 0xb) = (char)uVar5;
  puVar7[7] = puVar7[7] << 8 | puVar7[7] >> 8;
  puVar7[9] = puVar7[9] << 8 | puVar7[9] >> 8;
  uVar1 = FUN_00006200(6,*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x10),iVar2);
  puVar7[8] = ~uVar1;
  *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) & 0xfffff7ff;
  uVar5 = FUN_00017bf4(*(undefined4 *)(param_1 + 200));
  *(undefined4 *)(param_1 + 200) = uVar5;
  iVar8 = *(int *)(*(int *)(param_1 + 0xc) + 0x1a0);
  *(int *)(iVar8 + 0x30) = *(int *)(iVar8 + 0x30) + 1;
  DAT_0001b9f0 = DAT_0001b9f0 + 1;
  bVar6 = false;
  if (*(int *)(param_1 + 0xdc) != 0) {
    bVar6 = 0 < *(int *)(*(int *)(param_1 + 0xdc) + 0x18);
  }
  FUN_0000709c(*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x14),
               *(undefined4 *)(param_1 + 0x10),6,0x40,bVar6,iVar2,0);
  return param_5;
}


================================================================