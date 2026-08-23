FUNCTION FUN_005d7760 @ 0x005d7760  size=368
CALLERS (1): FUN_005d7e00@0x005d7e00
CALLEES (6): FUN_005d6a50@0x005d6a50, FUN_005df780@0x005df780, FUN_005d6c10@0x005d6c10, FUN_005d6a70@0x005d6a70, FUN_005d6c90@0x005d6c90, FUN_005d6b40@0x005d6b40
----------------------------------------------------------------

long FUN_005d7760(undefined8 param_1,long param_2,undefined8 param_3)

{
  char cVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  long extraout_a2;
  long extraout_a2_00;
  
  cVar1 = FUN_005df780();
  if ((cVar1 == '\x04') && (param_2 == 1)) {
    param_2 = 2;
  }
  lVar2 = FUN_005d6a70(iRam00701068 + 0x4f370,param_1);
  lVar3 = lVar2;
  switch(param_2) {
  case 4:
  case 5:
    if ((lVar2 == 0) && (lVar3 = FUN_005d6a50(param_3,1), lVar2 = extraout_a2, lVar3 != 0)) {
      return 0;
    }
  case 1:
    lVar3 = 0;
    if (lVar2 != 0) {
      *(undefined4 *)((int)lVar2 + 0x104) = 2;
      return lVar2;
    }
    break;
  case 6:
    lVar2 = FUN_005d6a50(param_3,1);
    lVar3 = extraout_a2_00;
    if (lVar2 != 0) {
      return 0;
    }
  }
  if ((lVar3 == 0) && (lVar3 = FUN_005d6c10(iRam00701068 + 0x4f370,param_1), lVar3 == 0)) {
    uVar4 = FUN_005d6b40(iRam00701068 + 0x4f370);
    FUN_005d6c90(uVar4);
    lVar3 = FUN_005d6c10(iRam00701068 + 0x4f370,param_1);
  }
  *(undefined4 *)((int)lVar3 + 0x104) = 3;
  return lVar3;
}



================================================================