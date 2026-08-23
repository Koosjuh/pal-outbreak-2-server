FUNCTION FUN_006176a0 @ 0x006176a0  size=292
CALLERS (1): FUN_00616c40@0x00616c40
CALLEES (6): FUN_005adc80@0x005adc80, FUN_005af300@0x005af300, FUN_005b6900@0x005b6900, FUN_00618b60@0x00618b60, FUN_00608680@0x00608680, FUN_005ac3e0@0x005ac3e0
----------------------------------------------------------------

void FUN_006176a0(undefined8 param_1)

{
  short sVar1;
  int iVar2;
  
  iVar2 = (int)param_1;
  switch(*(char *)(iVar2 + 0xf)) {
  case '\0':
    *(char *)(iVar2 + 0xf) = *(char *)(iVar2 + 0xf) + '\x01';
    func_0x001a6910(0,0,0x10);
  case '\x01':
    *(char *)(iVar2 + 0xf) = *(char *)(iVar2 + 0xf) + '\x01';
    *(undefined2 *)(iVar2 + 0x16) = 10;
    FUN_005af300(0);
    break;
  case '\x02':
    sVar1 = *(short *)(iVar2 + 0x16) + -1;
    *(short *)(iVar2 + 0x16) = sVar1;
    if (sVar1 < 0) {
      *(char *)(iVar2 + 0xf) = *(char *)(iVar2 + 0xf) + '\x01';
      FUN_00618b60();
    }
    break;
  case '\x03':
    sVar1 = *(short *)(iVar2 + 0x16) + -1;
    *(short *)(iVar2 + 0x16) = sVar1;
    if (sVar1 < 0) {
      *(undefined1 *)(iVar2 + 0xf) = 5;
    }
    break;
  case '\x04':
    FUN_005b6900();
    break;
  case '\x05':
    uRam00874f9c = 1;
    uRam00874f35 = 3;
    uRam00874fd4 = FUN_005adc80(0);
    FUN_00608680(param_1);
    FUN_005ac3e0();
  }
  return;
}



================================================================