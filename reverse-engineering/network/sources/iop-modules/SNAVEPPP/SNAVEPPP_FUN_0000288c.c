FUNCTION FUN_0000288c @ 0x0000288c size=100
CALLERS (2): FUN_00010848@0x00010848, FUN_00002b68@0x00002b68
CALLEES (1): FUN_00010c38@0x00010c38

undefined2 * FUN_0000288c(void)

{
  undefined2 *puVar1;
  
  if (DAT_00012efc != 0) {
    FUN_00010c38("ave-ppp %s:","PP_getDriverEntry");
    FUN_00010c38("called.\n",0);
  }
  puVar1 = (undefined2 *)0x0;
  if (DAT_000131f0 != 0) {
    puVar1 = &DAT_00012fb8;
  }
  return puVar1;
}


================================================================