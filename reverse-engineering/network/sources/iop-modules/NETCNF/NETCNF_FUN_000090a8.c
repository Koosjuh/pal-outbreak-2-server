FUNCTION FUN_000090a8 @ 0x000090a8 size=72
CALLERS (5): FUN_000020f4@0x000020f4, FUN_00007974@0x00007974, FUN_000018b0@0x000018b0, FUN_000027e4@0x000027e4, FUN_00000fe4@0x00000fe4
CALLEES (2): FUN_0000969c@0x0000969c, FUN_00009720@0x00009720

undefined4 FUN_000090a8(void)

{
  undefined4 uVar1;
  
  if (DAT_0000afd0 == 0) {
    uVar1 = FUN_0000969c();
  }
  else {
    FUN_00009720("[err] netcnf write()\n");
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


================================================================