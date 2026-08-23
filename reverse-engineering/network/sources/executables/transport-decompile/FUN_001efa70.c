
short FUN_001efa70(undefined2 param_1,undefined8 param_2,short param_3)

{
  FUN_001ef3e0();
  if (0x1000 < (int)param_3 + 0x26U) {
    param_3 = 0xfd9;
  }
  FUN_00106b60(0x37bf00,0,0x20);
  uRam0037cf1c = param_1;
  sRam0037cf1e = param_3;
  FUN_001ef400(0x12,0x37cf00,param_3 + 0x26,0x37bf00,param_3 + 0x26);
  FlushCache(0);
  if ((long)param_3 < (long)iRam0037bf18) {
    FUN_00107dc8(0x24e3c0);
  }
  else {
    param_3 = (short)iRam0037bf18;
  }
  if (0 < param_3) {
    FUN_001069a8(param_2,0x37bf20);
  }
  FUN_001ef3f0();
  return param_3;
}

