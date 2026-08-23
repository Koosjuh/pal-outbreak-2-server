FUNCTION FUN_005b6070 @ 0x005b6070  size=540
CALLERS (0): 
CALLEES (6): FUN_005bd830@0x005bd830, FUN_005bd860@0x005bd860, FUN_005be9a0@0x005be9a0, FUN_005f6970@0x005f6970, FUN_005bda30@0x005bda30, FUN_005bd890@0x005bd890
----------------------------------------------------------------

void FUN_005b6070(undefined4 *param_1)

{
  char cStack_10;
  char cStack_f;
  
  cStack_10 = (char)*param_1;
  cStack_f = (char)((uint)*param_1 >> 8);
  if (cStack_10 == -1) {
    if (cStack_f == '\t') {
      FUN_005f6970(4);
    }
    else if (cStack_f == '\b') {
      uRam006c4b9f = 0;
      uRam006c4b9e = 4;
      uRam006c550a = 2;
      FUN_005be9a0(0x6c517c);
    }
    else if (cStack_f == '\a') {
      uRam006c4b9f = 0;
      uRam006c4b9e = 4;
      uRam006c550a = 1;
      FUN_005be9a0(0x6c517c);
    }
  }
  else {
    switch(cStack_f) {
    case '\0':
      uRam006c4b9e = 5;
      uRam006c4b9f = 1;
      break;
    case '\x01':
      if (cRam00874f35 == '\0') {
        uRam006c4b9f = 0;
        uRam006c4b9e = 3;
        uRam006c4ba0 = 0;
      }
      else {
        uRam006c4ba0 = 0;
        uRam006c4b9e = 3;
        uRam006c4b9f = 7;
      }
      break;
    case '\x02':
      FUN_005bd830(0x6c69bc);
      FUN_005bd860(0x6c69cc);
      FUN_005bd890(0x6c69e0);
      func_0x001069a8(0x874fb0,0x6c69bc,0x10);
      func_0x001069a8(0x874fc0,0x6c69cc,0x11);
      break;
    case '\x03':
      uRam006c4b9f = 0;
      uRam006c4b9e = 8;
      break;
    case '\x04':
      uRam006c4b9f = 0;
      uRam006c4b9e = 2;
      FUN_005bda30(0x6c9d20);
      break;
    case '\x05':
      uRam006c4b9f = 0;
      uRam006c4b9e = 1;
    }
  }
  return;
}



================================================================