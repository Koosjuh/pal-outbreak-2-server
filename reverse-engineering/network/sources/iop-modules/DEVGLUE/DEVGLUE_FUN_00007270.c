FUNCTION FUN_00007270 @ 0x00007270 size=104
CALLERS (3): FUN_000072d8@0x000072d8, FUN_00007394@0x00007394, FUN_0000746c@0x0000746c
CALLEES (1): FUN_00008044@0x00008044

undefined4 FUN_00007270(int *param_1)

{
  undefined2 local_10;
  undefined2 local_e [3];
  
  local_10 = 0;
  FUN_00008044(*param_1,&local_10,2);
  *param_1 = *param_1 + 2;
  local_e[0] = 0;
  FUN_00008044(*param_1,local_e,2);
  *param_1 = *param_1 + 2;
  return 4;
}


================================================================