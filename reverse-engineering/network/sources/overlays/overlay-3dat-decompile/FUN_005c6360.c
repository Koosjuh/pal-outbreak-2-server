FUNCTION FUN_005c6360 @ 0x005c6360  size=412
CALLERS (1): FUN_005c6500@0x005c6500
CALLEES (0): 
----------------------------------------------------------------

void FUN_005c6360(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  func_0x00106b60(0x700b60,0,0x450);
  func_0x00106b60(0x700710,0,0x450);
  iVar3 = 0;
  cRam00700708 = '\0';
  for (iVar4 = 0; iVar4 < (int)(uint)bRam006ff2b3; iVar4 = iVar4 + 1) {
    if (*(char *)(iVar4 + 0x6ff2b5) == '\x01') {
      if (0 < iVar4) {
        func_0x0010a4f0(iVar3 * 0x114 + 0x700b60,iVar4 * 0x114 + 0x6ff70d,0x10);
      }
      iVar2 = iVar4 * 0x114;
      iVar1 = iVar3 * 0x114;
      func_0x0010a4f0(iVar1 + 0x700710,iVar2 + 0x6ff70d,0x10);
      func_0x0010a4f0(iVar1 + 0x700720,iVar2 + 0x6ff71d,0x10);
      func_0x001069a8(iVar1 + 0x700734,iVar2 + 0x6ff731,0xf0);
      iVar3 = iVar3 + 1;
      cRam00700708 = cRam00700708 + '\x01';
    }
  }
  return;
}



================================================================