FUNCTION FUN_000013a0 @ 0x000013a0 size=124
CALLERS (5): FUN_00001750@0x00001750, FUN_00001ae0@0x00001ae0, FUN_000027e4@0x000027e4, FUN_0000198c@0x0000198c, FUN_000032bc@0x000032bc
CALLEES (3): FUN_00009650@0x00009650, FUN_00009640@0x00009640, FUN_00009720@0x00009720

undefined4 FUN_000013a0(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = FUN_00009650(param_3);
  if (uVar1 < param_2) {
    FUN_00009640(param_1,param_3);
    uVar2 = 0;
  }
  else {
    FUN_00009720("[netcnf] strcpy failed(%d)\n",param_4);
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


================================================================