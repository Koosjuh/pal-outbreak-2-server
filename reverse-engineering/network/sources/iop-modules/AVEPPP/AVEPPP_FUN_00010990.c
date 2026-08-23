FUNCTION FUN_00010990 @ 0x00010990 size=52
CALLERS (0): 
CALLEES (1): FUN_00003a4c@0x00003a4c

int FUN_00010990(short *param_1)

{
  short sVar1;
  
  sVar1 = FUN_00003a4c((int)*param_1,(int)param_1[1],*(undefined4 *)(param_1 + 2));
  return (int)sVar1;
}


================================================================