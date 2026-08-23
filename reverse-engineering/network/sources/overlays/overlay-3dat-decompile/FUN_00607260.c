FUNCTION FUN_00607260 @ 0x00607260  size=220
CALLERS (1): FUN_00606cf0@0x00606cf0
CALLEES (4): FUN_00607a10@0x00607a10, FUN_005af2f0@0x005af2f0, FUN_00618b60@0x00618b60, FUN_00606fa0@0x00606fa0
----------------------------------------------------------------

void FUN_00607260(undefined8 param_1)

{
  if ((cRam00874f35 != '\x03') &&
     (((cRam00874f35 == '\x02' || (cRam00874f35 == '\x01')) || (cRam00874f35 == '\0')))) {
    if (cRam008744f8 == '\x01') {
      FUN_00606fa0();
    }
    else {
      *(char *)param_1 = *(char *)param_1 + '\x01';
      FUN_00618b60(param_1,2);
      func_0x00106b60(0x6c5490,0,0x20);
      uRam006c5494 = 1;
      FUN_00607a10(0x6c5490);
      FUN_005af2f0(0,10);
    }
    return;
  }
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



================================================================