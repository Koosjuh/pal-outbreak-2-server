FUNCTION FUN_00000844 @ 0x00000844 size=188
CALLERS (4): FUN_00000a64@0x00000a64, FUN_00000dc4@0x00000dc4, FUN_000009e4@0x000009e4, FUN_00000900@0x00000900
CALLEES (3): FUN_00001328@0x00001328, FUN_00001364@0x00001364, FUN_00000824@0x00000824

int FUN_00000844(int param_1)

{
  short sVar1;
  int iVar2;
  
  iVar2 = FUN_00000824();
  if (iVar2 != param_1) {
    if (param_1 == 0) {
      FUN_00001364();
      iVar2 = 0;
    }
    else if (param_1 == 1) {
      sVar1 = FUN_00001328(0,0,0xffffffff);
      iVar2 = 1;
      if (sVar1 != 0) {
        FUN_00001364();
        sVar1 = FUN_00001328(0,0,0xffffffff);
        iVar2 = 0;
        if (sVar1 == 0) {
          iVar2 = 1;
        }
        else {
          DAT_00002f50 = 3;
          DAT_00002f7c = 0xffffffff;
          DAT_00002eb0 = 0xfffffffe;
        }
      }
    }
  }
  return iVar2;
}


================================================================