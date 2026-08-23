
undefined2 FUN_001f0df0(undefined8 param_1,long param_2)

{
  int iVar1;
  undefined2 uVar2;
  
  FUN_001ef3e0();
  uVar2 = 0xffff;
  if (param_2 < 5) {
    uRam0037cf1c = (undefined4)param_2;
    FUN_001ef400(0x4e,0x37cf00,0xc54,0x37bf00,0xc54);
    iVar1 = iRam0037bf18;
    if (iRam0037bf18 < 0) {
      uVar2 = 0xffff;
    }
    else {
      FUN_001069a8(param_1,0x37bf20,iRam0037bf18 * 0x30c);
      FUN_001ef3f0();
      uVar2 = (undefined2)iVar1;
    }
  }
  return uVar2;
}

