
short FUN_001e4bec(undefined2 *param_1)

{
  short sStack_30;
  short sStack_2e;
  undefined1 auStack_2c [2];
  short sStack_2a;
  int iStack_28;
  undefined2 *puStack_24;
  uint uStack_20;
  
  iStack_28 = 1;
  if (param_1[2] == -1) {
    sStack_30 = -1;
  }
  else if (param_1[2] == 0xff0) {
    sStack_30 = 0;
  }
  else {
    puStack_24 = param_1;
    sStack_30 = FUN_001ef830(*param_1,&sStack_2e,auStack_2c,&sStack_2a);
    if (sStack_30 < 0) {
      FUN_001ef770(*puStack_24);
      puStack_24[2] = 0xff3;
    }
    else {
      while (iStack_28 != 0) {
        iStack_28 = 0;
        uStack_20 = (uint)(ushort)puStack_24[2];
        if (uStack_20 == 0xff3) {
          if (sStack_2e == 0) {
            puStack_24[2] = 0xffff;
            puStack_24[1] = 0xffff;
            iStack_28 = 1;
          }
        }
        else if (uStack_20 < 0xff4) {
          if (uStack_20 == 0xff1) {
            if (sStack_2e == 4) {
              puStack_24[2] = 0x7f;
              iStack_28 = 1;
            }
          }
          else if (uStack_20 < 0xff2) {
            if (uStack_20 == 0x7f) {
              if (0 < sStack_2a) {
                puStack_24[2] = 0xff4;
                iStack_28 = 1;
              }
            }
            else {
LAB_001e4e9c:
              sStack_30 = -1;
            }
          }
          else {
            sStack_30 = FUN_001efda0(*puStack_24);
            if (sStack_30 == 0) {
              puStack_24[2] = 0x7f;
              iStack_28 = 1;
            }
          }
        }
        else if (uStack_20 == 0xff5) {
          if (0 < sStack_2a) {
            puStack_24[2] = 0xff6;
            iStack_28 = 1;
          }
        }
        else if (uStack_20 < 0xff5) {
          if (sStack_2a == 0) {
            puStack_24[2] = 0x7f;
            iStack_28 = 1;
          }
        }
        else {
          if (uStack_20 != 0xff6) goto LAB_001e4e9c;
          if (sStack_2a == 0) {
            puStack_24[2] = 0xff5;
            iStack_28 = 1;
          }
        }
      }
    }
  }
  return sStack_30;
}

