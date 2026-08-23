FUNCTION FUN_005ba800 @ 0x005ba800  size=196
CALLERS (1): FUN_005ba8d0@0x005ba8d0
CALLEES (0): 
----------------------------------------------------------------

void FUN_005ba800(uint param_1,uint *param_2,int *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (param_1 < 0xa4cb62) {
    iVar1 = 0x1e;
    if (cRam0034363e == '\x01') {
      iVar1 = 0x19;
    }
    uVar3 = (int)param_1 / (iVar1 * 0xe10);
    iVar2 = uVar3 * iVar1 * 0xe10;
    if (99 < uVar3) {
      uVar3 = 99;
    }
    iVar2 = (int)(param_1 - iVar2) / (iVar1 * 0x3c);
    iVar1 = ((int)param_1 / iVar1) % 0x3c;
  }
  else {
    iVar2 = 0x3b;
    uVar3 = 99;
    iVar1 = 0x3b;
  }
  *param_2 = uVar3;
  *param_3 = iVar2;
  *param_4 = iVar1;
  return;
}



================================================================