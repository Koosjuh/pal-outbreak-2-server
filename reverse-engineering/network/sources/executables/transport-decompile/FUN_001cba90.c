
int FUN_001cba90(int param_1)

{
  if ((0x20ff < param_1) && (param_1 < 0x2400)) {
    param_1 = param_1 + (uint)bRam005a9048 * 0x60 + (uint)bRam005a9048 * -0x10 + -0x900;
  }
  return param_1;
}

