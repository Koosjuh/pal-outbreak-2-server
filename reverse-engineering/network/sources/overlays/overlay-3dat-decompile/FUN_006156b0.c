FUNCTION FUN_006156b0 @ 0x006156b0  size=196
CALLERS (0): 
CALLEES (3): FUN_00615670@0x00615670, FUN_00616470@0x00616470, FUN_00616518@0x00616518
----------------------------------------------------------------

long FUN_006156b0(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  long lVar2;
  
  if (param_1 == 0) {
    lVar2 = -0x65;
  }
  else {
    lVar1 = FUN_00616470(param_1,param_2,param_3,1);
    lVar2 = -1;
    if (-1 < lVar1) {
      FUN_00615670();
      uRam0070d248 = *(undefined4 *)param_1;
      lVar2 = func_0x00115c68(0x70d200,0xb,0,0x70d240,0x1000,0x70d240,0x1000,0);
      if (lVar2 < 0) {
        FUN_00616518(lVar1);
      }
      else {
        func_0x00112730(lVar1,param_4);
        lVar2 = lVar1;
      }
    }
  }
  return lVar2;
}



================================================================