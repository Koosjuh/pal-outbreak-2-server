FUNCTION FUN_005c2390 @ 0x005c2390  size=196
CALLERS (1): FUN_005ffb20@0x005ffb20
CALLEES (2): FUN_005be0a0@0x005be0a0, FUN_005c27d0@0x005c27d0
----------------------------------------------------------------

long FUN_005c2390(undefined8 param_1)

{
  undefined2 uVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  
  func_0x00106b60(0x6ce046,0,0x460);
  func_0x00106b60(0x6cdbe6,0,0x460);
  lVar2 = FUN_005be0a0(1,0,param_1);
  lVar3 = -1;
  if (lVar2 != -1) {
    uVar1 = FUN_005c27d0();
    iVar4 = (int)lVar2 * 0x20;
    *(undefined2 *)(iVar4 + 0x6ca97c) = uVar1;
    uRam006ca890 = 0;
    uVar1 = func_0x001de0c0(uRam006febac,uRam0086f840,0x5c2460);
    *(undefined2 *)(iVar4 + 0x6ca97e) = uVar1;
    lVar3 = lVar2;
  }
  return lVar3;
}



================================================================