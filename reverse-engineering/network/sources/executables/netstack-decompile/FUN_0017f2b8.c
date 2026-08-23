
undefined4 FUN_0017f2b8(int param_1)

{
  undefined4 uVar1;
  long lVar2;
  
  FUN_00113198(0x27e480,0x27e500);
  FUN_0011b8e0();
  uRam0027e500 = uRam0027e480;
  uRam0027e508 = uRam0027e488;
  uRam0027e510 = uRam0027e490;
  uRam0027e518 = uRam0027e498;
  uRam0027e520 = uRam0027e4a0;
  uRam0027e528 = uRam0027e4a8;
  uRam0027e530 = uRam0027e4b0;
  uRam0027e538 = uRam0027e4b8;
  FUN_0011b938();
  uVar1 = 0xfffffff4;
  if ((*(int *)(param_1 * 4 + 0x27e500) == 1) &&
     (iRam0027b000 = param_1,
     lVar2 = FUN_00115c68(0x27af88,0xffffffff80001303,0,0x27b000,0x280,0x27b000,0x280,0),
     uVar1 = uRam0027b004, lVar2 < 0)) {
    FUN_0017fd00(0x258ab8);
    uVar1 = 0;
  }
  return uVar1;
}

