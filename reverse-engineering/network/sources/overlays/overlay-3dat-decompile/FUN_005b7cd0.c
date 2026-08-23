FUNCTION FUN_005b7cd0 @ 0x005b7cd0  size=272
CALLERS (4): FUN_005ba2e0@0x005ba2e0, FUN_0061eab0@0x0061eab0, FUN_006080d0@0x006080d0, FUN_00629d60@0x00629d60
CALLEES (4): FUN_005b76f0@0x005b76f0, FUN_005b7320@0x005b7320, FUN_005b7f00@0x005b7f00, FUN_005af2c0@0x005af2c0
----------------------------------------------------------------

void FUN_005b7cd0(undefined4 param_1,undefined4 param_2,undefined4 param_3,long param_4)

{
  char cVar1;
  undefined8 uVar2;
  int iVar3;
  
  if ((param_4 != 0) && (cVar1 = FUN_005b7f00(), cVar1 == '\x01')) {
    uRam006ca878 = 5;
    uRam006ca886 = 6;
    uRam006ca87c = (undefined4)param_4;
    uRam006ca874 = 0;
    uRam006ca880 = 0;
    cRam006ca881 = '\0';
    uRam006ca860 = param_1;
    uRam006ca864 = param_2;
    uRam006ca868 = param_3;
    uRam006ca86c = param_1;
    uRam006ca870 = param_2;
    FUN_005af2c0(0);
    for (iVar3 = 0; iVar3 < 0x1a; iVar3 = iVar3 + 1) {
      uVar2 = FUN_005b7320();
      FUN_005b76f0(0,0,uVar2);
      if (cRam006ca881 != '\0') break;
    }
    FUN_005af2c0(0);
  }
  return;
}



================================================================