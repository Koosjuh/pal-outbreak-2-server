FUNCTION FUN_00009330 @ 0x00009330 size=72
CALLERS (2): FUN_00001cdc@0x00001cdc, FUN_00009378@0x00009378
CALLEES (2): FUN_000096dc@0x000096dc, FUN_00009720@0x00009720

undefined4 FUN_00009330(void)

{
  undefined4 uVar1;
  
  if (DAT_0000afd0 == 0) {
    uVar1 = FUN_000096dc();
  }
  else {
    FUN_00009720("[err] netcnf getstat()\n");
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


================================================================