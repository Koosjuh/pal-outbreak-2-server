FUNCTION FUN_0000e944 @ 0x0000e944 size=228
CALLERS (2): FUN_00003fd0@0x00003fd0, FUN_0000414c@0x0000414c
CALLEES (1): FUN_000042b8@0x000042b8

undefined4 FUN_0000e944(short param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = (int)param_1;
  if (iVar2 < 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = 0;
    if (iVar2 <= DAT_000168e0) {
      iVar3 = (&DAT_00016190)[iVar2];
    }
  }
  if ((iVar3 != 0) && (iVar2 = FUN_000042b8((int)param_1), iVar2 != 0)) {
    *(undefined1 *)(iVar2 + 1) = 1;
    sVar1 = (**(code **)(iVar3 + 0x24))((int)*(short *)(iVar3 + 4),0x608);
    if (sVar1 != 0) {
      return 0xffffffff;
    }
    sVar1 = (**(code **)(iVar3 + 0x24))((int)*(short *)(iVar3 + 4),8);
    if ((sVar1 == 0) &&
       (sVar1 = (**(code **)(iVar3 + 0x18))((int)*(short *)(iVar3 + 4)), sVar1 == 0)) {
      return 0;
    }
  }
  return 0xffffffff;
}


================================================================