FUNCTION FUN_005f5ea0 @ 0x005f5ea0  size=28
CALLERS (2): FUN_005ff1b0@0x005ff1b0, FUN_005f7f30@0x005f7f30
CALLEES (0): 
----------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void FUN_005f5ea0(int param_1)

{
  *(undefined1 *)(param_1 + 1) = 10;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



================================================================