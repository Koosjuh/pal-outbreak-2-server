FUNCTION FUN_0000c298 @ 0x0000c298 size=536
CALLERS (2): FUN_0000c4b0@0x0000c4b0, FUN_0000cc4c@0x0000cc4c
CALLEES (4): FUN_00001c50@0x00001c50, FUN_00001c20@0x00001c20, FUN_0000075c@0x0000075c, FUN_000006b0@0x000006b0

void FUN_0000c298(int *param_1,int param_2,undefined1 param_3,byte param_4,undefined4 param_5)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  undefined1 uVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  byte *pbVar7;
  int iVar8;
  
  uVar2 = (uint)param_4;
  iVar8 = uVar2 - 2;
  if (*param_1 == 0) {
    iVar3 = FUN_000006b0(1);
    *param_1 = iVar3;
    if (iVar3 == 0) {
      return;
    }
  }
  param_1 = (int *)*param_1;
  puVar6 = (undefined1 *)(*param_1 + (uint)*(ushort *)(param_1 + 1));
  *puVar6 = param_3;
  pbVar7 = puVar6 + 1;
  *pbVar7 = param_4;
  puVar6 = puVar6 + 2;
  switch(param_3) {
  case 1:
    iVar8 = uVar2 - 4;
    puVar6 = (undefined1 *)FUN_00001c50(puVar6,*(undefined2 *)(param_2 + 2));
    break;
  case 2:
    uVar5 = *(undefined4 *)(param_2 + 4);
    goto LAB_0000c404;
  case 3:
    iVar8 = uVar2 - 4;
    puVar6 = (undefined1 *)FUN_00001c50(puVar6,*(undefined2 *)(param_2 + 8));
    sVar1 = *(short *)(param_2 + 8);
    if (sVar1 == -0x3ddd) {
      *pbVar7 = 5;
      *puVar6 = *(undefined1 *)(param_2 + 0x14);
      puVar6 = puVar6 + 1;
      if (param_4 == 4) {
        param_4 = 5;
      }
      iVar8 = 0;
      sVar1 = *(short *)(param_2 + 8);
    }
    if (sVar1 != -0x3fdd) goto LAB_0000c414;
    *pbVar7 = 4;
    if (param_4 == 5) {
      param_4 = 4;
    }
    iVar8 = 0;
    break;
  case 5:
    uVar5 = *(undefined4 *)(param_2 + 0xc);
LAB_0000c404:
    iVar8 = uVar2 - 6;
    puVar6 = (undefined1 *)FUN_00001c20(puVar6,uVar5);
  }
LAB_0000c414:
  iVar3 = iVar8 << 0x10;
  while (0 < iVar3) {
    iVar8 = iVar8 + -1;
    sVar1 = FUN_0000075c(param_5,&DAT_00013674,1);
    uVar4 = 0xff;
    if (sVar1 == 1) {
      uVar4 = DAT_00013674;
    }
    *puVar6 = uVar4;
    puVar6 = puVar6 + 1;
    iVar3 = iVar8 * 0x10000;
  }
  *(ushort *)(param_1 + 1) = (short)param_1[1] + (ushort)param_4;
  return;
}


================================================================