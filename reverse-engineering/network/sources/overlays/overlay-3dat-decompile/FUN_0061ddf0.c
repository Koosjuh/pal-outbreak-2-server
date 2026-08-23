FUNCTION FUN_0061ddf0 @ 0x0061ddf0  size=212
CALLERS (1): FUN_0061ded0@0x0061ded0
CALLEES (0): 
----------------------------------------------------------------

void FUN_0061ddf0(void)

{
  int iVar1;
  short sVar2;
  int iVar3;
  undefined1 auStack_8 [8];
  
  if (0 < sRam007152e6) {
    sRam007152e6 = sRam007152e6 + -1;
  }
  func_0x00109728(auStack_8,0x669c28,(int)sRam007152e6 / 0x1e);
  func_0x001af0b0(0);
  func_0x001af0c0(0xffffffff80808080);
  func_0x001af060(0x16,0x14);
  func_0x001af0a0(0xffffffffffffffee);
  sVar2 = func_0x0010a050(auStack_8);
  iVar1 = -(sVar2 * 10 + (int)sVar2);
  iVar3 = iVar1 + 0x280;
  if (iVar3 < 0) {
    iVar3 = iVar1 + 0x281;
  }
  func_0x001af080(iVar3 >> 1,0x160);
  func_0x001af190(auStack_8);
  func_0x001af0a0(0xfffffffffffffffe);
  return;
}



================================================================