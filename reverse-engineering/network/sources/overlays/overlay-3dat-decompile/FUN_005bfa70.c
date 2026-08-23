FUNCTION FUN_005bfa70 @ 0x005bfa70  size=196
CALLERS (2): FUN_005ad030@0x005ad030, FUN_005ad680@0x005ad680
CALLEES (3): FUN_005be0a0@0x005be0a0, FUN_005c1f30@0x005c1f30, FUN_005bf0e0@0x005bf0e0
----------------------------------------------------------------

long FUN_005bfa70(undefined8 param_1,undefined8 param_2)

{
  undefined2 uVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  
  uRam00700680 = 0;
  uRam00700682 = 0;
  lVar2 = FUN_005be0a0(1,0,param_2);
  lVar3 = -1;
  if (lVar2 != -1) {
    FUN_005bf0e0(0,param_1);
    uVar1 = FUN_005c1f30(0);
    iVar4 = (int)lVar2 * 0x20;
    *(undefined2 *)(iVar4 + 0x6ca97c) = uVar1;
    uVar1 = func_0x001dc9fc(uRam006febac,*(undefined4 *)(((uint)param_1 & 0xffff) * 0x24 + 0x6fec04)
                            ,0x5bfb40);
    *(undefined2 *)(iVar4 + 0x6ca97e) = uVar1;
    lVar3 = lVar2;
  }
  return lVar3;
}



================================================================