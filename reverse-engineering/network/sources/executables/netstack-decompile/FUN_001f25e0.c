
undefined8 FUN_001f25e0(int param_1,ulong param_2)

{
  undefined8 uVar1;
  long lVar2;
  
  uVar1 = 0xffffffffffffffff;
  if (DAT_0024e430 != -1) {
    if (param_1 < iRam0037e940) {
      if (param_2 < 3) {
        *(int *)(param_1 * 0x38 + iRam0037e944) = (int)param_2;
        uRam0037ea40 = (undefined1)param_1;
        uRam0037ea41 = (undefined1)param_2;
        WaitSema();
        lVar2 = FUN_00115c68(0x37e9e0,5,1,0x37ea40,0x10,0x37ea80,0x10,0x1f2868);
        if (lVar2 == 0) {
          uRam0037e9d0 = 5;
          uRam0037e9d8 = 0;
          uVar1 = 0;
          iRam0037e9d4 = param_1;
        }
        else {
          FUN_00114ac8(0x25a958,lVar2);
          uVar1 = 0xfffffffffffffffe;
        }
      }
      else {
        uVar1 = 0xfffffffffffffff4;
      }
    }
    else {
      uVar1 = 0xfffffffffffffff5;
    }
  }
  return uVar1;
}

