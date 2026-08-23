FUNCTION FUN_005b3c30 @ 0x005b3c30  size=128
CALLERS (1): FUN_005b3070@0x005b3070
CALLEES (4): FUN_005b3cb0@0x005b3cb0, FUN_005b3d80@0x005b3d80, FUN_005b3ed0@0x005b3ed0, FUN_005b41b0@0x005b41b0
----------------------------------------------------------------

undefined8 FUN_005b3c30(int param_1)

{
  char cVar1;
  undefined8 uVar2;
  
  cVar1 = *(char *)(param_1 + 0x900);
  if (cVar1 == '\x03') {
    uVar2 = FUN_005b41b0(param_1,param_1 + 0x900);
  }
  else if (cVar1 == '\x02') {
    uVar2 = FUN_005b3ed0();
  }
  else if (cVar1 == '\x01') {
    uVar2 = FUN_005b3d80();
  }
  else if (cVar1 == '\0') {
    uVar2 = FUN_005b3cb0();
  }
  else {
    uVar2 = 0xffffffffffffffff;
  }
  return uVar2;
}



================================================================