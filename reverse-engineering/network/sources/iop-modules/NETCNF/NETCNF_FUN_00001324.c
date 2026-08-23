FUNCTION FUN_00001324 @ 0x00001324 size=40
CALLERS (1): FUN_00000da8@0x00000da8
CALLEES (0): 

uint FUN_00001324(uint param_1,int param_2)

{
  for (; param_2 != 0; param_2 = param_2 + -1) {
    param_1 = (param_1 & 0xff) >> 1 | param_1 << 7;
  }
  return param_1 & 0xff;
}


================================================================