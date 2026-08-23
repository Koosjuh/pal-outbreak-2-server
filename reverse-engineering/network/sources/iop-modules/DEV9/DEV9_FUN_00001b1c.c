FUNCTION FUN_00001b1c @ 0x00001b1c size=320
CALLERS (1): FUN_00001c5c@0x00001c5c
CALLEES (1): FUN_000021e0@0x000021e0

bool FUN_00001b1c(int param_1,ushort param_2,uint *param_3)

{
  bool bVar1;
  int iVar2;
  ushort local_30;
  undefined4 local_24;
  
  local_30 = param_2 & 0x1f | 0x1020;
  local_24 = 0;
  iVar2 = 0;
  *(undefined2 *)(param_1 + 0x5c) = 0;
  *(ushort *)(param_1 + 0x5e) = local_30;
  do {
    if (((*(ushort *)(param_1 + 0x5e) & 0x8000) != 0) &&
       ((*(ushort *)(param_1 + 0x5e) & 0x8000) != 0)) {
      local_24 = CONCAT22(*(undefined2 *)(param_1 + 0x5c),*(ushort *)(param_1 + 0x5e));
      bVar1 = iVar2 < 100;
      if ((*(ushort *)(param_1 + 0x5e) & 0x8000) != 0) break;
    }
    FUN_000021e0(1000);
    iVar2 = iVar2 + 1;
    bVar1 = false;
  } while (iVar2 < 100);
  if (bVar1) {
    *param_3 = local_24 >> 0x10;
  }
  return !bVar1;
}


================================================================