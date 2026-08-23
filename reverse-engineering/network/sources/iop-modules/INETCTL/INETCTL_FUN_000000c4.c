FUNCTION FUN_000000c4 @ 0x000000c4 size=64
CALLERS (6): FUN_00002d38@0x00002d38, FUN_0000271c@0x0000271c, FUN_0000332c@0x0000332c, FUN_00003528@0x00003528, FUN_00003ad0@0x00003ad0, FUN_00000a4c@0x00000a4c
CALLEES (3): FUN_00003eac@0x00003eac, FUN_00003ed0@0x00003ed0, FUN_00003ed8@0x00003ed8

void FUN_000000c4(int param_1)

{
  undefined4 local_10 [2];
  
  if (param_1 != 0) {
    FUN_00003ed0(local_10);
    FUN_00003eac(param_1);
    FUN_00003ed8(local_10[0]);
  }
  return;
}


================================================================