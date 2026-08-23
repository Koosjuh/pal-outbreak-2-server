FUNCTION FUN_0060acb0 @ 0x0060acb0  size=360
CALLERS (1): FUN_0060ae20@0x0060ae20
CALLEES (4): thunk_FUN_0060c0f0@0x0060bfe0, FUN_00608b70@0x00608b70, FUN_0060ac30@0x0060ac30, FUN_0060abc0@0x0060abc0
----------------------------------------------------------------

undefined4 FUN_0060acb0(long param_1,uint param_2,long param_3,long param_4)

{
  undefined4 uVar1;
  long lVar2;
  undefined8 uVar3;
  int iVar4;
  
  if (((param_3 == 0) || (*(char *)param_3 != s_1_1_4_0064a260[0])) || (param_4 != 0x48)) {
    uVar1 = 0xfffffffa;
  }
  else {
    uVar1 = 0xfffffffe;
    if (param_1 != 0) {
      iVar4 = (int)param_1;
      *(undefined4 *)(iVar4 + 0x20) = 0;
      if (*(int *)(iVar4 + 0x28) == 0) {
        *(code **)(iVar4 + 0x28) = thunk_FUN_0060c0f0;
        *(undefined4 *)(iVar4 + 0x30) = 0;
      }
      if (*(int *)(iVar4 + 0x2c) == 0) {
        *(undefined1 **)(iVar4 + 0x2c) = &LAB_0060bff0;
      }
      lVar2 = (**(code **)(iVar4 + 0x28))(*(undefined4 *)(iVar4 + 0x30),1,0x28);
      *(int *)(iVar4 + 0x24) = (int)lVar2;
      if (lVar2 == 0) {
        uVar1 = 0xfffffffc;
      }
      else {
        *(undefined4 *)(*(int *)(iVar4 + 0x24) + 0x20) = 0;
        *(undefined4 *)(*(int *)(iVar4 + 0x24) + 0x18) = 0;
        if ((int)param_2 < 0) {
          param_2 = -param_2;
          *(undefined4 *)(*(int *)(iVar4 + 0x24) + 0x18) = 1;
        }
        if (((int)param_2 < 8) || (0xf < (int)param_2)) {
          FUN_0060ac30(param_1);
          uVar1 = 0xfffffffe;
        }
        else {
          *(uint *)(*(int *)(iVar4 + 0x24) + 0x1c) = param_2;
          if (*(int *)(*(int *)(iVar4 + 0x24) + 0x18) == 0) {
            uVar3 = 0x60be50;
          }
          else {
            uVar3 = 0;
          }
          lVar2 = FUN_00608b70(param_1,uVar3,1 << (param_2 & 0x1f));
          *(int *)(*(int *)(iVar4 + 0x24) + 0x20) = (int)lVar2;
          if (lVar2 == 0) {
            FUN_0060ac30(param_1);
            uVar1 = 0xfffffffc;
          }
          else {
            FUN_0060abc0(param_1);
            uVar1 = 0;
          }
        }
      }
    }
  }
  return uVar1;
}



================================================================