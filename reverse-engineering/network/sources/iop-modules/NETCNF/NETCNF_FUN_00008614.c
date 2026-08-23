FUNCTION FUN_00008614 @ 0x00008614 size=664
CALLERS (2): FUN_00003f98@0x00003f98, FUN_000032bc@0x000032bc
CALLEES (7): FUN_00009720@0x00009720, FUN_000084e4@0x000084e4, FUN_00001198@0x00001198, FUN_00000da8@0x00000da8, FUN_00009470@0x00009470, FUN_00009658@0x00009658, FUN_000094b8@0x000094b8

int FUN_00008614(undefined4 param_1,int param_2,int param_3,int param_4)

{
  char cVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  
  if (param_2 == 1) {
    if (param_4 == 0) {
      iVar4 = FUN_00000da8(param_1,&DAT_0000c200);
    }
    else {
      iVar4 = FUN_00001198(param_1,&DAT_0000c200);
    }
    if (-1 < iVar4) {
      pcVar5 = (char *)FUN_00009470(0x400);
      pcVar9 = DAT_0000c200;
      if (pcVar5 == (char *)0x0) {
        FUN_000094b8(DAT_0000c200);
        iVar4 = -2;
      }
      else {
        if ((param_3 == 0) ||
           ((0x23 < iVar4 &&
            (iVar6 = FUN_00009658(DAT_0000c200,"# <Sony Computer Entertainment Inc.>",0x24),
            iVar6 == 0)))) {
          pcVar8 = pcVar5;
          iVar6 = 0;
          if (0 < iVar4) {
            iVar7 = iVar4;
            do {
              iVar4 = iVar6;
              iVar7 = iVar7 + -1;
              cVar2 = *pcVar9;
              cVar1 = *pcVar9;
              pcVar9 = pcVar9 + 1;
              if (cVar1 == '\n') {
                if ((pcVar5 < pcVar8) && (pcVar8[-1] == '\\')) {
                  pcVar8 = pcVar8 + -1;
                }
                else {
                  *pcVar8 = '\0';
                  iVar4 = FUN_000084e4(pcVar5,pcVar8);
                  pcVar8 = pcVar5;
                  if (iVar4 < 0) goto LAB_00008860;
                }
              }
              else if ((pcVar8 < pcVar5 + 0x3ff) && (cVar1 != '\r')) {
                *pcVar8 = cVar2;
                pcVar8 = pcVar8 + 1;
              }
              iVar6 = iVar4;
            } while (0 < iVar7);
          }
          iVar4 = iVar6;
          if (pcVar5 < pcVar8) {
            iVar4 = FUN_000084e4(pcVar5,pcVar8);
          }
        }
        else {
          iVar6 = 0;
          FUN_00009720("netcnf: decoding error (magic=\"");
          bVar3 = true;
          if (0 < iVar4) {
            do {
              if (!bVar3) break;
              if ((byte)pcVar9[iVar6] - 0x20 < 0x5f) {
                iVar7 = (int)pcVar9[iVar6];
              }
              else {
                iVar7 = 0x3f;
              }
              FUN_00009720(&DAT_0000aa6c,iVar7);
              iVar6 = iVar6 + 1;
              bVar3 = iVar6 < 0x24;
            } while (iVar6 < iVar4);
          }
          iVar4 = -0xf;
          FUN_00009720(&DAT_0000aa70);
        }
LAB_00008860:
        FUN_000094b8(DAT_0000c200);
        FUN_000094b8(pcVar5);
      }
    }
  }
  else {
    if (param_2 < 2) {
      if (param_2 != 0) {
        return -10;
      }
    }
    else if (param_2 != 2) {
      return -10;
    }
    iVar4 = 0;
  }
  return iVar4;
}


================================================================