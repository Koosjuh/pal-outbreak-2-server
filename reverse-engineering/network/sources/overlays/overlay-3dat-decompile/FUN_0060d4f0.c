FUNCTION FUN_0060d4f0 @ 0x0060d4f0  size=536
CALLERS (1): FUN_005d7a30@0x005d7a30
CALLEES (7): FUN_0060cb40@0x0060cb40, thunk_FUN_0060c000@0x0060c240, FUN_0060d1d0@0x0060d1d0, FUN_0060c000@0x0060c000, FUN_0060d710@0x0060d710, FUN_0060ac30@0x0060ac30, FUN_0060d4a0@0x0060d4a0
----------------------------------------------------------------

ulong FUN_0060d4f0(undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined2 *param_4,
                  undefined2 *param_5)

{
  undefined4 uVar1;
  ulong uVar2;
  long lVar3;
  undefined8 uVar4;
  ulong uVar5;
  int iVar6;
  undefined1 auStack_50 [80];
  
  FUN_0060c000();
  func_0x00106b60(0x70d100,0,0xc0);
  uRam0070d108 = 0;
  uRam0070d100 = param_2;
  uRam0070d104 = param_2;
  uVar2 = func_0x00193a50();
  if (uVar2 == 0) {
    uVar2 = 0xffffffffffffffff;
  }
  else {
    iVar6 = (((uint)uVar2 & 0xffff) - 1) * 0x38;
    lVar3 = FUN_0060cb40(auStack_50,param_1);
    if (lVar3 == 0) {
      thunk_FUN_0060c000();
      uVar2 = 0xfffffffffffffffe;
    }
    else {
      lVar3 = func_0x00193460(auStack_50,1,uVar2,param_3);
      if (lVar3 == 0) {
        thunk_FUN_0060c000();
        uVar2 = 0xfffffffffffffffd;
      }
      else {
        uVar1 = func_0x00184170(*(undefined4 *)(iVar6 + 0x282a88),2);
        *(undefined4 *)(iVar6 + 0x282aa4) = uVar1;
        if (*(int *)(iVar6 + 0x282aa4) == 0) {
          thunk_FUN_0060c000();
          FUN_0060d4a0(uVar2);
          uVar2 = 0xffffffffffffffff;
        }
        else {
          uVar4 = func_0x001841c0();
          FUN_0060d1d0(auStack_50,uVar4);
          if (cRam0070d10c == '\0') {
            func_0x00193670(uVar2,param_3);
            if (cRam0070d11e == '\b') {
              uVar5 = FUN_0060d710(param_3);
              if (uVar5 == 0) {
                FUN_0060ac30(0x70d128);
                thunk_FUN_0060c000();
                func_0x001841b0(*(undefined4 *)(iVar6 + 0x282aa4));
                FUN_0060d4a0(uVar2);
                return 0xffffffffffffffff;
              }
              uVar2 = uVar2 | uVar5;
            }
            FUN_0060ac30(0x70d128);
            thunk_FUN_0060c000();
            *param_4 = (short)uRam0070d110;
            *param_5 = (short)uRam0070d114;
          }
          else {
            FUN_0060ac30(0x70d128);
            thunk_FUN_0060c000();
            func_0x001841b0(*(undefined4 *)(iVar6 + 0x282aa4));
            FUN_0060d4a0(uVar2);
            uVar2 = 0xfffffffffffffffe;
          }
        }
      }
    }
  }
  return uVar2;
}



================================================================