FUNCTION FUN_00009180 @ 0x00009180 size=72
CALLERS (3): FUN_00001cdc@0x00001cdc, FUN_00003c4c@0x00003c4c, FUN_00002220@0x00002220
CALLEES (2): FUN_000096ac@0x000096ac, FUN_00009720@0x00009720

undefined4 FUN_00009180(void)

{
  undefined4 uVar1;
  
  if (DAT_0000afd0 == 0) {
    uVar1 = FUN_000096ac();
  }
  else {
    FUN_00009720("[err] netcnf remove()\n");
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


================================================================