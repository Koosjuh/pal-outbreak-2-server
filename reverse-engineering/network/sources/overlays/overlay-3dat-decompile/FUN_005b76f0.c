FUNCTION FUN_005b76f0 @ 0x005b76f0  size=1504
CALLERS (2): FUN_005b7de0@0x005b7de0, FUN_005b7cd0@0x005b7cd0
CALLEES (5): FUN_005b75b0@0x005b75b0, FUN_005af2e0@0x005af2e0, FUN_005b7f70@0x005b7f70, FUN_005af2c0@0x005af2c0, FUN_005af1e0@0x005af1e0
----------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x005b79fc) */
/* WARNING: Removing unreachable block (ram,0x005b7aa4) */
/* WARNING: Removing unreachable block (ram,0x005b7c60) */
/* WARNING: Removing unreachable block (ram,0x005b787c) */

void FUN_005b76f0(float param_1,float param_2)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  if (cRam006ca881 == '\x02') {
    return;
  }
  iVar6 = (int)param_1;
  piVar5 = (int *)0x6ca600;
  iVar4 = 0;
LAB_005b7c9c:
  if (0x1d < iVar4) {
    return;
  }
  if ((*(char *)((int)piVar5 + 0xb) == '\0') && (piVar5[1] == 0)) {
    return;
  }
  iVar3 = 0;
  uVar2 = piVar5[1];
LAB_005b7b10:
  if (0xf < iVar3) goto LAB_005b7b1c;
  if ((piVar5[1] & 2U) != 0) {
    uRam006ca878 = (uint)*(byte *)((int)piVar5 + 9);
  }
  if ((uVar2 & 1) == 0) {
    if (uVar2 >> 1 != 0) goto switchD_005b77b0_caseD_ffffffff;
    goto LAB_005b7b1c;
  }
  switch(iVar3) {
  case 0:
    if (cRam006ca886 == '\a') {
      fRam006ca860 = fRam006ca86c +
                     (396.0 - (float)uRam006ca884 *
                              ((*(float *)(&DAT_00638f60 + uRam006ca878 * 4) * 20.0) / 2.0));
      break;
    }
    if (cRam006ca886 == '\x06') {
      fRam006ca860 = fRam006ca86c;
      break;
    }
    if (cRam006ca886 == '\x05') {
      FUN_005b75b0(*(undefined4 *)(&DAT_00638f60 + uRam006ca878 * 4),uRam006ca884);
      break;
    }
    iVar3 = iVar3 + 1;
    uVar2 = uVar2 >> 1;
    goto LAB_005b7b10;
  case 1:
    uRam006ca878 = (uint)*(byte *)((int)piVar5 + 9);
    break;
  case 2:
  case 9:
    FUN_005af2c0(*(undefined1 *)(*(byte *)(piVar5 + 2) + 0x638f50));
    break;
  case 3:
    fRam006ca860 = fRam006ca86c;
    if (param_2 == 0.0) {
      fRam006ca864 = fRam006ca864 + *(float *)(&DAT_00638f60 + uRam006ca878 * 4) * 20.0;
    }
    else {
      fRam006ca864 = fRam006ca864 + param_2;
    }
    break;
  case 4:
    cRam006ca886 = '\x05';
    FUN_005b75b0(*(undefined4 *)(&DAT_00638f60 + uRam006ca878 * 4),uRam006ca884);
    break;
  case 5:
    cRam006ca886 = '\x06';
    fRam006ca860 = fRam006ca86c;
    break;
  case 6:
    cRam006ca886 = '\a';
    fRam006ca860 = fRam006ca86c +
                   (396.0 - (float)uRam006ca884 *
                            ((*(float *)(&DAT_00638f60 + uRam006ca878 * 4) * 20.0) / 2.0));
    break;
  case 7:
    return;
  case 8:
    fRam006ca860 = fRam006ca86c;
    fRam006ca864 = fRam006ca864 +
                   (float)*(byte *)((int)piVar5 + 10) *
                   *(float *)(&DAT_00638f60 + uRam006ca878 * 4) * 20.0;
  }
switchD_005b77b0_caseD_ffffffff:
  iVar3 = iVar3 + 1;
  uVar2 = uVar2 >> 1;
  goto LAB_005b7b10;
LAB_005b7b1c:
  if ((*(char *)((int)piVar5 + 0xb) != '\0') && (*piVar5 != 0)) {
    func_0x00106b60(0x6ca300,0,0x300);
    func_0x001069a8(0x6ca300,*piVar5,*(undefined1 *)((int)piVar5 + 0xb));
    *(undefined1 *)(*(byte *)((int)piVar5 + 0xb) + 0x6ca301) = 0;
    if (param_1 == 0.0) {
      FUN_005af2e0((int)(*(float *)(&DAT_00638f60 + uRam006ca878 * 4) * 20.0));
    }
    else {
      FUN_005af2e0(iVar6);
    }
    FUN_005af1e0((int)fRam006ca860,(int)fRam006ca864,(int)fRam006ca868,0x6ca300);
    bVar1 = FUN_005b7f70(0x6ca300,*(undefined1 *)((int)piVar5 + 0xb));
    fRam006ca860 = fRam006ca860 +
                   (float)bVar1 * ((*(float *)(&DAT_00638f60 + uRam006ca878 * 4) * 20.0) / 2.0);
  }
  piVar5 = piVar5 + 3;
  iVar4 = iVar4 + 1;
  goto LAB_005b7c9c;
}



================================================================