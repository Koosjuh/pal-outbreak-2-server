FUNCTION FUN_00001560 @ 0x00001560 size=160
CALLERS (4): FUN_00001750@0x00001750, FUN_000020f4@0x000020f4, FUN_000027e4@0x000027e4, FUN_000032bc@0x000032bc
CALLEES (4): FUN_00009650@0x00009650, FUN_00009640@0x00009640, FUN_00009628@0x00009628, FUN_00009720@0x00009720

undefined4 FUN_00001560(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_00009650(param_3);
  iVar2 = FUN_00009650(param_4);
  if ((uint)(iVar1 + iVar2) < param_2) {
    FUN_00009640(param_1,param_3);
    FUN_00009628(param_1,param_4);
    uVar3 = 0;
  }
  else {
    FUN_00009720("[netcnf] make_name failed\n");
    uVar3 = 0xffffffff;
  }
  return uVar3;
}


================================================================