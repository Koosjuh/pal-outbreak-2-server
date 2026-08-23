FUNCTION FUN_0000d5e0 @ 0x0000d5e0 size=80
CALLERS (2): FUN_000114dc@0x000114dc, FUN_0000d658@0x0000d658
CALLEES (2): FUN_00011d90@0x00011d90, FUN_00019a84@0x00019a84

int FUN_0000d5e0(void)

{
  int iVar1;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_18 = 0;
  local_10 = 0;
  local_14 = 0;
  iVar1 = FUN_00019a84(&local_18);
  if (iVar1 < 1) {
    FUN_00011d90("inet: CreateEventFlag (%d)\n",iVar1);
  }
  return iVar1;
}


================================================================