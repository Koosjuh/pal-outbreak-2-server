FUNCTION FUN_005c0860 @ 0x005c0860  size=52
CALLERS (5): FUN_0062edc0@0x0062edc0, FUN_00600e90@0x00600e90, FUN_005b5970@0x005b5970, FUN_005fc0c0@0x005fc0c0, FUN_0062e9b0@0x0062e9b0
CALLEES (0): 
----------------------------------------------------------------

undefined8 FUN_005c0860(uint param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)((param_1 & 0xffff) * 0x144 + 0x6cfa18);
  return 0;
}



================================================================