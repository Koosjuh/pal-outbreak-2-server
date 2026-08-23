
int FUN_001cab70(undefined8 param_1,int param_2)

{
  int iVar1;
  
  if ((iRam003688d0 == 0) && (iRam003688d8 == 0)) {
    FUN_001cac50();
    iVar1 = iRam003688c8;
    if (param_2 <= iRam003688c8) {
      iVar1 = param_2;
    }
    if (0 < iVar1) {
      FUN_001069a8(param_1,0x36a900,iVar1);
    }
    if (iRam003688c8 != iVar1) {
      FUN_00106a58(0x36a900,iVar1 + 0x36a900);
    }
    iRam003688c8 = iRam003688c8 - iVar1;
    DAT_00248850 = iRam003688c8 + 0x36a900;
    FUN_001cac60();
  }
  else {
    iVar1 = -0x10;
  }
  return iVar1;
}

