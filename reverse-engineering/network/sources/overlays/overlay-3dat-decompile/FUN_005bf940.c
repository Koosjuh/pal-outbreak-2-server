FUNCTION FUN_005bf940 @ 0x005bf940  size=52
CALLERS (2): FUN_005ad890@0x005ad890, FUN_005b57a0@0x005b57a0
CALLEES (0): 
----------------------------------------------------------------

undefined8 FUN_005bf940(uint param_1,undefined2 *param_2)

{
  *param_2 = *(undefined2 *)((param_1 & 0xffff) * 0x144 + 0x6ce49a);
  return 0;
}



================================================================