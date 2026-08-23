FUNCTION FUN_006149f0 @ 0x006149f0  size=224
CALLERS (1): FUN_00610830@0x00610830
CALLEES (2): FUN_006345e0@0x006345e0, FUN_006371d0@0x006371d0
----------------------------------------------------------------

void FUN_006149f0(int param_1,undefined8 param_2)

{
  int iVar1;
  
  iVar1 = iRam0070d1c0 + 0x58;
  func_0x00106b60(iVar1,0,0x200);
  *(int *)(iRam0070d1c0 + 0x54) = (int)param_2;
  func_0x00109eb8(iVar1,param_2);
  FUN_006371d0(0x42840000,300);
  if (param_1 == 2) {
    FUN_006345e0(0,10,0xff,param_2);
  }
  else if (param_1 == 1) {
    FUN_006345e0(0,9,0xff,param_2);
  }
  else if (param_1 == 0) {
    FUN_006345e0(0,8,0xff,param_2);
  }
  return;
}



================================================================