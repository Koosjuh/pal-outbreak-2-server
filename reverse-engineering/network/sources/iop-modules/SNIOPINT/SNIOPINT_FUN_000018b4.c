FUNCTION FUN_000018b4 @ 0x000018b4 size=160
CALLERS (1): FUN_00002858@0x00002858
CALLEES (1): FUN_00003614@0x00003614

void FUN_000018b4(int param_1)

{
  short sVar1;
  undefined2 local_10 [2];
  int local_c;
  
  sVar1 = FUN_00003614(&DAT_00004151,0,0);
  if (((sVar1 == 0) && (sVar1 = FUN_00003614(&DAT_00004153,0,&local_c), sVar1 == 0)) &&
     (local_c != 0)) {
    local_10[0] = 0;
    sVar1 = FUN_00003614(&DAT_00004141,local_10,0);
    if (sVar1 == 0) {
      *(undefined4 *)(param_1 + 0x18) = 0;
      DAT_00003ae0 = local_c;
      return;
    }
  }
  *(undefined4 *)(param_1 + 0x18) = 0xffffffff;
  return;
}


================================================================