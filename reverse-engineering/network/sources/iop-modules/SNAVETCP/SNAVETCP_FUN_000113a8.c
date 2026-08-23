FUNCTION FUN_000113a8 @ 0x000113a8 size=108
CALLERS (1): FUN_00000768@0x00000768
CALLEES (2): FUN_0000edbc@0x0000edbc, FUN_0000f580@0x0000f580

undefined4 FUN_000113a8(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = *param_1;
  uVar1 = FUN_0000f580(uVar3,DAT_00017e14,DAT_00017e10);
  iVar2 = FUN_0000edbc(uVar3,uVar1,param_1[1],0);
  uVar1 = 0;
  if (iVar2 << 0x10 < 0) {
    uVar1 = 0xfffffff0;
  }
  return uVar1;
}


================================================================