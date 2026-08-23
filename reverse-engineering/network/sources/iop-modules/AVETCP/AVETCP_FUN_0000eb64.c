FUNCTION FUN_0000eb64 @ 0x0000eb64 size=192
CALLERS (1): FUN_0000ea28@0x0000ea28
CALLEES (2): FUN_0000139c@0x0000139c, FUN_000010c0@0x000010c0

int FUN_0000eb64(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined1 auStack_28 [8];
  
  if (*param_2 == 0) {
    iVar3 = 0;
  }
  else {
    iVar5 = *param_2 + -1;
    iVar3 = 0;
    if (-1 < iVar5) {
      piVar4 = param_2 + iVar5 * 3;
      iVar6 = iVar5 * 0xc + 8;
      do {
        FUN_0000139c(auStack_28,param_1);
        iVar2 = iVar6 + 4;
        iVar6 = iVar6 + -0xc;
        iVar5 = iVar5 + -1;
        FUN_000010c0(auStack_28,(int)param_2 + iVar2,(int)(short)piVar4[2]);
        piVar1 = piVar4 + 2;
        piVar4 = piVar4 + -3;
        param_1 = param_1 + (short)*piVar1;
        iVar3 = iVar3 + (short)*piVar1;
      } while (-1 < iVar5);
    }
  }
  return iVar3;
}


================================================================