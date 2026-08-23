FUNCTION FUN_00000a80 @ 0x00000a80 size=132
CALLERS (0): 
CALLEES (3): FUN_00001120@0x00001120, FUN_00002a78@0x00002a78, FUN_0000560c@0x0000560c

undefined4 FUN_00000a80(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (DAT_000096d4 == 0) {
    FUN_00002a78(DAT_00009708,param_1);
    iVar2 = FUN_00001120(DAT_00009708);
    uVar1 = 2;
    if (-1 < iVar2) {
      uVar1 = 0;
    }
  }
  else {
    DAT_000096d0 = FUN_0000560c(&DAT_00009740);
    uVar1 = 0;
    if ((int)((uint)DAT_000096d0 << 0x10) < 0) {
      uVar1 = 2;
    }
  }
  return uVar1;
}


================================================================