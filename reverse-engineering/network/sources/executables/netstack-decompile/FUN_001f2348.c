
undefined8 FUN_001f2348(uint param_1,undefined4 param_2)

{
  undefined8 uVar1;
  long lVar2;
  
  uVar1 = 0xffffffffffffffff;
  if (DAT_0024e430 != -1) {
    if (param_1 < uRam0037e940) {
      uRam0037ea40 = (undefined1)param_1;
      WaitSema();
      lVar2 = FUN_00115c68(0x37e9e0,2,1,0x37ea40,0x10,0x37ea80,0x50,0x1f2868);
      if (lVar2 == 0) {
        uRam0037e9d0 = 2;
        uVar1 = 0;
        uRam0037e9d4 = param_1;
        uRam0037e9d8 = param_2;
      }
      else {
        FUN_00114ac8(0x25a8d0,lVar2);
        uVar1 = 0xfffffffffffffffe;
      }
    }
    else {
      uVar1 = 0xfffffffffffffff5;
    }
  }
  return uVar1;
}

