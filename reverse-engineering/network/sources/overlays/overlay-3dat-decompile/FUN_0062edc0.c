FUNCTION FUN_0062edc0 @ 0x0062edc0  size=436
CALLERS (0): 
CALLEES (7): FUN_005c09c0@0x005c09c0, FUN_005c1c10@0x005c1c10, FUN_005c0860@0x005c0860, FUN_005c0210@0x005c0210, FUN_005be9a0@0x005be9a0, FUN_005c01d0@0x005c01d0, FUN_005bff80@0x005bff80
----------------------------------------------------------------

void FUN_0062edc0(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  char cStack_10;
  char cStack_f;
  undefined1 auStack_4 [4];
  
  if ((cRam006c4b90 != '\x06') && (cRam006c4fbb == '\t')) {
    cStack_10 = (char)*param_1;
    if (cStack_10 == '\x02') {
      cStack_f = (char)((uint)*param_1 >> 8);
      if ((cStack_f != '\v') && (cStack_f == '\n')) {
        FUN_005c1c10(auStack_4);
      }
    }
    else if (cStack_10 == '\0') {
      FUN_005bff80(0x6c4602);
      for (iVar2 = 0; iVar2 < (int)(uint)uRam006c4602; iVar2 = iVar2 + 1) {
        iVar1 = iVar2 * 0x15c;
        *(short *)(iVar1 + 0x6c0760) = (short)(iVar2 + 1U);
        FUN_005c01d0(iVar2 + 1U & 0xffff,iVar1 + 0x6c0762);
        FUN_005c0210(iVar2 + 1U & 0xffff,iVar1 + 0x6c076e);
        FUN_005c09c0(iVar2 + 1U & 0xffff,iVar1 + 0x6c076f);
        FUN_005c0860(iVar2 + 1U & 0xffff,iVar1 + 0x6c0774);
        FUN_005c01d0(iVar2 + 1U & 0xffff,iVar1 + 0x6c0762);
      }
      cRam006c4fbb = '\0';
      uRam006c4b9f = 1;
      uRam006c5530 = 0x708;
      uRam006c4ba0 = 0;
      uRam006c4ba1 = 0;
    }
    else {
      cRam006c4fbb = '\0';
      uRam006c4b9f = 1;
      uRam006c5530 = 0x708;
      uRam006c4ba0 = 0;
      uRam006c4ba1 = 0;
      FUN_005be9a0(0x6c517c);
    }
  }
  return;
}



================================================================