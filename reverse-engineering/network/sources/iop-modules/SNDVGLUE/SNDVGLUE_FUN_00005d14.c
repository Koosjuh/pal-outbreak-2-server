FUNCTION FUN_00005d14 @ 0x00005d14 size=200
CALLERS (2): FUN_000059d0@0x000059d0, FUN_0000678c@0x0000678c
CALLEES (1): FUN_00008044@0x00008044

undefined2 * FUN_00005d14(int param_1,ushort param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  ushort local_10 [4];
  
  if (0x13 < param_2) {
    FUN_00008044(local_10,param_1 + 0x10,2);
    uVar1 = local_10[0] << 8 | local_10[0] >> 8;
    if (uVar1 != 0) {
      iVar2 = 0;
      iVar5 = 0;
      do {
        iVar3 = iVar2 >> 0x10;
        iVar4 = iVar5 + 1;
        if (uVar1 == (&DAT_0000de92)[iVar3 * 0x70a]) break;
        iVar2 = iVar4 * 0x10000;
        iVar5 = iVar4;
      } while (iVar4 * 0x10000 < 1);
      if (0 < iVar5 << 0x10) {
        return (undefined2 *)0x0;
      }
      return &DAT_0000de90 + iVar3 * 0x70a;
    }
  }
  return (undefined2 *)0x0;
}


================================================================