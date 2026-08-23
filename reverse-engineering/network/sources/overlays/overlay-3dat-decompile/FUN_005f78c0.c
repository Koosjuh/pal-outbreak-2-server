FUNCTION FUN_005f78c0 @ 0x005f78c0  size=580
CALLERS (1): FUN_005f7800@0x005f7800
CALLEES (9): FUN_005bf410@0x005bf410, FUN_005f8340@0x005f8340, FUN_005adc80@0x005adc80, FUN_005b6900@0x005b6900, FUN_00618b60@0x00618b60, FUN_005fe1e0@0x005fe1e0, FUN_005b68e0@0x005b68e0, FUN_005bfbe0@0x005bfbe0, FUN_005bae80@0x005bae80
----------------------------------------------------------------

void FUN_005f78c0(undefined8 param_1)

{
  char cVar1;
  uint uVar2;
  undefined2 uVar3;
  uint uVar4;
  short sVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  char *pcVar11;
  
  iVar7 = (int)param_1;
  *(undefined1 *)(iVar7 + 0x45a) = 0;
  cVar1 = *(char *)(iVar7 + 0xf);
  if (cVar1 == '\x02') {
    sVar5 = *(short *)(iVar7 + 0x16) + -1;
    *(short *)(iVar7 + 0x16) = sVar5;
    if (sVar5 < 0) {
      uVar3 = FUN_005adc80(0);
      FUN_005bf410(uVar3,0x5f7b10);
      *(char *)(iVar7 + 0xe) = *(char *)(iVar7 + 0xe) + '\x01';
      *(undefined1 *)(iVar7 + 0xf) = 0;
      FUN_005fe1e0(param_1);
      func_0x00106b60(0x70b410,0xff,8);
      iVar9 = 1;
      if (cRam006c303e != '\0') {
        uRam0070b410 = 1;
      }
      iVar10 = 0x15c;
      do {
        if (*(char *)(iVar10 + 0x6c303e) == '\0') {
          *(undefined1 *)(iVar9 + 0x70b410) = 0xff;
        }
        else {
          *(undefined1 *)(iVar9 + 0x70b410) = 0;
        }
        iVar9 = iVar9 + 1;
        iVar10 = iVar9 * 0x15c;
      } while (iVar9 < 6);
      uVar4 = FUN_005bae80(bRam006c45f8 - 1);
      iVar9 = 1;
      uVar2 = 1;
      uVar6 = 0;
      do {
        uVar8 = uVar2;
        if ((uVar4 & 1 << (uVar6 & 0x1f)) != 0) {
          if (*(char *)(iVar9 + 0x70b410) == '\0') {
            *(char *)(iVar9 + 0x70b410) = (char)uVar8;
          }
          iVar9 = iVar9 + 1;
        }
        uVar2 = uVar8 + 1;
        uVar6 = uVar8;
      } while ((int)(uVar8 + 1) < 0xc);
      pcVar11 = (char *)0x70b411;
      iVar9 = 1;
      do {
        cVar1 = *pcVar11;
        if ((((cVar1 != '\0') && (cVar1 != -1)) && (cVar1 == '\x05')) &&
           (*(short *)(iVar7 + 0x4c4) == -1)) {
          *pcVar11 = '\0';
        }
        iVar10 = iVar9 + 1;
        pcVar11 = (char *)(iVar9 + 0x70b411);
        iVar9 = iVar10;
      } while (iVar10 < 6);
    }
  }
  else if (cVar1 == '\x01') {
    FUN_005b6900();
  }
  else if (cVar1 == '\0') {
    *(undefined1 *)(iVar7 + 0xf) = 1;
    *(undefined2 *)(iVar7 + 0x16) = 10;
    uRam006c45fc = 0;
    FUN_00618b60();
    func_0x00106b60(0x70b410,0xff,8);
    FUN_005f8340(param_1);
    *(undefined1 *)(iVar7 + 0x45a) = 0;
    *(undefined1 *)(iVar7 + 0x454) = 1;
    *(undefined1 *)(iVar7 + 0x10b3) = 0;
    FUN_005b68e0();
    *(undefined1 *)(iVar7 + 0x42b) = 7;
    FUN_005bfbe0(0,7,0x5f7b30);
  }
  return;
}



================================================================