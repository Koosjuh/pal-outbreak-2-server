FUNCTION FUN_005bf980 @ 0x005bf980  size=88
CALLERS (1): FUN_005b0950@0x005b0950
CALLEES (0): 
----------------------------------------------------------------

undefined8 FUN_005bf980(uint param_1,uint param_2,int param_3)

{
  int iVar1;
  
  for (iVar1 = 0; iVar1 < (int)(param_2 & 0xffff); iVar1 = iVar1 + 1) {
    *(undefined2 *)(param_3 + iVar1 * 2) =
         *(undefined2 *)((param_1 & 0xffff) * 0x144 + iVar1 * 2 + 0x6ce49a);
  }
  return 0;
}



================================================================