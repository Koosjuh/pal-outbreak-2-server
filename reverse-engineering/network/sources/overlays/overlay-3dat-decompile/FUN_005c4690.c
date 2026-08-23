FUNCTION FUN_005c4690 @ 0x005c4690  size=136
CALLERS (1): FUN_00606520@0x00606520
CALLEES (0): 
----------------------------------------------------------------

void FUN_005c4690(undefined4 *param_1,ushort *param_2)

{
  uint uVar1;
  
  *param_1 = CONCAT13(uRam006fb74d,CONCAT12(uRam006fb74c,CONCAT11(uRam006fb74b,uRam006fb74a)));
  uVar1 = (uint)bRam006fb753 + (uint)bRam006fb752 * 0x100 & 0xffff;
  *param_2 = (ushort)(uVar1 << 8) | (ushort)(uVar1 >> 8);
  return;
}



================================================================