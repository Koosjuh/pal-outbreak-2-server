FUNCTION FUN_00606ea0 @ 0x00606ea0  size=104
CALLERS (3): FUN_005ac610@0x005ac610, FUN_00606e40@0x00606e40, FUN_005ac6f0@0x005ac6f0
CALLEES (0): 
----------------------------------------------------------------

void FUN_00606ea0(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  func_0x00106b60(uRam003435d4,0,0x8000);
  iVar2 = 0;
  iVar1 = 0;
  uVar3 = uRam003435d4;
  do {
    *(uint *)(iVar1 + 0x6c5480) = uVar3;
    iVar2 = iVar2 + 1;
    uVar3 = uVar3 + 0x17bb & 0xffffffc0;
    iVar1 = iVar2 * 4;
  } while (iVar2 < 3);
  return;
}



================================================================