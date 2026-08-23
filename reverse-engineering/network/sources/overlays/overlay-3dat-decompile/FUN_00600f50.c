FUNCTION FUN_00600f50 @ 0x00600f50  size=148
CALLERS (0): 
CALLEES (1): FUN_005c01d0@0x005c01d0
----------------------------------------------------------------

void FUN_00600f50(undefined4 *param_1)

{
  undefined1 uStack_10;
  
  if (cRam006c4b90 != '\x06') {
    uStack_10 = (char)*param_1;
    if (uStack_10 == '\0') {
      FUN_005c01d0(bRam006c4600,(bRam006c4600 - 1) * 0x15c + 0x6c0762);
    }
    else {
      *(undefined2 *)((uint)bRam006c4600 * 0x15c + 0x6c0606) = 0;
    }
  }
  return;
}



================================================================