FUNCTION FUN_00000d2c @ 0x00000d2c size=132
CALLERS (0): 
CALLEES (3): FUN_000059d0@0x000059d0, FUN_00002840@0x00002840, FUN_00005ba0@0x00005ba0

bool FUN_00000d2c(void)

{
  bool bVar1;
  short sVar2;
  int iVar3;
  
  if (DAT_000096d4 == 0) {
    iVar3 = FUN_00002840(DAT_00009708);
    bVar1 = iVar3 != 0;
  }
  else if (DAT_000096d0 < 0) {
    bVar1 = false;
  }
  else {
    FUN_000059d0(0,0,0);
    sVar2 = FUN_00005ba0((int)DAT_000096d0);
    bVar1 = sVar2 == 4;
  }
  return bVar1;
}


================================================================