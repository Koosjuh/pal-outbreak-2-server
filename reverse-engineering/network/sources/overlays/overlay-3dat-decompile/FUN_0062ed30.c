FUNCTION FUN_0062ed30 @ 0x0062ed30  size=144
CALLERS (0): 
CALLEES (1): FUN_005f6970@0x005f6970
----------------------------------------------------------------

void FUN_0062ed30(undefined4 *param_1)

{
  undefined1 uStack_10;
  
  if ((cRam006c4b90 != '\x06') && (cRam006c4fbb == '\x14')) {
    uStack_10 = (char)*param_1;
    cRam006c4fbb = '\0';
    if (uStack_10 == '\0') {
      uRam006c4ba1 = 0;
      uRam006c4ba0 = 7;
      uRam006c5539 = 0xff;
    }
    else {
      FUN_005f6970(4);
    }
  }
  return;
}



================================================================