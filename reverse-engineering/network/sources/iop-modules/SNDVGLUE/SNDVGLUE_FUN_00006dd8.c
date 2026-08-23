FUNCTION FUN_00006dd8 @ 0x00006dd8 size=200
CALLERS (1): FUN_000059d0@0x000059d0
CALLEES (2): FUN_00008034@0x00008034, FUN_00006c1c@0x00006c1c

void FUN_00006dd8(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = FUN_00008034();
  iVar3 = 0;
  do {
    iVar2 = (int)(short)iVar3;
    if ((((&DAT_0000de90)[iVar2 * 0x70a] != -1) && ((&DAT_0000de98)[iVar2 * 0x385] != 0)) &&
       ((int)(&DAT_0000de98)[iVar2 * 0x385] < iVar1 - (&DAT_0000de9c)[iVar2 * 0x385])) {
      FUN_00006c1c();
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 * 0x10000 < 1);
  return;
}


================================================================