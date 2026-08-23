FUNCTION FUN_005c2120 @ 0x005c2120  size=152
CALLERS (1): FUN_005ffa90@0x005ffa90
CALLEES (2): FUN_005be0a0@0x005be0a0, FUN_005c2250@0x005c2250
----------------------------------------------------------------

long FUN_005c2120(undefined8 param_1)

{
  undefined2 uVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  
  uRam007005ad = 1;
  lVar2 = FUN_005be0a0(1,0,param_1);
  lVar3 = -1;
  if (lVar2 != -1) {
    uVar1 = FUN_005c2250();
    iVar4 = (int)lVar2 * 0x20;
    *(undefined2 *)(iVar4 + 0x6ca97c) = uVar1;
    uVar1 = func_0x001de470(uRam006febac,0x7004d0,0x5c21c0);
    *(undefined2 *)(iVar4 + 0x6ca97e) = uVar1;
    lVar3 = lVar2;
  }
  return lVar3;
}



================================================================