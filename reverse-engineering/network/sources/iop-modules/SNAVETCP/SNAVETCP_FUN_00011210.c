FUNCTION FUN_00011210 @ 0x00011210 size=120
CALLERS (1): FUN_000006fc@0x000006fc
CALLEES (0): 

undefined4 FUN_00011210(short *param_1)

{
  undefined2 local_8;
  
  if (*param_1 == 1) {
    if ((ushort)param_1[1] < 4) {
      return 0xfffffff3;
    }
    if (**(uint **)(param_1 + 2) < 2) {
      local_8 = (undefined2)**(uint **)(param_1 + 2);
      DAT_00016194 = local_8;
      return 0;
    }
  }
  return 0xfffffff3;
}


================================================================