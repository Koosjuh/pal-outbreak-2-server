FUNCTION FUN_00010c8c @ 0x00010c8c size=48
CALLERS (1): FUN_000005dc@0x000005dc
CALLEES (1): FUN_0000decc@0x0000decc

int FUN_00010c8c(short *param_1)

{
  short sVar1;
  
  sVar1 = FUN_0000decc((int)*param_1,param_1[1]);
  return (int)sVar1;
}


================================================================