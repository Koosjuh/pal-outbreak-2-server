FUNCTION FUN_005dfbc0 @ 0x005dfbc0  size=276
CALLERS (2): FUN_005e2fa0@0x005e2fa0, FUN_005cab10@0x005cab10
CALLEES (0): 
----------------------------------------------------------------

undefined8 FUN_005dfbc0(byte *param_1,byte *param_2,int param_3,int param_4)

{
  byte bVar1;
  
  while( true ) {
    while( true ) {
      while( true ) {
        while( true ) {
          bVar1 = *param_2;
          if (bVar1 == 0) {
            *param_1 = 0;
            return 0;
          }
          if (param_3 < param_4) {
            *param_1 = 0;
            return 0;
          }
          param_3 = param_3 - param_4;
          if (0x7f < bVar1) break;
          *param_1 = bVar1;
          param_2 = param_2 + 1;
          param_1 = param_1 + 1;
        }
        if ((bVar1 < 0xc0) || (0xdf < bVar1)) break;
        *param_1 = bVar1;
        bVar1 = param_2[1];
        if ((bVar1 < 0x80) || (0xbf < bVar1)) {
          param_1[1] = 0;
          return 0;
        }
        param_1[1] = bVar1;
        param_2 = param_2 + 2;
        param_1 = param_1 + 2;
      }
      if ((0xdf < bVar1) && (bVar1 < 0xf0)) break;
      *param_1 = bVar1;
      param_2 = param_2 + 1;
      param_1 = param_1 + 1;
    }
    *param_1 = bVar1;
    bVar1 = param_2[1];
    if ((bVar1 < 0x80) || (0xbf < bVar1)) {
      param_1[1] = 0;
      return 0;
    }
    param_1[1] = bVar1;
    bVar1 = param_2[2];
    if ((bVar1 < 0x80) || (0xbf < bVar1)) break;
    param_1[2] = bVar1;
    param_2 = param_2 + 3;
    param_1 = param_1 + 3;
  }
  param_1[2] = 0;
  return 0;
}



================================================================
FUNCTION thunk_EXT_FUN_001ae3e0 @ 0x005dfce0  size=8
CALLERS (2): FUN_005e2fa0@0x005e2fa0, FUN_005cab10@0x005cab10
CALLEES (0): 
----------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thunk_EXT_FUN_001ae3e0(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



================================================================