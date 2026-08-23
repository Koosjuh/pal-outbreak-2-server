FUNCTION FUN_0062f2b0 @ 0x0062f2b0  size=176
CALLERS (0): 
CALLEES (1): FUN_005c01d0@0x005c01d0
----------------------------------------------------------------

void FUN_0062f2b0(undefined4 *param_1)

{
  char cStack_10;
  
  if ((cRam006c4b90 != '\x06') && (cRam006c4b90 == '\x0e')) {
    cStack_10 = (char)*param_1;
    cRam006c4ba0 = cRam006c4ba0 + '\x01';
    if (cStack_10 == '\0') {
      FUN_005c01d0(bRam006c4600,(bRam006c4600 - 1) * 0x15c + 0x6c0762);
    }
    else {
      *(undefined2 *)((uint)bRam006c4600 * 0x15c + 0x6c0606) = 0;
    }
  }
  return;
}



================================================================