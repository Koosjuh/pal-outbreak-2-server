FUNCTION FUN_00000834 @ 0x00000834 size=252
CALLERS (1): FUN_00002098@0x00002098
CALLEES (2): FUN_00002804@0x00002804, FUN_00000010@0x00000010

void FUN_00000834(int param_1)

{
  short sVar1;
  int iVar2;
  undefined2 local_30;
  ushort local_2e;
  int local_2c;
  undefined4 local_28;
  short local_20 [3];
  ushort local_1a;
  undefined2 local_18 [4];
  
  iVar2 = FUN_00000010();
  if (-1 < iVar2 << 0x10) {
    local_18[0] = *(undefined2 *)(param_1 + 0x1c);
    sVar1 = FUN_00002804(&DAT_00004117,local_18,local_20);
    iVar2 = (int)sVar1;
    if ((-1 < iVar2) &&
       ((local_20[0] == 4 ||
        (((local_20[0] == 5 || (iVar2 = -6, local_20[0] == -1)) && (iVar2 = -6, local_1a != 0))))))
    {
      if (local_1a == 0) {
        *(undefined4 *)(param_1 + 0x18) = 0;
        return;
      }
      local_30 = *(undefined2 *)(param_1 + 0x1c);
      local_2e = *(ushort *)(param_1 + 0x1e);
      if ((int)(uint)local_1a < (int)(short)*(ushort *)(param_1 + 0x1e)) {
        local_2e = local_1a;
      }
      local_2c = param_1 + 0x20;
      local_28 = 0;
      sVar1 = FUN_00002804(&DAT_00004119,&local_30,0);
      iVar2 = (int)sVar1;
    }
    *(int *)(param_1 + 0x18) = iVar2;
  }
  return;
}


================================================================