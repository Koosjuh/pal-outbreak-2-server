FUNCTION FUN_00001568 @ 0x00001568 size=544
CALLERS (2): FUN_00001d38@0x00001d38, FUN_000029ac@0x000029ac
CALLEES (2): FUN_0000046c@0x0000046c, FUN_000012ac@0x000012ac

void FUN_00001568(undefined4 param_1)

{
  int iVar1;
  uint *local_28;
  uint local_24;
  uint local_20 [2];
  
  iVar1 = FUN_000012ac(param_1,0x33,&local_28);
  if (iVar1 == 4) {
    local_24 = *local_28;
    local_20[0] = local_24 >> 0x18 | local_24 >> 8 & 0xff00 | (local_24 & 0xff00) << 8 |
                  local_24 << 0x18;
    FUN_0000046c(7,4,local_20);
    iVar1 = FUN_000012ac(param_1,0x3a,&local_28);
    if (iVar1 == 4) {
      local_24 = *local_28;
      local_20[0] = local_24 >> 0x18 | local_24 >> 8 & 0xff00 | (local_24 & 0xff00) << 8 |
                    local_24 << 0x18;
      FUN_0000046c(8,4,local_20);
    }
    else {
      FUN_0000046c(8,0,0);
      DAT_0000429c = DAT_00004298 >> 1;
    }
    iVar1 = FUN_000012ac(param_1,0x3b,&local_28);
    if (iVar1 == 4) {
      local_24 = *local_28;
      local_20[0] = local_24 >> 0x18 | local_24 >> 8 & 0xff00 | (local_24 & 0xff00) << 8 |
                    local_24 << 0x18;
      FUN_0000046c(9,4,local_20);
    }
    else {
      FUN_0000046c(9,0,0);
      DAT_000042a0 = (DAT_00004298 >> 1) + (DAT_00004298 >> 2) + (DAT_00004298 >> 3);
    }
  }
  else {
    FUN_0000046c(7,0,0);
    DAT_00004298 = 0xffffffff;
  }
  return;
}


================================================================