FUNCTION FUN_00637da0 @ 0x00637da0  size=112
CALLERS (5): FUN_00635ab0@0x00635ab0, FUN_00630c90@0x00630c90, FUN_006345e0@0x006345e0, FUN_00634ab0@0x00634ab0, FUN_006378b0@0x006378b0
CALLEES (0): 
----------------------------------------------------------------

void FUN_00637da0(char *param_1,int param_2)

{
  long lVar1;
  int iVar2;
  int iVar3;
  char *pcStack_4;
  
  iVar3 = 0;
  pcStack_4 = param_1;
  while (*pcStack_4 != '\0') {
    lVar1 = func_0x001af320(&pcStack_4);
    if (lVar1 < 0) break;
    iVar2 = iVar3 * 2;
    iVar3 = iVar3 + 1;
    *(short *)(param_2 + iVar2) = (short)lVar1;
  }
  *(undefined2 *)(param_2 + iVar3 * 2) = 0;
  return;
}



================================================================