FUNCTION FUN_005c28f0 @ 0x005c28f0  size=200
CALLERS (2): FUN_005c6500@0x005c6500, FUN_0062dc40@0x0062dc40
CALLEES (2): FUN_005c08b0@0x005c08b0, FUN_005be0a0@0x005be0a0
----------------------------------------------------------------

long FUN_005c28f0(undefined8 param_1,undefined8 param_2)

{
  undefined2 uVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  uint uStack_4;
  
  lVar2 = FUN_005be0a0(1,0,param_2);
  lVar3 = -1;
  if (lVar2 != -1) {
    uVar1 = FUN_005c08b0(param_1);
    iVar4 = (int)lVar2 * 0x20;
    *(undefined2 *)(iVar4 + 0x6ca97c) = uVar1;
    uStack_4 = (uRam006febe4 & 0xf000000) << 1 | 0x40000000;
    uVar1 = func_0x001dd33c(uRam006febac,0x53544154,&uStack_4,4,0,0x5c29c0);
    *(undefined2 *)(iVar4 + 0x6ca97e) = uVar1;
    lVar3 = lVar2;
  }
  return lVar3;
}



================================================================