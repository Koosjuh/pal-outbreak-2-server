FUNCTION FUN_0000f344 @ 0x0000f344 size=440
CALLERS (0): 
CALLEES (3): FUN_00004254@0x00004254, FUN_0000f60c@0x0000f60c, FUN_0000eecc@0x0000eecc

undefined4 FUN_0000f344(int param_1,int *param_2,int *param_3)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (((param_2 != (int *)0x0) && (iVar3 = *param_2, iVar3 != 0)) &&
     (*(char *)(iVar3 + 0x18) == '\0')) {
    if ((*(ushort *)(iVar3 + 0xe) & 1) != 0) {
      if (param_3 == (int *)0x0) {
        return 0;
      }
      iVar3 = FUN_00004254((int)*(short *)(iVar3 + 0x14));
      if (iVar3 != 0) {
        *param_3 = param_2[1];
        param_3[1] = *(int *)(iVar3 + 4);
        *(undefined2 *)((int)param_3 + 10) = *(undefined2 *)(iVar3 + 2);
        *(undefined2 *)(param_3 + 2) = *(undefined2 *)(*param_2 + 0x14);
        return 0;
      }
      return 0xffffffff;
    }
    FUN_0000eecc(param_2);
  }
  sVar1 = FUN_0000f60c(param_1);
  iVar3 = (int)sVar1;
  if (iVar3 == -1) {
    return 0xffffffff;
  }
  iVar2 = FUN_00004254((int)*(short *)(&DAT_00018404 + iVar3 * 7));
  if (iVar2 != 0) {
    iVar4 = (&DAT_000183f8)[iVar3 * 7];
    if (*(int *)(iVar2 + 4) == (&DAT_000183f8)[iVar3 * 7]) {
      iVar4 = param_1;
    }
    if (param_2 != (int *)0x0) {
      *param_2 = (int)(&DAT_000183f0 + iVar3 * 7);
      (&DAT_00018400)[iVar3 * 7] = (&DAT_00018400)[iVar3 * 7] + 1;
      param_2[1] = iVar4;
    }
    if (param_3 != (int *)0x0) {
      *param_3 = iVar4;
      param_3[1] = *(int *)(iVar2 + 4);
      *(undefined2 *)((int)param_3 + 10) = *(undefined2 *)(iVar2 + 2);
      *(undefined2 *)(param_3 + 2) = *(undefined2 *)(&DAT_00018404 + iVar3 * 7);
      return 0;
    }
    return 0;
  }
  return 0xffffffff;
}


================================================================