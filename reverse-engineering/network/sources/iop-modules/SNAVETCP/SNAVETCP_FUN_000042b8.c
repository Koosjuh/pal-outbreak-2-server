FUNCTION FUN_000042b8 @ 0x000042b8 size=68
CALLERS (3): FUN_0000e7ec@0x0000e7ec, FUN_0000e750@0x0000e750, FUN_0000e944@0x0000e944
CALLEES (0): 

int FUN_000042b8(short param_1)

{
  if ((int)DAT_00016160 <= (int)param_1) {
    return 0;
  }
  return param_1 * 0x2c + 0x22870;
}


================================================================