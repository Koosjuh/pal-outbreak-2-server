FUNCTION FUN_00001c20 @ 0x00001c20 size=48
CALLERS (3): FUN_00009044@0x00009044, FUN_0000a9c0@0x0000a9c0, FUN_0000c298@0x0000c298
CALLEES (0): 

undefined1 * FUN_00001c20(undefined1 *param_1,undefined4 param_2)

{
  *param_1 = (char)((uint)param_2 >> 0x18);
  param_1[1] = (char)((uint)param_2 >> 0x10);
  param_1[2] = (char)((uint)param_2 >> 8);
  param_1[3] = (char)param_2;
  return param_1 + 4;
}


================================================================