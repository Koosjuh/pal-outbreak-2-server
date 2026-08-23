FUNCTION FUN_000008a4 @ 0x000008a4 size=48
CALLERS (0): 
CALLEES (1): FUN_0000e584@0x0000e584

int FUN_000008a4(short *param_1)

{
  short sVar1;
  
  sVar1 = FUN_0000e584((int)*param_1,(int)param_1[1],param_1 + 2);
  return (int)sVar1;
}


================================================================