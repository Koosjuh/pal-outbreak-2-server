FUNCTION FUN_0062fe20 @ 0x0062fe20  size=80
CALLERS (1): FUN_005b1e80@0x005b1e80
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_0062fe20(int param_1,long param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = *(int *)(&DAT_0068ace0 + (uint)bRam0034359d * 4);
  }
  else {
    iVar1 = *(int *)(&DAT_0068ad00 + (uint)bRam0034359d * 4);
  }
  return *(undefined4 *)(iVar1 + param_1 * 4);
}



================================================================