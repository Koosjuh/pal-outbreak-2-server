FUNCTION FUN_00008b6c @ 0x00008b6c size=72
CALLERS (1): FUN_00008ddc@0x00008ddc
CALLEES (1): FUN_00009658@0x00009658

undefined4 FUN_00008b6c(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 1;
  if (DAT_0000c210 == 1) {
    iVar2 = FUN_00009658(param_1,&DAT_0000aa80,2);
    uVar1 = 0;
    if (iVar2 == 0) {
      uVar1 = 1;
    }
  }
  return uVar1;
}


================================================================