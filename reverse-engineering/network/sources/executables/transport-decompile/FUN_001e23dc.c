
uint FUN_001e23dc(uint param_1)

{
  return (param_1 & 0xffff) >> 8 | (param_1 & 0xff) << 8;
}

