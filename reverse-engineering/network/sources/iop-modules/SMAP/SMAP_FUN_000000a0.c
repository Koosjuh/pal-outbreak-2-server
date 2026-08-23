FUNCTION FUN_000000a0 @ 0x000000a0 size=224
CALLERS (2): FUN_000011c4@0x000011c4, FUN_00000998@0x00000998
CALLEES (2): FUN_000029f4@0x000029f4, FUN_00002b40@0x00002b40

uint FUN_000000a0(int param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  iVar2 = 0;
  *(uint *)(param_1 + 0x5c) = (param_2 & 0x1f | 0x1020) << 0x10;
  do {
    if (((*(uint *)(param_1 + 0x5c) >> 0x10 & 0x8000) != 0) &&
       ((*(uint *)(param_1 + 0x5c) >> 0x10 & 0x8000) != 0)) {
      uVar3 = *(uint *)(param_1 + 0x5c) << 0x10;
      bVar1 = iVar2 < 100;
      if ((*(uint *)(param_1 + 0x5c) >> 0x10 & 0x8000) != 0) break;
    }
    FUN_00002b40(1000);
    iVar2 = iVar2 + 1;
    bVar1 = false;
  } while (iVar2 < 100);
  if (!bVar1) {
    FUN_000029f4("smap: %s: > %d ms\n","_smap_read_phy",iVar2);
  }
  return uVar3 >> 0x10;
}


================================================================