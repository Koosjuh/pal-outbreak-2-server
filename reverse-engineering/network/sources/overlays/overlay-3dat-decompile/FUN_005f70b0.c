FUNCTION FUN_005f70b0 @ 0x005f70b0  size=448
CALLERS (1): FUN_005f7270@0x005f7270
CALLEES (4): FUN_005af2e0@0x005af2e0, FUN_0062fea0@0x0062fea0, FUN_005af2c0@0x005af2c0, FUN_005af1e0@0x005af1e0
----------------------------------------------------------------

void FUN_005f70b0(long param_1,char param_2)

{
  int iVar1;
  undefined8 uVar2;
  int iVar3;
  
  if (param_1 == 0) {
    if (((param_2 == '\x05') || (param_2 == '\x03')) || (param_2 == '\x01')) {
      FUN_005af2c0(4);
      FUN_005af2e0(0x14);
      uVar2 = FUN_0062fea0(0x11);
      iVar1 = func_0x001ae3e0(uVar2);
      uVar2 = FUN_0062fea0(0x11);
      iVar3 = (int)((ulong)((long)(iVar1 * 5) << 0x21) >> 0x20);
      if (iVar1 * 10 < 0) {
        iVar3 = iVar1 * 10 + 1;
      }
      FUN_005af1e0(0x140 - (iVar3 >> 1),0x160,2,uVar2);
    }
  }
  else if (((param_2 == '\x05') || (param_2 == '\x03')) || (param_2 == '\x01')) {
    FUN_005af2c0(4);
    FUN_005af2e0(0x14);
    uVar2 = FUN_0062fea0(0x11);
    iVar1 = func_0x001ae3e0(uVar2);
    uVar2 = FUN_0062fea0(0x11);
    iVar3 = (int)((ulong)((long)(iVar1 * 5) << 0x21) >> 0x20);
    if (iVar1 * 10 < 0) {
      iVar3 = iVar1 * 10 + 1;
    }
    FUN_005af1e0(0x140 - (iVar3 >> 1),0x160,2,uVar2);
  }
  return;
}



================================================================