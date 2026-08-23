FUNCTION FUN_00000b04 @ 0x00000b04 size=236
CALLERS (0): 
CALLEES (5): FUN_000059d0@0x000059d0, FUN_00005798@0x00005798, FUN_00005ba0@0x00005ba0, FUN_000081bc@0x000081bc, FUN_0000129c@0x0000129c

void FUN_00000b04(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  if (DAT_000096d4 == 0) {
    FUN_0000129c(DAT_00009708);
  }
  else if (-1 < DAT_000096d0) {
    iVar3 = 0;
    FUN_00005798();
    while( true ) {
      FUN_000081bc(10000);
      iVar2 = FUN_000059d0(0,0,0);
      if (iVar2 << 0x10 < 0) break;
      sVar1 = FUN_00005ba0((int)DAT_000096d0);
      iVar3 = iVar3 + 1;
      if ((sVar1 == -1) || (299 < iVar3)) break;
    }
    sVar1 = FUN_00005ba0((int)DAT_000096d0);
    if (sVar1 != -1) {
      FUN_00005798((int)DAT_000096d0);
    }
    DAT_000096d0 = -1;
  }
  return;
}


================================================================