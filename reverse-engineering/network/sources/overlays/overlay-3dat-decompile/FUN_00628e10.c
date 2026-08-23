FUNCTION FUN_00628e10 @ 0x00628e10  size=208
CALLERS (3): FUN_005fe620@0x005fe620, FUN_005f76f0@0x005f76f0, FUN_005f8d40@0x005f8d40
CALLEES (9): FUN_00629330@0x00629330, FUN_00629370@0x00629370, FUN_006293f0@0x006293f0, FUN_00628f70@0x00628f70, FUN_006293b0@0x006293b0, FUN_00628f00@0x00628f00, FUN_00629200@0x00629200, FUN_006290e0@0x006290e0, FUN_006296a0@0x006296a0
----------------------------------------------------------------

undefined8 FUN_00628e10(void)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  switch(uRam00695cf8) {
  case 0:
    uVar1 = FUN_00628f00();
    break;
  case 1:
    uVar1 = FUN_00628f70();
    break;
  case 2:
    uVar1 = FUN_006290e0();
    break;
  case 3:
    uVar1 = FUN_00629200();
    break;
  case 4:
    uVar1 = FUN_00629330();
    break;
  case 5:
    uVar1 = FUN_00629370();
    break;
  case 6:
    uVar1 = FUN_006293b0();
    break;
  case 7:
    uVar1 = FUN_006293f0();
    break;
  case 8:
    uVar1 = FUN_006296a0();
  }
  return uVar1;
}



================================================================