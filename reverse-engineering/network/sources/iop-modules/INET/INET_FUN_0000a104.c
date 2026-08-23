FUNCTION FUN_0000a104 @ 0x0000a104 size=408
CALLERS (2): FUN_00013fd4@0x00013fd4, FUN_000169bc@0x000169bc
CALLEES (2): FUN_00009eec@0x00009eec, FUN_0000a9c0@0x0000a9c0

int FUN_0000a104(int *param_1,int param_2,int param_3,uint *param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = 0;
  piVar3 = (int *)*param_1;
  for (iVar4 = param_3; (piVar3 != (int *)0x0 && (0 < iVar4)); iVar4 = iVar4 - iVar1) {
    if (((piVar3[3] & 0x20U) == 0) || (param_5 != 0)) {
      iVar1 = piVar3[5] - piVar3[4];
      if (iVar4 < iVar1) {
        iVar1 = iVar4;
      }
      if ((0 < iVar1) && (param_2 != 0)) {
        FUN_0000a9c0(piVar3[4],param_2);
        param_2 = param_2 + iVar1;
      }
      uVar5 = uVar5 | piVar3[3] & 0x20U;
      if (piVar3[5] - piVar3[4] <= iVar4) {
        uVar5 = uVar5 | piVar3[3];
      }
      iVar2 = piVar3[4] + iVar1;
      piVar3[4] = iVar2;
      if (piVar3[5] - iVar2 < 1) {
        iVar2 = *piVar3;
        *param_1 = iVar2;
        if (iVar2 == 0) {
          param_1[1] = 0;
        }
        else {
          *(undefined4 *)(*piVar3 + 4) = 0;
        }
        *piVar3 = 0;
        FUN_00009eec(piVar3);
      }
    }
    else {
      iVar1 = *piVar3;
      *param_1 = iVar1;
      if (iVar1 == 0) {
        param_1[1] = 0;
      }
      else {
        *(undefined4 *)(*piVar3 + 4) = 0;
      }
      *piVar3 = 0;
      FUN_00009eec(piVar3);
      iVar1 = 0;
    }
    piVar3 = (int *)*param_1;
  }
  if (param_4 != (uint *)0x0) {
    *param_4 = uVar5;
  }
  return param_3 - iVar4;
}


================================================================