FUNCTION FUN_00010d7c @ 0x00010d7c size=148
CALLERS (1): FUN_00000648@0x00000648
CALLEES (1): FUN_000032d4@0x000032d4

int FUN_00010d7c(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = FUN_000032d4(*param_1,*(undefined2 *)(param_1 + 1),*(undefined2 *)((int)param_1 + 6),
                       *(undefined1 *)(param_1 + 2),*(undefined1 *)((int)param_1 + 9),
                       *(undefined1 *)((int)param_1 + 10),*(undefined1 *)((int)param_1 + 0xb),
                       (int)*(short *)(param_1 + 3),param_1[4],param_1[5],param_1[6]);
  iVar2 = uVar1 << 0x10;
  if (-1 < iVar2) {
    iVar2 = (uVar1 | 0x80) << 0x10;
  }
  return iVar2 >> 0x10;
}


================================================================