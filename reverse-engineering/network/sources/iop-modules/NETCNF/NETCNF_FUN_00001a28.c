FUNCTION FUN_00001a28 @ 0x00001a28 size=184
CALLERS (2): FUN_00001cdc@0x00001cdc, FUN_000027e4@0x000027e4
CALLEES (3): FUN_000018b0@0x000018b0, FUN_000014ac@0x000014ac, FUN_0000198c@0x0000198c

int FUN_00001a28(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 auStack_210 [256];
  undefined1 auStack_110 [256];
  
  iVar1 = FUN_0000198c(auStack_210,0x100,param_1);
  if (iVar1 != 0) {
    FUN_000014ac(auStack_110,0x100,auStack_210,"SYS_NET.ICO");
    iVar1 = FUN_000018b0(param_2,auStack_110);
    if (iVar1 < 0) {
      return iVar1;
    }
    FUN_000014ac(auStack_110,0x100,auStack_210,"icon.sys");
    iVar1 = FUN_000018b0(param_3,auStack_110);
    if (iVar1 < 0) {
      return iVar1;
    }
  }
  return 0;
}


================================================================