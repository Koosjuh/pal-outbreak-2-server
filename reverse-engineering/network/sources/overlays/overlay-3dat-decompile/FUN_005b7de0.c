FUNCTION FUN_005b7de0 @ 0x005b7de0  size=288
CALLERS (1): FUN_005b6e10@0x005b6e10
CALLEES (4): FUN_005b76f0@0x005b76f0, FUN_005b7320@0x005b7320, FUN_005b7f00@0x005b7f00, FUN_005af2c0@0x005af2c0
----------------------------------------------------------------

void FUN_005b7de0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  char cVar1;
  undefined8 uVar2;
  int iVar3;
  
  cVar1 = FUN_005b7f00();
  if (cVar1 == '\x01') {
    uRam006ca878 = 5;
    uRam006ca886 = 6;
    uRam006ca874 = 0;
    uRam006ca880 = 0;
    cRam006ca881 = '\0';
    uRam006ca860 = param_1;
    uRam006ca864 = param_2;
    uRam006ca868 = param_3;
    uRam006ca86c = param_1;
    uRam006ca870 = param_2;
    uRam006ca87c = param_6;
    FUN_005af2c0(0);
    for (iVar3 = 0; iVar3 < 0x1a; iVar3 = iVar3 + 1) {
      uVar2 = FUN_005b7320();
      FUN_005b76f0(param_4,param_5,uVar2);
      if (cRam006ca881 != '\0') break;
    }
    FUN_005af2c0(0);
  }
  return;
}



================================================================