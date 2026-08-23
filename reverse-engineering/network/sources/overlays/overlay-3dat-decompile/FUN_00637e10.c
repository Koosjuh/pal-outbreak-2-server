FUNCTION FUN_00637e10 @ 0x00637e10  size=72
CALLERS (4): FUN_00631ec0@0x00631ec0, FUN_00631f80@0x00631f80, FUN_00635cb0@0x00635cb0, FUN_006320f0@0x006320f0
CALLEES (0): 
----------------------------------------------------------------

short * FUN_00637e10(short *param_1,short *param_2)

{
  short sVar1;
  short *psVar2;
  
  for (psVar2 = param_1; *psVar2 != 0; psVar2 = psVar2 + 1) {
  }
  do {
    sVar1 = *param_2;
    *psVar2 = sVar1;
    psVar2 = psVar2 + 1;
    param_2 = param_2 + 1;
  } while (sVar1 != 0);
  return param_1;
}



================================================================