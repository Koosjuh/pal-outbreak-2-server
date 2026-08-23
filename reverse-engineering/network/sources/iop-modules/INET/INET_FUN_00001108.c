FUNCTION FUN_00001108 @ 0x00001108 size=980
CALLERS (1): FUN_0000dcf8@0x0000dcf8
CALLEES (11): FUN_00006ea8@0x00006ea8, FUN_0000df10@0x0000df10, FUN_00006e70@0x00006e70, FUN_0000e594@0x0000e594, FUN_00000994@0x00000994, FUN_00017ad8@0x00017ad8, FUN_0000a60c@0x0000a60c, FUN_00011d90@0x00011d90, FUN_0000029c@0x0000029c, FUN_00009e60@0x00009e60, FUN_00009eec@0x00009eec

void FUN_00001108(int param_1,int *param_2)

{
  undefined2 uVar1;
  uint uVar2;
  undefined2 *puVar3;
  int iVar4;
  undefined2 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  code *pcVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar11;
  int *piVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  
  iVar13 = 0;
  iVar15 = 0;
  if (param_1 == 0) {
    if ((DAT_0001b850 & 1) != 0) {
      FUN_00011d90("# ERR # %s:%d: %s\n",s_arp_c_0001b3f8,0x14e,"arp_snd - no ops");
    }
    goto LAB_000014a4;
  }
  uVar16 = *(uint *)(param_1 + 0x70);
  uVar14 = *(uint *)(param_1 + 0x74);
  uVar11 = *(uint *)(param_2[4] + 0x10);
  uVar2 = uVar11 >> 8 & 0xff00;
  uVar10 = uVar11 << 0x18 | (uVar11 & 0xff00) << 8 | uVar2 | uVar11 >> 0x18;
  if ((param_2[3] & 0x400U) == 0) {
    piVar12 = (int *)FUN_00009e60(0,0xe);
    if (piVar12 != (int *)0x0) {
      puVar3 = (undefined2 *)piVar12[5];
      goto LAB_00001228;
    }
    uVar9 = 0x15b;
  }
  else {
    piVar12 = (int *)0x0;
    puVar3 = (undefined2 *)(param_2[4] + -0xe);
    param_2[4] = (int)puVar3;
LAB_00001228:
    DAT_0001b9c4 = DAT_0001b9c4 + 1;
    iVar4 = FUN_00006e70(param_1,uVar10);
    if (iVar4 < 1) {
      iVar15 = FUN_00006ea8(param_1,uVar10);
      if (((iVar15 == 0) && ((uVar10 & uVar14) != (uVar16 & uVar14))) &&
         ((uVar2 = FUN_0000e594(uVar10), uVar11 = uVar10, uVar2 == 0 ||
          (uVar11 = uVar2, uVar2 != 0xffffffff)))) {
        uVar10 = uVar11;
      }
      iVar13 = FUN_0000029c(param_1,uVar10);
      if (iVar13 == 0) {
        if (iVar15 == 0) goto LAB_000014a4;
        *puVar3 = DAT_0001b3e8;
        puVar3[1] = DAT_0001b3ea;
        puVar3[2] = DAT_0001b3ec;
      }
      else if ((*(uint *)(iVar13 + 8) & 1) != 0) {
        *puVar3 = *(undefined2 *)(iVar13 + 0x14);
        puVar3[1] = *(undefined2 *)(iVar13 + 0x16);
        puVar3[2] = *(undefined2 *)(iVar13 + 0x18);
      }
    }
    else {
      *puVar3 = DAT_0001b3f0;
      puVar3[1] = DAT_0001b3f2;
      uVar1 = DAT_0001b3f4;
      *(byte *)((int)puVar3 + 3) = (byte)((uVar11 & 0xff00) >> 8) & 0x7f;
      puVar3[2] = uVar1;
      *(char *)(puVar3 + 2) = (char)(uVar2 >> 8);
      *(char *)((int)puVar3 + 5) = (char)(uVar11 >> 0x18);
    }
    puVar5 = (undefined2 *)0x0;
    if (param_1 != 0) {
      puVar5 = (undefined2 *)(param_1 + 0x88);
    }
    pcVar8 = (code *)0x2;
    puVar3[3] = *puVar5;
    if (param_1 != 0) {
      pcVar8 = (code *)(param_1 + 0x8a);
    }
    puVar5 = (undefined2 *)0x4;
    puVar3[4] = *(undefined2 *)pcVar8;
    if (param_1 != 0) {
      puVar5 = (undefined2 *)(param_1 + 0x8c);
    }
    uVar1 = *puVar5;
    puVar3[6] = 8;
    puVar3[5] = uVar1;
    if (piVar12 != (int *)0x0) {
      *piVar12 = (int)param_2;
      piVar12[5] = piVar12[5] + 0xe;
      param_2[1] = (int)piVar12;
    }
    if (((iVar15 != 0) || (0 < iVar4)) || ((*(uint *)(iVar13 + 8) & 1) != 0)) {
      if (piVar12 == (int *)0x0) {
        piVar12 = param_2;
      }
      FUN_0000df10(param_1,piVar12);
      return;
    }
    puVar6 = (undefined4 *)FUN_0000a60c(0xc);
    if (puVar6 != (undefined4 *)0x0) {
      puVar6[2] = piVar12;
      if (piVar12 == (int *)0x0) {
        puVar6[2] = param_2;
      }
      puVar7 = *(undefined4 **)(iVar13 + 0x28);
      puVar6[1] = puVar7;
      if (puVar7 == (undefined4 *)0x0) {
        *(undefined4 **)(iVar13 + 0x24) = puVar6;
      }
      else {
        *puVar7 = puVar6;
      }
      *puVar6 = 0;
      *(undefined4 **)(iVar13 + 0x28) = puVar6;
      if (*(int *)(iVar13 + 0xc) != 0) {
        return;
      }
      *(undefined4 *)(iVar13 + 0xc) = 1;
      FUN_00000994(param_1,uVar10);
      uVar9 = FUN_00017ad8(0xc4,iVar13,1000);
      *(undefined4 *)(iVar13 + 0x1c) = uVar9;
      return;
    }
    uVar9 = 0x185;
  }
  if ((DAT_0001b850 & 1) != 0) {
    FUN_00011d90("# ERR # %s:%d: %s\n",s_arp_c_0001b3f8,uVar9,"arp_snd - no space");
  }
LAB_000014a4:
  FUN_00009eec(param_2);
  return;
}


================================================================