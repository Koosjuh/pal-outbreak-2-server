FUNCTION FUN_00009138 @ 0x00009138 size=72
CALLERS (2): FUN_00001cdc@0x00001cdc, FUN_00003c4c@0x00003c4c
CALLEES (2): FUN_000096d4@0x000096d4, FUN_00009720@0x00009720

undefined4 FUN_00009138(void)

{
  undefined4 uVar1;
  
  if (DAT_0000afd0 == 0) {
    uVar1 = FUN_000096d4();
  }
  else {
    FUN_00009720("[err] netcnf dread()\n");
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


================================================================