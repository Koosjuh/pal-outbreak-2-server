FUNCTION FUN_000024f0 @ 0x000024f0 size=128
CALLERS (1): FUN_00002858@0x00002858
CALLEES (1): FUN_00003614@0x00003614

void FUN_000024f0(int param_1)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  short local_10 [4];
  
  iVar3 = 0;
  piVar2 = &DAT_00009508;
  do {
    iVar3 = iVar3 + 1;
    if ((int)*(short *)(param_1 + 0x1c) == *piVar2) {
      *piVar2 = -1;
      break;
    }
    piVar2 = piVar2 + 1;
  } while (iVar3 < 4);
  local_10[0] = *(short *)(param_1 + 0x1c);
  sVar1 = FUN_00003614(&DAT_00004184,local_10,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================