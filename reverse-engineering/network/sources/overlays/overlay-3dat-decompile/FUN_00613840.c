FUNCTION FUN_00613840 @ 0x00613840  size=380
CALLERS (1): FUN_00612d10@0x00612d10
CALLEES (1): FUN_006146e0@0x006146e0
----------------------------------------------------------------

void FUN_00613840(ushort *param_1,undefined8 param_2,undefined8 param_3)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  int iVar6;
  char acStack_50 [18];
  undefined1 auStack_3e [54];
  char acStack_8 [8];
  
  bVar5 = false;
  iVar3 = 10000;
  iVar6 = 0;
  iVar4 = 0;
  do {
    iVar2 = (int)(uint)*param_1 / iVar3;
    iVar3 = iVar3 / 10;
    acStack_8[iVar6] = (char)(iVar2 % 10);
    if (acStack_8[iVar6] != '\0') {
      bVar5 = true;
    }
    if (bVar5) {
      iVar4 = iVar4 + 1;
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 < 5);
  if (iVar4 == 0) {
    iVar4 = 1;
  }
  if ((*(char *)(iRam0070d1c0 + 0x41) == '\0') ||
     (iVar3 = 0, *(ushort **)(iRam0070d1c0 + 0x44) != param_1)) {
    for (iVar3 = 0; iVar3 < -iVar4 + 0x12; iVar3 = iVar3 + 1) {
      acStack_50[iVar3] = ' ';
    }
    func_0x00109728(auStack_3e + -iVar4,0x654140,*param_1);
  }
  else {
    do {
      acStack_50[iVar3] = ' ';
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0xd);
    iVar4 = 0;
    do {
      iVar6 = iVar3;
      pcVar1 = acStack_8 + iVar4;
      iVar4 = iVar4 + 1;
      acStack_50[iVar6] = *pcVar1 + '0';
      iVar3 = iVar6 + 1;
    } while (iVar4 < 5);
    acStack_50[iVar6 + 1] = '\0';
  }
  FUN_006146e0(param_2,param_3,acStack_50);
  return;
}



================================================================