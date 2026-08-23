FUNCTION FUN_005c04f0 @ 0x005c04f0  size=200
CALLERS (2): FUN_0062dc40@0x0062dc40, FUN_005fada0@0x005fada0
CALLEES (3): FUN_005be0a0@0x005be0a0, FUN_005c1ff0@0x005c1ff0, FUN_005bf0e0@0x005bf0e0
----------------------------------------------------------------

long FUN_005c04f0(undefined8 param_1,undefined8 param_2)

{
  undefined2 uVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  
  lVar2 = FUN_005be0a0(1,0);
  lVar3 = -1;
  if (lVar2 != -1) {
    uVar1 = FUN_005c1ff0(param_1,param_2);
    iVar4 = (int)lVar2 * 0x20;
    *(undefined2 *)(iVar4 + 0x6ca97c) = uVar1;
    func_0x001dcdfc(uRam006febac,*(undefined4 *)(((uint)param_1 & 0xffff) * 0x24 + 0x6fee68),param_2
                    ,1,0x5c05c0);
    uVar1 = FUN_005bf0e0(2,param_1);
    *(undefined2 *)(iVar4 + 0x6ca97e) = uVar1;
    lVar3 = lVar2;
  }
  return lVar3;
}



================================================================