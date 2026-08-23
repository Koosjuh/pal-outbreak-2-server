FUNCTION FUN_005e00e0 @ 0x005e00e0  size=84
CALLERS (9): FUN_005e5200@0x005e5200, FUN_005e5650@0x005e5650, FUN_005e0570@0x005e0570, FUN_005e2060@0x005e2060, FUN_005daba0@0x005daba0, FUN_005e07c0@0x005e07c0, FUN_005e1670@0x005e1670, FUN_005e4f10@0x005e4f10, FUN_005e4b00@0x005e4b00
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_005e00e0(char param_1)

{
  undefined4 uVar1;
  
  if ((param_1 < '\0') || (*(char *)(iRam00701068 + 0x609c0) <= param_1)) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = *(undefined4 *)(param_1 * 4 + iRam00701068 + 0x607c0);
  }
  return uVar1;
}



================================================================