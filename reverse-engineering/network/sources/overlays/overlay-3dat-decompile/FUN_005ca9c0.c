FUNCTION FUN_005ca9c0 @ 0x005ca9c0  size=332
CALLERS (1): FUN_005cab10@0x005cab10
CALLEES (0): 
----------------------------------------------------------------

uint FUN_005ca9c0(uint param_1,ulong param_2)

{
  int iVar1;
  uint uVar2;
  
  if (param_1 == 0) {
    param_1 = 1;
  }
  param_1 = param_1 | 0xff000000;
  for (uVar2 = 0; uVar2 < 0x10; uVar2 = uVar2 + 1 & 0xff) {
    iVar1 = iRam00701068 + uVar2 * 8;
    if ((*(uint *)(iVar1 + 0x68f98) == param_1) &&
       ((ulong)*(byte *)(iVar1 + 0x68f95) == (param_2 & 0xff))) {
      return uVar2;
    }
  }
  uVar2 = 2;
  while( true ) {
    if (0xf < uVar2) {
      return 1;
    }
    iVar1 = uVar2 * 8;
    if (*(char *)(iRam00701068 + iVar1 + 0x68f94) == '\0') break;
    uVar2 = uVar2 + 1 & 0xff;
  }
  *(undefined1 *)(iRam00701068 + iVar1 + 0x68f94) = 1;
  *(uint *)(iVar1 + iRam00701068 + 0x68f98) = param_1;
  *(char *)(iVar1 + iRam00701068 + 0x68f95) = (char)param_2;
  if (param_2 != 0) {
    func_0x001af010(uVar2 + 0xd,0,param_1,param_1,param_1);
    return uVar2;
  }
  func_0x001af010(uVar2 + 0xd,0,0xffffffffff000000,param_1,param_1);
  return uVar2;
}



================================================================