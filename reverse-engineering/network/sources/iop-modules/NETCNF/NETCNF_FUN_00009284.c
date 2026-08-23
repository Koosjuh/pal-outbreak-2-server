FUNCTION FUN_00009284 @ 0x00009284 size=72
CALLERS (2): FUN_00001cdc@0x00001cdc, FUN_00003c4c@0x00003c4c
CALLEES (2): FUN_000096cc@0x000096cc, FUN_00009720@0x00009720

undefined4 FUN_00009284(void)

{
  undefined4 uVar1;
  
  if (DAT_0000afd0 == 0) {
    uVar1 = FUN_000096cc();
  }
  else {
    FUN_00009720("[err] netcnf dclose()\n");
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


================================================================