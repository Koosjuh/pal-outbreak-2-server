FUNCTION FUN_00618210 @ 0x00618210  size=20
CALLERS (2): FUN_006101d0@0x006101d0, FUN_00610830@0x00610830
CALLEES (0): 
----------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void FUN_00618210(undefined1 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[4] = 0;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



================================================================