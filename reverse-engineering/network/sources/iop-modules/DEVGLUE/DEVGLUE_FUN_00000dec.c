FUNCTION FUN_00000dec @ 0x00000dec size=84
CALLERS (0): 
CALLEES (3): FUN_00004cdc@0x00004cdc, FUN_000028b8@0x000028b8, FUN_00007cf4@0x00007cf4

bool FUN_00000dec(void)

{
  short sVar1;
  int iVar2;
  
  if (DAT_000096d4 == 0) {
    iVar2 = FUN_000028b8(DAT_00009708);
  }
  else {
    sVar1 = FUN_00007cf4();
    iVar2 = FUN_00004cdc((int)sVar1);
  }
  return iVar2 != 0;
}


================================================================