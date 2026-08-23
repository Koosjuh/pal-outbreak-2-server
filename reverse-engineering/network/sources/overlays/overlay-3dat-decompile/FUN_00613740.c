FUNCTION FUN_00613740 @ 0x00613740  size=244
CALLERS (1): FUN_00612d10@0x00612d10
CALLEES (1): FUN_006146e0@0x006146e0
----------------------------------------------------------------

void FUN_00613740(byte *param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  char cVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  char acStack_40 [64];
  
  iVar7 = 0;
  pcVar5 = acStack_40;
  do {
    pcVar6 = pcVar5;
    bVar2 = *param_1;
    param_1 = param_1 + 1;
    uVar3 = bVar2 / 100;
    uVar1 = (bVar2 / 10) % 10;
    cVar4 = (char)uVar1;
    if (uVar3 == 0) {
      *pcVar6 = ' ';
      if (uVar1 == 0) {
        pcVar6[1] = ' ';
      }
      else {
        pcVar6[1] = cVar4 + '0';
      }
    }
    else {
      *pcVar6 = (char)uVar3 + '0';
      pcVar6[1] = cVar4 + '0';
    }
    iVar7 = iVar7 + 1;
    pcVar6[2] = bVar2 % 10 + 0x30;
    pcVar6[3] = '.';
    pcVar6[4] = ' ';
    pcVar5 = pcVar6 + 5;
  } while (iVar7 < 4);
  pcVar6[3] = '\0';
  FUN_006146e0(param_2,param_3,acStack_40);
  return;
}



================================================================