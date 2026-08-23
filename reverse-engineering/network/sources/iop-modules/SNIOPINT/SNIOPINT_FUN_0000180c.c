FUNCTION FUN_0000180c @ 0x0000180c size=168
CALLERS (1): FUN_00002858@0x00002858
CALLEES (1): FUN_00003614@0x00003614

void FUN_0000180c(int param_1)

{
  int iVar1;
  short sVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined2 local_10 [2];
  undefined4 *local_c;
  
  local_10[0] = 0x40;
  local_c = &DAT_00004af0;
  sVar2 = FUN_00003614(&DAT_00004132,local_10,0);
  iVar4 = 0;
  puVar3 = (undefined4 *)(param_1 + 0x1c);
  if (0 < sVar2) {
    do {
      *puVar3 = (&DAT_00004af0)[iVar4 * 4];
      iVar1 = iVar4 * 4;
      iVar4 = iVar4 + 1;
      puVar3[1] = (&DAT_00004af4)[iVar1];
      puVar3 = puVar3 + 2;
    } while (iVar4 < sVar2);
  }
  *(int *)(param_1 + 0x18) = (int)sVar2;
  return;
}


================================================================