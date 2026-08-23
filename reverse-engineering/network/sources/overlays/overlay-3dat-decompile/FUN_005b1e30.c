FUNCTION FUN_005b1e30 @ 0x005b1e30  size=80
CALLERS (3): FUN_005b1e80@0x005b1e80, FUN_005b1b10@0x005b1b10, FUN_005b1d20@0x005b1d20
CALLEES (0): 
----------------------------------------------------------------

int FUN_005b1e30(void)

{
  int iVar1;
  
  if (bRam008744f8 < 2) {
    iVar1 = cRam006c4b90 * 0xf + 0x638b40;
  }
  else {
    iVar1 = cRam006c4b90 * 0x10 + 0x638a50;
  }
  return iVar1;
}



================================================================