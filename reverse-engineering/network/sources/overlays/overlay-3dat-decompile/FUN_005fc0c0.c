FUNCTION FUN_005fc0c0 @ 0x005fc0c0  size=484
CALLERS (0): 
CALLEES (13): FUN_005baa00@0x005baa00, FUN_005c0370@0x005c0370, FUN_005c1c10@0x005c1c10, FUN_005c0210@0x005c0210, FUN_005baa60@0x005baa60, FUN_005bff80@0x005bff80, FUN_005ba940@0x005ba940, FUN_005c0260@0x005c0260, FUN_005c09c0@0x005c09c0, FUN_005c0860@0x005c0860, FUN_005b9110@0x005b9110, FUN_005be9a0@0x005be9a0, ...
----------------------------------------------------------------

void FUN_005fc0c0(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  char cStack_10;
  char cStack_f;
  undefined4 uStack_4;
  
  if ((cRam006c4b90 != '\x06') && (cRam006c4fbb == '\t')) {
    cStack_10 = (char)*param_1;
    if (cStack_10 == '\x02') {
      cStack_f = (char)((uint)*param_1 >> 8);
      if (cStack_f == '\v') {
        FUN_005baa00();
      }
      else if (cStack_f == '\n') {
        FUN_005c1c10(&uStack_4);
        FUN_005ba940(uStack_4);
      }
    }
    else if (cStack_10 == '\0') {
      FUN_005bff80(0x6c4602);
      for (iVar2 = 0; iVar2 < (int)(uint)uRam006c4602; iVar2 = iVar2 + 1) {
        iVar1 = iVar2 * 0x15c;
        *(short *)(iVar1 + 0x6c0760) = (short)(iVar2 + 1U);
        FUN_005c0210(iVar2 + 1U & 0xffff,iVar1 + 0x6c076e);
        FUN_005c01d0(iVar2 + 1U & 0xffff,iVar1 + 0x6c0762);
        FUN_005c0260(iVar2 + 1U & 0xffff,iVar1 + 0x6c0778);
        FUN_005c0370(iVar2 + 1U & 0xffff,iVar1 + 0x6c0764,iVar1 + 0x6c0766,iVar1 + 0x6c0768,
                     iVar1 + 0x6c076a,iVar1 + 0x6c076c);
        FUN_005c09c0(iVar2 + 1U & 0xffff,iVar1 + 0x6c076f);
        FUN_005c0860(iVar2 + 1U & 0xffff,iVar1 + 0x6c0774);
      }
      cRam006c4fbb = '\0';
      uRam006c4b9f = 0;
      cRam006c4b9e = cRam006c4b9e + '\x01';
      FUN_005b9110(0x4c);
      FUN_005baa60();
    }
    else {
      cRam006c4fbb = '\0';
      uRam006c4b9f = 0;
      cRam006c4b9e = cRam006c4b9e + '\x01';
      FUN_005be9a0(0x6c517c);
      FUN_005b9110(0x4c);
    }
  }
  return;
}



================================================================