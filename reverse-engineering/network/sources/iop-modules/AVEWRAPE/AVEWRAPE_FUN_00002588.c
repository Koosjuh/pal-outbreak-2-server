FUNCTION FUN_00002588 @ 0x00002588 size=308
CALLERS (1): FUN_00002770@0x00002770
CALLEES (7): FUN_00002884@0x00002884, FUN_0000287c@0x0000287c, FUN_00002978@0x00002978, FUN_000028a8@0x000028a8, FUN_00002968@0x00002968, FUN_00002918@0x00002918, FUN_000029ac@0x000029ac

undefined4 FUN_00002588(void)

{
  int iVar1;
  undefined4 local_38;
  undefined4 local_34;
  code *local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10 [2];
  
  FUN_0000287c(local_10);
  iVar1 = FUN_000028a8(&DAT_000027b0);
  FUN_00002884(local_10[0]);
  if (iVar1 == 0) {
    local_20 = 0;
    local_18 = 1;
    local_14 = 1;
    local_1c = 0;
    DAT_00004db0 = FUN_000029ac(&local_20);
    if (-1 < DAT_00004db0) {
      local_38 = 0x2000000;
      local_30 = FUN_0000250c;
      local_28 = 9;
      DAT_00004a24 = 0;
      local_2c = 0x4000;
      local_34 = 0;
      iVar1 = FUN_00002968(&local_38);
      if (0 < iVar1) {
        FUN_00002978(iVar1,0);
        DAT_00004a20 = iVar1;
        FUN_00002918("Ave wrapper 2004.01.07-%d-%d(%d-%d)/%c%c%c%c%c%c%c%c%c%c%c%c\n",9,9,1,8,0x2d,
                     0x2d,0x44,0x2d,0x56,0x2d,0x2d,0x2d,0x55,0x49,0x2d,0x2e);
        return 2;
      }
    }
  }
  return 1;
}


================================================================