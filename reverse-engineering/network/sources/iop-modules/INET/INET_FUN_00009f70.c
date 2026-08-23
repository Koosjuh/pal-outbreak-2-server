FUNCTION FUN_00009f70 @ 0x00009f70 size=404
CALLERS (2): FUN_00013264@0x00013264, FUN_00013b50@0x00013b50
CALLEES (1): FUN_0000a9c0@0x0000a9c0

int FUN_00009f70(undefined4 *param_1,int param_2,int param_3,int param_4,uint *param_5)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  
  piVar3 = (int *)*param_1;
  uVar4 = 0;
  if (0 < param_2) {
    do {
      if ((piVar3 == (int *)0x0) || (param_2 < piVar3[5] - piVar3[4])) break;
      param_2 = param_2 - (piVar3[5] - piVar3[4]);
      piVar3 = (int *)*piVar3;
    } while (0 < param_2);
    if ((0 < param_2) && (piVar3 == (int *)0x0)) {
      return 0;
    }
  }
  iVar5 = param_4;
  if (piVar3 != (int *)0x0) {
    while (0 < iVar5) {
      iVar1 = (piVar3[5] - piVar3[4]) - param_2;
      iVar2 = iVar1;
      if (iVar5 < iVar1) {
        iVar2 = iVar5;
      }
      if ((piVar3[3] & 0x20U) == 0) {
        if ((iVar5 >= iVar1) && (*piVar3 == 0)) {
          uVar4 = uVar4 | 8;
        }
      }
      else {
        uVar4 = uVar4 | 0x20;
      }
      if ((0 < iVar2) && (param_3 != 0)) {
        FUN_0000a9c0(piVar3[4] + param_2,param_3,iVar2);
        param_3 = param_3 + iVar2;
      }
      iVar5 = iVar5 - iVar2;
      param_2 = 0;
      if ((*piVar3 != 0) && (((uVar4 ^ *(uint *)(*piVar3 + 0xc)) & 0x20) != 0)) {
        if ((uVar4 & 0x20) == 0) {
          uVar4 = uVar4 | 8;
        }
        break;
      }
      piVar3 = (int *)*piVar3;
      if (piVar3 == (int *)0x0) break;
    }
  }
  if (param_5 != (uint *)0x0) {
    *param_5 = uVar4;
  }
  return param_4 - iVar5;
}


================================================================