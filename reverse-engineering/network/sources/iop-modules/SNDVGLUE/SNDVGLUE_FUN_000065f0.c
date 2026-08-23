FUNCTION FUN_000065f0 @ 0x000065f0 size=412
CALLERS (1): FUN_0000678c@0x0000678c
CALLEES (2): FUN_00008044@0x00008044, FUN_00007d04@0x00007d04

undefined4 FUN_000065f0(undefined4 param_1,int param_2,uint param_3)

{
  char *pcVar1;
  ushort local_18;
  ushort local_16 [3];
  
  do {
    if ((param_3 & 0xffff) == 0) {
      return 0;
    }
    FUN_00008044(&local_18,param_2,2);
    local_18 = local_18 << 8 | local_18 >> 8;
    if (local_18 == 0) {
      return 0;
    }
    FUN_00008044(local_16,param_2 + 2,2);
    local_16[0] = local_16[0] << 8 | local_16[0] >> 8;
    if (local_18 == 0x202) {
      if ((DAT_00009710 & 2) == 0) goto LAB_00006750;
      pcVar1 = "[ac system error]:";
LAB_00006748:
      FUN_00007d04(pcVar1,param_2 + 4,local_16[0]);
    }
    else if (local_18 < 0x203) {
      if (local_18 == 0x201) {
        if ((DAT_00009710 & 2) != 0) {
          pcVar1 = "[service name error]:";
          goto LAB_00006748;
        }
      }
      else {
LAB_00006724:
        if ((DAT_00009710 & 2) != 0) {
          pcVar1 = "[unknown tag]:";
          goto LAB_00006748;
        }
      }
    }
    else {
      if (local_18 != 0x203) goto LAB_00006724;
      if ((DAT_00009710 & 2) != 0) {
        pcVar1 = "[generic error]:";
        goto LAB_00006748;
      }
    }
LAB_00006750:
    param_2 = param_2 + local_16[0] + 4;
    param_3 = (param_3 - 4) - (uint)local_16[0];
  } while( true );
}


================================================================