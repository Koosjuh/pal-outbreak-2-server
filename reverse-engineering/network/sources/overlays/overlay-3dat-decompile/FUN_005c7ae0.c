FUNCTION FUN_005c7ae0 @ 0x005c7ae0  size=192
CALLERS (1): FUN_005c7a00@0x005c7a00
CALLEES (0): 
----------------------------------------------------------------

undefined8 FUN_005c7ae0(undefined8 param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  if (cRam00700fd0 == '\x02') {
    uVar2 = 1;
  }
  else {
    if (cRam00700fd0 == '\x01') {
      lVar1 = func_0x001c08e0(0x700fc8,0x700fc0,0x35bed8,param_1);
      if (lVar1 == -1) {
        return 0xffffffffffffffff;
      }
      if (lVar1 == 1) {
        cRam00700fd0 = cRam00700fd0 + '\x01';
      }
    }
    else {
      if (cRam00700fd0 != '\0') {
        return 0;
      }
      cRam00700fd0 = '\x01';
      uRam00700fc8 = 0;
    }
    uVar2 = 0;
  }
  return uVar2;
}



================================================================