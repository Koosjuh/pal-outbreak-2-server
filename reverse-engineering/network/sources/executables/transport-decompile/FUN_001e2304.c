
uint FUN_001e2304(uint param_1)

{
  return param_1 << 0x18 | (param_1 & 0xff00) << 8 | (param_1 & 0xff0000) >> 8 | param_1 >> 0x18;
}

