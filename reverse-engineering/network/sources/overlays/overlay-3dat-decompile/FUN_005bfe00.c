FUNCTION FUN_005bfe00 @ 0x005bfe00  size=136
CALLERS (1): FUN_005c1c80@0x005c1c80
CALLEES (2): FUN_005be0a0@0x005be0a0, FUN_005c2080@0x005c2080
----------------------------------------------------------------

long FUN_005bfe00(undefined8 param_1)

{
  undefined2 uVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  
  lVar2 = FUN_005be0a0(1,0,param_1);
  lVar3 = -1;
  if (lVar2 != -1) {
    uVar1 = FUN_005c2080(1);
    iVar4 = (int)lVar2 * 0x20;
    *(undefined2 *)(iVar4 + 0x6ca97c) = uVar1;
    uVar1 = func_0x001dd07c(uRam006febac,0x5bfe90);
    *(undefined2 *)(iVar4 + 0x6ca97e) = uVar1;
    lVar3 = lVar2;
  }
  return lVar3;
}



================================================================