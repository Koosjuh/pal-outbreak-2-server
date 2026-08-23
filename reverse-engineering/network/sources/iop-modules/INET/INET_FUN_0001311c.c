FUNCTION FUN_0001311c @ 0x0001311c size=328
CALLERS (1): FUN_00013264@0x00013264
CALLEES (1): FUN_00009e60@0x00009e60

int FUN_0001311c(int param_1,int param_2,int param_3,uint *param_4)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  
  if (param_3 == *(int *)(param_1 + 0x54)) {
    piVar5 = *(int **)(param_1 + 0x84);
    for (; 0 < param_2; param_2 = param_2 - (*piVar1 - *piVar2)) {
      if (piVar5 == (int *)0x0) {
        return 0;
      }
      piVar1 = piVar5 + 5;
      piVar2 = piVar5 + 4;
      if (param_2 < *piVar1 - *piVar2) break;
      piVar5 = (int *)*piVar5;
    }
    if (piVar5 == (int *)0x0) {
      return 0;
    }
    if (param_2 != 0) {
      return 0;
    }
    if (piVar5[5] - piVar5[4] < param_3) {
      return 0;
    }
    if (*(int *)(param_1 + 0xd8) != piVar5[3]) {
      return 0;
    }
    iVar4 = FUN_00009e60(0,0);
    if (iVar4 != 0) {
      *(int *)(iVar4 + 8) = piVar5[2];
      *(int *)(iVar4 + 0xc) = piVar5[3];
      *(int *)(iVar4 + 0x10) = piVar5[4];
      *(int *)(iVar4 + 0x14) = piVar5[5];
      uVar3 = piVar5[3] & 0x20;
      piVar5[3] = piVar5[3] | 0x1000;
      *param_4 = uVar3;
      if (param_3 < 1) {
        return iVar4;
      }
      if (*piVar5 != 0) {
        return iVar4;
      }
      *param_4 = uVar3 | 8;
      return iVar4;
    }
  }
  return 0;
}


================================================================