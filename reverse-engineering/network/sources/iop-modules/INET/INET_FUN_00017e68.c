FUNCTION FUN_00017e68 @ 0x00017e68 size=200
CALLERS (2): FUN_0001866c@0x0001866c, FUN_00018db0@0x00018db0
CALLEES (5): FUN_00017bf4@0x00017bf4, FUN_0000a7e0@0x0000a7e0, FUN_0000d508@0x0000d508, FUN_00008cfc@0x00008cfc, FUN_00009eec@0x00009eec

void FUN_00017e68(undefined4 *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  FUN_0000d508(param_1 + 0xd,0);
  uVar2 = FUN_00017bf4(param_1[0xc]);
  param_1[0xc] = uVar2;
  piVar1 = (int *)param_1[10];
  while (piVar1 != (int *)0x0) {
    iVar3 = *piVar1;
    FUN_00009eec(piVar1[5]);
    FUN_0000a7e0(piVar1);
    piVar1 = (int *)iVar3;
  }
  uVar2 = param_1[2];
  if (param_1[1] != 0) {
    *(undefined4 *)(param_1[1] + 8) = param_1[2];
    uVar2 = DAT_0001b9bc;
  }
  DAT_0001b9bc = uVar2;
  uVar2 = param_1[1];
  if (param_1[2] != 0) {
    *(undefined4 *)(param_1[2] + 4) = param_1[1];
    uVar2 = DAT_0001b9b8;
  }
  DAT_0001b9b8 = uVar2;
  *param_1 = 0;
  FUN_00008cfc(param_1 + 0xf);
  FUN_0000a7e0(param_1);
  return;
}


================================================================