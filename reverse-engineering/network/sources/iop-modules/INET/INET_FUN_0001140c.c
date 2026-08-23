FUNCTION FUN_0001140c @ 0x0001140c size=92
CALLERS (0): 
CALLEES (3): FUN_0000d3d4@0x0000d3d4, FUN_0000d9ac@0x0000d9ac, FUN_0000d41c@0x0000d41c

int FUN_0001140c(void)

{
  int iVar1;
  
  iVar1 = FUN_0000d3d4();
  if (iVar1 == 0) {
    iVar1 = FUN_0000d9ac(&DAT_0001b308);
    FUN_0000d41c();
  }
  return iVar1;
}


================================================================