FUNCTION FUN_000014ac @ 0x000014ac size=180
CALLERS (3): FUN_00003c4c@0x00003c4c, FUN_00001cdc@0x00001cdc, FUN_00001a28@0x00001a28
CALLEES (4): FUN_00009650@0x00009650, FUN_00009640@0x00009640, FUN_00009628@0x00009628, FUN_00009720@0x00009720

undefined4 FUN_000014ac(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_00009650(param_3);
  iVar2 = FUN_00009650(param_4);
  if ((uint)(iVar1 + iVar2 + 1) < param_2) {
    FUN_00009640(param_1,param_3);
    FUN_00009628(param_1,&DAT_00009938);
    FUN_00009628(param_1,param_4);
    uVar3 = 0;
  }
  else {
    FUN_00009720("[netcnf] make_pathname failed\n");
    uVar3 = 0xffffffff;
  }
  return uVar3;
}


================================================================