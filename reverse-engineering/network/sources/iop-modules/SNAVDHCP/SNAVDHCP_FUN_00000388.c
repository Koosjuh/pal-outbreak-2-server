FUNCTION FUN_00000388 @ 0x00000388 size=108
CALLERS (0): 
CALLEES (3): FUN_00002d5c@0x00002d5c, FUN_000002d4@0x000002d4, FUN_00002d38@0x00002d38

undefined4 FUN_00000388(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00002d38(0);
  uVar2 = 1;
  if (iVar1 == 0) {
    FUN_00002d5c("AVE-DHCP version 0x%04x (%s)\n",0x104,"2001/10/15");
    iVar1 = FUN_000002d4();
    uVar2 = 0;
    if (iVar1 << 0x10 < 0) {
      FUN_00002d5c("AVE-DHCP internal error. NO_RESIDENT_END\n");
      uVar2 = 1;
    }
  }
  return uVar2;
}


================================================================