FUNCTION FUN_0000057c @ 0x0000057c size=324
CALLERS (1): FUN_000007f0@0x000007f0
CALLEES (9): FUN_0000092c@0x0000092c, FUN_00000900@0x00000900, FUN_000009f4@0x000009f4, FUN_0000052c@0x0000052c, FUN_0000099c@0x0000099c, FUN_000008c4@0x000008c4, FUN_00000908@0x00000908, FUN_000009e4@0x000009e4, FUN_000009c0@0x000009c0

undefined4 FUN_0000057c(void)

{
  undefined4 uVar1;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_18;
  undefined4 local_14;
  int local_10;
  
  FUN_00000900(&local_14);
  local_18 = FUN_0000092c(0x880);
  FUN_00000908(local_14);
  if (local_18 == 0) {
    FUN_000009c0(0xbc8,0xff,0x210);
    DAT_00000b60 = FUN_0000052c();
    if (DAT_00000b60 < 1) {
      uVar1 = 1;
    }
    else {
      local_20 = 0x40;
      local_24 = 0x800;
      local_28 = 0x4a4;
      local_30 = 0x2000000;
      local_2c = 0;
      local_10 = FUN_000009e4(&local_30);
      if (local_10 < 1) {
        uVar1 = 1;
      }
      else {
        FUN_000009f4(local_10,0);
        DAT_00000bc4 = local_10;
        FUN_000008c4(0xae8);
        FUN_0000099c(0xab4,0x40,0x55,0x2e);
        uVar1 = 2;
      }
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


================================================================