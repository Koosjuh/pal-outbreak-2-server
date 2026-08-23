
undefined4 FUN_001ce360(int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  
  piVar6 = *(int **)(param_1 + 0x808);
  if (((piVar6 != (int *)0x0) && (uVar4 = (uint)*(ushort *)(param_1 + 0x812), uVar4 != 0)) &&
     (*(int **)(param_2 + 0x808) != (int *)0x0)) {
    iVar3 = 0;
    if (*(ushort *)(param_2 + 0x812) != 0) {
      bVar1 = uVar4 != 0;
      while (bVar1) {
        if (*piVar6 != 0) {
          piVar5 = *(int **)(param_2 + 0x808);
          for (iVar2 = 0; iVar2 < (int)(uint)*(ushort *)(param_2 + 0x812); iVar2 = iVar2 + 1) {
            if ((*piVar5 != 0) && (*piVar6 == *piVar5)) {
              return 1;
            }
            piVar5 = piVar5 + 0x26;
          }
        }
        iVar3 = iVar3 + 1;
        piVar6 = piVar6 + 0x26;
        bVar1 = iVar3 < (int)uVar4;
      }
    }
  }
  return 0;
}

