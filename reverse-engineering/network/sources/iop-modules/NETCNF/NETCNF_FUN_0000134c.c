FUNCTION FUN_0000134c @ 0x0000134c size=40
CALLERS (1): FUN_00000fe4@0x00000fe4
CALLEES (0): 

uint FUN_0000134c(uint param_1,int param_2)

{
  for (; param_2 != 0; param_2 = param_2 + -1) {
    param_1 = (param_1 & 0xffff) >> 0xf | param_1 << 1;
  }
  return param_1 & 0xffff;
}


================================================================