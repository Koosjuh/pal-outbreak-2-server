FUNCTION FUN_005c22a0 @ 0x005c22a0  size=156
CALLERS (1): FUN_00600d10@0x00600d10
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_005c22a0(undefined4 param_1)

{
  undefined4 uVar1;
  
  if (cRam006cbb6c == '\0') {
    func_0x00106b60(0x6cdbe6,0,0x460);
    uRam006ce5ce = 1;
    uRam006ff2b1 = 3;
    pcRam006cbb48 = FUN_005c1c80;
    uVar1 = 0;
    uRam006ce5cf = 1;
    uRam006ce5d0 = 1;
    cRam006cbb6c = '\x01';
    uRam006cbb68 = 0;
    uRam006cbb4c = param_1;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



================================================================