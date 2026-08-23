FUNCTION FUN_00009378 @ 0x00009378 size=108
CALLERS (1): FUN_000027e4@0x000027e4
CALLEES (3): FUN_00009330@0x00009330, FUN_000096e4@0x000096e4, FUN_00009720@0x00009720

undefined4 FUN_00009378(undefined4 param_1)

{
  undefined4 uVar1;
  uint local_48 [16];
  
  if (DAT_0000afd0 == 0) {
    FUN_00009330(param_1,local_48);
    local_48[0] = local_48[0] | 8;
    FUN_000096e4(param_1,local_48,1);
    uVar1 = 0;
  }
  else {
    FUN_00009720("[err] netcnf chstat()\n");
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


================================================================