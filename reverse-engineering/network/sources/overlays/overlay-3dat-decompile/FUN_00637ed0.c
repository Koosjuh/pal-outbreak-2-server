FUNCTION FUN_00637ed0 @ 0x00637ed0  size=104
CALLERS (3): FUN_00631ff0@0x00631ff0, FUN_00632390@0x00632390, FUN_006320f0@0x006320f0
CALLEES (0): 
----------------------------------------------------------------

short * FUN_00637ed0(short *param_1,short *param_2,int param_3)

{
  short sVar1;
  short *psVar2;
  short *psVar3;
  
  psVar2 = param_1;
  for (; psVar3 = psVar2, param_3 != 0; param_3 = param_3 + -1) {
    psVar3 = psVar2 + 1;
    sVar1 = *param_2;
    *psVar2 = sVar1;
    if (sVar1 == 0) break;
    param_2 = param_2 + 1;
    psVar2 = psVar3;
  }
  if (param_3 != 0) {
    while (param_3 = param_3 + -1, param_3 != 0) {
      *psVar3 = 0;
      psVar3 = psVar3 + 1;
    }
  }
  return param_1;
}



================================================================