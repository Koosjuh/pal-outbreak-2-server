FUNCTION FUN_00008470 @ 0x00008470 size=116
CALLERS (2): FUN_000084e4@0x000084e4, FUN_000088ac@0x000088ac
CALLEES (2): FUN_00009630@0x00009630, FUN_00009658@0x00009658

undefined4 FUN_00008470(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = FUN_00009658(param_1,"aolnet/",7);
  uVar2 = 0;
  if (iVar1 == 0) {
    iVar1 = 0;
    while( true ) {
      iVar3 = FUN_00009630(param_1,0x2e);
      param_1 = iVar3 + 1;
      if (iVar3 == 0) break;
      iVar1 = iVar1 + 1;
    }
    uVar2 = 0xffffffec;
    if (iVar1 != 5) {
      uVar2 = 0;
    }
  }
  return uVar2;
}


================================================================