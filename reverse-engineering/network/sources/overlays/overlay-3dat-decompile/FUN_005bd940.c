FUNCTION FUN_005bd940 @ 0x005bd940  size=236
CALLERS (5): FUN_0062dc40@0x0062dc40, FUN_005f99c0@0x005f99c0, FUN_005b3790@0x005b3790, FUN_0062de90@0x0062de90, FUN_005fada0@0x005fada0
CALLEES (2): FUN_005be0a0@0x005be0a0, FUN_005bdef0@0x005bdef0
----------------------------------------------------------------

long FUN_005bd940(undefined8 param_1,ulong param_2,undefined8 param_3)

{
  undefined2 uVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  
  func_0x00106b60(0x7004d0,0,0xf0);
  func_0x001069a8(0x7004d0,param_1,param_2 & 0xffff);
  func_0x001069a8(0x7005b0,0x7005c0,0x10);
  lVar2 = FUN_005be0a0(1,0,param_3);
  lVar3 = -1;
  if (lVar2 != -1) {
    uVar1 = FUN_005bdef0(param_1,param_2);
    iVar4 = (int)lVar2 * 0x20;
    *(undefined2 *)(iVar4 + 0x6ca97c) = uVar1;
    uVar1 = func_0x001de470(uRam006febac,0x7004d0,0x5bd8c0);
    *(undefined2 *)(iVar4 + 0x6ca97e) = uVar1;
    lVar3 = lVar2;
  }
  return lVar3;
}



================================================================