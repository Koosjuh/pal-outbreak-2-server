FUNCTION FUN_005befa0 @ 0x005befa0  size=308
CALLERS (0): 
CALLEES (2): FUN_005bebf0@0x005bebf0, FUN_005beb40@0x005beb40
----------------------------------------------------------------

void FUN_005befa0(void)

{
  undefined1 auStack_10 [16];
  
  if (cRam006cbaf4 != '\0') {
    switch(cRam006cbaf0) {
    case '\0':
      cRam006cbaf0 = cRam006cbaf0 + '\x01';
      cRam006cbaf5 = '\0';
      FUN_005beb40(0x5bef50);
      break;
    case '\x01':
      if (cRam006cbaf5 == '\x01') {
        cRam006cbaf0 = cRam006cbaf0 + '\x01';
      }
      else if (cRam006cbaf5 == '\x02') {
        cRam006cbaf0 = '\x05';
      }
      break;
    case '\x02':
      cRam006cbaf0 = cRam006cbaf0 + '\x01';
      cRam006cbaf5 = '\0';
      FUN_005bebf0(0x5bef50);
      break;
    case '\x03':
      if (cRam006cbaf5 == '\x01') {
        cRam006cbaf0 = cRam006cbaf0 + '\x01';
      }
      else if (cRam006cbaf5 == '\x02') {
        cRam006cbaf0 = '\x05';
      }
      break;
    case '\x04':
      auStack_10[0] = 0;
      cRam006cbaf4 = '\0';
      cRam006cbaf0 = '\0';
      (*pcRam006cbad4)(auStack_10,auStack_10);
      break;
    case '\x05':
      auStack_10[0] = 0xff;
      cRam006cbaf4 = '\0';
      cRam006cbaf0 = '\0';
      (*pcRam006cbad4)(auStack_10,auStack_10);
    }
  }
  return;
}



================================================================