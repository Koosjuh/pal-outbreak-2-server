FUNCTION FUN_005dc1e0 @ 0x005dc1e0  size=196
CALLERS (1): FUN_005d1e80@0x005d1e80
CALLEES (2): FUN_006345e0@0x006345e0, FUN_006371d0@0x006371d0
----------------------------------------------------------------

void FUN_005dc1e0(undefined8 param_1,ushort param_2,undefined1 param_3)

{
  ulong uVar1;
  
  if (0xff < param_2) {
    param_2 = 0xff;
  }
  uVar1 = func_0x0010a050(param_1);
  if (uVar1 < 0x100) {
    func_0x00109eb8(iRam00701068 + 0x68e89,param_1);
  }
  else {
    func_0x00109eb8(iRam00701068 + 0x68e89,0x643398);
  }
  FUN_006371d0(0x42840000,300);
  FUN_006345e0(0,param_3,param_2,param_1);
  return;
}



================================================================