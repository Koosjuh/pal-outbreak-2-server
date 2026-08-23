FUNCTION FUN_00001c50 @ 0x00001c50 size=24
CALLERS (6): FUN_00003b50@0x00003b50, FUN_0000e6e0@0x0000e6e0, FUN_0000e90c@0x0000e90c, FUN_00008ed8@0x00008ed8, FUN_0000a9c0@0x0000a9c0, FUN_0000c298@0x0000c298
CALLEES (0): 

undefined1 * FUN_00001c50(undefined1 *param_1,undefined4 param_2)

{
  *param_1 = (char)((uint)param_2 >> 8);
  param_1[1] = (char)param_2;
  return param_1 + 2;
}


================================================================