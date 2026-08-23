FUNCTION FUN_00637e60 @ 0x00637e60  size=40
CALLERS (4): FUN_00633930@0x00633930, FUN_00633650@0x00633650, FUN_00633590@0x00633590, FUN_00633ab0@0x00633ab0
CALLEES (0): 
----------------------------------------------------------------

short * FUN_00637e60(short *param_1,short *param_2)

{
  short sVar1;
  short *psVar2;
  
  psVar2 = param_1;
  do {
    sVar1 = *param_2;
    *psVar2 = sVar1;
    param_2 = param_2 + 1;
    psVar2 = psVar2 + 1;
  } while (sVar1 != 0);
  return param_1;
}



================================================================