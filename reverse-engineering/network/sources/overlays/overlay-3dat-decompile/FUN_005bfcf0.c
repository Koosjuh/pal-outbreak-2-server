FUNCTION FUN_005bfcf0 @ 0x005bfcf0  size=52
CALLERS (2): FUN_005ada90@0x005ada90, FUN_005f7b30@0x005f7b30
CALLEES (0): 
----------------------------------------------------------------

undefined8 FUN_005bfcf0(uint param_1,undefined1 *param_2)

{
  *param_2 = *(undefined1 *)((param_1 & 0xffff) * 0x144 + 0x6cf154);
  return 0;
}



================================================================