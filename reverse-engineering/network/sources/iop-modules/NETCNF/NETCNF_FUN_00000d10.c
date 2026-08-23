FUNCTION FUN_00000d10 @ 0x00000d10 size=152
CALLERS (2): FUN_00000fe4@0x00000fe4, FUN_00000da8@0x00000da8
CALLEES (2): FUN_00009598@0x00009598, FUN_00009744@0x00009744

undefined4 FUN_00000d10(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    DAT_0000ab50 = 0;
    iVar1 = FUN_00009744(&DAT_0000b208,&DAT_0000ab50);
    if ((iVar1 == 1) && (DAT_0000ab50 == 0)) break;
    if (0x13 < iVar2) {
      return 0xfffffff3;
    }
    FUN_00009598(100000);
    iVar2 = iVar2 + 1;
  }
  return 0;
}


================================================================