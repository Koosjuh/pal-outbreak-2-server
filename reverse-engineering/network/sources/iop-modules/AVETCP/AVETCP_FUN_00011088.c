FUNCTION FUN_00011088 @ 0x00011088 size=72
CALLERS (1): FUN_000006b4@0x000006b4
CALLEES (1): FUN_00004aa4@0x00004aa4

int FUN_00011088(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = FUN_00004aa4(*param_1,*(undefined1 *)(param_1 + 1),param_1[2],param_1[3]);
  iVar2 = uVar1 << 0x10;
  if (-1 < iVar2) {
    iVar2 = (uVar1 | 0xc0) << 0x10;
  }
  return iVar2 >> 0x10;
}


================================================================