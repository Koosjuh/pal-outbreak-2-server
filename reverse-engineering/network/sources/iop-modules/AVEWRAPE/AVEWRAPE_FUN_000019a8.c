FUNCTION FUN_000019a8 @ 0x000019a8 size=124
CALLERS (1): FUN_00002098@0x00002098
CALLEES (1): FUN_00002804@0x00002804

void FUN_000019a8(int param_1)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  short local_10 [4];
  
  iVar3 = 0;
  piVar2 = &DAT_000031b8;
  do {
    iVar3 = iVar3 + 1;
    if ((int)*(short *)(param_1 + 0x1c) == *piVar2) {
      *piVar2 = -1;
      break;
    }
    piVar2 = piVar2 + 1;
  } while (iVar3 < 1);
  local_10[0] = *(short *)(param_1 + 0x1c);
  sVar1 = FUN_00002804(&DAT_00004184,local_10,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================