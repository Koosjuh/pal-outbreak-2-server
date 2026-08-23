FUNCTION FUN_00001e44 @ 0x00001e44 size=128
CALLERS (1): FUN_000054a8@0x000054a8
CALLEES (3): FUN_000075dc@0x000075dc, FUN_00006ecc@0x00006ecc, FUN_000073fc@0x000073fc

undefined4 FUN_00001e44(undefined4 param_1,undefined4 param_2,undefined2 param_3)

{
  short sVar1;
  undefined4 uVar2;
  
  FUN_00006ecc(param_1,param_2,&DAT_00014a30);
  sVar1 = FUN_000073fc(&DAT_00014a30,param_3);
  uVar2 = 0xffffffee;
  if (sVar1 < 0) {
    if (sVar1 != -0x12) {
      uVar2 = 0xffffffef;
    }
  }
  else {
    FUN_000075dc(&DAT_000149fc);
    uVar2 = 0;
  }
  return uVar2;
}


================================================================