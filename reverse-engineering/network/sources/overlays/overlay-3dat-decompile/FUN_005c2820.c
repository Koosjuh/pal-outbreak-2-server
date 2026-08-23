FUNCTION FUN_005c2820 @ 0x005c2820  size=104
CALLERS (3): FUN_0062e8e0@0x0062e8e0, FUN_005fe8d0@0x005fe8d0, FUN_005fe500@0x005fe500
CALLEES (1): FUN_005bf230@0x005bf230
----------------------------------------------------------------

undefined8 FUN_005c2820(ushort param_1,undefined8 param_2)

{
  *(undefined2 *)((uint)param_1 * 0x144 + 0x6cfa2c) = 0;
  *(undefined2 *)((uint)param_1 * 0x144 + 0x6cfa2e) = 0;
  uRam006cbc84 = 0;
  uRam006d2158 = param_1;
  FUN_005bf230(param_2);
  return 0;
}



================================================================