FUNCTION FUN_00002700 @ 0x00002700 size=208
CALLERS (1): FUN_00002858@0x00002858
CALLEES (2): FUN_00003648@0x00003648, FUN_00003650@0x00003650

void FUN_00002700(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int local_c40;
  int aiStack_c3c [779];
  
  iVar5 = *param_1;
  iVar1 = FUN_00003650(iVar5);
  if (iVar1 == 0) {
    iVar2 = FUN_00003648(&local_c40,0xc30);
    iVar3 = 0;
    if (0 < iVar2) {
      piVar4 = &local_c40;
      do {
        if (*piVar4 == iVar5) break;
        iVar3 = iVar3 + 1;
        piVar4 = piVar4 + 0xc3;
      } while (iVar3 < iVar2);
    }
    DAT_0000c5b4 = 1;
    if ((aiStack_c3c[iVar3 * 0xc3 + 1] != 0) && (DAT_0000c5b4 = 3, aiStack_c3c[iVar3 * 0xc3] == 0))
    {
      DAT_0000c5b4 = 2;
    }
  }
  param_1[6] = iVar1;
  return;
}


================================================================