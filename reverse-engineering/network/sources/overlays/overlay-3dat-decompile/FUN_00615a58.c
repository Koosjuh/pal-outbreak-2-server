FUNCTION FUN_00615a58 @ 0x00615a58  size=960
CALLERS (0): 
CALLEES (5): thunk_FUN_00616b40@0x006157d8, FUN_006158c8@0x006158c8, FUN_006157e8@0x006157e8, FUN_00615930@0x00615930, FUN_006159c0@0x006159c0
----------------------------------------------------------------

undefined4 FUN_00615a58(undefined8 param_1,uint param_2,undefined8 param_3,int param_4)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int aiStack_3c0 [196];
  int iStack_b0;
  uint uStack_ac;
  
  uStack_ac = param_2 & 0xffff;
  iVar10 = 0;
  iStack_b0 = 0;
  if (1 < uStack_ac - 1) {
    func_0x00105e30(0);
    func_0x00105e30(0);
    return 0xfffffff6;
  }
  bVar2 = (param_2 & 0x10000) == 0;
  FUN_006158c8(param_1,uStack_ac);
  do {
    lVar5 = thunk_FUN_00616b40(bVar2);
  } while (lVar5 != 0);
  FUN_006157e8(aiStack_3c0);
  iVar4 = aiStack_3c0[0];
  if (aiStack_3c0[0] < 1) {
    func_0x00105e30(0);
    iVar4 = 0;
  }
  else {
    iVar3 = func_0x00105ba8(0x40,aiStack_3c0[0] * 0x240);
    iVar7 = 0;
    if (iVar3 == 0) {
LAB_00615c34:
      func_0x00105e30(iVar7);
      func_0x00105e30(0);
      return 0xfffffffe;
    }
    func_0x00112b20(0);
    FUN_00615930(param_1,uStack_ac,iVar3,iVar4);
    do {
      lVar5 = thunk_FUN_00616b40(bVar2);
    } while (lVar5 != 0);
    FUN_006157e8(aiStack_3c0);
    if (aiStack_3c0[0] < 0) {
      func_0x00105e30(iVar3);
      iVar4 = 0;
    }
    else {
      iVar8 = 0;
      iVar7 = iVar3;
      while ((iVar9 = iStack_b0, iVar8 < iVar4 &&
             (lVar5 = func_0x00109d70(param_3,iVar7 + 0x108), iVar9 = iVar7, lVar5 != 0))) {
        iVar7 = iVar7 + 0x240;
        iVar8 = iVar8 + 1;
      }
      iStack_b0 = iVar9;
      if (iStack_b0 == 0) {
        func_0x00105e30(iVar3);
        iVar4 = 0;
LAB_00615d3c:
        func_0x00105e30(iVar4);
        return 0xfffffff8;
      }
      FUN_006158c8(param_1,0);
      do {
        lVar5 = thunk_FUN_00616b40(bVar2);
      } while (lVar5 != 0);
      FUN_006157e8(aiStack_3c0);
      iVar8 = aiStack_3c0[0];
      if (aiStack_3c0[0] < 1) {
        func_0x00105e30(iVar3);
        iVar4 = 0;
      }
      else {
        iVar4 = func_0x00105ba8(0x40,aiStack_3c0[0] * 0x240);
        iVar7 = iVar3;
        if (iVar4 == 0) goto LAB_00615c34;
        func_0x00112b20(0);
        FUN_00615930(param_1,0,iVar4,iVar8);
        do {
          lVar5 = thunk_FUN_00616b40(bVar2);
        } while (lVar5 != 0);
        FUN_006157e8(aiStack_3c0);
        if (-1 < aiStack_3c0[0]) {
          iVar9 = 0;
          iVar7 = iVar4;
          if (0 < iVar8) {
            do {
              func_0x00112b20(0);
              FUN_006159c0(param_1,0,iVar7 + 0x108,param_4);
              do {
                lVar5 = thunk_FUN_00616b40(bVar2);
              } while (lVar5 != 0);
              FUN_006157e8(aiStack_3c0);
              if (aiStack_3c0[0] < 0) {
                func_0x00105e30(iVar3);
                func_0x00105e30(iVar4);
                return 0xffffffff;
              }
              iVar6 = param_4;
              if (uStack_ac != 1) {
                iVar6 = param_4 + 0x100;
              }
              lVar5 = func_0x00109d70(iStack_b0 + 8,iVar6);
              if ((lVar5 == 0) && (bVar1 = iVar10 != 0, iVar10 = iVar7, bVar1)) {
                func_0x00105e30(iVar3);
                func_0x00105e30(iVar4);
                return 0xfffffff4;
              }
              iVar9 = iVar9 + 1;
              iVar7 = iVar7 + 0x240;
            } while (iVar9 < iVar8);
          }
          if (iVar10 == 0) {
            func_0x00105e30(iVar3);
            goto LAB_00615d3c;
          }
          func_0x00112b20(0);
          FUN_006159c0(param_1,0,iVar10 + 0x108,param_4);
          do {
            lVar5 = thunk_FUN_00616b40(bVar2);
          } while (lVar5 != 0);
          FUN_006157e8(aiStack_3c0);
          if (-1 < aiStack_3c0[0]) {
            func_0x00105e30(iVar3);
            func_0x00105e30(iVar4);
            return 0;
          }
        }
        func_0x00105e30(iVar3);
      }
    }
  }
  func_0x00105e30(iVar4);
  return 0xffffffff;
}



================================================================