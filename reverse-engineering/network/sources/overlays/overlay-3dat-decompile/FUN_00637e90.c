FUNCTION FUN_00637e90 @ 0x00637e90  size=60
CALLERS (10): FUN_00631880@0x00631880, FUN_00634280@0x00634280, FUN_00631ec0@0x00631ec0, FUN_00632390@0x00632390, FUN_006340d0@0x006340d0, FUN_00631810@0x00631810, FUN_00634010@0x00634010, FUN_006341d0@0x006341d0, FUN_00634310@0x00634310, FUN_00634160@0x00634160
CALLEES (0): 
----------------------------------------------------------------

int FUN_00637e90(short *param_1)

{
  short sVar1;
  short *psVar2;
  int iVar3;
  
  psVar2 = param_1;
  do {
    sVar1 = *psVar2;
    psVar2 = psVar2 + 1;
  } while (sVar1 != 0);
  iVar3 = (int)psVar2 - (int)param_1;
  if (iVar3 < 0) {
    iVar3 = iVar3 + 1;
  }
  return (iVar3 >> 1) + -1;
}



================================================================