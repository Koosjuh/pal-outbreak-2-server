FUNCTION FUN_005bebf0 @ 0x005bebf0  size=140
CALLERS (1): FUN_005befa0@0x005befa0
CALLEES (8): FUN_005bec80@0x005bec80, FUN_005bee90@0x005bee90, FUN_005be0a0@0x005be0a0, FUN_005bed60@0x005bed60, FUN_005bef00@0x005bef00, FUN_005becf0@0x005becf0, FUN_005bee40@0x005bee40, FUN_005bedd0@0x005bedd0
----------------------------------------------------------------

long FUN_005bebf0(undefined8 param_1)

{
  undefined2 uVar1;
  long lVar2;
  long lVar3;
  
  lVar2 = FUN_005be0a0(1,0,param_1);
  lVar3 = -1;
  if (lVar2 != -1) {
    FUN_005bec80();
    FUN_005becf0();
    FUN_005bed60();
    FUN_005bedd0();
    FUN_005bee40();
    FUN_005bee90();
    uVar1 = FUN_005bef00();
    *(undefined2 *)((int)lVar2 * 0x20 + 0x6ca97e) = uVar1;
    lVar3 = lVar2;
  }
  return lVar3;
}



================================================================