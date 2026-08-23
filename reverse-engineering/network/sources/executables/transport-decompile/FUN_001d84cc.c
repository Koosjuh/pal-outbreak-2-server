
void FUN_001d84cc(uint *param_1)

{
  *param_1 = *param_1 << 0x18 | (*param_1 & 0xff00) << 8 | (*param_1 & 0xff0000) >> 8 |
             *param_1 >> 0x18;
  param_1[1] = param_1[1] << 0x18 | (param_1[1] & 0xff00) << 8 | (param_1[1] & 0xff0000) >> 8 |
               param_1[1] >> 0x18;
  if (param_1[1] != 0x4e414d45) {
    param_1[2] = param_1[2] << 0x18 | (param_1[2] & 0xff00) << 8 | (param_1[2] & 0xff0000) >> 8 |
                 param_1[2] >> 0x18;
  }
  return;
}

