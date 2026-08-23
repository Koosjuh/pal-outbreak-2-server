FUNCTION FUN_00001dbc @ 0x00001dbc size=136
CALLERS (1): FUN_000054a8@0x000054a8
CALLEES (4): FUN_0000d9a8@0x0000d9a8, FUN_000075dc@0x000075dc, FUN_0000d990@0x0000d990, FUN_000095dc@0x000095dc

undefined4 FUN_00001dbc(undefined4 param_1,undefined4 param_2,undefined2 param_3)

{
  short sVar1;
  undefined4 uVar2;
  
  FUN_0000d990(param_1,param_2,&DAT_000149c8);
  FUN_000095dc(&DAT_000149c8);
  sVar1 = FUN_0000d9a8(&DAT_000149c8,param_3);
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