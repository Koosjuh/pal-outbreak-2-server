FUNCTION FUN_00002220 @ 0x00002220 size=96
CALLERS (1): FUN_000036ac@0x000036ac
CALLEES (2): FUN_00008940@0x00008940, FUN_00009180@0x00009180

undefined4 FUN_00002220(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00008940(param_1,param_2,&DAT_0000bdf8);
  if (iVar1 == 0) {
    uVar2 = 0xfffffff9;
  }
  else {
    iVar1 = FUN_00009180(iVar1);
    uVar2 = 0;
    if ((iVar1 < 0) && (uVar2 = 0xfffffff9, iVar1 == -5)) {
      uVar2 = 0xffffffee;
    }
  }
  return uVar2;
}


================================================================