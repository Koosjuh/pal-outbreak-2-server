FUNCTION FUN_00015a28 @ 0x00015a28 size=496
CALLERS (0): 
CALLEES (9): FUN_00013f78@0x00013f78, FUN_00017ad8@0x00017ad8, FUN_0001380c@0x0001380c, FUN_00012c60@0x00012c60, FUN_00012ab0@0x00012ab0, FUN_0000d8cc@0x0000d8cc, FUN_00016d00@0x00016d00, FUN_000100c4@0x000100c4, FUN_00012e20@0x00012e20

void FUN_00015a28(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  FUN_00012ab0();
  DAT_0001b9ac = DAT_0001b9ae + 0x7d;
  DAT_0001b9ae = DAT_0001b9ac;
  for (piVar4 = (int *)DAT_0001b9b0; iVar3 = DAT_0001b9a0, piVar4 != (int *)0x0;
      piVar4 = (int *)*piVar4) {
    piVar4[8] = 0;
  }
  while (piVar4 = (int *)DAT_0001b9b0, iVar3 != 0) {
    iVar5 = *(int *)(iVar3 + 4);
    iVar2 = *(int *)(iVar3 + 0xb0) + -500;
    if ((0 < *(int *)(iVar3 + 0xb0)) && (*(int *)(iVar3 + 0xb0) = iVar2, iVar2 < 1)) {
      FUN_0001380c(iVar3);
    }
    iVar2 = *(int *)(iVar3 + 0xb4) + -500;
    if ((0 < *(int *)(iVar3 + 0xb4)) && (*(int *)(iVar3 + 0xb4) = iVar2, iVar2 < 1)) {
      FUN_00013f78(iVar3);
    }
    iVar2 = *(int *)(iVar3 + 0xb8) + -500;
    if ((*(int *)(iVar3 + 0xb8) < 1) || (*(int *)(iVar3 + 0xb8) = iVar2, 0 < iVar2)) {
      iVar2 = *(int *)(iVar3 + 0xbc) + -500;
      if ((0 < *(int *)(iVar3 + 0xbc)) && (*(int *)(iVar3 + 0xbc) = iVar2, iVar2 < 1)) {
        if (*(int *)(iVar3 + 0x30) == 0) {
          *(undefined4 *)(iVar3 + 0x30) = 0xfffffe0c;
        }
        FUN_0000d8cc(iVar3 + 0xcc);
        FUN_000100c4();
      }
      iVar2 = *(int *)(iVar3 + 0xc0) + -500;
      if (((0 < *(int *)(iVar3 + 0xc0)) && (*(int *)(iVar3 + 0xc0) = iVar2, iVar2 < 1)) &&
         (*(int *)(iVar3 + 0x28) == 3)) {
        FUN_00016d00(iVar3,0xfffffe02);
      }
      piVar4 = (int *)(iVar3 + 0xdc);
      iVar3 = iVar5;
      if (*piVar4 != 0) {
        *(undefined4 *)(*piVar4 + 0x20) = 1;
      }
    }
    else {
      FUN_00012c60(iVar3);
      iVar3 = iVar5;
    }
  }
  while (piVar1 = piVar4, piVar1 != (int *)0x0) {
    iVar3 = piVar1[7];
    piVar4 = (int *)*piVar1;
    piVar1[7] = iVar3 + -500;
    if (iVar3 + -500 < 1) {
      if (piVar1[8] == 0) {
        FUN_00012e20();
      }
      else {
        piVar1[7] = 600000;
        piVar1[6] = piVar1[5];
      }
    }
  }
  DAT_0001b9a8 = FUN_00017ad8(FUN_00015a28,0,500);
  return;
}


================================================================