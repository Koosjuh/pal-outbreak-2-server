FUNCTION FUN_005ed6e0 @ 0x005ed6e0  size=1364
CALLERS (2): FUN_005edc40@0x005edc40, FUN_005f2940@0x005f2940
CALLEES (10): FUN_005ed630@0x005ed630, FUN_005d9450@0x005d9450, FUN_005ed530@0x005ed530, FUN_005d9160@0x005d9160, FUN_005d9030@0x005d9030, FUN_005d8e00@0x005d8e00, FUN_005d8d60@0x005d8d60, FUN_005d9520@0x005d9520, FUN_005d9dd0@0x005d9dd0, FUN_005d8ea0@0x005d8ea0
----------------------------------------------------------------

void FUN_005ed6e0(ushort param_1,short param_2,short *param_3,short *param_4,uint param_5)

{
  undefined1 uVar1;
  uint uVar2;
  short sVar3;
  int iVar4;
  short sVar5;
  uint uVar6;
  ushort uStack_8;
  short sStack_6;
  int iStack_4;
  
  iVar4 = iRam007012a0 + (uint)*(ushort *)(iRam007012a0 + 0x188) * 4;
  iStack_4 = iVar4 + 0x1540;
  sVar5 = 0;
  if (*(char *)(iRam007012a0 + 0x186) == '\x01') {
    if (*(char *)(iRam007012a0 + 0x4e4) == '\a') {
      if (*(ushort *)(iVar4 + 0x1542) < *(ushort *)(iRam007012a0 + 0x6ee)) {
        *(ushort *)(iVar4 + 0x1542) = *(ushort *)(iRam007012a0 + 0x6ee);
      }
    }
    else if (*(ushort *)(iVar4 + 0x1542) < 0x14) {
      *(undefined2 *)(iVar4 + 0x1542) = 0x14;
    }
  }
  uStack_8 = param_1;
  sStack_6 = param_2;
  switch(*(undefined1 *)(iRam007012a0 + 0x4e4)) {
  case 0:
    uVar2 = param_5 & 0xffff;
    if ((param_5 & 0xffff) < 2) {
      uVar2 = 2;
    }
    uVar2 = uVar2 * 8 + 8;
    uVar6 = uVar2 & 0xffff;
    sVar5 = (short)uVar2;
    FUN_005ed530(&uStack_8,&sStack_6,uVar6,&iStack_4);
    if ((*(char *)(iRam007012a0 + 0x186) == '\0') && (*(char *)(iRam007012a0 + 0xe96b) == '\0')) {
      uVar1 = FUN_005ed630(iRam007012a0 + 399);
      sVar3 = sStack_6 + *(short *)(iStack_4 + 2);
      FUN_005d9030(uStack_8,sVar3 + -0x14,uStack_8 + uVar6 & 0xffff,sVar3,iRam007012a0 + 0x2e4,
                   iRam007012a0 + 0x3e4,*(undefined2 *)(iRam007012a0 + 0x4e8),uVar1);
      sVar3 = *param_3;
      goto LAB_005edc08;
    }
    break;
  case 1:
    uVar2 = param_5 & 0xffff;
    if ((param_5 & 0xffff) < 2) {
      uVar2 = 2;
    }
    uVar2 = uVar2 * 8 + 8;
    uVar6 = uVar2 & 0xffff;
    sVar5 = (short)uVar2;
    FUN_005ed530(&uStack_8,&sStack_6,uVar6,&iStack_4);
    if ((*(char *)(iRam007012a0 + 0x186) == '\0') && (*(char *)(iRam007012a0 + 0xe96b) == '\0')) {
      uVar1 = FUN_005ed630(iRam007012a0 + 399);
      sVar3 = sStack_6 + *(short *)(iStack_4 + 2);
      FUN_005d9160(uStack_8,sVar3 + -0x14,uStack_8 + uVar6 & 0xffff,sVar3,iRam007012a0 + 0x2e4,
                   iRam007012a0 + 0x3e4,*(undefined2 *)(iRam007012a0 + 0x4e8),uVar1);
    }
    break;
  case 2:
    uVar2 = param_5 & 0xffff;
    if ((param_5 & 0xffff) < 2) {
      uVar2 = 2;
    }
    uVar2 = uVar2 * 8 + 8;
    uVar6 = uVar2 & 0xffff;
    sVar5 = (short)uVar2;
    FUN_005ed530(&uStack_8,&sStack_6,uVar6,&iStack_4);
    if ((*(char *)(iRam007012a0 + 0x186) == '\0') && (*(char *)(iRam007012a0 + 0xe96b) == '\0')) {
      sVar3 = sStack_6 + *(short *)(iStack_4 + 2);
      FUN_005d8d60(uStack_8,sVar3 + -0x14,uStack_8 + uVar6 & 0xffff,sVar3,iRam007012a0 + 0x3e4);
    }
    break;
  case 3:
    uVar2 = param_5 & 0xffff;
    if ((param_5 & 0xffff) < 2) {
      uVar2 = 2;
    }
    uVar2 = uVar2 * 8 + 8;
    uVar6 = uVar2 & 0xffff;
    sVar5 = (short)uVar2;
    FUN_005ed530(&uStack_8,&sStack_6,uVar6,&iStack_4);
    if ((*(char *)(iRam007012a0 + 0x186) == '\0') && (*(char *)(iRam007012a0 + 0xe96b) == '\0')) {
      sVar3 = sStack_6 + *(short *)(iStack_4 + 2);
      FUN_005d8e00(uStack_8,sVar3 + -0x14,uStack_8 + uVar6 & 0xffff,sVar3,iRam007012a0 + 0x3e4);
    }
    break;
  case 4:
    sVar5 = 0x14;
    FUN_005ed530(&uStack_8,&sStack_6,0x14,&iStack_4);
    if ((*(char *)(iRam007012a0 + 0x186) == '\0') && (*(char *)(iRam007012a0 + 0xe96b) == '\0')) {
      uVar1 = FUN_005ed630(iRam007012a0 + 399);
      FUN_005d9450(uStack_8,sStack_6 + *(short *)(iStack_4 + 2) + -0x14,
                   *(undefined1 *)(iRam007012a0 + 0x4ea),iRam007012a0 + 0x2e4,iRam007012a0 + 0x3e4,
                   uVar1);
    }
    break;
  case 5:
    sVar5 = 0x14;
    FUN_005ed530(&uStack_8,&sStack_6,0x14,&iStack_4);
    if ((*(char *)(iRam007012a0 + 0x186) == '\0') && (*(char *)(iRam007012a0 + 0xe96b) == '\0')) {
      uVar1 = FUN_005ed630(iRam007012a0 + 399);
      FUN_005d9520(uStack_8,sStack_6 + *(short *)(iStack_4 + 2) + -0x14,
                   *(undefined1 *)(iRam007012a0 + 0x4ea),iRam007012a0 + 0x2e4,iRam007012a0 + 0x3e4,
                   uVar1);
    }
    break;
  case 6:
    if ((*(char *)(iRam007012a0 + 0x186) == '\0') && (*(char *)(iRam007012a0 + 0xe96b) == '\0')) {
      FUN_005d9dd0(iRam007012a0 + 0x2e4,iRam007012a0 + 0x3e4);
    }
    break;
  case 7:
    sVar5 = (short)param_5;
    FUN_005ed530(&uStack_8,&sStack_6,param_5,&iStack_4);
    if ((*(char *)(iRam007012a0 + 0x186) == '\0') && (*(char *)(iRam007012a0 + 0xe96b) == '\0')) {
      sVar3 = sStack_6 + *(short *)(iStack_4 + 2);
      FUN_005d8ea0(uStack_8,sVar3 - *(short *)(iRam007012a0 + 0x6ee),
                   (uint)uStack_8 + (param_5 & 0xffff) & 0xffff,sVar3,iRam007012a0 + 0x2e4,
                   iRam007012a0 + 0x4eb,iRam007012a0 + 0x5eb);
    }
  }
  sVar3 = *param_3;
LAB_005edc08:
  *param_4 = sVar3 + sVar5;
  *param_3 = sVar3 + sVar5;
  return;
}



================================================================