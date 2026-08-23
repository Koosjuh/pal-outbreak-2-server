FUNCTION FUN_0060dea0 @ 0x0060dea0  size=444
CALLERS (1): FUN_005d7a30@0x005d7a30
CALLEES (7): FUN_0060de60@0x0060de60, FUN_0060ca90@0x0060ca90, FUN_0060da80@0x0060da80, FUN_0060dc90@0x0060dc90, FUN_0060c9e0@0x0060c9e0, FUN_0060d930@0x0060d930, FUN_0060d4a0@0x0060d4a0
----------------------------------------------------------------

ulong FUN_0060dea0(undefined8 param_1,undefined8 param_2,undefined2 *param_3,undefined2 *param_4)

{
  short sVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  ulong uVar4;
  long lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  ulong uVar8;
  int iVar9;
  undefined4 *extraout_t0_lo;
  undefined1 auStack_50 [4];
  undefined4 uStack_4c;
  uint uStack_48;
  
  uVar4 = func_0x00193a50();
  if (uVar4 == 0) {
    uVar4 = 0xffffffffffffffff;
  }
  else {
    iVar9 = (((uint)uVar4 & 0xffff) - 1) * 0x38;
    lVar5 = FUN_0060d930(auStack_50,param_1);
    if (lVar5 == 0) {
      uVar4 = 0xfffffffffffffffe;
    }
    else {
      uVar2 = (undefined2)uStack_4c;
      uVar3 = FUN_0060ca90();
      *extraout_t0_lo = uVar3;
      uStack_4c = FUN_0060c9e0(uStack_4c,*extraout_t0_lo);
      lVar5 = func_0x00193460(auStack_50,1,uVar4,param_2);
      if (lVar5 == 0) {
        uVar4 = 0xfffffffffffffffd;
      }
      else {
        uVar3 = func_0x00184170(*(undefined4 *)(iVar9 + 0x282a88),2);
        *(undefined4 *)(iVar9 + 0x282aa4) = uVar3;
        if (*(int *)(iVar9 + 0x282aa4) == 0) {
          FUN_0060d4a0(uVar4);
          uVar4 = 0xffffffffffffffff;
        }
        else {
          uVar6 = func_0x001841c0();
          uVar7 = FUN_0060de60(param_1);
          sVar1 = *(short *)((int)param_1 + 0x1c);
          FUN_0060da80(auStack_50,uVar6,uVar7,sVar1,uVar2,uStack_48 & 0xffff,param_1);
          func_0x00193670(uVar4,param_2);
          if (sVar1 == 8) {
            uVar8 = FUN_0060dc90(param_2,param_1);
            if (uVar8 == 0) {
              func_0x001841b0(*(undefined4 *)(iVar9 + 0x282aa4));
              FUN_0060d4a0(uVar4);
              return 0xffffffffffffffff;
            }
            uVar4 = uVar4 | uVar8;
          }
          *param_3 = uVar2;
          *param_4 = (short)uStack_48;
        }
      }
    }
  }
  return uVar4;
}



================================================================