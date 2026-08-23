FUNCTION FUN_0000122c @ 0x0000122c size=160
CALLERS (1): FUN_00002098@0x00002098
CALLEES (1): FUN_00002804@0x00002804

void FUN_0000122c(int param_1)

{
  short sVar1;
  undefined2 local_10 [2];
  int local_c;
  
  sVar1 = FUN_00002804(&DAT_00004161,0,0);
  if (((sVar1 == 0) && (sVar1 = FUN_00002804(&DAT_00004163,0,&local_c), sVar1 == 0)) &&
     (local_c != 0)) {
    local_10[0] = 0;
    sVar1 = FUN_00002804(&DAT_00004141,local_10,0);
    if (sVar1 == 0) {
      *(undefined4 *)(param_1 + 0x18) = 0;
      DAT_000030cc = local_c;
      return;
    }
  }
  *(undefined4 *)(param_1 + 0x18) = 0xffffffff;
  return;
}


================================================================