FUNCTION FUN_005d7540 @ 0x005d7540  size=324
CALLERS (4): FUN_005d3930@0x005d3930, FUN_005d47f0@0x005d47f0, FUN_005d5900@0x005d5900, FUN_005d5640@0x005d5640
CALLEES (1): FUN_005dfa90@0x005dfa90
----------------------------------------------------------------

int FUN_005d7540(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  ulong uVar4;
  int iVar5;
  int iVar6;
  
  lVar2 = func_0x0010a050(iRam00701068 + 0x4bf5c);
  uVar3 = func_0x0010a050(param_1);
  uVar4 = func_0x0010a050(param_2);
  iVar1 = (int)lVar2;
  if ((int)uVar4 + iVar1 + (int)uVar3 + 2 < 0x1000) {
    if ((uVar4 < 0x100) && (uVar3 < 0x100)) {
      iVar5 = 0;
      if (lVar2 != 0) {
        iVar5 = iVar1 + 1;
        *(undefined1 *)(iVar1 + iRam00701068 + 0x4bf5c) = 0x26;
      }
      func_0x001069a8(iRam00701068 + iVar5 + 0x4bf5c,param_1,uVar3);
      iVar5 = iVar5 + (int)uVar3;
      iVar6 = iVar5 + 1;
      *(undefined1 *)(iVar5 + iRam00701068 + 0x4bf5c) = 0x3d;
      iVar1 = FUN_005dfa90(iRam00701068 + iVar6 + 0x4bf5c,param_2);
      iVar6 = iVar6 + iVar1;
    }
    else {
      iVar6 = -1;
    }
  }
  else {
    iVar6 = -1;
  }
  return iVar6;
}



================================================================