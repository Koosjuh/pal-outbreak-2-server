FUNCTION FUN_00005e44 @ 0x00005e44 size=260
CALLERS (1): FUN_0000eab8@0x0000eab8
CALLEES (2): FUN_00017bf4@0x00017bf4, FUN_0000a7e0@0x0000a7e0

void FUN_00005e44(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  if (((param_1 != 0) && ((*(uint *)(param_1 + 0x48) & 0x20) != 0)) &&
     (piVar3 = DAT_0001b680, DAT_0001b680 != (int *)0x0)) {
    do {
      if (param_1 == piVar3[2]) break;
      piVar3 = (int *)*piVar3;
    } while (piVar3 != (int *)0x0);
    if (piVar3 != (int *)0x0) {
      iVar2 = FUN_00017bf4(piVar3[3]);
      piVar3[3] = iVar2;
      iVar2 = FUN_00017bf4(piVar3[4]);
      piVar3[4] = iVar2;
      iVar2 = FUN_00017bf4(piVar3[5]);
      piVar3[5] = iVar2;
      iVar2 = FUN_00017bf4(piVar3[6]);
      piVar3[6] = iVar2;
      if (param_1 != 0) {
        *(undefined4 *)(param_1 + 0x70) = 0;
        *(undefined4 *)(param_1 + 0x74) = 0;
        *(undefined4 *)(param_1 + 0x7c) = 0;
        *(undefined4 *)(param_1 + 0x80) = 0;
        *(undefined4 *)(param_1 + 0x1b0) = 0;
      }
      iVar2 = piVar3[1];
      if (*piVar3 != 0) {
        *(int *)(*piVar3 + 4) = piVar3[1];
        iVar2 = DAT_0001b684;
      }
      DAT_0001b684 = iVar2;
      piVar1 = (int *)*piVar3;
      if ((int *)piVar3[1] != (int *)0x0) {
        *(int *)piVar3[1] = *piVar3;
        piVar1 = DAT_0001b680;
      }
      DAT_0001b680 = piVar1;
      FUN_0000a7e0(piVar3);
    }
  }
  return;
}


================================================================