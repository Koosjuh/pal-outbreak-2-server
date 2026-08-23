FUNCTION FUN_000090f0 @ 0x000090f0 size=72
CALLERS (2): FUN_00001cdc@0x00001cdc, FUN_00003c4c@0x00003c4c
CALLEES (2): FUN_000096c4@0x000096c4, FUN_00009720@0x00009720

undefined4 FUN_000090f0(void)

{
  undefined4 uVar1;
  
  if (DAT_0000afd0 == 0) {
    uVar1 = FUN_000096c4();
  }
  else {
    FUN_00009720("[err] netcnf dopen()\n");
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


================================================================