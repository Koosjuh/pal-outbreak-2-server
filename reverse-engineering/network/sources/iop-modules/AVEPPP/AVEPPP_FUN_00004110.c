FUNCTION FUN_00004110 @ 0x00004110 size=144
CALLERS (2): FUN_00009044@0x00009044, FUN_0000402c@0x0000402c
CALLEES (2): FUN_00003b50@0x00003b50, FUN_00003bb4@0x00003bb4

int FUN_00004110(undefined4 param_1,undefined4 param_2,undefined2 param_3,undefined4 param_4)

{
  short sVar1;
  int iVar2;
  undefined1 local_10;
  undefined1 local_f;
  undefined2 local_e;
  
  if (DAT_00014990 == '\0') {
    iVar2 = -1;
    DAT_00014a7c = DAT_00014a7c + 1;
  }
  else {
    local_10 = 0xff;
    local_f = 3;
    local_e = param_3;
    iVar2 = FUN_00003b50(&local_10,param_4);
    if (iVar2 == 0) {
      iVar2 = -1;
      DAT_00014a7e = DAT_00014a7e + 1;
    }
    else {
      sVar1 = FUN_00003bb4(iVar2);
      iVar2 = (int)sVar1;
    }
  }
  return iVar2;
}


================================================================