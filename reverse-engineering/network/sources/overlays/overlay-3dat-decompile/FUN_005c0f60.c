FUNCTION FUN_005c0f60 @ 0x005c0f60  size=112
CALLERS (5): FUN_005fec30@0x005fec30, FUN_0062e8e0@0x0062e8e0, FUN_005fe8d0@0x005fe8d0, FUN_005fede0@0x005fede0, FUN_005fe500@0x005fe500
CALLEES (2): FUN_005c5f10@0x005c5f10, FUN_005bf230@0x005bf230
----------------------------------------------------------------

undefined8 FUN_005c0f60(undefined8 param_1,undefined8 param_2)

{
  if (cRam006ff2b0 == '\0') {
    uRam006febfc = (int)param_2;
    FUN_005c5f10(uRam006febe8);
  }
  else {
    uRam006cbc84 = 0;
    uRam006fb748 = (undefined2)(iRam006febec / 0x1e);
    FUN_005bf230(param_2);
  }
  return 0;
}



================================================================