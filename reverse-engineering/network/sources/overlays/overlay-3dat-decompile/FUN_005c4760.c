FUNCTION FUN_005c4760 @ 0x005c4760  size=872
CALLERS (0): 
CALLEES (0): 
----------------------------------------------------------------

void FUN_005c4760(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_10 [16];
  
  if (cRam006cbaa4 != '\0') {
    switch(cRam006cbaa0) {
    case '\0':
      cRam006cbaa5 = '\0';
      if (cRam006ff2b0 == '\0') {
        cRam006cbaa0 = '\x03';
      }
      else {
        cRam006cbaa0 = '\x04';
        iVar3 = 0;
        uRam006fb758 = uRam006ff2b3;
        uRam006fb759 = uRam006ff2b4;
        do {
          iVar2 = iVar3 * 0x150;
          *(char *)(iVar2 + 0x6fb9b8) = (char)iVar3 + '\x01';
          iVar1 = iVar3 * 0x114;
          func_0x0010a4f0(iVar2 + 0x6fb86c,iVar1 + 0x6fffad,0x10);
          func_0x0010a4f0(iVar2 + 0x6fb87c,iVar1 + 0x6fffbd,0x10);
          func_0x001069a8(iVar2 + 0x6fb890,iVar1 + 0x6fffd1,0xf0);
          iVar3 = iVar3 + 1;
        } while (iVar3 < 4);
      }
      break;
    case '\x01':
      if (cRam006cbaa5 == '\x01') {
        cRam006cbaa0 = cRam006cbaa0 + '\x01';
        cRam006cbaa5 = '\0';
        iRam006cba8c = 300;
      }
      else if (cRam006cbaa5 == '\x02') {
        cRam006cbaa0 = '\a';
      }
      break;
    case '\x02':
      iRam006cba8c = iRam006cba8c + -1;
      if (iRam006cba8c < 0) {
        cRam006cbaa0 = '\x04';
      }
      break;
    case '\x03':
      if (cRam006ff2af != '\0') {
        cRam006cbaa0 = '\x04';
        iVar3 = 0;
        uRam006fb758 = uRam006ff2b3;
        uRam006fb759 = uRam006ff2b4;
        do {
          iVar2 = iVar3 * 0x150;
          *(char *)(iVar2 + 0x6fb9b8) = (char)iVar3 + '\x01';
          iVar1 = iVar3 * 0x114;
          func_0x0010a4f0(iVar2 + 0x6fb86c,iVar1 + 0x6fffad,0x10);
          func_0x0010a4f0(iVar2 + 0x6fb87c,iVar1 + 0x6fffbd,0x10);
          func_0x001069a8(iVar2 + 0x6fb890,iVar1 + 0x6fffd1,0xf0);
          iVar3 = iVar3 + 1;
        } while (iVar3 < 4);
      }
      break;
    case '\x04':
      cRam006cbaa0 = cRam006cbaa0 + '\x01';
      func_0x001de648(uRam006febac,1,0x5c4720);
      break;
    case '\x05':
      if (cRam006cbaa5 == '\x01') {
        cRam006cbaa0 = '\x06';
        cRam006cbaa5 = '\0';
      }
      else if (cRam006cbaa5 == '\x02') {
        cRam006cbaa0 = '\a';
      }
      break;
    case '\x06':
      auStack_10[0] = 0;
      cRam006cbaa4 = '\0';
      cRam006cbaa0 = '\0';
      (*pcRam006cba84)(auStack_10,auStack_10);
      break;
    case '\a':
      auStack_10[0] = 0xff;
      cRam006cbaa4 = '\0';
      cRam006cbaa0 = '\0';
      (*pcRam006cba84)(auStack_10,auStack_10);
    }
  }
  return;
}



================================================================