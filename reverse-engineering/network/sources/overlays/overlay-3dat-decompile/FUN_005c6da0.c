FUNCTION FUN_005c6da0 @ 0x005c6da0  size=520
CALLERS (0): 
CALLEES (0): 
----------------------------------------------------------------

void FUN_005c6da0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iStack_30;
  undefined4 uStack_2c;
  undefined1 auStack_10 [8];
  undefined4 uStack_8;
  
  if (cRam006cbbbc != '\0') {
    if (cRam006cbbb8 == '\x02') {
      auStack_10[0] = 0;
      uStack_8 = 0;
      cRam006cbbbc = '\0';
      cRam006cbbb8 = '\0';
      (*pcRam006cbb9c)(auStack_10,auStack_10);
    }
    else if (cRam006cbbb8 == '\x01') {
      func_0x001c3380(&iStack_30);
      if (iStack_30 == 4) {
        func_0x001c33f0();
        auStack_10[0] = 0xff;
        uStack_8 = uStack_2c;
        cRam006cbbbc = '\0';
        cRam006cbbb8 = '\0';
        (*pcRam006cbb9c)(auStack_10,auStack_10);
      }
      else if (iStack_30 == 3) {
        func_0x001c33f0();
        cRam006cbbb8 = cRam006cbbb8 + '\x01';
      }
    }
    else if (cRam006cbbb8 == '\0') {
      cRam006cbbb8 = '\x01';
      func_0x00106b60(0x700480,0,0x4c);
      uRam00700480 = uRam006cc064;
      uRam00700481 = uRam006cc0ea;
      uRam00700482 = uRam006cc066;
      uRam00700489 = uRam006cc067;
      uRam00700488 = uRam006cc064;
      uRam0070048c = uRam006cc068;
      uRam00700490 = uRam006cc06c;
      uRam00700484 = 0x86f820;
      iVar2 = 0;
      do {
        iVar1 = iVar2 * 8;
        iVar3 = iVar2 + 1;
        *(int *)(iVar1 + 0x700494) = iVar2 * 0x11 + 0x6cc0a6;
        *(undefined1 *)(iVar1 + 0x700498) = *(undefined1 *)(iVar2 + 0x6cc070);
        *(undefined1 *)(iVar1 + 0x700499) = *(undefined1 *)(iVar2 + 0x6cc073);
        iVar2 = iVar3;
      } while (iVar3 < 3);
      uRam007004ac = uRam0086f858;
      uRam007004b0 = (uint)uRam006cc0ee;
      uRam007004b4 = uRam0086f850;
      uRam007004b8 = uRam0086f848;
      uRam007004bc = (uint)uRam006cc0f4;
      uRam007004c0 = (uint)uRam006cc0f6;
      uRam007004c4 = (uint)uRam006cc0f8;
      uRam007004c8 = (uint)uRam006cc0fa;
      func_0x001c3340(0x700480);
    }
  }
  return;
}



================================================================