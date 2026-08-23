FUNCTION FUN_0000f4fc @ 0x0000f4fc size=132
CALLERS (1): FUN_0000f8f0@0x0000f8f0
CALLEES (1): FUN_00001080@0x00001080

undefined4 FUN_0000f4fc(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar1 = FUN_00001080();
  uVar2 = FUN_00001080(param_2);
  if (uVar2 == 0) {
    return 0;
  }
  if ((int)uVar2 < 0) {
    if ((uVar2 & 0xc0000000) == 0x80000000) {
      uVar3 = 0xffff0000;
    }
    else {
      uVar3 = 0xffffff00;
      if ((uVar2 & 0xe0000000) != 0xc0000000) goto LAB_0000f564;
    }
  }
  else {
    uVar3 = 0xff000000;
  }
  uVar1 = uVar1 | uVar3;
LAB_0000f564:
  uVar4 = FUN_00001080(uVar1);
  return uVar4;
}


================================================================