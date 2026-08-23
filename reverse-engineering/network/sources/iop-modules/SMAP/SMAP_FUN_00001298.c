FUNCTION FUN_00001298 @ 0x00001298 size=784
CALLERS (0): 
CALLEES (13): FUN_00000584@0x00000584, FUN_00002a40@0x00002a40, FUN_00000750@0x00000750, FUN_00002a38@0x00002a38, FUN_000011c4@0x000011c4, FUN_00002b48@0x00002b48, FUN_00000254@0x00000254, FUN_000029f4@0x000029f4, FUN_00002b40@0x00002b40, FUN_00002b58@0x00002b58, FUN_00002b8c@0x00002b8c, FUN_00002b9c@0x00002b9c, FUN_00000998@0x00000998

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00001298(int *param_1)

{
  ushort uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int unaff_gp;
  uint local_30 [2];
  
  iVar4 = 3;
  iVar5 = *param_1;
  puVar3 = (undefined4 *)param_1[1];
  param_1[2] = 0x1000;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
LAB_000012f4:
  while( true ) {
    iVar2 = FUN_00002b9c(param_1[8],0x1f,0x11,local_30);
    if (iVar2 != 0) {
      FUN_000029f4("smap: WaitEventFlag -> %d\n",iVar2);
      return;
    }
    if (((local_30[0] & 2) != 0) && (param_1[0xb] != 0)) {
      FUN_00002a40(0x68);
      *puVar3 = 0;
      param_1[0xc] = 0;
      param_1[0xb] = 0;
      param_1[10] = 0;
    }
    if ((local_30[0] & 1) == 0) goto LAB_00001408;
    if (param_1[0xb] != 0) break;
    param_1[10] = 1;
    FUN_00002a38(0x68);
    iVar2 = FUN_00000998(param_1);
    if (iVar2 != 0) {
      return;
    }
    if (param_1[0xc] == 0) {
      *puVar3 = 0x1800;
      FUN_00002b40(10000);
      param_1[0xb] = 1;
      param_1[10] = 0;
      FUN_00002b8c(param_1[0x62],1);
      if (param_1[0xd] == 0) {
        FUN_00002b58(1000000,param_1 + 0x10);
        FUN_00002b48(param_1 + 0x10,FUN_00001210,param_1);
        param_1[0xd] = 1;
      }
      goto LAB_00001408;
    }
    param_1[0xc] = 0;
    param_1[10] = 0;
  }
  goto LAB_00001418;
LAB_00001408:
  if (param_1[0xb] != 0) {
LAB_00001418:
    uVar1 = _DAT_b0000028;
    iVar2 = 0;
    if (((local_30[0] & 4) != 0) && ((_DAT_b0000028 & 0x6c) != 0)) {
      *(int *)(unaff_gp + -0x7f50) = *(int *)(unaff_gp + -0x7f50) + 1;
      if ((uVar1 & 0x40) != 0) {
        *(undefined2 *)(iVar5 + 0x28) = 0x40;
        puVar3[5] = 0x1c00000;
      }
      if ((uVar1 & 0x20) != 0) {
        *(undefined2 *)(iVar5 + 0x28) = 0x20;
        iVar2 = FUN_00000254(param_1);
      }
      if ((uVar1 & 8) != 0) {
        *(undefined2 *)(iVar5 + 0x28) = 8;
        param_1[0x45] = param_1[0x45] + 1;
      }
      if ((uVar1 & 4) != 0) {
        FUN_00000584(param_1);
        local_30[0] = local_30[0] | 8;
      }
    }
    if ((local_30[0] & 8) != 0) {
      FUN_00000750(param_1);
    }
    FUN_00000584(param_1);
    FUN_00002a38(0x68);
    if (0 < param_1[3]) {
      puVar3[2] = 0x8000;
      FUN_00002a38(4);
    }
    if (iVar2 == 0) {
      if (((local_30[0] & 0x10) != 0) && (iVar4 = iVar4 + -1, iVar4 < 1)) {
        FUN_000011c4(param_1);
      }
    }
    else {
      iVar4 = 3;
    }
  }
  goto LAB_000012f4;
}


================================================================