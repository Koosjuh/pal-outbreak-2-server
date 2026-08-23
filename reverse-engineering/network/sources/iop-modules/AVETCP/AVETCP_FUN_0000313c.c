FUNCTION FUN_0000313c @ 0x0000313c size=228
CALLERS (1): FUN_0000223c@0x0000223c
CALLEES (4): FUN_000010c0@0x000010c0, FUN_00003088@0x00003088, FUN_00001454@0x00001454, FUN_00011d00@0x00011d00

undefined4 FUN_0000313c(int *param_1,int param_2)

{
  short *psVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  undefined1 auStack_28 [8];
  
  psVar1 = (short *)FUN_00003088();
  sVar5 = 0;
  if (psVar1 == (short *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    iVar4 = *param_1;
    FUN_00011d00(auStack_28,*(undefined4 *)(psVar1 + 2),8);
    while (0 < iVar4) {
      iVar3 = iVar4 + -1;
      FUN_000010c0(auStack_28,param_1 + iVar4 * 3,(int)(short)param_1[iVar3 * 3 + 2]);
      FUN_00001454(auStack_28,(int)(short)param_1[iVar3 * 3 + 2]);
      sVar5 = sVar5 + (short)param_1[iVar3 * 3 + 2];
      iVar4 = iVar3;
    }
    uVar2 = 0;
    *psVar1 = sVar5;
    *(short **)(param_2 + 8) = psVar1;
    *(short **)(param_2 + 0xc) = psVar1;
  }
  return uVar2;
}


================================================================