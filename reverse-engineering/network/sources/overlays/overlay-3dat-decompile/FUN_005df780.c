FUNCTION FUN_005df780 @ 0x005df780  size=44
CALLERS (5): FUN_005def30@0x005def30, FUN_005d7760@0x005d7760, FUN_005d7cf0@0x005d7cf0, FUN_005df170@0x005df170, FUN_005df340@0x005df340
CALLEES (1): FUN_005df700@0x005df700
----------------------------------------------------------------

char FUN_005df780(undefined8 param_1)

{
  char cVar1;
  
  cVar1 = FUN_005df700(0x646570,param_1);
  return cVar1 + '\x01';
}



================================================================