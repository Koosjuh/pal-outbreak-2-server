FUNCTION FUN_00017bf4 @ 0x00017bf4 size=284
CALLERS (17): FUN_00004670@0x00004670, FUN_00014380@0x00014380, FUN_00000000@0x00000000, FUN_00013264@0x00013264, FUN_0000d658@0x0000d658, FUN_000078f0@0x000078f0, FUN_00007abc@0x00007abc, FUN_00012c60@0x00012c60, FUN_00012bc0@0x00012bc0, FUN_000045a4@0x000045a4, FUN_00005e44@0x00005e44, FUN_000049e0@0x000049e0, FUN_000043a8@0x000043a8, FUN_0000ec64@0x0000ec64, FUN_00004b68@0x00004b68, FUN_00000344@0x00000344, FUN_00017e68@0x00017e68
CALLEES (1): FUN_0000d8cc@0x0000d8cc

undefined4 FUN_00017bf4(int *param_1)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  piVar1 = DAT_0001e428;
  if (param_1 != (int *)0x0) {
    for (; piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
      if (param_1 == piVar1) {
        iVar6 = param_1[1];
        if (*param_1 != 0) {
          *(int *)(*param_1 + 4) = param_1[1];
          iVar6 = DAT_0001e42c;
        }
        DAT_0001e42c = iVar6;
        piVar1 = (int *)*param_1;
        if ((undefined4 *)param_1[1] != (undefined4 *)0x0) {
          *(undefined4 *)param_1[1] = (int *)*param_1;
          piVar1 = DAT_0001e428;
        }
        DAT_0001e428 = piVar1;
        *param_1 = (int)DAT_0001e424;
        DAT_0001e424 = param_1;
        return 0;
      }
    }
    iVar5 = *param_1;
    iVar6 = param_1[1];
    if (iVar5 != 0) {
      uVar3 = param_1[2];
      iVar4 = param_1[3];
      uVar2 = *(int *)(iVar5 + 8) + uVar3;
      *(uint *)(iVar5 + 8) = uVar2;
      *(uint *)(iVar5 + 0xc) = *(int *)(iVar5 + 0xc) + iVar4 + (uint)(uVar2 < uVar3);
      *(int *)(*param_1 + 4) = iVar6;
      iVar6 = DAT_0001e420;
    }
    DAT_0001e420 = iVar6;
    iVar6 = *param_1;
    if ((int *)param_1[1] != (int *)0x0) {
      *(int *)param_1[1] = *param_1;
      iVar6 = DAT_0001e41c;
    }
    DAT_0001e41c = iVar6;
    *param_1 = (int)DAT_0001e424;
    DAT_0001e424 = param_1;
    FUN_0000d8cc(&DAT_0001e410);
  }
  return 0;
}


================================================================