FUNCTION FUN_0000141c @ 0x0000141c size=144
CALLERS (3): FUN_00003c4c@0x00003c4c, FUN_00001ae0@0x00001ae0, FUN_000032bc@0x000032bc
CALLEES (3): FUN_00009650@0x00009650, FUN_00009628@0x00009628, FUN_00009720@0x00009720

undefined4 FUN_0000141c(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_00009650();
  iVar2 = FUN_00009650(param_3);
  if ((uint)(iVar1 + iVar2) < param_2) {
    FUN_00009628(param_1,param_3);
    uVar3 = 0;
  }
  else {
    FUN_00009720("[netcnf] strcat failed(%d)\n",param_4);
    uVar3 = 0xffffffff;
  }
  return uVar3;
}


================================================================