FUNCTION FUN_005beb40 @ 0x005beb40  size=92
CALLERS (1): FUN_005befa0@0x005befa0
CALLEES (2): FUN_005be0a0@0x005be0a0, FUN_005beba0@0x005beba0
----------------------------------------------------------------

long FUN_005beb40(undefined8 param_1)

{
  undefined2 uVar1;
  long lVar2;
  long lVar3;
  
  lVar2 = FUN_005be0a0(1,0,param_1);
  lVar3 = -1;
  if (lVar2 != -1) {
    uVar1 = FUN_005beba0();
    *(undefined2 *)((int)lVar2 * 0x20 + 0x6ca97e) = uVar1;
    lVar3 = lVar2;
  }
  return lVar3;
}



================================================================