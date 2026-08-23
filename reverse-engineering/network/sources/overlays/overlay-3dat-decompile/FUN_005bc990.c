FUNCTION FUN_005bc990 @ 0x005bc990  size=248
CALLERS (0): 
CALLEES (5): FUN_005bdc70@0x005bdc70, FUN_005c7f20@0x005c7f20, FUN_005c5060@0x005c5060, FUN_005c7e30@0x005c7e30, FUN_005bdf90@0x005bdf90
----------------------------------------------------------------

void FUN_005bc990(char *param_1,int param_2)

{
  short *psVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  undefined1 auStack_40 [64];
  
  if (*param_1 == '\0') {
    iVar5 = param_2 + 0xc;
    for (iVar4 = 0; uVar2 = uRam0086f7f8, iVar4 < *(int *)(param_2 + 8); iVar4 = iVar4 + 1) {
      psVar1 = (short *)(iVar5 + 0x10);
      iVar5 = iVar5 + 0x24;
      uRam0086f7f8 = uRam0086f7f8 + *psVar1;
    }
    uVar3 = FUN_005c5060(uRam0086f800);
    if (uVar2 < uVar3) {
      FUN_005bdc70();
    }
    else {
      FUN_005c7e30(0xd);
      FUN_005bdf90(8,0);
    }
  }
  else if (*param_1 == '\'') {
    FUN_005c7e30(10);
    FUN_005c7f20(0xe);
    func_0x00109728(auStack_40,0x639e68,0x348);
    func_0x00109ab0(0x6fc5e8,auStack_40);
    FUN_005bdf90(2,0);
  }
  return;
}



================================================================