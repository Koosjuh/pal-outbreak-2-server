FUNCTION FUN_005f7b30 @ 0x005f7b30  size=324
CALLERS (0): 
CALLEES (5): FUN_005bfc60@0x005bfc60, FUN_005bfcb0@0x005bfcb0, FUN_005be9a0@0x005be9a0, FUN_005bfc40@0x005bfc40, FUN_005bfcf0@0x005bfcf0
----------------------------------------------------------------

void FUN_005f7b30(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  undefined1 uStack_10;
  
  if (((cRam006c4b90 != '\x06') && (cRam006c4fbb == '\a')) &&
     (uStack_10 = (char)*param_1, uStack_10 != '\x02')) {
    if (uStack_10 == '\0') {
      FUN_005bfc40(0x6c45fe);
      for (iVar2 = 0; iVar2 < (int)(uint)uRam006c45fe; iVar2 = iVar2 + 1) {
        iVar1 = iVar2 * 0x15c;
        *(short *)(iVar1 + 0x6c3030) = (short)(iVar2 + 1U);
        FUN_005bfcf0(iVar2 + 1U & 0xffff,iVar1 + 0x6c303e);
        FUN_005bfcb0(iVar2 + 1U & 0xffff,iVar1 + 0x6c3032);
        FUN_005bfc60(iVar2 + 1U & 0xffff,iVar1 + 0x6c3048);
      }
      cRam006c4fbb = '\0';
      uRam006c4ba0 = 0;
      cRam006c4b9f = cRam006c4b9f + '\x01';
    }
    else {
      cRam006c4fbb = '\0';
      FUN_005be9a0(0x6c517c);
      uRam006c4ba0 = 0;
      cRam006c4b9f = cRam006c4b9f + '\x01';
    }
  }
  return;
}



================================================================