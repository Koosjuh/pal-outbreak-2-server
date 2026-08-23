FUNCTION FUN_00001ff8 @ 0x00001ff8 size=88
CALLERS (1): FUN_000054a8@0x000054a8
CALLEES (2): FUN_0000bc4c@0x0000bc4c, FUN_0000c028@0x0000c028

undefined4 FUN_00001ff8(void)

{
  short sVar1;
  undefined4 uVar2;
  
  sVar1 = FUN_0000bc4c(&DAT_000149fc);
  if (sVar1 == 0) {
    sVar1 = FUN_0000c028(&DAT_000149fc);
    uVar2 = 0xffffffef;
    if (sVar1 == 0) {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0xffffffef;
  }
  return uVar2;
}


================================================================