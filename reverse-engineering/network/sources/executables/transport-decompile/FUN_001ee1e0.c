
int FUN_001ee1e0(long param_1,long param_2)

{
  long lVar1;
  undefined1 auStack_20 [12];
  short sStack_14;
  int iStack_8;
  undefined1 auStack_4 [4];
  
  if (((iRam0037a298 == 0) && (iRam0037a290 == 0)) && (lVar1 = FUN_001ee160(), lVar1 != 0)) {
    if ((param_1 == 3) || (param_1 == 2)) {
      lVar1 = FUN_001eeb50(auStack_20);
      if (lVar1 < 0) {
        iRam0037a298 = 1;
      }
      else if (sStack_14 != 4) {
        iRam0037a298 = 2;
      }
    }
    else if (param_1 == 1) {
      if ((param_2 == 0) || (lVar1 = FUN_001ef0d0(), -1 < lVar1)) {
        lVar1 = FUN_001eef00(&iStack_8);
        if (lVar1 < 0) {
          iRam0037a298 = 3;
        }
        else if (iStack_8 == 0) {
          iRam0037a298 = 3;
        }
        else {
          lVar1 = FUN_001ef1c0(auStack_4);
          if (lVar1 == 1) {
            iRam0037a298 = 2;
          }
        }
      }
      else {
        iRam0037a298 = 1;
      }
    }
  }
  return iRam0037a298;
}

