FUNCTION FUN_00010ce4 @ 0x00010ce4 size=72
CALLERS (1): FUN_000003e8@0x000003e8
CALLEES (1): FUN_0000d058@0x0000d058

int FUN_00010ce4(short *param_1)

{
  short sVar1;
  int iVar2;
  
  sVar1 = FUN_0000d058((int)*param_1,(int)param_1[1],*(undefined4 *)(param_1 + 4),(int)param_1[2]);
  iVar2 = (int)sVar1;
  if (-1 < iVar2) {
    iVar2 = 0;
  }
  return iVar2;
}


================================================================