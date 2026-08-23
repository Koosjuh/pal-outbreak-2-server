FUNCTION FUN_0000f580 @ 0x0000f580 size=140
CALLERS (3): FUN_000112ec@0x000112ec, FUN_0000f09c@0x0000f09c, FUN_000113a8@0x000113a8
CALLEES (1): FUN_00001080@0x00001080

void FUN_0000f580(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = FUN_00001080();
  uVar3 = 0xff000000;
  if (((int)uVar1 < 0) && (uVar3 = 0xffffff00, (uVar1 & 0x40000000) == 0)) {
    uVar3 = 0xffff0000;
  }
  uVar2 = FUN_00001080(param_3);
  if ((uVar1 & uVar3) == (uVar2 & uVar3)) {
    uVar3 = FUN_00001080(param_2);
  }
  FUN_00001080(uVar3);
  return;
}


================================================================