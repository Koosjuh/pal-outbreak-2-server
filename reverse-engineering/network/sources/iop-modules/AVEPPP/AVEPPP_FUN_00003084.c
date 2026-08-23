FUNCTION FUN_00003084 @ 0x00003084 size=72
CALLERS (0): 
CALLEES (1): FUN_000030cc@0x000030cc

undefined4 FUN_00003084(undefined4 param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 < 0x5eb) {
    iVar2 = FUN_000030cc(param_2);
    uVar1 = 0;
    if (iVar2 != 0) {
      uVar1 = 0xffffffff;
    }
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


================================================================