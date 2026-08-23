FUNCTION FUN_00000724 @ 0x00000724 size=184
CALLERS (1): FUN_00002098@0x00002098
CALLEES (2): FUN_00002804@0x00002804, FUN_00000010@0x00000010

void FUN_00000724(int param_1)

{
  short sVar1;
  int iVar2;
  undefined2 local_38 [2];
  undefined4 local_34;
  undefined1 local_30;
  undefined1 local_2f;
  undefined2 local_2c;
  int local_28;
  short local_20 [4];
  undefined2 local_18 [4];
  
  iVar2 = FUN_00000010();
  if (-1 < iVar2 << 0x10) {
    local_18[0] = *(undefined2 *)(param_1 + 0x1c);
    sVar1 = FUN_00002804(&DAT_00004117,local_18,local_20);
    iVar2 = (int)sVar1;
    if (-1 < iVar2) {
      if (local_20[0] == 4) {
        local_38[0] = *(undefined2 *)(param_1 + 0x1c);
        local_34 = 0;
        local_30 = 0;
        local_2f = 1;
        local_2c = *(undefined2 *)(param_1 + 0x1e);
        local_28 = param_1 + 0x20;
        sVar1 = FUN_00002804(&DAT_00004118,local_38,0);
        iVar2 = (int)sVar1;
      }
      else {
        iVar2 = -6;
      }
    }
    *(int *)(param_1 + 0x18) = iVar2;
  }
  return;
}


================================================================