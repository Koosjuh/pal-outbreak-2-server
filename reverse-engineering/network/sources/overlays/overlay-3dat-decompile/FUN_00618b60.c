FUNCTION FUN_00618b60 @ 0x00618b60  size=60
CALLERS (63): FUN_005fc850@0x005fc850, FUN_00606fc0@0x00606fc0, FUN_00617030@0x00617030, FUN_005b25c0@0x005b25c0, FUN_005f6d20@0x005f6d20, FUN_005f62e0@0x005f62e0, FUN_005fe800@0x005fe800, FUN_00629a40@0x00629a40, FUN_006020e0@0x006020e0, FUN_005b3ed0@0x005b3ed0, FUN_00603e40@0x00603e40, FUN_00607260@0x00607260, ...
CALLEES (0): 
----------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void FUN_00618b60(void)

{
  uRam006c5538 = 0;
  uRam006c4fce = 0;
  uRam006c4fd7 = 1;
  uRam006c4fcd = 0xff;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



================================================================