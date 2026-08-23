FUNCTION FUN_000005a8 @ 0x000005a8 size=240
CALLERS (5): FUN_00001128@0x00001128, FUN_00001228@0x00001228, FUN_00001468@0x00001468, FUN_00000698@0x00000698, FUN_000007c0@0x000007c0
CALLEES (2): FUN_00002d88@0x00002d88, FUN_00002d98@0x00002d98

undefined4 FUN_000005a8(short param_1,int param_2)

{
  int iVar1;
  undefined **ppuVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar4 = 0xffffffff;
  uVar3 = 0;
  ppuVar2 = &PTR_DAT_00002ec0;
  iVar1 = 0;
  while (*(short *)((int)&DAT_00002eb8 + iVar1) != param_1) {
    ppuVar2 = ppuVar2 + 3;
    uVar3 = uVar3 + 1;
    iVar1 = iVar1 + 0xc;
    if (0xb < uVar3) {
      return 0xffffffff;
    }
  }
  if (*(short *)((int)&DAT_00002eba + iVar1) != 0) {
    uVar4 = 0;
  }
  if (param_2 == 0) {
    return uVar4;
  }
  if (*(short *)((int)&DAT_00002ebc + iVar1) == 0) {
    FUN_00002d98(param_2,*ppuVar2);
    return uVar4;
  }
  if (*(short *)((int)&DAT_00002ebc + iVar1) != 1) {
    return uVar4;
  }
  FUN_00002d88(param_2,*ppuVar2,(int)*(short *)((int)&DAT_00002ebe + iVar1));
  return uVar4;
}


================================================================