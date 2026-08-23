
void FUN_001e5234(int param_1,int param_2,int param_3)

{
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  uint uStack_28;
  undefined4 uStack_24;
  undefined4 auStack_20 [4];
  
  for (iStack_34 = 0; iStack_34 < 4; iStack_34 = iStack_34 + 1) {
    for (iStack_30 = 0; iStack_30 < 0x100; iStack_30 = iStack_30 + 1) {
      *(undefined4 *)(param_1 + (iStack_34 * 0x100 + iStack_30) * 4 + 0x48) =
           *(undefined4 *)(&DAT_00259778 + (iStack_34 * 0x100 + iStack_30) * 4);
    }
  }
  iStack_30 = 0;
  for (iStack_34 = 0; iStack_34 < 0x12; iStack_34 = iStack_34 + 1) {
    uStack_28 = 0;
    for (iStack_2c = 0; iStack_2c < 4; iStack_2c = iStack_2c + 1) {
      uStack_28 = uStack_28 << 8 | (uint)*(byte *)(param_2 + iStack_30);
      iStack_30 = iStack_30 + 1;
      if (param_3 <= iStack_30) {
        iStack_30 = 0;
      }
    }
    *(uint *)(param_1 + iStack_34 * 4) = *(uint *)(&DAT_00259730 + iStack_34 * 4) ^ uStack_28;
  }
  uStack_24 = 0;
  auStack_20[0] = 0;
  for (iStack_34 = 0; iStack_34 < 0x12; iStack_34 = iStack_34 + 2) {
    FUN_001e4fd8(param_1,&uStack_24,auStack_20);
    *(undefined4 *)(param_1 + iStack_34 * 4) = uStack_24;
    *(undefined4 *)(param_1 + iStack_34 * 4 + 4) = auStack_20[0];
  }
  for (iStack_34 = 0; iStack_34 < 4; iStack_34 = iStack_34 + 1) {
    for (iStack_30 = 0; iStack_30 < 0x100; iStack_30 = iStack_30 + 2) {
      FUN_001e4fd8(param_1,&uStack_24,auStack_20);
      *(undefined4 *)(param_1 + (iStack_34 * 0x100 + iStack_30) * 4 + 0x48) = uStack_24;
      *(undefined4 *)(param_1 + (iStack_34 * 0x100 + iStack_30) * 4 + 0x4c) = auStack_20[0];
    }
  }
  return;
}

