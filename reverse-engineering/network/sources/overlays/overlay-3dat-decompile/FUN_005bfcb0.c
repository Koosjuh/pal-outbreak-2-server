FUNCTION FUN_005bfcb0 @ 0x005bfcb0  size=52
CALLERS (3): FUN_005ada90@0x005ada90, FUN_005f7b30@0x005f7b30, FUN_005b57e0@0x005b57e0
CALLEES (0): 
----------------------------------------------------------------

undefined8 FUN_005bfcb0(uint param_1,undefined2 *param_2)

{
  *param_2 = *(undefined2 *)((param_1 & 0xffff) * 0x144 + 0x6cf142);
  return 0;
}



================================================================