FUNCTION FUN_000013ac @ 0x000013ac size=16
CALLERS (7): FUN_00010f40@0x00010f40, FUN_000110d0@0x000110d0, FUN_000102e4@0x000102e4, FUN_00010e10@0x00010e10, FUN_00011514@0x00011514, FUN_0001090c@0x0001090c, FUN_00010694@0x00010694
CALLEES (0): 

void FUN_000013ac(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  *(undefined1 *)(param_1 + 1) = 3;
  return;
}


================================================================