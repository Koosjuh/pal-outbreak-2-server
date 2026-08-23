
int FUN_001c3490(byte *param_1,undefined1 *param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  iVar3 = 0;
  iVar1 = 0;
  do {
    do {
      if (param_3 < 1) {
        return iVar1;
      }
      uVar2 = (uint)*param_1;
      if (uVar2 != 0x3d) {
        if ((uVar2 < 0x41) || (0x5a < uVar2)) {
          if ((uVar2 < 0x61) || (0x7a < uVar2)) {
            if ((uVar2 < 0x30) || (0x39 < uVar2)) {
              if (uVar2 == 0x2b) {
                uVar2 = 0x3e;
              }
              else if (uVar2 == 0x2f) {
                uVar2 = 0x3f;
              }
              else {
                uVar2 = 0xffffffff;
              }
            }
            else {
              uVar2 = uVar2 + 4;
            }
          }
          else {
            uVar2 = uVar2 - 0x47;
          }
        }
        else {
          uVar2 = uVar2 - 0x41;
        }
        iVar3 = iVar3 + 6;
        uVar4 = uVar4 << 6 | uVar2;
      }
      param_1 = param_1 + 1;
      param_3 = param_3 + -1;
    } while (iVar3 < 8);
    uVar2 = iVar3 - 8;
    param_4 = param_4 + -1;
    iVar3 = iVar3 + -8;
    *param_2 = (char)(uVar4 >> (uVar2 & 0x1f));
    iVar1 = iVar1 + 1;
    param_2 = param_2 + 1;
  } while (0 < param_4);
  return -1;
}

