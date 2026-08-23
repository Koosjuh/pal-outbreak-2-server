
void FUN_001a7a80(int param_1)

{
  param_1 = param_1 * 3;
  bRam0034321c = (&DAT_00245400)[param_1];
  bRam0034321d = (&DAT_00245401)[param_1];
  bRam0034321e = (&DAT_00245402)[param_1];
  FUN_001a7b70(0x14,(uint)bRam0034321e |
                    (uint)bRam0034321c << 0x10 | 0xff000000 | (uint)bRam0034321d << 8);
  return;
}

