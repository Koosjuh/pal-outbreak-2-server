
short FUN_001efcf0(undefined2 param_1,undefined2 *param_2,undefined4 *param_3,undefined2 *param_4)

{
  short sVar1;
  
  FUN_001ef3e0();
  uRam0037cf1c = param_1;
  FUN_001ef400(0x16,0x37cf00,0x22,0x37bf00,0x2c);
  sVar1 = sRam0037bf18;
  if (sRam0037bf18 == 0) {
    *param_2 = uRam0037bf1e;
    *param_3 = uRam0037bf20;
    *param_4 = uRam0037bf24;
  }
  FUN_001ef3f0();
  return sVar1;
}

