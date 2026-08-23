
void FUN_00113cd0(int param_1,ulong param_2,undefined4 *param_3)

{
  ushort *puVar1;
  undefined1 *puVar2;
  long lVar3;
  ushort *puVar4;
  int iVar5;
  int iVar6;
  
  if (param_1 == 3) {
    lVar3 = FUN_00113b48(*param_3,param_3[4],param_3[1] & 0xffff);
    if (-1 < lVar3) {
      param_3[4] = param_3[4] + (int)lVar3;
      param_3[1] = param_3[1] - (int)lVar3;
      return;
    }
    FUN_00114a90(0x24fd60);
  }
  else {
    if (param_1 < 4) {
      if (param_1 < 1) {
        return;
      }
      if (param_2 == 0) {
        puVar1 = (ushort *)param_3[5];
        iVar6 = 0xc;
        if (0xc < *puVar1) {
          iVar5 = param_3[6];
          puVar4 = puVar1;
          while( true ) {
            puVar2 = (undefined1 *)((int)puVar4 + iVar6);
            iVar6 = iVar6 + 1;
            **(undefined1 **)(iVar5 + 0xc) = *puVar2;
            FUN_00113c50(param_3[6]);
            if ((int)(uint)*puVar1 <= iVar6) break;
            puVar4 = (ushort *)param_3[5];
            iVar5 = param_3[6];
          }
        }
        param_3[2] = 0;
        return;
      }
      if (0x140 < (uint)(param_3[2] + (int)param_2)) {
        FUN_00114a90(0x24fd20);
      }
      lVar3 = FUN_00113b10(*param_3,param_3[5] + param_3[2],param_2 & 0xffff);
      if (lVar3 < 0) {
        FUN_00114a90(0x24fd48);
      }
      param_3[2] = param_3[2] + (int)lVar3;
      return;
    }
    if (param_1 != 4) {
      return;
    }
    if (param_3[1] != 0) {
      FUN_00114a90(0x24fd78,param_3[1]);
    }
  }
  param_3[3] = 0;
  return;
}
