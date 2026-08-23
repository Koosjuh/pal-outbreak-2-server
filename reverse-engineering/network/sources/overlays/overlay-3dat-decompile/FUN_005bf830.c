FUNCTION FUN_005bf830 @ 0x005bf830  size=272
CALLERS (0): 
CALLEES (2): FUN_005c7d00@0x005c7d00, FUN_005bf1e0@0x005bf1e0
----------------------------------------------------------------

void FUN_005bf830(char *param_1,int param_2)

{
  short *psVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  FUN_005c7d00();
  uVar3 = FUN_005bf1e0(0);
  if (*param_1 == '\0') {
    iVar2 = *(int *)(param_2 + 8);
    param_2 = param_2 + 0xc;
    iVar4 = ((uVar3 & 0xffff) - 1) * 0x144;
    for (iVar5 = 0; iVar5 < iVar2; iVar5 = iVar5 + 1) {
      *(int *)(iRam006cbc1c * 4 + 0x7006b0) =
           *(int *)(iRam006cbc1c * 4 + 0x7006b0) + *(int *)(param_2 + 0x14);
      psVar1 = (short *)(param_2 + 0x14);
      param_2 = param_2 + 0x28;
      *(short *)(iVar4 + 0x6ce5e0) = *(short *)(iVar4 + 0x6ce5e0) + *psVar1;
    }
    if ((param_1[1] != '\x01') || (*(short *)(param_1 + 2) == 0)) {
      uRam006cbc35 = 1;
    }
  }
  else if (*param_1 == '\'') {
    uRam006cbc35 = 2;
  }
  return;
}



================================================================