FUNCTION FUN_0061e8f0 @ 0x0061e8f0  size=8
CALLERS (1): FUN_00622180@0x00622180
CALLEES (0): 
----------------------------------------------------------------

void FUN_0061e8f0(void)

{
  return;
}



================================================================
FUNCTION thunk_FUN_00619800 @ 0x0061e900  size=8
CALLERS (2): FUN_00622130@0x00622130, FUN_005b2e40@0x005b2e40
CALLEES (0): 
----------------------------------------------------------------

void thunk_FUN_00619800(void)

{
  char cVar1;
  int iVar2;
  long lVar3;
  
  bRam0071530a = bRam0071530a + 2;
  if (4 < bRam0071530a) {
    bRam0071530a = 0;
    bRam0071530b = bRam0071530b + 2;
    if (0xf < bRam0071530b) {
      bRam0071530b = 0;
    }
  }
  func_0x0018c8d0(0xe,0xffffffffffffffff);
  func_0x0018c8d0(0xc,0);
  func_0x0018c8d0(0x62,0);
  func_0x0018c8d0(0xd,0);
  func_0x0018c8d0(0x5f,4);
  func_0x0018c8d0(0x60,0);
  func_0x0018c8d0(0x5e,0x32);
  func_0x0018c8d0(99,0);
  func_0x0018c8d0(0x6c,0);
  if ((uRam0071530c & 1) != 0) {
    FUN_00619e00(1);
  }
  func_0x0018c8d0(99,0x10000);
  if ((uRam0071530c & 2) != 0) {
    FUN_00619e00(2);
  }
  if ((uRam0071530c & 4) != 0) {
    FUN_00619e00(4);
  }
  if ((uRam0071530c & 0x8000000) != 0) {
    FUN_00619e00();
  }
  if ((uRam0071530c & 0x80) != 0) {
    FUN_00619e00(0x80);
  }
  if ((uRam0071530c & 0x100) != 0) {
    FUN_00619e00(0x100);
  }
  if ((uRam0071530c & 0x200) != 0) {
    FUN_00619e00(0x200);
  }
  if ((uRam0071530c & 0x800000) != 0) {
    FUN_00619e00();
  }
  func_0x001af0a0(0xfffffffffffffffe);
  lVar3 = 0;
  while (lVar3 < cRam00715312) {
    iVar2 = (int)lVar3;
    cVar1 = *(char *)(iVar2 + 0x715328);
    if (cVar1 == '\x03') {
      FUN_0061d210(*(undefined1 *)(iVar2 + 0x715320));
LAB_00619a44:
      lVar3 = (long)(iVar2 + 1);
    }
    else {
      if (cVar1 == '\x02') {
        FUN_0061eab0(*(undefined1 *)(iVar2 + 0x715320));
        goto LAB_00619a44;
      }
      if (cVar1 == '\x01') {
        FUN_0061d3a0(*(undefined1 *)(iVar2 + 0x715320));
        goto LAB_00619a44;
      }
      if (cVar1 == '\0') {
        FUN_0061d080(*(undefined1 *)(iVar2 + 0x715320));
        goto LAB_00619a44;
      }
      lVar3 = (long)(iVar2 + 1);
    }
  }
  cRam00715312 = 0;
  func_0x0018c8d0(0x6c,0);
  func_0x001af000(2);
  func_0x0018c8d0(0x6c,0);
  if ((uRam0071530c & 0x400) != 0) {
    FUN_00619e00(0x400);
  }
  func_0x0018c8d0(99,0);
  if ((uRam0071530c & 0x1000) != 0) {
    FUN_00619e00(0x1000);
  }
  if ((uRam0071530c & 0x10000000) != 0) {
    FUN_00619e00();
  }
  func_0x0018c8d0(99,0x10000);
  if ((uRam0071530c & 0x2000) != 0) {
    FUN_00619e00(0x2000);
  }
  func_0x0018c8d0(99,0);
  if ((uRam0071530c & 0x4000) != 0) {
    FUN_00619e00(0x4000);
  }
  if ((uRam0071530c & 0x8000) != 0) {
    FUN_00619e00(0x8000);
  }
  if ((uRam0071530c & 0x2000000) != 0) {
    FUN_00619e00();
  }
  if ((uRam0071530c & 0x4000000) != 0) {
    FUN_00619e00();
  }
  if ((uRam0071530c & 0x10000) != 0) {
    FUN_00619e00();
  }
  func_0x0018c8d0(99,0x10000);
  if ((uRam0071530c & 0x80000) != 0) {
    FUN_00619e00();
  }
  if ((uRam0071530c & 0x100000) != 0) {
    FUN_00619e00();
  }
  if ((uRam0071530c & 0x200000) != 0) {
    FUN_00619e00();
  }
  if ((uRam0071530c & 0x1000000) != 0) {
    FUN_00619e00();
  }
  func_0x001af0a0(0xffffffffffffffee);
  lVar3 = 0;
LAB_00619ce4:
  do {
    if (cRam00715313 <= lVar3) {
      cRam00715313 = 0;
      func_0x0018c8d0(0x6c,0);
      func_0x001af000(1);
      func_0x001af0a0(0xffffffffffffffce);
      func_0x001af000(0);
      lVar3 = FUN_00637170();
      if (lVar3 != 0) {
        FUN_00636890(0);
      }
      FUN_0061f850();
      func_0x0018c8d0(0x5f,4);
      func_0x0018c8d0(0x60,0);
      func_0x0018c8d0(0x5e,0x32);
      func_0x0018c8d0(0x6c,1);
      func_0x0018c8d0(99,0);
      return;
    }
    iVar2 = (int)lVar3;
    switch(*(undefined1 *)(iVar2 + 0x715338)) {
    case 0:
      FUN_0061d080(*(undefined1 *)(iVar2 + 0x715330));
      lVar3 = (long)(iVar2 + 1);
      goto LAB_00619ce4;
    case 1:
      FUN_0061d3a0(*(undefined1 *)(iVar2 + 0x715330));
      break;
    case 2:
      FUN_0061eab0(*(undefined1 *)(iVar2 + 0x715330));
      break;
    case 3:
      FUN_0061d210(*(undefined1 *)(iVar2 + 0x715330));
      break;
    case 4:
      FUN_0061c9f0(*(undefined1 *)(iVar2 + 0x715330),0);
      break;
    case 5:
      FUN_0061c9f0(*(undefined1 *)(iVar2 + 0x715330),1);
    }
    lVar3 = (long)(iVar2 + 1);
  } while( true );
}



================================================================