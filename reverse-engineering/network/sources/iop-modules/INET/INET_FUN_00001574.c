FUNCTION FUN_00001574 @ 0x00001574 size=76
CALLERS (3): FUN_000027d8@0x000027d8, FUN_000029f8@0x000029f8, FUN_00004b68@0x00004b68
CALLEES (1): FUN_00011d90@0x00011d90

void FUN_00001574(undefined1 *param_1)

{
  FUN_00011d90("%02x:%02x:%02x:%02x:%02x:%02x",*param_1,param_1[1],param_1[2],param_1[3],param_1[4],
               param_1[5]);
  return;
}


================================================================