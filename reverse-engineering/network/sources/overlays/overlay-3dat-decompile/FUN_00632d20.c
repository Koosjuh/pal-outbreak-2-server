FUNCTION FUN_00632d20 @ 0x00632d20  size=736
CALLERS (1): FUN_00632ce0@0x00632ce0
CALLEES (3): FUN_006331a0@0x006331a0, FUN_006332a0@0x006332a0, FUN_00633000@0x00633000
----------------------------------------------------------------

void FUN_00632d20(undefined8 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  long lVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  int iVar11;
  char *pcStack_220;
  char acStack_210 [256];
  char acStack_110 [260];
  uint uStack_c;
  uint uStack_8;
  uint uStack_4;
  
  pcStack_220 = s_AFTER_0068b6e0;
  uVar5 = func_0x0010a050();
  FUN_00633000(acStack_110,param_1,uVar5);
  iVar4 = 0;
LAB_00632fc4:
  if (acStack_110[iVar4] == '\0') {
    return;
  }
  iVar7 = 0;
  pcVar10 = pcStack_220;
LAB_00632f40:
  iVar11 = (int)param_1;
  iVar9 = iVar4;
  if (*pcVar10 != '\0') {
    iVar1 = FUN_006332a0(pcVar10,acStack_210,uVar5);
    iVar8 = 0;
    if (iVar1 != -1) {
      do {
        if ((acStack_210[iVar8] == '\0') || (*(char *)(iVar11 + iVar9) == '\0')) goto LAB_00632eb0;
        iVar2 = func_0x001af430(acStack_110 + iVar9,&uStack_4);
        if ((&DAT_0068ef90)[uStack_4 & 0xff] != '\0') {
          iVar3 = func_0x001af430(acStack_210 + iVar8,&uStack_8);
          if (uStack_4 != uStack_8) {
            func_0x001af430((char *)(iVar11 + iVar9),&uStack_c);
            if ((uStack_c != 0x31) && (uStack_c != 0x21)) {
              if (((uStack_c == 0x28) || (uStack_c == 0x3c)) && (iVar8 == 0)) goto LAB_00632e70;
              goto LAB_00632eb0;
            }
            if (uStack_8 != 0x4c) goto LAB_00632eb0;
          }
          iVar8 = iVar8 + iVar3;
          if (iVar8 == iVar1) goto code_r0x00632e64;
        }
LAB_00632e70:
        iVar9 = iVar9 + iVar2;
      } while( true );
    }
    goto LAB_00632f3c;
  }
  goto LAB_00632fb4;
code_r0x00632e64:
  iVar9 = iVar9 + iVar2;
  iVar7 = 1;
LAB_00632eb0:
  if (iVar7 == 1) {
    func_0x001af430(iVar11 + iVar9,&uStack_c);
    iVar1 = iVar4;
    if ((&DAT_0068ef90)[uStack_c & 0xff] == '\0') goto LAB_00632f10;
    lVar6 = FUN_006331a0(acStack_110 + iVar9);
    iVar7 = 0;
    if (lVar6 != 0) goto LAB_00632f10;
    pcVar10 = pcVar10 + 0x10;
  }
  else {
LAB_00632f3c:
    pcVar10 = pcVar10 + 0x10;
  }
  goto LAB_00632f40;
LAB_00632f10:
  while (iVar7 = iVar1, iVar7 < iVar9) {
    acStack_110[iVar7] = '*';
    iVar1 = iVar7 + 1;
  }
  func_0x0010a4f0(iVar11 + iVar4,acStack_110 + iVar4,iVar9 - iVar4);
LAB_00632fb4:
  do {
    iVar4 = iVar9;
    if ((acStack_110[iVar9] == '\0') || (iVar7 != 0)) break;
    iVar4 = func_0x001af430(iVar11 + iVar9,&uStack_c);
    iVar9 = iVar9 + iVar4;
  } while (((&DAT_0068ef90)[uStack_c & 0xff] != '\0') ||
          (func_0x001af430(acStack_110 + iVar9,&uStack_4), iVar4 = iVar9,
          (&DAT_0068ef90)[uStack_4 & 0xff] == '\0'));
  goto LAB_00632fc4;
}



================================================================