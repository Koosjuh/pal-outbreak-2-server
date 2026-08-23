FUNCTION FUN_0060d1d0 @ 0x0060d1d0  size=716
CALLERS (1): FUN_0060d4f0@0x0060d4f0
CALLEES (2): FUN_0060c6e0@0x0060c6e0, FUN_0060c230@0x0060c230
----------------------------------------------------------------

void FUN_0060d1d0(int param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  uint uVar8;
  
  pcVar4 = (char *)FUN_0060c230(iRam0070d120 + 1);
  if (cRam0070d11e == '\b') {
    uVar8 = 0;
    while ((int)uVar8 < *(int *)(param_1 + 8)) {
      if (uVar8 < uRam0070d114) {
        FUN_0060c6e0(pcVar4);
        if (cRam0070d10c != '\0') {
          return;
        }
        uVar6 = 0;
        pcVar7 = pcVar4;
        while( true ) {
          if (*(int *)(param_1 + 4) <= (int)uVar6) goto LAB_0060d46c;
          if (uRam0070d110 <= uVar6) break;
          uVar6 = uVar6 + 1;
          *param_2 = *pcVar7;
          pcVar7 = pcVar7 + 1;
          param_2 = param_2 + 1;
        }
        iVar5 = *(int *)(param_1 + 4);
        for (; (int)uVar6 < iVar5; uVar6 = uVar6 + 1) {
          *param_2 = '\0';
          param_2 = param_2 + 1;
          iVar5 = *(int *)(param_1 + 4);
        }
LAB_0060d46c:
        uVar8 = uVar8 + 1;
      }
      else {
        for (iVar5 = 0; iVar5 < *(int *)(param_1 + 4); iVar5 = iVar5 + 1) {
          *param_2 = '\0';
          param_2 = param_2 + 1;
        }
        uVar8 = uVar8 + 1;
      }
    }
  }
  else {
    uVar8 = 0;
    if (cRam0070d11e == '\x18') {
      iVar5 = *(int *)(param_1 + 8);
LAB_0060d394:
      if (iVar5 <= (int)uVar8) {
        return;
      }
      if (uVar8 < uRam0070d114) {
        FUN_0060c6e0(pcVar4);
        if (cRam0070d10c != '\0') {
          return;
        }
        pcVar7 = pcVar4;
        for (uVar6 = 0; (int)uVar6 < *(int *)(param_1 + 4); uVar6 = uVar6 + 1) {
          if (uRam0070d110 <= uVar6) goto LAB_0060d2d8;
          cVar1 = *pcVar7;
          cVar2 = pcVar7[1];
          cVar3 = pcVar7[2];
          *param_2 = cVar1;
          param_2[1] = cVar2;
          param_2[2] = cVar3;
          pcVar7 = pcVar7 + 3;
          if (cRam0070d124 == '\0') {
            param_2[3] = -0x80;
          }
          else if (((cRam0070d125 == cVar1) && (cRam0070d126 == cVar2)) && (cRam0070d127 == cVar3))
          {
            param_2[3] = '\0';
          }
          else {
            param_2[3] = -0x80;
          }
          param_2 = param_2 + 4;
        }
      }
      else {
        for (iVar5 = 0; iVar5 < *(int *)(param_1 + 4); iVar5 = iVar5 + 1) {
          *param_2 = '\0';
          param_2[1] = '\0';
          param_2[2] = '\0';
          param_2[3] = -0x80;
          param_2 = param_2 + 4;
        }
      }
      goto LAB_0060d390;
    }
  }
  return;
LAB_0060d2d8:
  for (; (int)uVar6 < *(int *)(param_1 + 4); uVar6 = uVar6 + 1) {
    *param_2 = '\0';
    param_2[1] = '\0';
    param_2[2] = '\0';
    param_2[3] = -0x80;
    param_2 = param_2 + 4;
  }
LAB_0060d390:
  uVar8 = uVar8 + 1;
  iVar5 = *(int *)(param_1 + 8);
  goto LAB_0060d394;
}



================================================================