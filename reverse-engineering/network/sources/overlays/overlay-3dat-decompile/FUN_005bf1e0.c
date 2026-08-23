FUNCTION FUN_005bf1e0 @ 0x005bf1e0  size=72
CALLERS (24): FUN_005c1770@0x005c1770, FUN_005c7320@0x005c7320, FUN_005bb980@0x005bb980, FUN_005bbe00@0x005bbe00, FUN_005bf830@0x005bf830, FUN_005be330@0x005be330, FUN_005bb8e0@0x005bb8e0, FUN_005c4600@0x005c4600, FUN_005c7420@0x005c7420, FUN_005c4bd0@0x005c4bd0, FUN_005c44a0@0x005c44a0, FUN_005bb4d0@0x005bb4d0, ...
CALLEES (0): 
----------------------------------------------------------------

ulong FUN_005bf1e0(char param_1)

{
  ulong uVar1;
  
  if (param_1 == '\x02') {
    uVar1 = (ulong)bRam006ce5d0;
  }
  else if (param_1 == '\x01') {
    uVar1 = (ulong)bRam006ce5cf;
  }
  else if (param_1 == '\0') {
    uVar1 = (ulong)bRam006ce5ce;
  }
  else {
    uVar1 = 0xffff;
  }
  return uVar1;
}



================================================================