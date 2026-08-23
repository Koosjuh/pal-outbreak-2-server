FUNCTION FUN_0000db2c @ 0x0000db2c size=460
CALLERS (1): FUN_0000dcf8@0x0000dcf8
CALLEES (5): FUN_000060a8@0x000060a8, FUN_0000a494@0x0000a494, FUN_00006200@0x00006200, FUN_00009eec@0x00009eec, FUN_00007e28@0x00007e28

void FUN_0000db2c(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  
  iVar4 = FUN_0000a494(param_2);
  if (iVar4 == 0) {
    return;
  }
  pbVar5 = *(byte **)(iVar4 + 0x10);
  *(uint *)(pbVar5 + 0xc) =
       param_3 << 0x18 | (param_3 & 0xff00) << 8 | param_3 >> 8 & 0xff00 | param_3 >> 0x18;
  bVar1 = *pbVar5;
  *(uint *)(pbVar5 + 0x10) =
       param_4 << 0x18 | (param_4 & 0xff00) << 8 | param_4 >> 8 & 0xff00 | param_4 >> 0x18;
  pbVar5[10] = 0;
  pbVar5[0xb] = 0;
  iVar6 = (bVar1 & 0xf) * 4;
  uVar3 = FUN_000060a8(0,pbVar5,iVar6);
  bVar2 = pbVar5[9];
  *(ushort *)(pbVar5 + 10) = ~uVar3;
  if (bVar2 == 6) {
    if ((uint)(*(int *)(iVar4 + 0x14) - *(int *)(iVar4 + 0x10)) < iVar6 + 0x14U) goto LAB_0000dccc;
    iVar6 = *(int *)(iVar4 + 0x10) + iVar6;
    *(int *)(iVar4 + 0x10) = iVar6;
    *(undefined2 *)(iVar6 + 0x10) = 0;
    uVar3 = FUN_00006200(6,param_3,param_4,iVar4);
    *(ushort *)(iVar6 + 0x10) = ~uVar3;
LAB_0000dca8:
    *(uint *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x10) + (bVar1 & 0xf) * -4;
  }
  else {
    if (6 < bVar2) {
      if ((bVar2 != 0x11) || ((uint)(*(int *)(iVar4 + 0x14) - *(int *)(iVar4 + 0x10)) < iVar6 + 8U))
      goto LAB_0000dccc;
      iVar6 = *(int *)(iVar4 + 0x10) + iVar6;
      *(int *)(iVar4 + 0x10) = iVar6;
      *(undefined2 *)(iVar6 + 6) = 0;
      uVar3 = FUN_00006200(0x11,param_3,param_4,iVar4);
      *(ushort *)(iVar6 + 6) = ~uVar3;
      goto LAB_0000dca8;
    }
    if (bVar2 != 1) goto LAB_0000dccc;
  }
  iVar4 = FUN_00007e28(param_1,iVar4,0);
LAB_0000dccc:
  FUN_00009eec(iVar4);
  return;
}


================================================================