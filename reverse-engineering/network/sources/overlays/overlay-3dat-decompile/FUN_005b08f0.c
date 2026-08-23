FUNCTION FUN_005b08f0 @ 0x005b08f0  size=96
CALLERS (0): 
CALLEES (4): FUN_005af2e0@0x005af2e0, FUN_0062fea0@0x0062fea0, FUN_005af2c0@0x005af2c0, FUN_005af1e0@0x005af1e0
----------------------------------------------------------------

void FUN_005b08f0(int param_1)

{
  undefined8 uVar1;
  
  FUN_005af2c0(0);
  FUN_005af2e0(0x1c);
  uVar1 = FUN_0062fea0(0x15);
  FUN_005af1e0(0x30,0x14,0,uVar1);
  *(ushort *)(param_1 + 0x24) = *(ushort *)(param_1 + 0x24) | 0x80;
  *(undefined4 *)(param_1 + 0x2c) = 0xff000000;
  return;
}



================================================================