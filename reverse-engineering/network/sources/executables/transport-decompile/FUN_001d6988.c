
int FUN_001d6988(int param_1,int param_2,undefined8 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  undefined4 uStack_60;
  int iStack_5c;
  ushort auStack_50 [4];
  uint uStack_48;
  int iStack_40;
  uint uStack_3c;
  int iStack_38;
  int iStack_34;
  uint uStack_30;
  int iStack_2c;
  
  iStack_34 = 1;
  uStack_30 = 0;
  if ((*(ushort *)(param_1 + 0x2c) & 0x4000) != 0) {
    FUN_001e1ac8(param_2,*(undefined4 *)(param_2 + 0x58),*(undefined4 *)(param_1 + 0x38),param_4);
    FUN_001ed634(param_1,*(undefined4 *)(param_1 + 0x38));
  }
  if ((*(ushort *)(param_1 + 0x2c) & 0x8000) == 0) {
    if (*(uint *)(param_2 + 0x10) <= *(uint *)(param_1 + 0x34)) {
      *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(param_1 + 0x34);
      iStack_34 = 0;
    }
    iStack_5c = param_2 + 0x68;
  }
  else {
    uStack_30 = *(uint *)(param_1 + 0x34);
    FUN_001e16b4(param_2,*(undefined4 *)(param_2 + 0x60),uStack_30);
    if (**(uint **)(param_2 + 0x5c) <= uStack_30) {
      FUN_001ed68c(param_1,uStack_30);
      iStack_34 = 0;
    }
    iStack_5c = *(int *)(param_2 + 0x5c) + 4;
  }
  if ((iStack_34 == 0) && (iStack_2c = FUN_001eb3b8(iStack_5c,param_1), iStack_2c != 0)) {
    DAT_0025b790 = 0x1771;
  }
  else {
    if ((*(ushort *)(param_1 + 0x2c) & 0x800) != 0) {
      iStack_40 = FUN_001ed6bc(param_1);
      uStack_3c = *(ushort *)(param_1 + 0x2c) & 0x3ff;
      for (iStack_38 = 0; iStack_38 < 0x38; iStack_38 = iStack_38 + 1) {
        iStack_40 = iStack_40 + uStack_3c;
        uVar2 = iStack_40 + 0x10;
        uVar1 = FUN_001ed21c(param_1);
        if (uVar1 < uVar2) break;
        FUN_001069a8(auStack_50,iStack_40,0x10);
        uStack_3c = auStack_50[0] & 0x3ff;
        if ((auStack_50[0] & 0x8000) == 0) {
          if (*(uint *)(param_2 + 0x10) <= uStack_48) {
            *(uint *)(param_2 + 0x10) = uStack_48;
            iStack_5c = param_2 + 0x68;
            goto LAB_001d6c98;
          }
        }
        else {
          if (uStack_30 == 0) {
            uStack_30 = uStack_48;
            FUN_001e16b4(param_2,*(undefined4 *)(param_2 + 0x60),uStack_48);
          }
          if (**(uint **)(param_2 + 0x5c) <= uStack_30) {
            iStack_5c = *(int *)(param_2 + 0x5c) + 4;
LAB_001d6c98:
            iStack_2c = FUN_001ec1f8(*(undefined4 *)(param_2 + 0x520),&uStack_60,
                                     (undefined2)uStack_3c,1,0);
            if (iStack_2c < 0) {
              DAT_0025b790 = 0x1772;
              return iStack_2c;
            }
            iStack_2c = FUN_001ed74c(uStack_60,iStack_40,uStack_3c);
            if (iStack_2c < 0) {
              DAT_0025b790 = 0x1773;
              return iStack_2c;
            }
            FUN_001ed68c(uStack_60,uStack_30);
            iStack_2c = FUN_001eb3b8(iStack_5c,uStack_60);
            if (iStack_2c != 0) {
              DAT_0025b790 = 0x1774;
              return iStack_2c;
            }
          }
        }
      }
    }
    FUN_001ebcd0(param_1,*(ushort *)(param_1 + 0x2c) & 0x3ff);
    if ((iStack_34 == 0) ||
       (iStack_2c = FUN_001ec9e0(*(undefined4 *)(param_2 + 0x520),param_1), iStack_2c == 0)) {
      iStack_2c = 0;
    }
  }
  return iStack_2c;
}

