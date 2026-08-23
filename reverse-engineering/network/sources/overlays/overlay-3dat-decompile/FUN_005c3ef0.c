FUNCTION FUN_005c3ef0 @ 0x005c3ef0  size=160
CALLERS (1): FUN_0062bee0@0x0062bee0
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_005c3ef0(undefined8 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (cRam006cbc0c == '\0') {
    func_0x00106b60(0x6fbe58,0,0x201);
    func_0x0010a4f0(0x7003fd,param_1,0x10);
    cRam006cbc0c = '\x01';
    pcRam006cbbe8 = FUN_005c40a0;
    uVar1 = 0;
    uRam0070047d = 0;
    uRam006cbc08 = 0;
    uRam006cbbec = param_2;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



================================================================