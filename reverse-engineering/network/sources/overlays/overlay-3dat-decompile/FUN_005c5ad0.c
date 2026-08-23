FUNCTION FUN_005c5ad0 @ 0x005c5ad0  size=220
CALLERS (1): FUN_005c40a0@0x005c40a0
CALLEES (2): FUN_005be0a0@0x005be0a0, FUN_005c6fb0@0x005c6fb0
----------------------------------------------------------------

long FUN_005c5ad0(undefined8 param_1,undefined8 param_2)

{
  undefined2 uVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  int iVar5;
  undefined1 auStack_10 [16];
  
  lVar3 = FUN_005be0a0(1,0,param_2);
  lVar4 = -1;
  if (lVar3 != -1) {
    uVar1 = FUN_005c6fb0(param_1);
    iVar5 = (int)lVar3 * 0x20;
    *(undefined2 *)(iVar5 + 0x6ca97c) = uVar1;
    func_0x00106b60(auStack_10,0,0x10);
    func_0x00109eb8(auStack_10,param_1);
    iVar2 = func_0x001ae3e0(param_1);
    if (iVar2 < 0xf) {
      auStack_10[iVar2] = 0x2d;
      iVar2 = iVar2 + 1;
    }
    uVar1 = func_0x001dff7c(uRam006febac,auStack_10,iVar2,1,0x5c5a10);
    *(undefined2 *)(iVar5 + 0x6ca97e) = uVar1;
    lVar4 = lVar3;
  }
  return lVar4;
}



================================================================