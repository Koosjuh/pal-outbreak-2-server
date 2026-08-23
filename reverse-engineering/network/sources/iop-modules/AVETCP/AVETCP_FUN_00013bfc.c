FUNCTION FUN_00013bfc @ 0x00013bfc size=76
CALLERS (2): FUN_00014818@0x00014818, FUN_000143e4@0x000143e4
CALLEES (0): 

byte * FUN_00013bfc(byte *param_1)

{
  byte bVar1;
  
  bVar1 = *param_1;
  while( true ) {
    if (bVar1 == 0) {
      return param_1 + 1;
    }
    if ((bVar1 & 0xc0) == 0xc0) break;
    param_1 = param_1 + *param_1 + 1;
    bVar1 = *param_1;
  }
  return param_1 + 2;
}


================================================================