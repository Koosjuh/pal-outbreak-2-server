FUNCTION FUN_005c09c0 @ 0x005c09c0  size=52
CALLERS (4): FUN_005b5930@0x005b5930, FUN_0062edc0@0x0062edc0, FUN_005fc0c0@0x005fc0c0, FUN_0062e9b0@0x0062e9b0
CALLEES (0): 
----------------------------------------------------------------

undefined8 FUN_005c09c0(uint param_1,undefined1 *param_2)

{
  *param_2 = *(undefined1 *)((param_1 & 0xffff) * 0x144 + 0x6cfa31);
  return 0;
}



================================================================