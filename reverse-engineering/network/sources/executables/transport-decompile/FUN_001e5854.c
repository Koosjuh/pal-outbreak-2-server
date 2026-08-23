
void FUN_001e5854(undefined4 *param_1)

{
  int iStack_1c;
  
  *param_1 = 0x67452301;
  param_1[1] = 0xefcdab89;
  param_1[2] = 0x98badcfe;
  param_1[3] = 0x10325476;
  param_1[4] = 0xc3d2e1f0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  for (iStack_1c = 0; iStack_1c < 0x50; iStack_1c = iStack_1c + 1) {
    param_1[iStack_1c + 9] = 0;
  }
  return;
}

