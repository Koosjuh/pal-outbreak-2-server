FUNCTION FUN_000038a4 @ 0x000038a4 size=1456
CALLERS (5): FUN_00004078@0x00004078, FUN_00003e54@0x00003e54, FUN_00004130@0x00004130, FUN_00003f0c@0x00003f0c, FUN_00004290@0x00004290
CALLEES (5): FUN_0000ae24@0x0000ae24, FUN_00006200@0x00006200, FUN_0000709c@0x0000709c, FUN_0000a9c0@0x0000a9c0, FUN_00009e60@0x00009e60

void FUN_000038a4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int param_6)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  ushort uVar4;
  int iVar5;
  code *pcVar6;
  undefined2 *puVar7;
  int iVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  ushort *puVar14;
  
  iVar13 = *(int *)(param_1 + 8);
  iVar11 = param_6 + 9;
  if (*(int *)(iVar13 + 0x198) != 0) {
    iVar11 = param_6 + 0xb + *(int *)(iVar13 + 0x198);
  }
  uVar12 = iVar11 + 1;
  iVar8 = 0x134;
  if (0x3f < (int)uVar12) {
    iVar8 = (iVar11 + 4U & 0xfffffffc) + 0xf4;
  }
  iVar5 = FUN_00009e60(0,iVar8);
  if (iVar5 != 0) {
    puVar14 = *(ushort **)(iVar5 + 0x14);
    *puVar14 = 0x44;
    puVar14[1] = 0x43;
    puVar14[2] = (ushort)iVar8;
    puVar14[3] = 0;
    *(int *)(iVar5 + 0x14) = *(int *)(iVar5 + 0x14) + 8;
    *puVar14 = *puVar14 << 8 | *puVar14 >> 8;
    puVar14[1] = puVar14[1] << 8 | puVar14[1] >> 8;
    puVar14[2] = puVar14[2] << 8 | puVar14[2] >> 8;
    puVar10 = *(undefined1 **)(iVar5 + 0x14);
    FUN_0000ae24(puVar10,0xec);
    puVar7 = (undefined2 *)0x0;
    *puVar10 = 1;
    puVar10[1] = 1;
    puVar10[2] = 6;
    puVar10[4] = (char)param_4;
    puVar10[5] = (char)((uint)param_4 >> 8);
    puVar10[6] = (char)((uint)param_4 >> 0x10);
    puVar10[7] = (char)((uint)param_4 >> 0x18);
    *(undefined2 *)(puVar10 + 8) = 0;
    *(undefined2 *)(puVar10 + 10) = 0;
    puVar10[0xc] = (char)param_2;
    puVar10[0xd] = (char)((uint)param_2 >> 8);
    puVar10[0xe] = (char)((uint)param_2 >> 0x10);
    puVar10[0xf] = (char)((uint)param_2 >> 0x18);
    puVar10[0x10] = 0;
    puVar10[0x11] = 0;
    puVar10[0x12] = 0;
    puVar10[0x13] = 0;
    puVar10[0x14] = 0;
    puVar10[0x15] = 0;
    puVar10[0x16] = 0;
    puVar10[0x17] = 0;
    puVar10[0x18] = 0;
    puVar10[0x19] = 0;
    puVar10[0x1a] = 0;
    puVar10[0x1b] = 0;
    if (iVar13 != 0) {
      puVar7 = (undefined2 *)(iVar13 + 0x88);
    }
    pcVar6 = (code *)0x2;
    *(undefined2 *)(puVar10 + 0x1c) = *puVar7;
    if (iVar13 != 0) {
      pcVar6 = (code *)(iVar13 + 0x8a);
    }
    puVar7 = (undefined2 *)0x4;
    *(undefined2 *)(puVar10 + 0x1e) = *(undefined2 *)pcVar6;
    if (iVar13 != 0) {
      puVar7 = (undefined2 *)(iVar13 + 0x8c);
    }
    *(undefined2 *)(puVar10 + 0x20) = *puVar7;
    FUN_0000a9c0(param_5,puVar10 + 0xec,param_6);
    puVar9 = puVar10 + param_6 + 0xec;
    *puVar9 = 0x3d;
    puVar9[1] = puVar10[2] + '\x01';
    puVar9[2] = puVar10[1];
    FUN_0000a9c0(puVar10 + 0x1c,puVar9 + 3,puVar10[2]);
    puVar9 = puVar9 + 3 + (byte)puVar10[2];
    if (*(int *)(iVar13 + 0x198) != 0) {
      *puVar9 = 0xc;
      puVar9[1] = *(undefined1 *)(iVar13 + 0x198);
      FUN_0000a9c0(iVar13 + 0x98,puVar9 + 2,*(undefined4 *)(iVar13 + 0x198));
      puVar9 = puVar9 + 2 + *(int *)(iVar13 + 0x198);
    }
    FUN_0000a9c0(&DAT_0001b130,puVar9,1);
    if ((int)uVar12 < 0x40) {
      FUN_0000ae24(puVar10 + iVar11 + 0xed,0x40 - uVar12);
      uVar12 = 0x40;
    }
    else if ((uVar12 & 3) != 0) {
      FUN_0000ae24(puVar10 + iVar11 + 0xed,4 - (uVar12 & 3));
      uVar12 = iVar11 + 4U & 0xfffffffc;
    }
    *(uint *)(iVar5 + 0x14) = *(int *)(iVar5 + 0x14) + uVar12 + 0xec;
    uVar3 = *(undefined4 *)(puVar10 + 4);
    puVar10[4] = (char)((uint)uVar3 >> 0x18);
    puVar10[5] = (char)((uint)uVar3 >> 0x10);
    puVar10[6] = (char)((uint)uVar3 >> 8);
    puVar10[7] = (char)uVar3;
    uVar1 = puVar10[0xc];
    *(ushort *)(puVar10 + 8) = *(ushort *)(puVar10 + 8) << 8 | *(ushort *)(puVar10 + 8) >> 8;
    *(ushort *)(puVar10 + 10) = *(ushort *)(puVar10 + 10) << 8 | *(ushort *)(puVar10 + 10) >> 8;
    uVar2 = puVar10[0xd];
    puVar10[0xc] = puVar10[0xf];
    puVar10[0xd] = puVar10[0xe];
    puVar10[0xe] = uVar2;
    puVar10[0xf] = uVar1;
    uVar3 = *(undefined4 *)(puVar10 + 0x10);
    puVar10[0x10] = (char)((uint)uVar3 >> 0x18);
    puVar10[0x11] = (char)((uint)uVar3 >> 0x10);
    puVar10[0x12] = (char)((uint)uVar3 >> 8);
    puVar10[0x13] = (char)uVar3;
    uVar3 = *(undefined4 *)(puVar10 + 0x14);
    puVar10[0x14] = (char)((uint)uVar3 >> 0x18);
    puVar10[0x15] = (char)((uint)uVar3 >> 0x10);
    puVar10[0x16] = (char)((uint)uVar3 >> 8);
    puVar10[0x17] = (char)uVar3;
    uVar3 = *(undefined4 *)(puVar10 + 0x18);
    puVar10[0x18] = (char)((uint)uVar3 >> 0x18);
    puVar10[0x19] = (char)((uint)uVar3 >> 0x10);
    puVar10[0x1a] = (char)((uint)uVar3 >> 8);
    puVar10[0x1b] = (char)uVar3;
    uVar4 = FUN_00006200(0x11,param_2,param_3,iVar5);
    puVar14[3] = ~uVar4;
    FUN_0000709c(iVar13,param_2,param_3,0x11,0x40,0,iVar5,0);
  }
  return;
}


================================================================