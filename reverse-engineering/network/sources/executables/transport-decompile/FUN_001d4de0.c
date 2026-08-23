
undefined4 FUN_001d4de0(int param_1)

{
  undefined4 uVar1;
  
  if ((param_1 == 1) && (DAT_0025b78c != (undefined4 *)0x0)) {
    FUN_001e3f98(*DAT_0025b78c);
    FUN_001e1dd0();
    DAT_0025b78c = (undefined4 *)0x0;
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

