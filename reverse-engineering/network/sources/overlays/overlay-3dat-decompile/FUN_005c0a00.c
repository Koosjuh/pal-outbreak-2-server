FUNCTION FUN_005c0a00 @ 0x005c0a00  size=212
CALLERS (4): FUN_005fa190@0x005fa190, FUN_005fe8d0@0x005fe8d0, FUN_0062e440@0x0062e440, FUN_005fe500@0x005fe500
CALLEES (2): FUN_005be0a0@0x005be0a0, FUN_005c0dc0@0x005c0dc0
----------------------------------------------------------------

long FUN_005c0a00(undefined8 param_1,undefined8 param_2)

{
  undefined2 uVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  
  func_0x00106b60(0x6cdbe6,0,0x460);
  lVar2 = FUN_005be0a0(1,0,param_2);
  lVar3 = -1;
  if (lVar2 != -1) {
    uVar1 = FUN_005c0dc0(param_1);
    iVar4 = (int)lVar2 * 0x20;
    *(undefined2 *)(iVar4 + 0x6ca97c) = uVar1;
    uVar1 = func_0x001de0c0(uRam006febac,*(undefined4 *)(((uint)param_1 & 0xffff) * 0x24 + 0x6fee68)
                            ,0x5c0ae0);
    uRam006ca890 = 0;
    *(undefined2 *)(iVar4 + 0x6ca97e) = uVar1;
    lVar3 = lVar2;
  }
  return lVar3;
}



================================================================