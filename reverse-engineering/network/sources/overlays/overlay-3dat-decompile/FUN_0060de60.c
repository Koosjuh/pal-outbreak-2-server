FUNCTION FUN_0060de60 @ 0x0060de60  size=52
CALLERS (1): FUN_0060dea0@0x0060dea0
CALLEES (0): 
----------------------------------------------------------------

int FUN_0060de60(short *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (*param_1 == 0x4d42) {
    iVar1 = (int)param_1 + *(int *)(param_1 + 5);
  }
  return iVar1;
}



================================================================