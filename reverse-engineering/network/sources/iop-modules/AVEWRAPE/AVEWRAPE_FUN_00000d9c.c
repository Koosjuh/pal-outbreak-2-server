FUNCTION FUN_00000d9c @ 0x00000d9c size=184
CALLERS (1): FUN_00002098@0x00002098
CALLEES (2): FUN_00002804@0x00002804, FUN_00000cd8@0x00000cd8

void FUN_00000d9c(int param_1)

{
  short sVar1;
  undefined2 local_18 [2];
  int local_14;
  
  FUN_00000cd8(&DAT_000030d0);
  sVar1 = FUN_00002804(&DAT_00004151,&DAT_000030d0,0);
  if (((sVar1 == 0) && (sVar1 = FUN_00002804(&DAT_00004153,0,&local_14), sVar1 == 0)) &&
     (local_14 != 0)) {
    local_18[0] = 0;
    sVar1 = FUN_00002804(&DAT_00004141,local_18,0);
    if (sVar1 == 0) {
      *(undefined4 *)(param_1 + 0x18) = 0;
      DAT_000030cc = local_14;
      return;
    }
  }
  *(undefined4 *)(param_1 + 0x18) = 0xffffffff;
  return;
}


================================================================