FUNCTION FUN_005c4fd0 @ 0x005c4fd0  size=136
CALLERS (3): FUN_005bca90@0x005bca90, FUN_005c0ff0@0x005c0ff0, FUN_005c7020@0x005c7020
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_005c4fd0(void)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(((uint)uRam0086f800 * 0x12 + (uint)uRam0086f800) * 0x20 + 0x365d20);
  func_0x00106b60(0x700fb0,0,0x10);
  func_0x00109eb8(0x700fb0,uVar1);
  func_0x00109ab0(0x700fb0,0x6405b8);
  return 0x700fb0;
}



================================================================