FUNCTION FUN_005df7b0 @ 0x005df7b0  size=724
CALLERS (2): FUN_005d76b0@0x005d76b0, FUN_005d7a30@0x005d7a30
CALLEES (2): FUN_005dee60@0x005dee60, FUN_005deee0@0x005deee0
----------------------------------------------------------------

undefined4 FUN_005df7b0(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  int iVar7;
  undefined8 uVar8;
  long lVar9;
  undefined8 extraout_a2;
  long extraout_a3;
  
  uVar8 = FUN_005dee60(param_1,param_2,param_1);
  lVar9 = FUN_005deee0(extraout_a2,uVar8);
  if (lVar9 == 0) {
    return 0;
  }
  iVar7 = (int)lVar9;
  cVar1 = *(char *)(iVar7 + 1);
  if ((cVar1 != '\0') && (cVar2 = *(char *)(iVar7 + 2), cVar2 != '\0')) {
    cVar3 = *(char *)(iVar7 + 3);
    if ((cVar3 != '\0') && (iVar7 + 4 == extraout_a3)) {
      if ((((cVar1 == 'P') || (cVar1 == 'p')) && ((cVar2 == 'N' || (cVar2 == 'n')))) &&
         ((cVar3 == 'G' || (cVar3 == 'g')))) {
        return 2;
      }
      if ((((cVar1 == 'B') || (cVar1 == 'b')) && ((cVar2 == 'M' || (cVar2 == 'm')))) &&
         ((cVar3 == 'P' || (cVar3 == 'p')))) {
        return 3;
      }
      if ((((cVar1 == 'H') || (cVar1 == 'h')) && ((cVar2 == 'T' || (cVar2 == 't')))) &&
         ((cVar3 == 'M' || (cVar3 == 'm')))) {
        return 1;
      }
    }
  }
  if (((cVar1 != '\0') && (cVar2 = *(char *)(iVar7 + 2), cVar2 != '\0')) &&
     (cVar3 = *(char *)(iVar7 + 3), cVar3 != '\0')) {
    cVar4 = *(char *)(iVar7 + 4);
    if ((((cVar4 != '\0') && (iVar7 + 5 == extraout_a3)) && ((cVar1 == 'H' || (cVar1 == 'h')))) &&
       ((((cVar2 == 'T' || (cVar2 == 't')) && ((cVar3 == 'M' || (cVar3 == 'm')))) &&
        ((cVar4 == 'L' || (cVar4 == 'l')))))) {
      return 1;
    }
  }
  if (((((cVar1 != '\0') && (cVar2 = *(char *)(iVar7 + 2), cVar2 != '\0')) &&
       (cVar3 = *(char *)(iVar7 + 3), cVar3 != '\0')) &&
      ((cVar4 = *(char *)(iVar7 + 4), cVar4 != '\0' && (cVar5 = *(char *)(iVar7 + 5), cVar5 != '\0')
       ))) && ((cVar6 = *(char *)(iVar7 + 6), cVar6 != '\0' && (iVar7 + 7 == extraout_a3)))) {
    if ((cVar1 != 'M') && (cVar1 != 'm')) {
      return 0;
    }
    if ((((((cVar2 == 'M') || (cVar2 == 'm')) && ((cVar3 == 'B' || (cVar3 == 'b')))) &&
         ((cVar4 == 'B' || (cVar4 == 'b')))) && ((cVar5 == 'I' || (cVar5 == 'i')))) &&
       ((cVar6 == 'N' || (cVar6 == 'n')))) {
      return 4;
    }
  }
  return 0;
}



================================================================