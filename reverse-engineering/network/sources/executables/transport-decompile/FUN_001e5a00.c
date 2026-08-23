
bool FUN_001e5a00(uint *param_1,int *param_2,uint *param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uStack_50;
  uint uStack_4c;
  
  uStack_4c = 0;
  if (*param_3 < 0x40 - param_1[7]) {
    if (*param_3 != 0) {
      FUN_001069a8((int)param_1 + param_1[7] + 0x24,*param_2,*param_3);
      *param_2 = *param_2 + *param_3;
      param_1[7] = param_1[7] + *param_3;
      *param_3 = 0;
    }
    if (param_4 == 0) {
      return true;
    }
    uStack_4c = param_1[7];
    param_1[7] = 0;
    uVar1 = param_1[6] + uStack_4c * 8;
    param_1[6] = uVar1;
    if (uVar1 < uStack_4c * 8) {
      param_1[5] = param_1[5] + 1;
    }
    if (param_1[8] == 0) {
      *(undefined1 *)((int)param_1 + uStack_4c + 0x24) = 0x80;
      uStack_4c = uStack_4c + 1;
      param_1[8] = 1;
    }
    for (uStack_50 = uStack_4c; (int)uStack_50 < 0x40; uStack_50 = uStack_50 + 1) {
      *(undefined1 *)((int)param_1 + uStack_50 + 0x24) = 0;
    }
    if ((int)uStack_4c < 0x39) {
      param_1[0x17] = param_1[5];
      param_1[0x18] = param_1[6];
      FUN_001e5934(param_1 + 9,0x38);
    }
    else {
      FUN_001e5934(param_1 + 9,0x40);
    }
  }
  else {
    FUN_001069a8((int)param_1 + param_1[7] + 0x24,*param_2,0x40 - param_1[7]);
    *param_2 = (*param_2 - param_1[7]) + 0x40;
    *param_3 = (*param_3 + param_1[7]) - 0x40;
    param_1[7] = 0;
    uVar1 = param_1[6];
    param_1[6] = uVar1 + 0x200;
    if (uVar1 + 0x200 < 0x200) {
      param_1[5] = param_1[5] + 1;
    }
    FUN_001e5934(param_1 + 9,0x40);
  }
  uVar1 = *param_1;
  uVar5 = param_1[1];
  uVar4 = param_1[2];
  uVar3 = param_1[3];
  uVar2 = (uVar1 << 5 | uVar1 >> 0x1b) + ((uVar4 ^ uVar3) & uVar5 ^ uVar3) + param_1[4] + param_1[9]
          + 0x5a827999;
  uVar5 = uVar5 << 0x1e | uVar5 >> 2;
  uVar3 = (uVar2 * 0x20 | uVar2 >> 0x1b) + ((uVar5 ^ uVar4) & uVar1 ^ uVar4) + uVar3 + param_1[10] +
          0x5a827999;
  uVar1 = uVar1 << 0x1e | uVar1 >> 2;
  uVar4 = (uVar3 * 0x20 | uVar3 >> 0x1b) + ((uVar1 ^ uVar5) & uVar2 ^ uVar5) + uVar4 + param_1[0xb]
          + 0x5a827999;
  uVar2 = uVar2 * 0x40000000 | uVar2 >> 2;
  uVar5 = (uVar4 * 0x20 | uVar4 >> 0x1b) + ((uVar2 ^ uVar1) & uVar3 ^ uVar1) + uVar5 + param_1[0xc]
          + 0x5a827999;
  uVar3 = uVar3 * 0x40000000 | uVar3 >> 2;
  uVar1 = (uVar5 * 0x20 | uVar5 >> 0x1b) + ((uVar3 ^ uVar2) & uVar4 ^ uVar2) + uVar1 + param_1[0xd]
          + 0x5a827999;
  uVar4 = uVar4 * 0x40000000 | uVar4 >> 2;
  uVar2 = (uVar1 * 0x20 | uVar1 >> 0x1b) + ((uVar4 ^ uVar3) & uVar5 ^ uVar3) + uVar2 + param_1[0xe]
          + 0x5a827999;
  uVar5 = uVar5 * 0x40000000 | uVar5 >> 2;
  uVar3 = (uVar2 * 0x20 | uVar2 >> 0x1b) + ((uVar5 ^ uVar4) & uVar1 ^ uVar4) + uVar3 + param_1[0xf]
          + 0x5a827999;
  uVar1 = uVar1 * 0x40000000 | uVar1 >> 2;
  uVar4 = (uVar3 * 0x20 | uVar3 >> 0x1b) + ((uVar1 ^ uVar5) & uVar2 ^ uVar5) + uVar4 + param_1[0x10]
          + 0x5a827999;
  uVar2 = uVar2 * 0x40000000 | uVar2 >> 2;
  uVar5 = (uVar4 * 0x20 | uVar4 >> 0x1b) + ((uVar2 ^ uVar1) & uVar3 ^ uVar1) + uVar5 + param_1[0x11]
          + 0x5a827999;
  uVar3 = uVar3 * 0x40000000 | uVar3 >> 2;
  uVar1 = (uVar5 * 0x20 | uVar5 >> 0x1b) + ((uVar3 ^ uVar2) & uVar4 ^ uVar2) + uVar1 + param_1[0x12]
          + 0x5a827999;
  uVar4 = uVar4 * 0x40000000 | uVar4 >> 2;
  uVar2 = (uVar1 * 0x20 | uVar1 >> 0x1b) + ((uVar4 ^ uVar3) & uVar5 ^ uVar3) + uVar2 + param_1[0x13]
          + 0x5a827999;
  uVar5 = uVar5 * 0x40000000 | uVar5 >> 2;
  uVar3 = (uVar2 * 0x20 | uVar2 >> 0x1b) + ((uVar5 ^ uVar4) & uVar1 ^ uVar4) + uVar3 + param_1[0x14]
          + 0x5a827999;
  uVar1 = uVar1 * 0x40000000 | uVar1 >> 2;
  uVar4 = (uVar3 * 0x20 | uVar3 >> 0x1b) + ((uVar1 ^ uVar5) & uVar2 ^ uVar5) + uVar4 + param_1[0x15]
          + 0x5a827999;
  uVar2 = uVar2 * 0x40000000 | uVar2 >> 2;
  uVar5 = (uVar4 * 0x20 | uVar4 >> 0x1b) + ((uVar2 ^ uVar1) & uVar3 ^ uVar1) + uVar5 + param_1[0x16]
          + 0x5a827999;
  uVar3 = uVar3 * 0x40000000 | uVar3 >> 2;
  uVar1 = (uVar5 * 0x20 | uVar5 >> 0x1b) + ((uVar3 ^ uVar2) & uVar4 ^ uVar2) + uVar1 + param_1[0x17]
          + 0x5a827999;
  uVar4 = uVar4 * 0x40000000 | uVar4 >> 2;
  uVar2 = (uVar1 * 0x20 | uVar1 >> 0x1b) + ((uVar4 ^ uVar3) & uVar5 ^ uVar3) + uVar2 + param_1[0x18]
          + 0x5a827999;
  uVar5 = uVar5 * 0x40000000 | uVar5 >> 2;
  uVar6 = param_1[0x16] ^ param_1[0x11] ^ param_1[0xb] ^ param_1[9];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x19] = uVar6;
  uVar3 = (uVar2 * 0x20 | uVar2 >> 0x1b) + ((uVar5 ^ uVar4) & uVar1 ^ uVar4) + uVar3 + uVar6 +
          0x5a827999;
  uVar1 = uVar1 * 0x40000000 | uVar1 >> 2;
  uVar6 = param_1[0x17] ^ param_1[0x12] ^ param_1[0xc] ^ param_1[10];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x1a] = uVar6;
  uVar4 = (uVar3 * 0x20 | uVar3 >> 0x1b) + ((uVar1 ^ uVar5) & uVar2 ^ uVar5) + uVar4 + uVar6 +
          0x5a827999;
  uVar2 = uVar2 * 0x40000000 | uVar2 >> 2;
  uVar6 = param_1[0x18] ^ param_1[0x13] ^ param_1[0xd] ^ param_1[0xb];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x1b] = uVar6;
  uVar5 = (uVar4 * 0x20 | uVar4 >> 0x1b) + ((uVar2 ^ uVar1) & uVar3 ^ uVar1) + uVar5 + uVar6 +
          0x5a827999;
  uVar3 = uVar3 * 0x40000000 | uVar3 >> 2;
  uVar6 = param_1[0x19] ^ param_1[0x14] ^ param_1[0xe] ^ param_1[0xc];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x1c] = uVar6;
  uVar1 = (uVar5 * 0x20 | uVar5 >> 0x1b) + ((uVar3 ^ uVar2) & uVar4 ^ uVar2) + uVar1 + uVar6 +
          0x5a827999;
  uVar4 = uVar4 * 0x40000000 | uVar4 >> 2;
  uVar6 = param_1[0x1a] ^ param_1[0x15] ^ param_1[0xf] ^ param_1[0xd];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x1d] = uVar6;
  uVar2 = (uVar1 * 0x20 | uVar1 >> 0x1b) + (uVar5 ^ uVar4 ^ uVar3) + uVar2 + uVar6 + 0x6ed9eba1;
  uVar5 = uVar5 * 0x40000000 | uVar5 >> 2;
  uVar6 = param_1[0x1b] ^ param_1[0x16] ^ param_1[0x10] ^ param_1[0xe];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x1e] = uVar6;
  uVar3 = (uVar2 * 0x20 | uVar2 >> 0x1b) + (uVar1 ^ uVar5 ^ uVar4) + uVar3 + uVar6 + 0x6ed9eba1;
  uVar1 = uVar1 * 0x40000000 | uVar1 >> 2;
  uVar6 = param_1[0x1c] ^ param_1[0x17] ^ param_1[0x11] ^ param_1[0xf];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x1f] = uVar6;
  uVar4 = (uVar3 * 0x20 | uVar3 >> 0x1b) + (uVar2 ^ uVar1 ^ uVar5) + uVar4 + uVar6 + 0x6ed9eba1;
  uVar2 = uVar2 * 0x40000000 | uVar2 >> 2;
  uVar6 = param_1[0x1d] ^ param_1[0x18] ^ param_1[0x12] ^ param_1[0x10];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x20] = uVar6;
  uVar5 = (uVar4 * 0x20 | uVar4 >> 0x1b) + (uVar3 ^ uVar2 ^ uVar1) + uVar5 + uVar6 + 0x6ed9eba1;
  uVar3 = uVar3 * 0x40000000 | uVar3 >> 2;
  uVar6 = param_1[0x1e] ^ param_1[0x19] ^ param_1[0x13] ^ param_1[0x11];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x21] = uVar6;
  uVar1 = (uVar5 * 0x20 | uVar5 >> 0x1b) + (uVar4 ^ uVar3 ^ uVar2) + uVar1 + uVar6 + 0x6ed9eba1;
  uVar4 = uVar4 * 0x40000000 | uVar4 >> 2;
  uVar6 = param_1[0x1f] ^ param_1[0x1a] ^ param_1[0x14] ^ param_1[0x12];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x22] = uVar6;
  uVar2 = (uVar1 * 0x20 | uVar1 >> 0x1b) + (uVar5 ^ uVar4 ^ uVar3) + uVar2 + uVar6 + 0x6ed9eba1;
  uVar5 = uVar5 * 0x40000000 | uVar5 >> 2;
  uVar6 = param_1[0x20] ^ param_1[0x1b] ^ param_1[0x15] ^ param_1[0x13];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x23] = uVar6;
  uVar3 = (uVar2 * 0x20 | uVar2 >> 0x1b) + (uVar1 ^ uVar5 ^ uVar4) + uVar3 + uVar6 + 0x6ed9eba1;
  uVar1 = uVar1 * 0x40000000 | uVar1 >> 2;
  uVar6 = param_1[0x21] ^ param_1[0x1c] ^ param_1[0x16] ^ param_1[0x14];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x24] = uVar6;
  uVar4 = (uVar3 * 0x20 | uVar3 >> 0x1b) + (uVar2 ^ uVar1 ^ uVar5) + uVar4 + uVar6 + 0x6ed9eba1;
  uVar2 = uVar2 * 0x40000000 | uVar2 >> 2;
  uVar6 = param_1[0x22] ^ param_1[0x1d] ^ param_1[0x17] ^ param_1[0x15];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x25] = uVar6;
  uVar5 = (uVar4 * 0x20 | uVar4 >> 0x1b) + (uVar3 ^ uVar2 ^ uVar1) + uVar5 + uVar6 + 0x6ed9eba1;
  uVar3 = uVar3 * 0x40000000 | uVar3 >> 2;
  uVar6 = param_1[0x23] ^ param_1[0x1e] ^ param_1[0x18] ^ param_1[0x16];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x26] = uVar6;
  uVar1 = (uVar5 * 0x20 | uVar5 >> 0x1b) + (uVar4 ^ uVar3 ^ uVar2) + uVar1 + uVar6 + 0x6ed9eba1;
  uVar4 = uVar4 * 0x40000000 | uVar4 >> 2;
  uVar6 = param_1[0x24] ^ param_1[0x1f] ^ param_1[0x19] ^ param_1[0x17];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x27] = uVar6;
  uVar2 = (uVar1 * 0x20 | uVar1 >> 0x1b) + (uVar5 ^ uVar4 ^ uVar3) + uVar2 + uVar6 + 0x6ed9eba1;
  uVar5 = uVar5 * 0x40000000 | uVar5 >> 2;
  uVar6 = param_1[0x25] ^ param_1[0x20] ^ param_1[0x1a] ^ param_1[0x18];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x28] = uVar6;
  uVar3 = (uVar2 * 0x20 | uVar2 >> 0x1b) + (uVar1 ^ uVar5 ^ uVar4) + uVar3 + uVar6 + 0x6ed9eba1;
  uVar1 = uVar1 * 0x40000000 | uVar1 >> 2;
  uVar6 = param_1[0x26] ^ param_1[0x21] ^ param_1[0x1b] ^ param_1[0x19];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x29] = uVar6;
  uVar4 = (uVar3 * 0x20 | uVar3 >> 0x1b) + (uVar2 ^ uVar1 ^ uVar5) + uVar4 + uVar6 + 0x6ed9eba1;
  uVar2 = uVar2 * 0x40000000 | uVar2 >> 2;
  uVar6 = param_1[0x27] ^ param_1[0x22] ^ param_1[0x1c] ^ param_1[0x1a];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x2a] = uVar6;
  uVar5 = (uVar4 * 0x20 | uVar4 >> 0x1b) + (uVar3 ^ uVar2 ^ uVar1) + uVar5 + uVar6 + 0x6ed9eba1;
  uVar3 = uVar3 * 0x40000000 | uVar3 >> 2;
  uVar6 = param_1[0x28] ^ param_1[0x23] ^ param_1[0x1d] ^ param_1[0x1b];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x2b] = uVar6;
  uVar1 = (uVar5 * 0x20 | uVar5 >> 0x1b) + (uVar4 ^ uVar3 ^ uVar2) + uVar1 + uVar6 + 0x6ed9eba1;
  uVar4 = uVar4 * 0x40000000 | uVar4 >> 2;
  uVar6 = param_1[0x29] ^ param_1[0x24] ^ param_1[0x1e] ^ param_1[0x1c];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x2c] = uVar6;
  uVar2 = (uVar1 * 0x20 | uVar1 >> 0x1b) + (uVar5 ^ uVar4 ^ uVar3) + uVar2 + uVar6 + 0x6ed9eba1;
  uVar5 = uVar5 * 0x40000000 | uVar5 >> 2;
  uVar6 = param_1[0x2a] ^ param_1[0x25] ^ param_1[0x1f] ^ param_1[0x1d];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x2d] = uVar6;
  uVar3 = (uVar2 * 0x20 | uVar2 >> 0x1b) + (uVar1 ^ uVar5 ^ uVar4) + uVar3 + uVar6 + 0x6ed9eba1;
  uVar1 = uVar1 * 0x40000000 | uVar1 >> 2;
  uVar6 = param_1[0x2b] ^ param_1[0x26] ^ param_1[0x20] ^ param_1[0x1e];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x2e] = uVar6;
  uVar4 = (uVar3 * 0x20 | uVar3 >> 0x1b) + (uVar2 ^ uVar1 ^ uVar5) + uVar4 + uVar6 + 0x6ed9eba1;
  uVar2 = uVar2 * 0x40000000 | uVar2 >> 2;
  uVar6 = param_1[0x2c] ^ param_1[0x27] ^ param_1[0x21] ^ param_1[0x1f];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x2f] = uVar6;
  uVar5 = (uVar4 * 0x20 | uVar4 >> 0x1b) + (uVar3 ^ uVar2 ^ uVar1) + uVar5 + uVar6 + 0x6ed9eba1;
  uVar3 = uVar3 * 0x40000000 | uVar3 >> 2;
  uVar6 = param_1[0x2d] ^ param_1[0x28] ^ param_1[0x22] ^ param_1[0x20];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x30] = uVar6;
  uVar1 = (uVar5 * 0x20 | uVar5 >> 0x1b) + (uVar4 ^ uVar3 ^ uVar2) + uVar1 + uVar6 + 0x6ed9eba1;
  uVar4 = uVar4 * 0x40000000 | uVar4 >> 2;
  uVar6 = param_1[0x2e] ^ param_1[0x29] ^ param_1[0x23] ^ param_1[0x21];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x31] = uVar6;
  iVar7 = (uVar1 * 0x20 | uVar1 >> 0x1b) + (uVar5 & uVar4 | (uVar5 | uVar4) & uVar3) + uVar2 + uVar6
  ;
  uVar2 = iVar7 + 0x8f1bbcdc;
  uVar5 = uVar5 * 0x40000000 | uVar5 >> 2;
  uVar6 = param_1[0x2f] ^ param_1[0x2a] ^ param_1[0x24] ^ param_1[0x22];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x32] = uVar6;
  iVar8 = (uVar2 * 0x20 | uVar2 >> 0x1b) + (uVar1 & uVar5 | (uVar1 | uVar5) & uVar4) + uVar3 + uVar6
  ;
  uVar3 = iVar8 + 0x8f1bbcdc;
  uVar1 = uVar1 * 0x40000000 | uVar1 >> 2;
  uVar6 = param_1[0x30] ^ param_1[0x2b] ^ param_1[0x25] ^ param_1[0x23];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x33] = uVar6;
  iVar9 = (uVar3 * 0x20 | uVar3 >> 0x1b) + (uVar2 & uVar1 | (uVar2 | uVar1) & uVar5) + uVar4 + uVar6
  ;
  uVar4 = iVar9 + 0x8f1bbcdc;
  uVar2 = iVar7 * 0x40000000 | uVar2 >> 2;
  uVar6 = param_1[0x31] ^ param_1[0x2c] ^ param_1[0x26] ^ param_1[0x24];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x34] = uVar6;
  iVar7 = (uVar4 * 0x20 | uVar4 >> 0x1b) + (uVar3 & uVar2 | (uVar3 | uVar2) & uVar1) + uVar5 + uVar6
  ;
  uVar5 = iVar7 + 0x8f1bbcdc;
  uVar3 = iVar8 * 0x40000000 | uVar3 >> 2;
  uVar6 = param_1[0x32] ^ param_1[0x2d] ^ param_1[0x27] ^ param_1[0x25];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x35] = uVar6;
  iVar8 = (uVar5 * 0x20 | uVar5 >> 0x1b) + (uVar4 & uVar3 | (uVar4 | uVar3) & uVar2) + uVar1 + uVar6
  ;
  uVar1 = iVar8 + 0x8f1bbcdc;
  uVar4 = iVar9 * 0x40000000 | uVar4 >> 2;
  uVar6 = param_1[0x33] ^ param_1[0x2e] ^ param_1[0x28] ^ param_1[0x26];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x36] = uVar6;
  iVar9 = (uVar1 * 0x20 | uVar1 >> 0x1b) + (uVar5 & uVar4 | (uVar5 | uVar4) & uVar3) + uVar2 + uVar6
  ;
  uVar2 = iVar9 + 0x8f1bbcdc;
  uVar5 = iVar7 * 0x40000000 | uVar5 >> 2;
  uVar6 = param_1[0x34] ^ param_1[0x2f] ^ param_1[0x29] ^ param_1[0x27];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x37] = uVar6;
  iVar7 = (uVar2 * 0x20 | uVar2 >> 0x1b) + (uVar1 & uVar5 | (uVar1 | uVar5) & uVar4) + uVar3 + uVar6
  ;
  uVar3 = iVar7 + 0x8f1bbcdc;
  uVar1 = iVar8 * 0x40000000 | uVar1 >> 2;
  uVar6 = param_1[0x35] ^ param_1[0x30] ^ param_1[0x2a] ^ param_1[0x28];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x38] = uVar6;
  iVar8 = (uVar3 * 0x20 | uVar3 >> 0x1b) + (uVar2 & uVar1 | (uVar2 | uVar1) & uVar5) + uVar4 + uVar6
  ;
  uVar4 = iVar8 + 0x8f1bbcdc;
  uVar2 = iVar9 * 0x40000000 | uVar2 >> 2;
  uVar6 = param_1[0x36] ^ param_1[0x31] ^ param_1[0x2b] ^ param_1[0x29];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x39] = uVar6;
  iVar9 = (uVar4 * 0x20 | uVar4 >> 0x1b) + (uVar3 & uVar2 | (uVar3 | uVar2) & uVar1) + uVar5 + uVar6
  ;
  uVar5 = iVar9 + 0x8f1bbcdc;
  uVar3 = iVar7 * 0x40000000 | uVar3 >> 2;
  uVar6 = param_1[0x37] ^ param_1[0x32] ^ param_1[0x2c] ^ param_1[0x2a];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x3a] = uVar6;
  iVar7 = (uVar5 * 0x20 | uVar5 >> 0x1b) + (uVar4 & uVar3 | (uVar4 | uVar3) & uVar2) + uVar1 + uVar6
  ;
  uVar1 = iVar7 + 0x8f1bbcdc;
  uVar4 = iVar8 * 0x40000000 | uVar4 >> 2;
  uVar6 = param_1[0x38] ^ param_1[0x33] ^ param_1[0x2d] ^ param_1[0x2b];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x3b] = uVar6;
  iVar8 = (uVar1 * 0x20 | uVar1 >> 0x1b) + (uVar5 & uVar4 | (uVar5 | uVar4) & uVar3) + uVar2 + uVar6
  ;
  uVar2 = iVar8 + 0x8f1bbcdc;
  uVar5 = iVar9 * 0x40000000 | uVar5 >> 2;
  uVar6 = param_1[0x39] ^ param_1[0x34] ^ param_1[0x2e] ^ param_1[0x2c];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x3c] = uVar6;
  iVar9 = (uVar2 * 0x20 | uVar2 >> 0x1b) + (uVar1 & uVar5 | (uVar1 | uVar5) & uVar4) + uVar3 + uVar6
  ;
  uVar3 = iVar9 + 0x8f1bbcdc;
  uVar1 = iVar7 * 0x40000000 | uVar1 >> 2;
  uVar6 = param_1[0x3a] ^ param_1[0x35] ^ param_1[0x2f] ^ param_1[0x2d];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x3d] = uVar6;
  iVar7 = (uVar3 * 0x20 | uVar3 >> 0x1b) + (uVar2 & uVar1 | (uVar2 | uVar1) & uVar5) + uVar4 + uVar6
  ;
  uVar4 = iVar7 + 0x8f1bbcdc;
  uVar2 = iVar8 * 0x40000000 | uVar2 >> 2;
  uVar6 = param_1[0x3b] ^ param_1[0x36] ^ param_1[0x30] ^ param_1[0x2e];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x3e] = uVar6;
  iVar8 = (uVar4 * 0x20 | uVar4 >> 0x1b) + (uVar3 & uVar2 | (uVar3 | uVar2) & uVar1) + uVar5 + uVar6
  ;
  uVar5 = iVar8 + 0x8f1bbcdc;
  uVar3 = iVar9 * 0x40000000 | uVar3 >> 2;
  uVar6 = param_1[0x3c] ^ param_1[0x37] ^ param_1[0x31] ^ param_1[0x2f];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x3f] = uVar6;
  iVar9 = (uVar5 * 0x20 | uVar5 >> 0x1b) + (uVar4 & uVar3 | (uVar4 | uVar3) & uVar2) + uVar1 + uVar6
  ;
  uVar1 = iVar9 + 0x8f1bbcdc;
  uVar4 = iVar7 * 0x40000000 | uVar4 >> 2;
  uVar6 = param_1[0x3d] ^ param_1[0x38] ^ param_1[0x32] ^ param_1[0x30];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x40] = uVar6;
  iVar7 = (uVar1 * 0x20 | uVar1 >> 0x1b) + (uVar5 & uVar4 | (uVar5 | uVar4) & uVar3) + uVar2 + uVar6
  ;
  uVar2 = iVar7 + 0x8f1bbcdc;
  uVar5 = iVar8 * 0x40000000 | uVar5 >> 2;
  uVar6 = param_1[0x3e] ^ param_1[0x39] ^ param_1[0x33] ^ param_1[0x31];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x41] = uVar6;
  iVar8 = (uVar2 * 0x20 | uVar2 >> 0x1b) + (uVar1 & uVar5 | (uVar1 | uVar5) & uVar4) + uVar3 + uVar6
  ;
  uVar3 = iVar8 + 0x8f1bbcdc;
  uVar1 = iVar9 * 0x40000000 | uVar1 >> 2;
  uVar6 = param_1[0x3f] ^ param_1[0x3a] ^ param_1[0x34] ^ param_1[0x32];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x42] = uVar6;
  iVar9 = (uVar3 * 0x20 | uVar3 >> 0x1b) + (uVar2 & uVar1 | (uVar2 | uVar1) & uVar5) + uVar4 + uVar6
  ;
  uVar4 = iVar9 + 0x8f1bbcdc;
  uVar2 = iVar7 * 0x40000000 | uVar2 >> 2;
  uVar6 = param_1[0x40] ^ param_1[0x3b] ^ param_1[0x35] ^ param_1[0x33];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x43] = uVar6;
  iVar7 = (uVar4 * 0x20 | uVar4 >> 0x1b) + (uVar3 & uVar2 | (uVar3 | uVar2) & uVar1) + uVar5 + uVar6
  ;
  uVar5 = iVar7 + 0x8f1bbcdc;
  uVar3 = iVar8 * 0x40000000 | uVar3 >> 2;
  uVar6 = param_1[0x41] ^ param_1[0x3c] ^ param_1[0x36] ^ param_1[0x34];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x44] = uVar6;
  iVar8 = (uVar5 * 0x20 | uVar5 >> 0x1b) + (uVar4 & uVar3 | (uVar4 | uVar3) & uVar2) + uVar1 + uVar6
  ;
  uVar1 = iVar8 + 0x8f1bbcdc;
  uVar4 = iVar9 * 0x40000000 | uVar4 >> 2;
  uVar6 = param_1[0x42] ^ param_1[0x3d] ^ param_1[0x37] ^ param_1[0x35];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x45] = uVar6;
  uVar2 = (uVar1 * 0x20 | uVar1 >> 0x1b) + (uVar5 ^ uVar4 ^ uVar3) + uVar2 + uVar6 + 0xca62c1d6;
  uVar5 = iVar7 * 0x40000000 | uVar5 >> 2;
  uVar6 = param_1[0x43] ^ param_1[0x3e] ^ param_1[0x38] ^ param_1[0x36];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x46] = uVar6;
  uVar3 = (uVar2 * 0x20 | uVar2 >> 0x1b) + (uVar1 ^ uVar5 ^ uVar4) + uVar3 + uVar6 + 0xca62c1d6;
  uVar1 = iVar8 * 0x40000000 | uVar1 >> 2;
  uVar6 = param_1[0x44] ^ param_1[0x3f] ^ param_1[0x39] ^ param_1[0x37];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x47] = uVar6;
  uVar4 = (uVar3 * 0x20 | uVar3 >> 0x1b) + (uVar2 ^ uVar1 ^ uVar5) + uVar4 + uVar6 + 0xca62c1d6;
  uVar2 = uVar2 * 0x40000000 | uVar2 >> 2;
  uVar6 = param_1[0x45] ^ param_1[0x40] ^ param_1[0x3a] ^ param_1[0x38];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x48] = uVar6;
  uVar5 = (uVar4 * 0x20 | uVar4 >> 0x1b) + (uVar3 ^ uVar2 ^ uVar1) + uVar5 + uVar6 + 0xca62c1d6;
  uVar3 = uVar3 * 0x40000000 | uVar3 >> 2;
  uVar6 = param_1[0x46] ^ param_1[0x41] ^ param_1[0x3b] ^ param_1[0x39];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x49] = uVar6;
  uVar1 = (uVar5 * 0x20 | uVar5 >> 0x1b) + (uVar4 ^ uVar3 ^ uVar2) + uVar1 + uVar6 + 0xca62c1d6;
  uVar4 = uVar4 * 0x40000000 | uVar4 >> 2;
  uVar6 = param_1[0x47] ^ param_1[0x42] ^ param_1[0x3c] ^ param_1[0x3a];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x4a] = uVar6;
  uVar2 = (uVar1 * 0x20 | uVar1 >> 0x1b) + (uVar5 ^ uVar4 ^ uVar3) + uVar2 + uVar6 + 0xca62c1d6;
  uVar5 = uVar5 * 0x40000000 | uVar5 >> 2;
  uVar6 = param_1[0x48] ^ param_1[0x43] ^ param_1[0x3d] ^ param_1[0x3b];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x4b] = uVar6;
  uVar3 = (uVar2 * 0x20 | uVar2 >> 0x1b) + (uVar1 ^ uVar5 ^ uVar4) + uVar3 + uVar6 + 0xca62c1d6;
  uVar1 = uVar1 * 0x40000000 | uVar1 >> 2;
  uVar6 = param_1[0x49] ^ param_1[0x44] ^ param_1[0x3e] ^ param_1[0x3c];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x4c] = uVar6;
  uVar4 = (uVar3 * 0x20 | uVar3 >> 0x1b) + (uVar2 ^ uVar1 ^ uVar5) + uVar4 + uVar6 + 0xca62c1d6;
  uVar2 = uVar2 * 0x40000000 | uVar2 >> 2;
  uVar6 = param_1[0x4a] ^ param_1[0x45] ^ param_1[0x3f] ^ param_1[0x3d];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x4d] = uVar6;
  uVar5 = (uVar4 * 0x20 | uVar4 >> 0x1b) + (uVar3 ^ uVar2 ^ uVar1) + uVar5 + uVar6 + 0xca62c1d6;
  uVar3 = uVar3 * 0x40000000 | uVar3 >> 2;
  uVar6 = param_1[0x4b] ^ param_1[0x46] ^ param_1[0x40] ^ param_1[0x3e];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x4e] = uVar6;
  uVar1 = (uVar5 * 0x20 | uVar5 >> 0x1b) + (uVar4 ^ uVar3 ^ uVar2) + uVar1 + uVar6 + 0xca62c1d6;
  uVar4 = uVar4 * 0x40000000 | uVar4 >> 2;
  uVar6 = param_1[0x4c] ^ param_1[0x47] ^ param_1[0x41] ^ param_1[0x3f];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x4f] = uVar6;
  uVar2 = (uVar1 * 0x20 | uVar1 >> 0x1b) + (uVar5 ^ uVar4 ^ uVar3) + uVar2 + uVar6 + 0xca62c1d6;
  uVar5 = uVar5 * 0x40000000 | uVar5 >> 2;
  uVar6 = param_1[0x4d] ^ param_1[0x48] ^ param_1[0x42] ^ param_1[0x40];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x50] = uVar6;
  uVar3 = (uVar2 * 0x20 | uVar2 >> 0x1b) + (uVar1 ^ uVar5 ^ uVar4) + uVar3 + uVar6 + 0xca62c1d6;
  uVar1 = uVar1 * 0x40000000 | uVar1 >> 2;
  uVar6 = param_1[0x4e] ^ param_1[0x49] ^ param_1[0x43] ^ param_1[0x41];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x51] = uVar6;
  uVar4 = (uVar3 * 0x20 | uVar3 >> 0x1b) + (uVar2 ^ uVar1 ^ uVar5) + uVar4 + uVar6 + 0xca62c1d6;
  uVar2 = uVar2 * 0x40000000 | uVar2 >> 2;
  uVar6 = param_1[0x4f] ^ param_1[0x4a] ^ param_1[0x44] ^ param_1[0x42];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x52] = uVar6;
  uVar5 = (uVar4 * 0x20 | uVar4 >> 0x1b) + (uVar3 ^ uVar2 ^ uVar1) + uVar5 + uVar6 + 0xca62c1d6;
  uVar3 = uVar3 * 0x40000000 | uVar3 >> 2;
  uVar6 = param_1[0x50] ^ param_1[0x4b] ^ param_1[0x45] ^ param_1[0x43];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x53] = uVar6;
  uVar1 = (uVar5 * 0x20 | uVar5 >> 0x1b) + (uVar4 ^ uVar3 ^ uVar2) + uVar1 + uVar6 + 0xca62c1d6;
  uVar4 = uVar4 * 0x40000000 | uVar4 >> 2;
  uVar6 = param_1[0x51] ^ param_1[0x4c] ^ param_1[0x46] ^ param_1[0x44];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x54] = uVar6;
  uVar2 = (uVar1 * 0x20 | uVar1 >> 0x1b) + (uVar5 ^ uVar4 ^ uVar3) + uVar2 + uVar6 + 0xca62c1d6;
  uVar5 = uVar5 * 0x40000000 | uVar5 >> 2;
  uVar6 = param_1[0x52] ^ param_1[0x4d] ^ param_1[0x47] ^ param_1[0x45];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x55] = uVar6;
  uVar3 = (uVar2 * 0x20 | uVar2 >> 0x1b) + (uVar1 ^ uVar5 ^ uVar4) + uVar3 + uVar6 + 0xca62c1d6;
  uVar1 = uVar1 * 0x40000000 | uVar1 >> 2;
  uVar6 = param_1[0x53] ^ param_1[0x4e] ^ param_1[0x48] ^ param_1[0x46];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x56] = uVar6;
  uVar4 = (uVar3 * 0x20 | uVar3 >> 0x1b) + (uVar2 ^ uVar1 ^ uVar5) + uVar4 + uVar6 + 0xca62c1d6;
  uVar2 = uVar2 * 0x40000000 | uVar2 >> 2;
  uVar6 = param_1[0x54] ^ param_1[0x4f] ^ param_1[0x49] ^ param_1[0x47];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x57] = uVar6;
  uVar5 = (uVar4 * 0x20 | uVar4 >> 0x1b) + (uVar3 ^ uVar2 ^ uVar1) + uVar5 + uVar6 + 0xca62c1d6;
  uVar3 = uVar3 * 0x40000000 | uVar3 >> 2;
  uVar6 = param_1[0x55] ^ param_1[0x50] ^ param_1[0x4a] ^ param_1[0x48];
  uVar6 = uVar6 << 1 | uVar6 >> 0x1f;
  param_1[0x58] = uVar6;
  *param_1 = *param_1 +
             (uVar5 * 0x20 | uVar5 >> 0x1b) + (uVar4 ^ uVar3 ^ uVar2) + uVar1 + uVar6 + -0x359d3e2a;
  param_1[1] = param_1[1] + uVar5;
  param_1[2] = param_1[2] + (uVar4 * 0x40000000 | uVar4 >> 2);
  param_1[3] = param_1[3] + uVar3;
  param_1[4] = param_1[4] + uVar2;
  return 0x38 < (int)uStack_4c;
}

