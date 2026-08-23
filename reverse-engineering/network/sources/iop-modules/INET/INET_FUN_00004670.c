FUNCTION FUN_00004670 @ 0x00004670 size=228
CALLERS (2): FUN_00004b68@0x00004b68, FUN_00004754@0x00004754
CALLEES (2): FUN_00017bf4@0x00017bf4, FUN_000179cc@0x000179cc

void FUN_00004670(int param_1)

{
  longlong lVar1;
  undefined4 uVar2;
  
  uVar2 = FUN_00017bf4(*(undefined4 *)(param_1 + 0xc));
  *(undefined4 *)(param_1 + 0xc) = uVar2;
  uVar2 = FUN_00017bf4(*(undefined4 *)(param_1 + 0x10));
  *(undefined4 *)(param_1 + 0x10) = uVar2;
  uVar2 = FUN_00017bf4(*(undefined4 *)(param_1 + 0x14));
  *(undefined4 *)(param_1 + 0x14) = uVar2;
  if (*(uint *)(param_1 + 0x4c) != 0xffffffff) {
    lVar1 = (ulonglong)*(uint *)(param_1 + 0x4c) * 1000;
    uVar2 = FUN_000179cc(FUN_000043a8,param_1,(int)lVar1,(int)((ulonglong)lVar1 >> 0x20));
    *(undefined4 *)(param_1 + 0xc) = uVar2;
  }
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined4 *)(param_1 + 0x74) = 0;
  if (*(uint *)(param_1 + 0x50) != 0xffffffff) {
    lVar1 = (ulonglong)*(uint *)(param_1 + 0x50) * 1000;
    uVar2 = FUN_000179cc(FUN_000044dc,param_1,(int)lVar1,(int)((ulonglong)lVar1 >> 0x20));
    *(undefined4 *)(param_1 + 0x10) = uVar2;
  }
  if (*(uint *)(param_1 + 0x54) != 0xffffffff) {
    lVar1 = (ulonglong)*(uint *)(param_1 + 0x54) * 1000;
    uVar2 = FUN_000179cc(FUN_000045a4,param_1,(int)lVar1,(int)((ulonglong)lVar1 >> 0x20));
    *(undefined4 *)(param_1 + 0x14) = uVar2;
  }
  return;
}


================================================================