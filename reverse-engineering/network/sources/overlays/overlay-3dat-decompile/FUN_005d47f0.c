FUNCTION FUN_005d47f0 @ 0x005d47f0  size=3652
CALLERS (1): FUN_005d1e80@0x005d1e80
CALLEES (8): FUN_005d7540@0x005d7540, FUN_005d59f0@0x005d59f0, FUN_005d5c20@0x005d5c20, FUN_005d5a40@0x005d5a40, FUN_005d5cc0@0x005d5cc0, FUN_005d7410@0x005d7410, FUN_005d74a0@0x005d74a0, FUN_005d7690@0x005d7690
----------------------------------------------------------------

void FUN_005d47f0(int param_1)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  long lVar6;
  long lVar7;
  char cVar8;
  bool bVar9;
  int iVar10;
  char *pcVar11;
  int iVar12;
  short sVar13;
  ulong uVar14;
  undefined1 auStack_200 [256];
  char acStack_100 [256];
  
  bVar9 = false;
  cVar8 = '\0';
  if (*(char *)(iRam00701070 + 0x38) != '\0') {
    return;
  }
  iVar12 = param_1;
  if (*(char *)(iRam00701070 + 0x3a) != '\0') {
    return;
  }
  for (; iVar10 = 0, 0 < iVar12; iVar12 = iVar12 + -1) {
    iVar10 = *(int *)(iRam00701068 + iVar12 * 4 + 0x5ffc0);
    if (*(char *)(iVar10 + 2) == '\x13') {
      if ((**(char **)(iVar10 + 0x60) == '\0') && (*(char *)(iRam00701068 + 0x60dc5) == '\0')) {
        return;
      }
      cVar8 = *(char *)(iVar10 + 5);
      bVar9 = true;
      iVar10 = iVar12;
      break;
    }
  }
  if (!bVar9) {
    return;
  }
  iVar12 = iVar10;
  if (*(char *)(iRam00701068 + 0x60dc5) != '\0') {
    for (; iVar12 < 500; iVar12 = iVar12 + 1) {
      iVar3 = *(int *)(iRam00701068 + iVar12 * 4 + 0x5ffc0);
      if (*(char *)(iVar3 + 2) == '\x06') {
        FUN_005d5cc0(*(undefined4 *)(iVar3 + 100));
        *(undefined4 *)(iRam00701078 + 0x20) = 0;
        *(undefined1 *)(*(int *)(param_1 * 4 + iRam00701068 + 0x5ffc0) + 5) = 1;
        *(undefined4 *)(iRam00701068 + 0x69018) = 2;
        FUN_005d59f0();
        return;
      }
    }
  }
  iVar12 = *(int *)(param_1 * 4 + iRam00701068 + 0x5ffc0);
  cVar1 = *(char *)(iVar12 + 2);
  if ((cVar1 == '\x04') || (cVar1 == '\x03')) {
    *(undefined1 *)(iVar12 + 5) = 1;
    *(undefined4 *)(iRam00701068 + 0x69018) = 2;
  }
  if (cVar8 != '\0') {
    FUN_005d7690();
    func_0x00106b60(auStack_200,0,0x100);
    lVar6 = 0;
    iVar12 = iVar10;
LAB_005d5588:
    do {
      iVar12 = iVar12 + 1;
      if (499 < iVar12) {
LAB_005d5594:
        *(undefined4 *)(iRam00701078 + 0x20) = 0;
        *(undefined1 *)(iRam00701070 + 0x2c) = 0;
        FUN_005d5cc0(*(undefined4 *)(*(int *)(iVar10 * 4 + iRam00701068 + 0x5ffc0) + 0x60));
        if (*(char *)(iRam00701070 + 0x2e) == '\b') {
          FUN_005d5c20(9);
          return;
        }
        FUN_005d74a0(iRam00701068 + 0x4f97c);
        uRam00700fe8 = 1;
        FUN_005d5a40();
        return;
      }
      iVar3 = iVar12 * 4;
      pcVar11 = *(char **)(iRam00701068 + iVar3 + 0x5ffc0);
      if (((pcVar11 == (char *)0x0) || (*pcVar11 == '\0')) || (cVar8 = pcVar11[2], cVar8 == '\x13'))
      goto LAB_005d5594;
      if (cVar8 == '\x14') {
        lVar7 = func_0x0010a050(auStack_200);
        if ((lVar7 != 0) &&
           (lVar7 = func_0x00109d70(*(undefined4 *)(*(int *)(iRam00701068 + iVar3 + 0x5ffc0) + 0x60)
                                    ,auStack_200), lVar7 == 0)) goto LAB_005d5588;
        iVar4 = *(int *)(iRam00701068 + iVar3 + 0x5ffc0);
        lVar6 = FUN_005d7540(*(undefined4 *)(iVar4 + 0x60),*(undefined4 *)(iVar4 + 100));
        func_0x00106b60(auStack_200,0,0x100);
        func_0x00109eb8(auStack_200,*(undefined4 *)(*(int *)(iRam00701068 + iVar3 + 0x5ffc0) + 0x60)
                       );
      }
      else if ((cVar8 == '\v') || (cVar8 == '\f')) {
        lVar7 = func_0x0010a050(auStack_200);
        if ((lVar7 != 0) &&
           (lVar7 = func_0x00109d70(*(undefined4 *)(*(int *)(iRam00701068 + iVar3 + 0x5ffc0) + 0x60)
                                    ,auStack_200), lVar7 == 0)) goto LAB_005d5588;
        iVar4 = *(int *)(iRam00701068 + iVar3 + 0x5ffc0);
        if (*(char *)(iVar4 + 5) != '\0') {
          lVar6 = FUN_005d7540(*(undefined4 *)(iVar4 + 0x60),*(undefined4 *)(iVar4 + 100));
          func_0x00106b60(auStack_200,0,0x100);
          func_0x00109eb8(auStack_200,
                          *(undefined4 *)(*(int *)(iRam00701068 + iVar3 + 0x5ffc0) + 0x60));
        }
      }
      else if ((cVar8 == '\a') || (cVar8 == '\x06')) {
        if ((*(char *)(iRam00701068 + 0x60dc5) == '\0') ||
           (lVar7 = func_0x0010a700(*(undefined4 *)(pcVar11 + 0x60),0x642fb8), lVar7 == 0)) {
          lVar7 = func_0x0010a050(auStack_200);
          if ((lVar7 != 0) &&
             (lVar7 = func_0x00109d70(*(undefined4 *)
                                       (*(int *)(iRam00701068 + iVar3 + 0x5ffc0) + 0x60),auStack_200
                                     ), lVar7 == 0)) goto LAB_005d5588;
          iVar4 = *(int *)(iRam00701068 + iVar3 + 0x5ffc0);
          lVar6 = FUN_005d7540(*(undefined4 *)(iVar4 + 0x60),*(undefined4 *)(iVar4 + 100));
          func_0x00106b60(auStack_200,0,0x100);
          func_0x00109eb8(auStack_200,
                          *(undefined4 *)(*(int *)(iRam00701068 + iVar3 + 0x5ffc0) + 0x60));
          iVar4 = *(int *)(iRam00701068 + iVar3 + 0x5ffc0);
          cVar8 = *(char *)(iVar4 + 0x5d);
          if (cVar8 == '\x03') {
            if ((*(char *)(iRam00701070 + 0x35) == '\x02') ||
               (*(char *)(iRam00701070 + 0x35) == '\x04')) {
              func_0x00106b60(iRam00701070 + 0x5b2,0,0x11);
              func_0x00109eb8(iRam00701070 + 0x5b2,
                              *(undefined4 *)(*(int *)(iRam00701068 + iVar3 + 0x5ffc0) + 100));
            }
          }
          else if (cVar8 == '\x02') {
            func_0x00109eb8(iRam00701070 + 0x56e,*(undefined4 *)(iVar4 + 100));
          }
          else if (cVar8 == '\x01') {
            func_0x00109eb8(iRam00701070 + 0x55d,*(undefined4 *)(iVar4 + 100));
          }
        }
      }
      else if (cVar8 == '\b') {
        if ((pcVar11[0x5f] != '\0') ||
           ((lVar7 = func_0x0010a050(auStack_200), lVar7 != 0 &&
            (lVar7 = func_0x00109d70(*(undefined4 *)
                                      (*(int *)(iRam00701068 + iVar3 + 0x5ffc0) + 0x60),auStack_200)
            , lVar7 == 0)))) goto LAB_005d5588;
        iVar4 = *(int *)(iRam00701068 + iVar3 + 0x5ffc0);
        lVar6 = FUN_005d7540(*(undefined4 *)(iVar4 + 100),
                             *(undefined4 *)
                              (*(int *)(iRam00701068 + (iVar12 + (uint)*(byte *)(iVar4 + 5)) * 4 +
                                       0x5ffc0) + 100));
        func_0x00106b60(auStack_200,0,0x100);
        func_0x00109eb8(auStack_200,*(undefined4 *)(*(int *)(iRam00701068 + iVar3 + 0x5ffc0) + 0x60)
                       );
      }
      if (lVar6 < 0) {
        return;
      }
    } while( true );
  }
  func_0x00106b60(acStack_100,0,0x100);
  uVar2 = func_0x0010a050(*(undefined4 *)(*(int *)(iVar10 * 4 + iRam00701068 + 0x5ffc0) + 0x60));
  uVar2 = uVar2 & 0xff;
  if (0xff < uVar2) {
    return;
  }
  func_0x001069a8(acStack_100,*(undefined4 *)(*(int *)(iVar10 * 4 + iRam00701068 + 0x5ffc0) + 0x60),
                  uVar2);
  sVar13 = -uVar2 + 0xff;
  if (0 < sVar13) {
    func_0x00109ab0(acStack_100,0x642f80);
    sVar13 = -uVar2 + 0xfe;
  }
  func_0x00106b60(auStack_200,0,0x100);
  iVar10 = iVar10 + 1;
  while (iVar10 < 500) {
    iVar12 = iVar10 * 4;
    pcVar11 = *(char **)(iRam00701068 + iVar12 + 0x5ffc0);
    if (((pcVar11 == (char *)0x0) || (*pcVar11 == '\0')) || (cVar8 = pcVar11[2], cVar8 == '\x13'))
    break;
    if ((((cVar8 == '\v') || (cVar8 == '\f')) || (cVar8 == '\x14')) ||
       ((cVar8 == '\a' || (cVar8 == '\x06')))) {
      if ((((cVar8 != '\f') && (cVar8 != '\v')) || (pcVar11[5] != '\0')) &&
         ((lVar6 = func_0x0010a050(auStack_200), lVar6 == 0 ||
          (lVar6 = func_0x00109d70(*(undefined4 *)(*(int *)(iRam00701068 + iVar12 + 0x5ffc0) + 0x60)
                                   ,auStack_200), lVar6 != 0)))) {
        iVar3 = func_0x0010a050(*(undefined4 *)(*(int *)(iRam00701068 + iVar12 + 0x5ffc0) + 0x60));
        iVar4 = func_0x0010a050(*(undefined4 *)(*(int *)(iRam00701068 + iVar12 + 0x5ffc0) + 100));
        uVar14 = (long)(iVar3 + 1 + iVar4) & 0xff;
        if ((long)sVar13 < (long)uVar14) {
          return;
        }
        func_0x00109ab0(acStack_100,
                        *(undefined4 *)(*(int *)(iRam00701068 + iVar12 + 0x5ffc0) + 0x60));
        func_0x00109ab0(acStack_100,0x642f88);
        func_0x00109ab0(acStack_100,*(undefined4 *)(*(int *)(iRam00701068 + iVar12 + 0x5ffc0) + 100)
                       );
        sVar13 = sVar13 - (short)uVar14;
        func_0x00106b60(auStack_200,0,0x100);
        func_0x00109eb8(auStack_200,
                        *(undefined4 *)(*(int *)(iRam00701068 + iVar12 + 0x5ffc0) + 0x60));
        iVar3 = *(int *)(iRam00701068 + iVar12 + 0x5ffc0);
        cVar8 = *(char *)(iVar3 + 0x5d);
        if (cVar8 == '\x03') {
          if ((*(char *)(iRam00701070 + 0x35) == '\x02') ||
             (*(char *)(iRam00701070 + 0x35) == '\x04')) {
            func_0x00106b60(iRam00701070 + 0x5b2,0,0x11);
            func_0x00109eb8(iRam00701070 + 0x5b2,
                            *(undefined4 *)(*(int *)(iRam00701068 + iVar12 + 0x5ffc0) + 100));
          }
        }
        else if (cVar8 == '\x02') {
          func_0x00109eb8(iRam00701070 + 0x56e,*(undefined4 *)(iVar3 + 100));
        }
        else if (cVar8 == '\x01') {
          func_0x00109eb8(iRam00701070 + 0x55d,*(undefined4 *)(iVar3 + 100));
        }
        if (0 < sVar13) {
          func_0x00109ab0(acStack_100,0x642f90);
          sVar13 = sVar13 + -1;
        }
      }
LAB_005d4f30:
      iVar10 = iVar10 + 1;
    }
    else {
      if (cVar8 == '\b') {
        if ((pcVar11[0x5f] == '\0') &&
           ((lVar6 = func_0x0010a050(auStack_200), lVar6 == 0 ||
            (lVar6 = func_0x00109d70(*(undefined4 *)
                                      (*(int *)(iRam00701068 + iVar12 + 0x5ffc0) + 100),auStack_200)
            , lVar6 != 0)))) {
          iVar3 = func_0x0010a050(*(undefined4 *)
                                   (*(int *)(iRam00701068 +
                                             (iVar10 + (uint)*(byte *)(*(int *)(iRam00701068 +
                                                                                iVar12 + 0x5ffc0) +
                                                                      5)) * 4 + 0x5ffc0) + 100));
          iVar4 = func_0x0010a050(*(undefined4 *)(*(int *)(iRam00701068 + iVar12 + 0x5ffc0) + 100));
          uVar14 = (long)(iVar4 + 1 + iVar3) & 0xff;
          if ((long)sVar13 < (long)uVar14) {
            return;
          }
          func_0x00109ab0(acStack_100,
                          *(undefined4 *)(*(int *)(iRam00701068 + iVar12 + 0x5ffc0) + 100));
          func_0x00109ab0(acStack_100,0x642f88);
          func_0x00109ab0(acStack_100,
                          *(undefined4 *)
                           (*(int *)(iRam00701068 +
                                     (iVar10 + (uint)*(byte *)(*(int *)(iRam00701068 + iVar12 +
                                                                       0x5ffc0) + 5)) * 4 + 0x5ffc0)
                           + 100));
          sVar13 = sVar13 - (short)uVar14;
          func_0x00106b60(auStack_200,0,0x100);
          func_0x00109eb8(auStack_200,
                          *(undefined4 *)(*(int *)(iRam00701068 + iVar12 + 0x5ffc0) + 100));
          if (0 < sVar13) {
            func_0x00109ab0(acStack_100,0x642f90);
            sVar13 = sVar13 + -1;
          }
        }
        goto LAB_005d4f30;
      }
      iVar10 = iVar10 + 1;
    }
  }
  for (pcVar11 = acStack_100; *pcVar11 != '\0'; pcVar11 = pcVar11 + 1) {
    if ((*pcVar11 == '&') && (pcVar11[1] == '\0')) {
      *pcVar11 = '\0';
      break;
    }
  }
  pcVar11 = acStack_100;
  if (pcVar11 == (char *)0x0) {
    return;
  }
  if (acStack_100[0] == '\0') {
    return;
  }
  uVar5 = FUN_005d7410();
  lVar6 = func_0x0010a700(uVar5,0x642f98);
  if (((lVar6 != 0) && (lVar6 = func_0x0010a700(pcVar11,0x642fa0), lVar6 == 0)) &&
     (lVar6 = func_0x0010a700(pcVar11,0x642fa8), lVar6 == 0)) {
    for (; *pcVar11 != '\0'; pcVar11 = pcVar11 + 1) {
      if ((*pcVar11 == '?') && (pcVar11[1] == '\0')) {
        *pcVar11 = '\0';
        break;
      }
    }
  }
  uVar5 = FUN_005d7410();
  lVar6 = func_0x0010a700(uVar5,0x642fa0);
  if (lVar6 == 0) {
    uVar5 = FUN_005d7410();
    lVar6 = func_0x0010a700(uVar5,0x642fa8);
    if (lVar6 == 0) goto LAB_005d50ac;
  }
  lVar6 = func_0x0010a700(pcVar11,0x642f98);
  if (lVar6 != 0) {
    for (; *pcVar11 != '\0'; pcVar11 = pcVar11 + 1) {
      if ((*pcVar11 == '?') && (pcVar11[1] == '\0')) {
        *pcVar11 = '\0';
        break;
      }
    }
  }
LAB_005d50ac:
  FUN_005d5cc0(acStack_100);
  *(undefined1 *)(iRam00701070 + 0x2c) = 0;
  *(undefined4 *)(iRam00701078 + 0x20) = 0;
  if (*(char *)(iRam00701070 + 0x2e) == '\b') {
    FUN_005d5c20();
  }
  else {
    FUN_005d59f0();
  }
  return;
}



================================================================