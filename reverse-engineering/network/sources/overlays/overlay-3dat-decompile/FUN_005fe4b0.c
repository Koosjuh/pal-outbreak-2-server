FUNCTION FUN_005fe4b0 @ 0x005fe4b0  size=80
CALLERS (7): FUN_005fd9e0@0x005fd9e0, FUN_00605790@0x00605790, FUN_0062f5b0@0x0062f5b0, FUN_005fcc70@0x005fcc70, FUN_00602340@0x00602340, FUN_00617c30@0x00617c30, FUN_00601d50@0x00601d50
CALLEES (0): 
----------------------------------------------------------------

int FUN_005fe4b0(int param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = 0;
  while( true ) {
    uVar2 = (uint)*(ushort *)(iVar1 * 0xc + 0x3c4d50);
    if (uVar2 == 999) {
      return -1;
    }
    if (param_1 - 1U == uVar2) break;
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}



================================================================