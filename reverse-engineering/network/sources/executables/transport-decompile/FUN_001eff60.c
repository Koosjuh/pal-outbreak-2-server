
short FUN_001eff60(undefined2 param_1,ushort param_2,undefined4 param_3,undefined2 param_4,
                  undefined8 param_5)

{
  short sVar1;
  
  FUN_001ef3e0();
  if (((short)param_2 < 1) || (0x1000 < (short)param_2)) {
    sVar1 = 0;
  }
  else {
    uRam0037cf1e = 4 - (param_2 & 3) & 3;
    uRam0037cf1c = param_1;
    uRam0037cf20 = param_3;
    uRam0037cf24 = param_4;
    uRam0037cf26 = param_2;
    FUN_001069a8(0x37cf28,param_5,param_2);
    FUN_001ef400(0x19,0x37cf00,(short)param_2 + 0x30,0x37bf00,0x20);
    sVar1 = sRam0037bf18;
    FUN_001ef3f0();
    if (sVar1 < 0) {
      FUN_00107dc8(0x24e3f0);
      sVar1 = 0;
    }
  }
  return sVar1;
}

