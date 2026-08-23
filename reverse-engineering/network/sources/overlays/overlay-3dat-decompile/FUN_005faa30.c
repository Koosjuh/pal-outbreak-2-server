FUNCTION FUN_005faa30 @ 0x005faa30  size=48
CALLERS (1): FUN_005fa990@0x005fa990
CALLEES (0): 
----------------------------------------------------------------

int FUN_005faa30(int param_1,long param_2)

{
  int iVar1;
  
  if (param_2 < 0) {
    iVar1 = *(short *)(param_1 + 10) + -1;
  }
  else {
    iVar1 = (int)param_2 % (int)*(short *)(param_1 + 10);
  }
  return iVar1;
}



================================================================