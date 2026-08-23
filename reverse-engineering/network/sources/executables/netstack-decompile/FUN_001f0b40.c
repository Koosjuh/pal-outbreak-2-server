
undefined2 FUN_001f0b40(long param_1,undefined4 param_2,undefined4 param_3)

{
  undefined2 uVar1;
  
  FUN_001ef3e0();
  if (param_1 == 0) {
    uRam0037cf1c = 0;
  }
  else {
    FUN_00109eb8(0x37cf1c,param_1);
  }
  uRam0037d01c = param_2;
  uRam0037d020 = param_3;
  FUN_001ef400(0x38,0x37cf00,0x128,0x37bf00,0x20);
  uVar1 = uRam0037bf18;
  FUN_001ef3f0();
  return uVar1;
}

