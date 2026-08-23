FUNCTION FUN_0000d464 @ 0x0000d464 size=164
CALLERS (2): FUN_000114dc@0x000114dc, FUN_00012170@0x00012170
CALLEES (4): FUN_00019a08@0x00019a08, FUN_00019a00@0x00019a00, FUN_00011d90@0x00011d90, FUN_00019a10@0x00019a10

int FUN_0000d464(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  local_28 = 0x2000000;
  local_24 = 0;
  local_18 = DAT_0001b848;
  local_1c = DAT_0001b84c;
  local_20 = param_1;
  iVar1 = FUN_00019a00(&local_28);
  if (iVar1 < 1) {
    FUN_00011d90("inet: CreateThread (%d)\n",iVar1);
  }
  else {
    iVar2 = FUN_00019a10(iVar1,param_2);
    if (iVar2 != 0) {
      FUN_00011d90("inet: StartThread (%d)\n",iVar2);
      FUN_00019a08(iVar1);
      iVar1 = iVar2;
    }
  }
  return iVar1;
}


================================================================