FUNCTION FUN_005c4380 @ 0x005c4380  size=160
CALLERS (1): FUN_00627b00@0x00627b00
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_005c4380(undefined8 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (cRam006cbc0c == '\0') {
    func_0x00106b60(0x6fbe58,0,0x201);
    func_0x0010a4f0(0x7003fd,param_1,0x10);
    uRam0070047d = 1;
    cRam006cbc0c = '\x01';
    uVar1 = 0;
    pcRam006cbbe8 = FUN_005c40a0;
    uRam006cbc08 = 0;
    uRam006cbbec = param_2;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



================================================================