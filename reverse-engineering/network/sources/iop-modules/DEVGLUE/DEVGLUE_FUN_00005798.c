FUNCTION FUN_00005798 @ 0x00005798 size=240
CALLERS (1): FUN_00000b04@0x00000b04
CALLEES (4): FUN_00005ce4@0x00005ce4, FUN_000074ac@0x000074ac, FUN_0000810c@0x0000810c, FUN_00006b50@0x00006b50

undefined4 FUN_00005798(short param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_1 == 0) {
    uVar1 = DAT_0000de90;
    switch(DAT_0000de90) {
    case 0:
    case 1:
    case 2:
      FUN_00005ce4(&DAT_0000de90);
      uVar1 = 0xffff;
      break;
    case 3:
      uVar1 = 5;
      break;
    case 4:
      DAT_0000de90 = 5;
      iVar3 = FUN_000074ac(&DAT_0000de90);
      if (iVar3 << 0x10 < 0) {
        return 0;
      }
      FUN_00006b50(&DAT_0000e0ca,DAT_0000e6b4);
      return 0;
    case 5:
      FUN_00005ce4(&DAT_0000de90);
      uVar1 = 0xffff;
      if ((DAT_0000de92 != 0) && (uVar1 = 6, (DAT_00009710 & 2) != 0)) {
        FUN_0000810c("pppoe : state ==> FATAL\n");
        uVar1 = 6;
      }
    }
    DAT_0000de90 = uVar1;
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


================================================================