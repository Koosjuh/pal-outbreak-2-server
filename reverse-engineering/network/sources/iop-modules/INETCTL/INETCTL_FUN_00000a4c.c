FUNCTION FUN_00000a4c @ 0x00000a4c size=2932
CALLERS (1): FUN_00001688@0x00001688
CALLEES (18): FUN_0000018c@0x0000018c, FUN_00003d40@0x00003d40, FUN_000000c4@0x000000c4, FUN_000003b0@0x000003b0, FUN_00003ce8@0x00003ce8, FUN_00003d8c@0x00003d8c, FUN_000009bc@0x000009bc, FUN_00003d7c@0x00003d7c, FUN_00003d84@0x00003d84, FUN_0000091c@0x0000091c, FUN_00000360@0x00000360, FUN_0000007c@0x0000007c, FUN_00000290@0x00000290, FUN_000002f0@0x000002f0, FUN_00000230@0x00000230, FUN_00000328@0x00000328, FUN_00000400@0x00000400, FUN_0000043c@0x0000043c

int FUN_00000a4c(int param_1)

{
  bool bVar1;
  int *piVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  char *pcVar28;
  undefined4 uVar29;
  int iVar30;
  int iVar31;
  undefined4 uVar32;
  undefined1 *puVar33;
  int *piVar34;
  undefined4 uVar35;
  undefined4 uVar36;
  undefined4 *puVar37;
  int iVar38;
  undefined1 auStack_60 [40];
  undefined2 local_38 [2];
  uint local_34;
  undefined4 local_30 [2];
  
  puVar33 = &DAT_00004fc8;
  iVar38 = *(int *)(param_1 + 0x18);
  puVar37 = *(undefined4 **)(iVar38 + 0x24);
  local_30[0] = 0x3ff;
  iVar31 = puVar37[1];
  uVar32 = puVar37[2];
  iVar30 = 0;
  if (*(int *)(iVar31 + 0x13c) != -1) {
    local_38[0] = *(undefined2 *)(iVar31 + 0x13c);
    iVar4 = FUN_000002f0(uVar32,0x10c,*(int *)(iVar31 + 0x13c));
    iVar5 = FUN_000002f0(uVar32,0x9000403a,*(undefined4 *)(iVar31 + 0x13c));
    iVar6 = FUN_0000018c(uVar32,0x90004012,local_38,2);
    iVar30 = FUN_0000018c(uVar32,0x9000401e,local_38,2);
    iVar30 = iVar4 + iVar5 + iVar6 + iVar30;
  }
  iVar4 = FUN_00000230(uVar32,0x90004002,*(undefined4 *)(iVar31 + 0x6c));
  iVar5 = FUN_00000230(uVar32,0x90004004,*(undefined4 *)(iVar31 + 0x70));
  iVar6 = FUN_00000230(uVar32,0x90004005,*(undefined4 *)(iVar31 + 0x74));
  iVar7 = FUN_00000230(uVar32,0x90004006,*(undefined4 *)(iVar31 + 0x78));
  iVar8 = FUN_00000230(uVar32,0x90004007,*(undefined4 *)(iVar31 + 0x7c));
  iVar9 = FUN_00000360(uVar32,0x90004008,*(undefined4 *)(iVar31 + 0x80));
  iVar10 = FUN_00000360(uVar32,0x90004009,*(undefined4 *)(iVar31 + 0x84));
  iVar11 = FUN_00000360(uVar32,0x9000400a,*(undefined4 *)(iVar31 + 0x88));
  iVar12 = FUN_00000360(uVar32,0x9000402b,*(undefined4 *)(iVar31 + 0x8c));
  iVar13 = FUN_00000328(uVar32,0x9000403e,*(undefined1 *)(iVar31 + 0x140));
  iVar14 = FUN_00000328(uVar32,0x9000403c,*(undefined1 *)(iVar31 + 0x141));
  iVar15 = FUN_00000328(uVar32,0x9000403f,*(undefined1 *)(iVar31 + 0x142));
  iVar16 = FUN_00000328(uVar32,0x9000403d,*(undefined1 *)(iVar31 + 0x143));
  iVar17 = FUN_000003b0(uVar32,0x9000403b,*(undefined1 *)(iVar31 + 0x144));
  iVar18 = FUN_00000328(uVar32,0x90004041,*(undefined1 *)(iVar31 + 0x145));
  iVar19 = FUN_00000400(uVar32,0x9000400b,*(undefined1 *)(iVar31 + 0x90));
  iVar20 = FUN_00000400(uVar32,0x9000400c,*(undefined1 *)(iVar31 + 0x91));
  iVar21 = FUN_00000400(uVar32,0x9000400d,*(undefined1 *)(iVar31 + 0x92));
  iVar22 = FUN_00000400(uVar32,0x9000400e,*(undefined1 *)(iVar31 + 0x93));
  iVar23 = FUN_00000400(uVar32,0x9000400f,*(undefined1 *)(iVar31 + 0x94));
  iVar24 = FUN_00000400(uVar32,0x90004010,*(undefined1 *)(iVar31 + 0x95));
  iVar25 = FUN_00000400(uVar32,0x90004011,*(undefined1 *)(iVar31 + 0x96));
  iVar26 = FUN_00000400(uVar32,0x90004023,*(undefined1 *)(iVar31 + 0x97));
  iVar27 = FUN_00000400(uVar32,0x90004024,*(undefined1 *)(iVar31 + 0x98));
  iVar27 = iVar30 + iVar4 + iVar5 + iVar6 + iVar7 + iVar8 + iVar9 + iVar10 + iVar11 + iVar12 +
           iVar13 + iVar14 + iVar15 + iVar16 + iVar17 + iVar18 + iVar19 + iVar20 + iVar21 + iVar22 +
           iVar23 + iVar24 + iVar25 + iVar26 + iVar27;
  if (*(char *)(iVar31 + 0xa9) != '\0') {
    iVar30 = FUN_0000018c(uVar32,0x90004012,iVar31 + 0xa0,2);
    iVar27 = iVar27 + iVar30;
  }
  if (*(char *)(iVar31 + 0xaa) != '\0') {
    iVar30 = FUN_0000018c(uVar32,0x90004013,iVar31 + 0xa4,4);
    iVar27 = iVar27 + iVar30;
  }
  if (*(char *)(iVar31 + 0xab) != '\0') {
    iVar30 = FUN_0000018c(uVar32,0x90004014,iVar31 + 0xa8,1);
    iVar27 = iVar27 + iVar30;
  }
  iVar30 = FUN_0000043c(uVar32,0x90004015,*(undefined4 *)(iVar31 + 0xac));
  iVar4 = FUN_0000043c(uVar32,0x90004016,*(undefined4 *)(iVar31 + 0xb0));
  iVar5 = FUN_0000043c(uVar32,0x90004025,*(undefined4 *)(iVar31 + 0xb4));
  iVar6 = FUN_0000043c(uVar32,0x90004026,*(undefined4 *)(iVar31 + 0xb8));
  iVar7 = FUN_00000400(uVar32,0x90004017,*(undefined1 *)(iVar31 + 0xdc));
  iVar8 = FUN_00000400(uVar32,0x90004018,*(undefined1 *)(iVar31 + 0xdd));
  iVar9 = FUN_00000400(uVar32,0x90004019,*(undefined1 *)(iVar31 + 0xde));
  iVar10 = FUN_00000400(uVar32,0x9000401a,*(undefined1 *)(iVar31 + 0xdf));
  iVar11 = FUN_00000400(uVar32,0x9000401b,*(undefined1 *)(iVar31 + 0xe0));
  iVar12 = FUN_00000400(uVar32,0x9000401c,*(undefined1 *)(iVar31 + 0xe1));
  iVar13 = FUN_00000400(uVar32,0x9000401d,*(undefined1 *)(iVar31 + 0xe2));
  iVar14 = FUN_00000400(uVar32,0x90004027,*(undefined1 *)(iVar31 + 0xe3));
  iVar15 = FUN_00000400(uVar32,0x90004028,*(undefined1 *)(iVar31 + 0xe4));
  iVar15 = iVar27 + iVar30 + iVar4 + iVar5 + iVar6 + iVar7 + iVar8 + iVar9 + iVar10 + iVar11 +
           iVar12 + iVar13 + iVar14 + iVar15;
  if (*(char *)(iVar31 + 0xf5) != '\0') {
    iVar30 = FUN_0000018c(uVar32,0x9000401e,iVar31 + 0xec,2);
    iVar15 = iVar15 + iVar30;
  }
  if (*(char *)(iVar31 + 0xf6) != '\0') {
    iVar30 = FUN_0000018c(uVar32,0x9000401f,iVar31 + 0xf0,4);
    iVar15 = iVar15 + iVar30;
  }
  if (*(char *)(iVar31 + 0xf7) != '\0') {
    iVar30 = FUN_0000018c(uVar32,0x90004020,iVar31 + 0xf4,1);
    iVar15 = iVar15 + iVar30;
  }
  iVar30 = FUN_0000043c(uVar32,0x90004021,*(undefined4 *)(iVar31 + 0xf8));
  iVar4 = FUN_0000043c(uVar32,0x90004022,*(undefined4 *)(iVar31 + 0xfc));
  iVar5 = FUN_0000043c(uVar32,0x90004029,*(undefined4 *)(iVar31 + 0x100));
  iVar6 = FUN_0000043c(uVar32,0x9000402a,*(undefined4 *)(iVar31 + 0x104));
  iVar7 = FUN_000002f0(uVar32,0x90004033,*(undefined4 *)(iVar31 + 0x128));
  iVar7 = iVar15 + iVar30 + iVar4 + iVar5 + iVar6 + iVar7;
  if (*(byte *)(iVar31 + 300) != 0xff) {
    local_34 = (uint)*(byte *)(iVar31 + 300);
    iVar30 = FUN_0000018c(uVar32,0x90004037,&local_34,4);
    iVar7 = iVar7 + iVar30;
  }
  iVar30 = FUN_00000400(uVar32,0x90004036,*(undefined1 *)(iVar31 + 0x12d));
  iVar4 = FUN_0000018c(uVar32,0xc0000200,&DAT_00004fc8,0x400);
  iVar4 = iVar7 + iVar30 + iVar4;
  if (*(char *)(iVar31 + 0x12e) == '\x01') {
    iVar30 = FUN_00000290(uVar32,0xd0000001,*(undefined4 *)(iVar31 + 0x134));
    iVar38 = FUN_00000290(uVar32,0xd0000002,*(undefined4 *)(iVar31 + 0x138));
    iVar31 = FUN_00000400(uVar32,0xd0000004,*(undefined1 *)(iVar31 + 0x12f));
    return iVar4 + iVar30 + iVar38 + iVar31;
  }
  if (iVar4 != 0) {
    return -1;
  }
  piVar2 = DAT_00004700;
  if (DAT_00004fc8 == '\0') {
    pcVar28 = "inetctl: no dial_cnf\n";
LAB_00001180:
    FUN_00003d40(pcVar28);
LAB_00001188:
    iVar30 = -1;
  }
  else {
    for (; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
      iVar30 = FUN_00003d84(&DAT_00004fc8,piVar2[2]);
      if (iVar30 == 0) {
        FUN_000000c4(*(undefined4 *)(param_1 + 0x1c));
        *(undefined4 *)(param_1 + 0x1c) = 0;
        piVar34 = (int *)piVar2[3];
        bVar1 = DAT_000045d8 != 0;
        *puVar37 = piVar34;
        if (bVar1) {
          FUN_00003d40("inetctl: Using pre-loaded %s\n",piVar2[2]);
        }
        goto LAB_00001218;
      }
    }
    if (*(int *)(param_1 + 0x1c) == 0) {
      iVar30 = FUN_0000007c(0x400);
      *(int *)(param_1 + 0x1c) = iVar30;
      if (iVar30 == 0) {
        pcVar28 = "inetctl: no space for sceNetCnfLoadDial\n";
        goto LAB_00001180;
      }
    }
    puVar3 = PTR_DAT_000045e0;
    iVar30 = DAT_000045d8;
    iVar4 = *(int *)(param_1 + 0x1c);
    uVar35 = *(undefined4 *)(PTR_DAT_000045e0 + 8);
    uVar36 = *(undefined4 *)(PTR_DAT_000045e0 + 0xc);
    uVar29 = *(undefined4 *)(PTR_DAT_000045e0 + 0x10);
    *(int *)(PTR_DAT_000045e0 + 8) = iVar4;
    *(int *)(puVar3 + 0xc) = iVar4;
    *(undefined4 *)puVar3 = 0;
    *(char **)(puVar3 + 4) = &DAT_00004fc8;
    *(int *)(puVar3 + 0x10) = iVar4 + 0x400;
    if (iVar30 != 0) {
      FUN_00003d40("inetctl: Loading %s\n");
    }
    iVar30 = FUN_00003ce8(PTR_DAT_000045e0,iVar38);
    puVar3 = PTR_DAT_000045e0;
    *(undefined4 *)(PTR_DAT_000045e0 + 8) = uVar35;
    *(undefined4 *)(puVar3 + 0xc) = uVar36;
    *(undefined4 *)(puVar3 + 0x10) = uVar29;
    if (iVar30 != 0) {
      FUN_00003d40("inetctl: sceNetCnfLoadDial -> %d\n");
      return -1;
    }
    piVar34 = (int *)*puVar37;
LAB_00001218:
    if ((piVar34[3] != 0) &&
       (puVar33 = (undefined1 *)FUN_0000091c(&DAT_00004fc8,piVar34[3],local_30),
       puVar33 == (undefined1 *)0x0)) {
      return -1;
    }
    if ((*(int *)(iVar31 + 0x24) != 0) &&
       (puVar33 = (undefined1 *)FUN_0000091c(puVar33,*(int *)(iVar31 + 0x24),local_30),
       puVar33 == (undefined1 *)0x0)) {
      return -1;
    }
    if ((*(char *)(iVar31 + 0x60) == '\0') || (*(char *)(iVar31 + 0x60) == -1)) {
      if ((piVar34[4] != 0) &&
         (puVar33 = (undefined1 *)FUN_0000091c(puVar33,piVar34[4],local_30),
         puVar33 == (undefined1 *)0x0)) {
        return -1;
      }
      while ((&DAT_00004fc8 < puVar33 && (puVar33[-1] == ' '))) {
        puVar33 = puVar33 + -1;
        *puVar33 = 0;
      }
      iVar30 = FUN_0000018c(uVar32,0x90004001,&DAT_00004fc8,puVar33 + -0x4fc7);
      iVar38 = *piVar34;
      if (iVar38 != 0) {
        iVar4 = FUN_00003d8c(iVar38);
        iVar38 = FUN_0000018c(uVar32,0x9000402e,iVar38,iVar4 + 1);
        iVar30 = iVar30 + iVar38;
      }
      iVar38 = piVar34[1];
      if (iVar38 != 0) {
        iVar4 = FUN_00003d8c(iVar38);
        iVar38 = FUN_0000018c(uVar32,0x9000402f,iVar38,iVar4 + 1);
        iVar30 = iVar30 + iVar38;
      }
      iVar38 = piVar34[2];
      if (iVar38 != 0) {
        iVar4 = FUN_00003d8c(iVar38);
        iVar38 = FUN_0000018c(uVar32,0x90004030,iVar38,iVar4 + 1);
        iVar30 = iVar30 + iVar38;
      }
      iVar38 = FUN_00000400(uVar32,0x9000402c,*(undefined1 *)(iVar31 + 0x68));
      iVar30 = iVar30 + iVar38;
      pcVar28 = *(char **)(iVar31 + 0x30);
      local_30[0] = 0x3ff;
      puVar33 = &DAT_00004fc8;
      if ((pcVar28 != (char *)0x0) && (puVar33 = &DAT_00004fc8, *pcVar28 != '\0')) {
        puVar33 = (undefined1 *)FUN_000009bc(&DAT_00004fc8,pcVar28,local_30);
        if (puVar33 == (undefined1 *)0x0) {
          return -1;
        }
        pcVar28 = *(char **)(iVar31 + 0x34);
        if (((pcVar28 != (char *)0x0) && (*pcVar28 != '\0')) &&
           (puVar33 = (undefined1 *)FUN_000009bc(puVar33,pcVar28,local_30),
           puVar33 == (undefined1 *)0x0)) {
          return -1;
        }
      }
      iVar4 = 0;
      iVar38 = iVar31;
      do {
        if ((*(char **)(iVar38 + 0x38) != (char *)0x0) && (**(char **)(iVar38 + 0x38) != '\0'))
        break;
        iVar4 = iVar4 + 1;
        iVar38 = iVar38 + 4;
      } while (iVar4 < 10);
      if (9 < iVar4) {
        iVar30 = FUN_00003d40("inetctl: phone number not found\n");
        return iVar30;
      }
      puVar37[3] = iVar4;
      puVar37[4] = 0;
      puVar33 = (undefined1 *)
                FUN_000009bc(puVar33,*(undefined4 *)(iVar31 + iVar4 * 4 + 0x38),local_30);
      if (puVar33 == (undefined1 *)0x0) goto LAB_00001188;
      *puVar33 = 0;
      uVar29 = 0x90004003;
      puVar33 = puVar33 + -0x4fc6;
    }
    else {
      if (0 < *(int *)(iVar31 + 100)) {
        FUN_00003d7c(auStack_60,"TIMEOUT %d");
        puVar33 = (undefined1 *)FUN_0000091c(puVar33,auStack_60,local_30);
        if (puVar33 == (undefined1 *)0x0) {
          return -1;
        }
      }
      if ((piVar34[5] != 0) &&
         (puVar33 = (undefined1 *)FUN_0000091c(puVar33,piVar34[5],local_30),
         puVar33 == (undefined1 *)0x0)) {
        return -1;
      }
      while ((&DAT_00004fc8 < puVar33 && (puVar33[-1] == ' '))) {
        puVar33 = puVar33 + -1;
        *puVar33 = 0;
      }
      uVar29 = 0x90004001;
      puVar33 = puVar33 + -0x4fc7;
      iVar30 = 0;
    }
    iVar31 = FUN_0000018c(uVar32,uVar29,&DAT_00004fc8,puVar33);
    iVar30 = iVar30 + iVar31;
  }
  return iVar30;
}


================================================================