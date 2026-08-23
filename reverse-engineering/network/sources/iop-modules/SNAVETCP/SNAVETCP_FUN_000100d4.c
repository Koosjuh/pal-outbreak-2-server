FUNCTION FUN_000100d4 @ 0x000100d4 size=52
CALLERS (1): FUN_000004f4@0x000004f4
CALLEES (1): FUN_0000d634@0x0000d634

undefined4 FUN_000100d4(short *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0000d634((int)*param_1,1);
  uVar2 = 0xfffffffc;
  if (-1 < iVar1 << 0x10) {
    uVar2 = 0;
  }
  return uVar2;
}


================================================================