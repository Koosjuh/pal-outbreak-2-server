FUNCTION FUN_005af1e0 @ 0x005af1e0  size=216
CALLERS (52): FUN_005fd9e0@0x005fd9e0, FUN_005ae630@0x005ae630, FUN_005f6d20@0x005f6d20, FUN_005b76f0@0x005b76f0, FUN_005b86c0@0x005b86c0, FUN_005fcc70@0x005fcc70, FUN_00629d60@0x00629d60, FUN_0062fa80@0x0062fa80, FUN_005ac4c0@0x005ac4c0, FUN_00628860@0x00628860, FUN_005ba8d0@0x005ba8d0, FUN_005fbbf0@0x005fbbf0, ...
CALLEES (0): 
----------------------------------------------------------------

void FUN_005af1e0(undefined8 param_1,undefined8 param_2,char param_3,undefined8 param_4)

{
  if (param_3 == '\x03') {
    func_0x001af0a0(0xffffffffffffffe2);
    func_0x001ad8b0(1);
  }
  else if (param_3 == '\x02') {
    func_0x001af0a0(0xfffffffffffffffe);
    func_0x001ad8b0(1);
  }
  else if (param_3 == '\x01') {
    func_0x001af0a0(0xffffffffffffffee);
    func_0x001ad8b0(1);
  }
  else if (param_3 == '\0') {
    func_0x001af0a0(0xffffffffffffffde);
    func_0x001ad8b0(1);
  }
  func_0x001af080(param_1,param_2);
  func_0x001af0d0(param_4);
  return;
}



================================================================