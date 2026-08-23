FUNCTION FUN_00007ddc @ 0x00007ddc size=160
CALLERS (1): FUN_00007660@0x00007660
CALLEES (1): FUN_00010a9c@0x00010a9c

int FUN_00007ddc(undefined4 param_1)

{
  short sVar1;
  undefined **ppuVar2;
  int iVar3;
  
  iVar3 = 0;
  if (PTR_DAT_00011d74 != (undefined *)0x0) {
    ppuVar2 = &PTR_DAT_00011d74;
    do {
      sVar1 = FUN_00010a9c(param_1,*ppuVar2);
      ppuVar2 = ppuVar2 + 1;
      if (sVar1 == 0) break;
      iVar3 = iVar3 + 1;
    } while (*ppuVar2 != (undefined *)0x0);
    if ((&PTR_DAT_00011d74)[iVar3] != (undefined *)0x0) {
      return (iVar3 - (iVar3 >> 0x1f)) * 0x8000 >> 0x10;
    }
  }
  return -1;
}


================================================================