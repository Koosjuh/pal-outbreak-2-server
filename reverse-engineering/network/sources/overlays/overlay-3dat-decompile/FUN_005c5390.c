FUNCTION FUN_005c5390 @ 0x005c5390  size=208
CALLERS (1): FUN_005c5610@0x005c5610
CALLEES (0): 
----------------------------------------------------------------

void FUN_005c5390(ushort param_1)

{
  int iVar1;
  
  iVar1 = param_1 - 1;
  func_0x00106b60(iVar1 * 0x24 + 0x6fee6c,0,0x24);
  func_0x00106b60(iVar1 * 0x144 + 0x6cfb58,0,0x144);
  iVar1 = (uint)param_1 * 0x144;
  *(undefined1 *)(iVar1 + 0x6cfa30) = 1;
  *(ushort *)(iVar1 + 0x6cfa1c) = param_1;
  return;
}



================================================================