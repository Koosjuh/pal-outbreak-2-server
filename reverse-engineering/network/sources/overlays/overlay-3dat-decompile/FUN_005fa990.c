FUNCTION FUN_005fa990 @ 0x005fa990  size=152
CALLERS (1): FUN_005fa490@0x005fa490
CALLEES (3): FUN_005b14b0@0x005b14b0, FUN_005fa890@0x005fa890, FUN_005faa30@0x005faa30
----------------------------------------------------------------

void FUN_005fa990(undefined8 param_1)

{
  undefined2 uVar1;
  long lVar2;
  undefined8 uVar3;
  undefined2 extraout_t1_lo;
  int iVar4;
  
  lVar2 = FUN_005b14b0(0x40004);
  iVar4 = (int)param_1;
  if (lVar2 == 0) {
    FUN_005b14b0(0x80008);
    uVar1 = *(undefined2 *)(iVar4 + 4);
  }
  else {
    uVar1 = *(undefined2 *)(iVar4 + 4);
  }
  uVar3 = FUN_005faa30(param_1,uVar1);
  while (lVar2 = FUN_005fa890(param_1,uVar3), lVar2 != 0) {
    uVar3 = FUN_005faa30();
  }
  *(undefined2 *)(iVar4 + 4) = extraout_t1_lo;
  return;
}



================================================================