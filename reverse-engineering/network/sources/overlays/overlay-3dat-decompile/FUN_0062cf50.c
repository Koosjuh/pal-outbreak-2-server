FUNCTION FUN_0062cf50 @ 0x0062cf50  size=116
CALLERS (2): FUN_0062c1d0@0x0062c1d0, FUN_0062aeb0@0x0062aeb0
CALLEES (3): FUN_0062cfd0@0x0062cfd0, FUN_0062d380@0x0062d380, FUN_0062d0f0@0x0062d0f0
----------------------------------------------------------------

undefined8 FUN_0062cf50(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (cRam00695d40 == '\x02') {
    uVar1 = FUN_0062d380(param_1,0x695d40,param_2);
  }
  else if (cRam00695d40 == '\x01') {
    uVar1 = FUN_0062d0f0();
  }
  else if (cRam00695d40 == '\0') {
    uVar1 = FUN_0062cfd0();
  }
  return uVar1;
}



================================================================