FUNCTION FUN_00616400 @ 0x00616400  size=112
CALLERS (0): 
CALLEES (0): 
----------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void FUN_00616400(void)

{
  undefined8 uVar1;
  
  func_0x00115300(0);
  uVar1 = func_0x00112790();
  func_0x00115ea0(0x70f318,uVar1);
  func_0x00115f38(0x70f2d0,0xffffffff80001101,0x616318,0x70e2c0,0,0,0x70f318);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



================================================================