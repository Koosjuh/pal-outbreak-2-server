FUNCTION FUN_005fa820 @ 0x005fa820  size=100
CALLERS (1): FUN_005adcd0@0x005adcd0
CALLEES (0): 
----------------------------------------------------------------

uint FUN_005fa820(int param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    uVar1 = (uint)*(ushort *)(iVar2 * 0xc + 0x3c4d50);
    if (uVar1 == 999) {
      return 999;
    }
    if (param_1 - 1U == uVar1) break;
    iVar2 = iVar2 + 1;
  }
  return (uint)*(byte *)(iVar2 * 0xc + 0x3c4d52);
}



================================================================