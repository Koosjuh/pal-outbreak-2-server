FUNCTION FUN_005c01d0 @ 0x005c01d0  size=52
CALLERS (6): FUN_005b58a0@0x005b58a0, FUN_0062edc0@0x0062edc0, FUN_0062f2b0@0x0062f2b0, FUN_00600f50@0x00600f50, FUN_005fc0c0@0x005fc0c0, FUN_0062e9b0@0x0062e9b0
CALLEES (0): 
----------------------------------------------------------------

undefined8 FUN_005c01d0(uint param_1,undefined2 *param_2)

{
  *param_2 = *(undefined2 *)((param_1 & 0xffff) * 0x144 + 0x6cfa1e);
  return 0;
}



================================================================