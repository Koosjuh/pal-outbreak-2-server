FUNCTION FUN_00000254 @ 0x00000254 size=816
CALLERS (1): FUN_00001298@0x00001298
CALLEES (4): FUN_000029fc@0x000029fc, FUN_00002b8c@0x00002b8c, FUN_00000214@0x00000214, FUN_000029e4@0x000029e4

int FUN_00000254(int *param_1)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  ushort *puVar11;
  int iVar12;
  
  iVar12 = 0;
  iVar10 = *param_1;
  do {
    puVar11 = (ushort *)("smap: can\'t unload (busy)\n" + iVar10 + (param_1[6] & 0x3fU) * 8 + 4);
    uVar1 = *puVar11;
    if ((uVar1 & 0x8000) != 0) {
      if (iVar12 != 0) {
        FUN_00002b8c(param_1[0x62],4);
      }
      return iVar12;
    }
    uVar2 = puVar11[3];
    uVar3 = puVar11[2];
    uVar9 = (uint)uVar3;
    uVar8 = 0;
    piVar7 = param_1;
    if ((uVar1 & 0x27f) == 0) {
      DAT_00003280 = DAT_00003280 + 1;
      iVar4 = FUN_000029fc(param_1 + 0x4f,uVar9 + 3 & 0xfffffffc);
      if (iVar4 == 0) {
        DAT_00003284 = DAT_00003284 + 1;
        param_1[0x38] = param_1[0x38] + 1;
        goto LAB_000003d4;
      }
      *(ushort *)(iVar10 + 0xf34) = uVar2;
      iVar5 = FUN_00000214(iVar10,*(undefined4 *)(iVar4 + 0x14),uVar9,0);
      if (0 < iVar5) {
        *(int *)(iVar4 + 0x14) = *(int *)(iVar4 + 0x14) + iVar5;
      }
      for (; iVar5 < (int)uVar9; iVar5 = iVar5 + 4) {
        puVar6 = *(undefined4 **)(iVar4 + 0x14);
        *puVar6 = *(undefined4 *)(iVar10 + 0x1100);
        *(undefined4 **)(iVar4 + 0x14) = puVar6 + 1;
      }
      param_1[0x32] = param_1[0x32] + 1;
      param_1[0x34] = param_1[0x34] + uVar9;
      if ((**(byte **)(iVar4 + 0x10) & 1) != 0) {
        param_1[0x42] = param_1[0x42] + 1;
        if ((**(int **)(iVar4 + 0x10) == -1) && ((short)(*(int **)(iVar4 + 0x10))[1] == -1)) {
          param_1[0x3a] = param_1[0x3a] + 1;
          param_1[0x3c] = param_1[0x3c] + uVar9;
        }
        else {
          param_1[0x3e] = param_1[0x3e] + 1;
          param_1[0x40] = param_1[0x40] + uVar9;
        }
      }
      iVar12 = iVar12 + 1;
      *(uint *)(iVar4 + 0x14) = *(int *)(iVar4 + 0x10) + uVar9;
      FUN_000029e4(param_1 + 99);
    }
    else {
      do {
        if (((int)(uint)uVar1 >> (uVar8 & 0x1f) & 1U) != 0) {
          piVar7[0x12] = piVar7[0x12] + 1;
        }
        uVar8 = uVar8 + 1;
        piVar7 = piVar7 + 1;
      } while ((int)uVar8 < 0x10);
      param_1[0x36] = param_1[0x36] + 1;
      if ((uVar1 & 0x200) != 0) {
        param_1[0x45] = param_1[0x45] + 1;
      }
      if ((uVar1 & 0x67) != 0) {
        param_1[0x44] = param_1[0x44] + 1;
      }
      if ((uVar1 & 8) != 0) {
        param_1[0x46] = param_1[0x46] + 1;
      }
      if ((uVar1 & 0x10) != 0) {
        param_1[0x47] = param_1[0x47] + 1;
      }
LAB_000003d4:
      *(ushort *)(iVar10 + 0xf34) = uVar2 + (uVar3 + 3 & 0xfffc);
    }
    *(undefined1 *)(iVar10 + 0xf40) = 0;
    *puVar11 = 0x8000;
    param_1[6] = param_1[6] + 1;
  } while( true );
}


================================================================