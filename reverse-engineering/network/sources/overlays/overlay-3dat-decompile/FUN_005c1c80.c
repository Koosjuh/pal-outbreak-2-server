FUNCTION FUN_005c1c80 @ 0x005c1c80  size=484
CALLERS (0): 
CALLEES (5): FUN_005bfe00@0x005bfe00, FUN_005bf180@0x005bf180, FUN_005bf130@0x005bf130, FUN_005c0750@0x005c0750, FUN_005bf1e0@0x005bf1e0
----------------------------------------------------------------

void FUN_005c1c80(void)

{
  long lVar1;
  undefined1 auStack_10 [16];
  
  if (cRam006cbb6c != '\0') {
    switch(cRam006cbb68) {
    case '\0':
      cRam006cbb68 = cRam006cbb68 + '\x01';
      cRam006cbb6d = '\0';
      lVar1 = FUN_005bf1e0(2);
      if (lVar1 == 0) {
        cRam006cbb68 = '\x02';
      }
      else {
        FUN_005c0750(0x5c1c30);
      }
      break;
    case '\x01':
      if (cRam006cbb6d == '\x01') {
        cRam006cbb68 = cRam006cbb68 + '\x01';
        cRam006cbb6d = '\0';
      }
      else if (cRam006cbb6d == '\x02') {
        cRam006cbb68 = '\x05';
      }
      break;
    case '\x02':
      cRam006cbb68 = cRam006cbb68 + '\x01';
      cRam006cbb6d = '\0';
      lVar1 = FUN_005bf1e0(1);
      if (((lVar1 == 0) && (lVar1 = FUN_005bf1e0(0), lVar1 == 0)) || (cRam006ce5c4 != '\0')) {
        cRam006cbb68 = '\x04';
      }
      else {
        FUN_005bfe00(0x5c1c30);
      }
      break;
    case '\x03':
      if (cRam006cbb6d == '\x01') {
        cRam006cbb68 = cRam006cbb68 + '\x01';
        cRam006cbb6d = '\0';
      }
      else if (cRam006cbb6d == '\x02') {
        cRam006cbb68 = '\x05';
      }
      break;
    case '\x04':
      if (cRam0070047c == '\0') {
        FUN_005bf180(0);
        FUN_005bf180(1);
        FUN_005bf180(2);
      }
      else {
        FUN_005bf130(0);
        FUN_005bf130(1);
        FUN_005bf130(2);
      }
      cRam0070047c = '\0';
      auStack_10[0] = 0;
      cRam006cbb6c = '\0';
      cRam006cbb68 = '\0';
      (*pcRam006cbb4c)(auStack_10,auStack_10);
      break;
    case '\x05':
      auStack_10[0] = 0xff;
      cRam006cbb6c = '\0';
      cRam006cbb68 = '\0';
      (*pcRam006cbb4c)(auStack_10,auStack_10);
    }
  }
  return;
}



================================================================