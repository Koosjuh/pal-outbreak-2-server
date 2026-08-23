FUNCTION FUN_005c7290 @ 0x005c7290  size=64
CALLERS (1): FUN_005c7210@0x005c7210
CALLEES (0): 
----------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void FUN_005c7290(int param_1)

{
  *(char *)(param_1 + 0x20) = *(char *)(param_1 + 0x20) + '\x01';
  *(undefined4 *)(param_1 + 8) = 1;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined1 *)(param_1 + 0x25) = 0;
  uRam006ff2a4 = 0;
  uRam006ff2a6 = 0;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



================================================================