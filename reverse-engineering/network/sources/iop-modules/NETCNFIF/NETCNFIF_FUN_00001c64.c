FUNCTION FUN_00001c64 @ 0x00001c64 size=1112
CALLERS (2): FUN_000020bc@0x000020bc, FUN_00002284@0x00002284
CALLEES (5): FUN_0000273c@0x0000273c, FUN_00002734@0x00002734, FUN_00001a20@0x00001a20, FUN_0000276c@0x0000276c, FUN_00001740@0x00001740

int FUN_00001c64(int param_1,int param_2,int param_3)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  code cVar10;
  char cVar11;
  char cVar12;
  char cVar13;
  char cVar14;
  char cVar15;
  char cVar16;
  char cVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  
  iVar20 = 0;
  if (*(int *)(param_1 + 0x1c) == 0) {
    iVar18 = FUN_00002734(param_1,0x160,2);
    *(int *)(param_1 + 0x1c) = iVar18;
    if (iVar18 == 0) {
      return -2;
    }
    FUN_0000273c(iVar18);
  }
  bVar8 = true;
  FUN_00001740(*(undefined4 *)(param_1 + 0x1c));
  if (param_3 == 1) {
    iVar18 = *(int *)(param_2 + 0x1300);
    if (iVar18 != -1) {
      **(int **)(param_1 + 0x1c) = iVar18;
    }
    cVar10 = FUN_00001320[param_2];
    if (cVar10 != (code)0xff) {
      *(code *)(*(int *)(param_1 + 0x1c) + 0x10) = cVar10;
    }
    bVar8 = *(char *)(param_2 + 0x200) == '\0';
    if (!bVar8) {
      *(int *)(*(int *)(param_1 + 0x1c) + 0x14) = param_2 + 0x200;
    }
    bVar9 = *(char *)(param_2 + 0x300) == '\0';
    if (!bVar9) {
      *(int *)(*(int *)(param_1 + 0x1c) + 0x1c) = param_2 + 0x300;
    }
    bVar1 = *(char *)(param_2 + 0x400) == '\0';
    if (!bVar1) {
      *(int *)(*(int *)(param_1 + 0x1c) + 0x20) = param_2 + 0x400;
    }
    iVar20 = FUN_00001a20(param_1,param_2);
    if (iVar20 < 0) {
      return iVar20;
    }
    bVar2 = *(char *)(param_2 + 0x800) == '\0';
    if (!bVar2) {
      *(int *)(*(int *)(param_1 + 0x1c) + 0x38) = param_2 + 0x800;
    }
    bVar3 = *(char *)(param_2 + 0x900) == '\0';
    if (!bVar3) {
      *(int *)(*(int *)(param_1 + 0x1c) + 0x3c) = param_2 + 0x900;
    }
    bVar4 = *(char *)(param_2 + 0xa00) == '\0';
    if (!bVar4) {
      *(int *)(*(int *)(param_1 + 0x1c) + 0x40) = param_2 + 0xa00;
    }
    bVar5 = *(char *)(param_2 + 0xb00) == '\0';
    if (!bVar5) {
      *(int *)(*(int *)(param_1 + 0x1c) + 0x70) = param_2 + 0xb00;
    }
    bVar6 = *(char *)(param_2 + 0xc00) == '\0';
    if (!bVar6) {
      *(int *)(*(int *)(param_1 + 0x1c) + 0x74) = param_2 + 0xc00;
    }
    bVar7 = *(char *)(param_2 + 0xd00) == '\0';
    if (!bVar7) {
      *(int *)(*(int *)(param_1 + 0x1c) + 0x78) = param_2 + 0xd00;
    }
    cVar11 = *(char *)(param_2 + 0x1321);
    if (cVar11 != -1) {
      *(char *)(*(int *)(param_1 + 0x1c) + 0x97) = cVar11;
    }
    cVar12 = *(char *)(param_2 + 0x1322);
    if (cVar12 != -1) {
      *(char *)(*(int *)(param_1 + 0x1c) + 0x98) = cVar12;
    }
    cVar13 = *(char *)(param_2 + 0x1323);
    if (cVar13 != '\0') {
      *(char *)(*(int *)(param_1 + 0x1c) + 0xf7) = cVar13;
    }
    *(undefined1 *)(*(int *)(param_1 + 0x1c) + 0xf4) = *(undefined1 *)(param_2 + 0x1324);
    cVar14 = *(char *)(param_2 + 0x1325);
    if (cVar14 != -1) {
      *(char *)(*(int *)(param_1 + 0x1c) + 0x12e) = cVar14;
    }
    cVar15 = *(char *)(param_2 + 0x1326);
    if (cVar15 != -1) {
      *(char *)(*(int *)(param_1 + 0x1c) + 0x93) = cVar15;
    }
    cVar16 = *(char *)(param_2 + 0x1327);
    if (cVar16 != -1) {
      *(char *)(*(int *)(param_1 + 0x1c) + 0x94) = cVar16;
    }
    cVar17 = *(char *)(param_2 + 0x1328);
    if (cVar17 != -1) {
      *(char *)(*(int *)(param_1 + 0x1c) + 0x91) = cVar17;
    }
    iVar19 = *(int *)(param_2 + 0x1304);
    if (iVar19 != -1) {
      *(int *)(*(int *)(param_1 + 0x1c) + 0x13c) = iVar19;
    }
    bVar8 = iVar19 == -1 &&
            (cVar17 == -1 &&
            (cVar16 == -1 &&
            (cVar15 == -1 &&
            (cVar14 == -1 &&
            (cVar13 == '\0' &&
            (cVar12 == -1 &&
            (cVar11 == -1 &&
            (bVar7 && (bVar6 && (bVar5 && (bVar4 && (bVar3 && (bVar2 && (iVar20 == 0 &&
                                                                        (bVar1 && (bVar9 && (bVar8 
                                                  && (cVar10 == (code)0xff && iVar18 == -1))))))))))
            ))))))));
    iVar18 = *(int *)(param_2 + 0x1308);
  }
  else {
    if (param_3 != 2) goto LAB_00002088;
    iVar18 = *(int *)(param_2 + 0x130c);
    if (iVar18 != -1) {
      **(int **)(param_1 + 0x1c) = iVar18;
    }
    bVar8 = *(char *)(param_2 + 0xe00) == '\0';
    if (!bVar8) {
      *(int *)(*(int *)(param_1 + 0x1c) + 4) = param_2 + 0xe00;
    }
    bVar9 = *(char *)(param_2 + 0xf00) == '\0';
    if (!bVar9) {
      *(int *)(*(int *)(param_1 + 0x1c) + 8) = param_2 + 0xf00;
    }
    iVar19 = *(int *)(param_2 + 0x1310);
    if (iVar19 != -1) {
      *(int *)(*(int *)(param_1 + 0x1c) + 0x14c) = iVar19;
    }
    bVar8 = iVar19 == -1 && (bVar9 && (bVar8 && iVar18 == -1));
    if (*(char *)(param_2 + 0x1000) != '\0') {
      iVar20 = FUN_0000276c(param_2 + 0x1000,&DAT_00006170,0x100);
      bVar8 = false;
      if (iVar20 < 0) {
        return iVar20;
      }
      *(undefined **)(*(int *)(param_1 + 0x1c) + 0x24) = &DAT_00006170;
    }
    if (*(char *)(param_2 + 0x1100) != '\0') {
      bVar8 = false;
      *(int *)(*(int *)(param_1 + 0x1c) + 0x30) = param_2 + 0x1100;
    }
    if (*(char *)(param_2 + 0x1200) != '\0') {
      bVar8 = false;
      *(int *)(*(int *)(param_1 + 0x1c) + 0x34) = param_2 + 0x1200;
    }
    if (*(int *)(param_2 + 0x1314) != -1) {
      bVar8 = false;
      *(int *)(*(int *)(param_1 + 0x1c) + 0x68) = *(int *)(param_2 + 0x1314);
    }
    iVar18 = *(int *)(param_2 + 0x1318);
  }
  if (iVar18 != -1) {
    bVar8 = false;
    *(int *)(*(int *)(param_1 + 0x1c) + 0x88) = iVar18;
  }
LAB_00002088:
  if (bVar8) {
    *(undefined4 *)(param_1 + 0x1c) = 0;
    iVar20 = -100;
  }
  return iVar20;
}


================================================================