FUNCTION FUN_005ad890 @ 0x005ad890  size=340
CALLERS (0): 
CALLEES (6): FUN_005bf9e0@0x005bf9e0, FUN_005bfa20@0x005bfa20, FUN_005bf940@0x005bf940, FUN_005be9a0@0x005be9a0, FUN_005bf3c0@0x005bf3c0, FUN_005bf3a0@0x005bf3a0
----------------------------------------------------------------

void FUN_005ad890(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  undefined1 uStack_10;
  
  if (((cRam006c4b90 != '\x06') && (cRam006c4fbb == '\x03')) &&
     (uStack_10 = (char)*param_1, uStack_10 != '\x02')) {
    if (uStack_10 == '\0') {
      FUN_005bf3a0(0x6c45fa);
      for (iVar2 = 0; iVar2 < (int)(uint)uRam006c45fa; iVar2 = iVar2 + 1) {
        iVar1 = iVar2 * 0x15c;
        *(short *)(iVar1 + 0x6c3860) = (short)(iVar2 + 1U);
        FUN_005bf9e0(iVar2 + 1U & 0xffff,iVar1 + 0x6c386e);
        FUN_005bf940(iVar2 + 1U & 0xffff,iVar1 + 0x6c3862);
        FUN_005bf3c0(iVar2 + 1U & 0xffff,iVar1 + 0x6c3878);
        FUN_005bfa20(iVar2 + 1U & 0xffff,iVar1 + 0x6c38b9);
      }
      cRam006c4fbb = '\0';
      uRam006c4ba0 = 0;
      cRam006c4b9f = cRam006c4b9f + '\x01';
    }
    else {
      cRam006c4fbb = '\0';
      uRam006c4ba0 = 1;
      cRam006c4b9f = cRam006c4b9f + '\x01';
      FUN_005be9a0(0x6c517c);
    }
  }
  return;
}



================================================================