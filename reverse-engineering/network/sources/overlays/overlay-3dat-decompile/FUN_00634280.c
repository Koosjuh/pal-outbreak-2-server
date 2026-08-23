FUNCTION FUN_00634280 @ 0x00634280  size=132
CALLERS (1): FUN_006320f0@0x006320f0
CALLEES (2): FUN_00637d10@0x00637d10, FUN_00637e90@0x00637e90
----------------------------------------------------------------

short FUN_00634280(int param_1)

{
  short sVar1;
  long lVar2;
  short sVar3;
  uint uVar4;
  undefined1 auStack_2 [2];
  
  sVar3 = 0;
  uVar4 = 0;
  lVar2 = FUN_00637e90();
  if (lVar2 == 0) {
    sVar3 = 0;
  }
  else {
    for (; sVar1 = *(short *)(param_1 + uVar4 * 2), sVar1 != 0; uVar4 = uVar4 + 1 & 0xffff) {
      sVar1 = FUN_00637d10(sVar1,auStack_2);
      sVar3 = sVar3 + sVar1;
    }
  }
  return sVar3;
}



================================================================