
undefined2 FUN_001ef8d0(undefined2 param_1,undefined8 param_2,short param_3)

{
  undefined2 uVar1;
  
  FUN_001ef3e0();
  if (param_3 < 1) {
    uVar1 = 0;
  }
  else {
    if (0xc00 < param_3) {
      param_3 = 0xc00;
    }
    uRam0037cf1c = param_1;
    sRam0037cf1e = param_3;
    FUN_001069a8(0x37cf20,param_2,param_3);
    FUN_001ef400(0xf,0x37cf00,param_3 + 0x26,0x37bf00,param_3 + 0x26);
    uVar1 = uRam0037bf18;
    FUN_001ef3f0();
  }
  return uVar1;
}

