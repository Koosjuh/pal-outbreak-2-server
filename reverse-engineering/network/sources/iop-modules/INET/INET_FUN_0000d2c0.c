FUNCTION FUN_0000d2c0 @ 0x0000d2c0 size=92
CALLERS (17): FUN_0000e594@0x0000e594, FUN_0000e428@0x0000e428, FUN_00010dd4@0x00010dd4, FUN_00010c40@0x00010c40, FUN_0000e4e8@0x0000e4e8, FUN_0000e1c8@0x0000e1c8, FUN_00010bd0@0x00010bd0, FUN_0001104c@0x0001104c, FUN_0001804c@0x0001804c, FUN_0000da44@0x0000da44, FUN_00006fa0@0x00006fa0, FUN_00011794@0x00011794, FUN_000114dc@0x000114dc, FUN_00011d20@0x00011d20, FUN_00010cc0@0x00010cc0, FUN_0000e6ac@0x0000e6ac, FUN_0000e770@0x0000e770
CALLEES (3): FUN_00011d90@0x00011d90, FUN_00019a28@0x00019a28, FUN_00019a30@0x00019a30

int FUN_0000d2c0(void)

{
  int iVar1;
  undefined1 auStack_50 [32];
  int local_30;
  
  iVar1 = FUN_00019a30(0,auStack_50);
  if (iVar1 == 0) {
    FUN_00019a28(0,1);
  }
  else {
    FUN_00011d90("inet: ReferThreadStatus (%d)\n",iVar1);
    local_30 = iVar1;
  }
  return local_30;
}


================================================================