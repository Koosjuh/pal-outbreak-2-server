FUNCTION FUN_005c13e0 @ 0x005c13e0  size=180
CALLERS (0): 
CALLEES (1): FUN_005c7d00@0x005c7d00
----------------------------------------------------------------

void FUN_005c13e0(char *param_1,int param_2)

{
  short *psVar1;
  int iVar2;
  int iVar3;
  
  FUN_005c7d00();
  if (*param_1 == '\0') {
    iVar3 = param_2 + 0xc;
    for (iVar2 = 0; iVar2 < *(int *)(param_2 + 8); iVar2 = iVar2 + 1) {
      psVar1 = (short *)(iVar3 + 0x14);
      iVar3 = iVar3 + 0x28;
      sRam006cf286 = sRam006cf286 + *psVar1;
    }
    if ((param_1[1] != '\x01') || (*(short *)(param_1 + 2) == 0)) {
      uRam006cba05 = 1;
    }
  }
  else if (*param_1 == '\'') {
    uRam006cba05 = 2;
  }
  return;
}



================================================================