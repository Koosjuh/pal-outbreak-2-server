FUNCTION FUN_00007a90 @ 0x00007a90 size=144
CALLERS (3): FUN_00008270@0x00008270, FUN_00007660@0x00007660, FUN_00007fb4@0x00007fb4
CALLEES (4): FUN_0000226c@0x0000226c, FUN_00010c38@0x00010c38, FUN_00010be8@0x00010be8, FUN_0000231c@0x0000231c

void FUN_00007a90(void)

{
  short sVar1;
  undefined1 auStack_10 [4];
  short local_c;
  undefined1 auStack_a [2];
  
  do {
    sVar1 = FUN_00010be8(auStack_10);
    if (sVar1 == 0) {
      if ((DAT_00012efc & 1) != 0) {
        FUN_00010c38("aveppp: RemainRecv: device not ready.\n");
      }
      return;
    }
    sVar1 = FUN_0000231c(&local_c);
    if (sVar1 != 0) {
      return;
    }
    if (local_c == 0) {
      return;
    }
    sVar1 = FUN_0000226c(auStack_a,1);
  } while (sVar1 == 0);
  return;
}


================================================================