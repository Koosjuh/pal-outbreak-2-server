FUNCTION FUN_00000000 @ 0x00000000 size=160
CALLERS (1): FUN_00000998@0x00000998
CALLEES (2): FUN_000029f4@0x000029f4, FUN_00002b40@0x00002b40

void FUN_00000000(int param_1,uint param_2,uint param_3)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = 0;
  *(uint *)(param_1 + 0x5c) = (param_2 & 0x1f | 0x2020) << 0x10 | param_3 & 0xffff;
  do {
    bVar1 = iVar2 < 100;
    if ((*(uint *)(param_1 + 0x5c) >> 0x10 & 0x8000) != 0) break;
    FUN_00002b40(1000);
    iVar2 = iVar2 + 1;
    bVar1 = false;
  } while (iVar2 < 100);
  if (!bVar1) {
    FUN_000029f4("smap: %s: > %d ms\n","_smap_write_phy",iVar2);
  }
  return;
}


================================================================