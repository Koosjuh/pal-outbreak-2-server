
undefined8 FUN_001f22a0(undefined4 param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  uVar1 = 0xffffffffffffffff;
  if (DAT_0024e430 != -1) {
    WaitSema();
    lVar2 = FUN_00115c68(0x37e9e0,1,1,0x37ea40,0x10,0x37ea80,0x90,0x1f2868);
    if (lVar2 == 0) {
      uVar1 = 0;
      uRam0037e9d0 = 1;
      uRam0037e9d8 = param_1;
    }
    else {
      FUN_00114ac8(0x25a8a8,lVar2);
      uVar1 = 0xfffffffffffffffe;
    }
  }
  return uVar1;
}

