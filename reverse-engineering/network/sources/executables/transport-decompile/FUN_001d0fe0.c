
void FUN_001d0fe0(uint param_1,uint param_2,uint param_3)

{
  if (cRam00343577 == '\0') {
    bRam005a9048 = bRam005a9048 ^ 1;
    FUN_001ccb80(param_3 & 0xff | (param_1 & 0xff) << 0x10 | (param_2 & 0xff) << 8,
                 (uint)bRam005a9048 * 0x80 + 0x1800);
  }
  return;
}

