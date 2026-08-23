FUNCTION FUN_0061f970 @ 0x0061f970  size=92
CALLERS (7): FUN_006205c0@0x006205c0, FUN_00622c30@0x00622c30, FUN_00620d60@0x00620d60, FUN_00620b60@0x00620b60, FUN_0061f9f0@0x0061f9f0, FUN_0061fd70@0x0061fd70, FUN_00620250@0x00620250
CALLEES (3): FUN_0061ea10@0x0061ea10, thunk_FUN_0061f0d0@0x0061ea00, FUN_0061ea40@0x0061ea40
----------------------------------------------------------------

undefined4 FUN_0061f970(void)

{
  undefined4 uVar1;
  
  if ((bRam007152f1 & 1) == 0) {
    uVar1 = 2;
  }
  else {
    thunk_FUN_0061f0d0(0);
    FUN_0061ea10();
    FUN_0061ea40();
    uVar1 = 1;
    uRam0071530c = 0;
    uRam00715270 = 0;
  }
  return uVar1;
}



================================================================