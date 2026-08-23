FUNCTION FUN_00634310 @ 0x00634310  size=148
CALLERS (1): FUN_006320f0@0x006320f0
CALLEES (2): FUN_00637d10@0x00637d10, FUN_00637e90@0x00637e90
----------------------------------------------------------------

uint FUN_00634310(int param_1)

{
  short sVar1;
  long lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined1 auStack_2 [2];
  
  uVar5 = 0;
  uVar4 = 0;
  lVar2 = FUN_00637e90();
  if (lVar2 == 0) {
    uVar5 = 0;
  }
  else {
    for (; sVar1 = *(short *)(param_1 + uVar4 * 2), sVar1 != 0; uVar4 = uVar4 + 1 & 0xffff) {
      lVar2 = FUN_00637d10(sVar1,auStack_2);
      uVar3 = (uint)lVar2 & 0xffff;
      if (lVar2 == 1) {
        uVar3 = 2;
      }
      uVar5 = uVar5 + uVar3 & 0xffff;
    }
  }
  return uVar5;
}



================================================================