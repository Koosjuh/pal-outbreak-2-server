FUNCTION FUN_005bce80 @ 0x005bce80  size=96
CALLERS (0): 
CALLEES (1): FUN_005bcce0@0x005bcce0
----------------------------------------------------------------

void FUN_005bce80(undefined8 param_1,char *param_2)

{
  int iVar1;
  
  if ((long)*param_2 == (long)(int)((uint)bRam006ff2ad + (uint)bRam006ff2ae)) {
    iVar1 = REG_RCNT1_COUNT;
    FUN_005bcce0((iVar1 * 0x1e) / 0x3840);
  }
  return;
}



================================================================