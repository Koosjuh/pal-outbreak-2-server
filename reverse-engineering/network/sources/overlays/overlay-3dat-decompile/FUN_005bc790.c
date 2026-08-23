FUNCTION FUN_005bc790 @ 0x005bc790  size=208
CALLERS (0): 
CALLEES (2): FUN_005c7d00@0x005c7d00, FUN_005bdf90@0x005bdf90
----------------------------------------------------------------

void FUN_005bc790(undefined8 param_1,undefined1 *param_2)

{
  byte bVar1;
  undefined1 auStack_20 [32];
  
  FUN_005c7d00();
  func_0x00106b60(0x6fc05a,0,0x128);
  if (param_2[1] == '\0') {
    uRam006fc17e = *param_2;
    bVar1 = param_2[2];
    func_0x001069a8(0x6fc06a,param_2 + 6,bVar1);
    func_0x001069a8(0x6fc07e,param_2 + bVar1 + 6,param_2[3]);
    FUN_005bdf90(5,0);
  }
  else {
    func_0x00106b60(auStack_20,0,0x20);
    func_0x001069a8(auStack_20,param_2 + 6,param_2[3]);
    func_0x0010a338(0x36842c,auStack_20,0x20);
  }
  return;
}



================================================================