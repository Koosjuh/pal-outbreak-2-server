FUNCTION FUN_00001a70 @ 0x00001a70 size=172
CALLERS (1): FUN_00001c5c@0x00001c5c
CALLEES (1): FUN_000021e0@0x000021e0

byte FUN_00001a70(int param_1,ushort param_2,undefined2 param_3)

{
  bool bVar1;
  int iVar2;
  undefined2 local_18;
  
  local_18 = param_2 & 0x1f | 0x2020;
  iVar2 = 0;
  *(undefined2 *)(param_1 + 0x5c) = param_3;
  *(ushort *)(param_1 + 0x5e) = local_18;
  do {
    bVar1 = iVar2 < 100;
    if ((*(ushort *)(param_1 + 0x5e) & 0x8000) != 0) break;
    FUN_000021e0(1000);
    iVar2 = iVar2 + 1;
    bVar1 = false;
  } while (iVar2 < 100);
  return bVar1 ^ 1;
}


================================================================