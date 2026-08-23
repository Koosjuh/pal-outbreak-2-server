FUNCTION FUN_00011314 @ 0x00011314 size=92
CALLERS (0): 
CALLEES (3): FUN_0000d8cc@0x0000d8cc, FUN_0000d3d4@0x0000d3d4, FUN_0000d41c@0x0000d41c

int FUN_00011314(void)

{
  int iVar1;
  
  iVar1 = FUN_0000d3d4();
  if (iVar1 == 0) {
    iVar1 = FUN_0000d8cc(&DAT_0001b300);
    FUN_0000d41c();
  }
  return iVar1;
}


================================================================