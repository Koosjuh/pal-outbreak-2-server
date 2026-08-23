FUNCTION FUN_005cce30 @ 0x005cce30  size=920
CALLERS (9): FUN_005ca480@0x005ca480, FUN_005ca0a0@0x005ca0a0, FUN_005ca1a0@0x005ca1a0, FUN_005ca320@0x005ca320, FUN_005ca380@0x005ca380, FUN_005ca5c0@0x005ca5c0, FUN_005ca4f0@0x005ca4f0, FUN_005ca420@0x005ca420, FUN_005ca290@0x005ca290
CALLEES (2): FUN_005d8340@0x005d8340, FUN_005dedf0@0x005dedf0
----------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x005cd020) */

undefined4 FUN_005cce30(void)

{
  char *pcVar1;
  char cVar2;
  char cVar3;
  int *piVar4;
  undefined4 uVar5;
  long lVar6;
  ushort *puVar7;
  int iVar8;
  uint uVar9;
  undefined1 auStack_4 [4];
  
  cVar2 = '\0';
  for (uVar9 = 0; uVar9 < 500; uVar9 = uVar9 + 1 & 0xffff) {
    iVar8 = uVar9 * 4;
    pcVar1 = *(char **)(iRam00701068 + iVar8 + 0x5ffc0);
    if ((pcVar1 == (char *)0x0) || (*pcVar1 == '\0')) break;
    if ((pcVar1[2] == '\r') && (cVar2 = cVar2 + '\x01', pcVar1[5] == '\x01')) {
      FUN_005dedf0(auStack_4,*(undefined4 *)(pcVar1 + 100));
      lVar6 = FUN_005d8340(auStack_4);
      if (lVar6 != 0) {
        piVar4 = (int *)lVar6;
        if (*piVar4 == 0) {
          *(undefined1 *)(*(int *)(iRam00701068 + iVar8 + 0x5ffc0) + 5) = 3;
        }
        else {
          *(undefined1 *)(*(int *)(iRam00701068 + iVar8 + 0x5ffc0) + 5) = 2;
          *(undefined1 *)(*(int *)(iRam00701068 + iVar8 + 0x5ffc0) + 0x5f) =
               *(undefined1 *)(iRam00701068 + 0x60dcf);
          *(undefined4 *)(iRam00701068 + (uint)*(byte *)(iRam00701068 + 0x60dcf) * 4 + 0x68dd8) =
               *(undefined4 *)*piVar4;
          *(undefined2 *)(iRam00701068 + (uint)*(byte *)(iRam00701068 + 0x60dcf) * 2 + 0x68e28) =
               *(undefined2 *)((int)piVar4 + 6);
          *(short *)(iRam00701068 + (uint)*(byte *)(iRam00701068 + 0x60dcf) * 2 + 0x68e50) =
               (short)piVar4[2];
          iVar8 = *(int *)(iRam00701068 + iVar8 + 0x5ffc0);
          if ((*(char *)(iVar8 + 4) == '\x10') &&
             (puVar7 = (ushort *)
                       (iRam00701068 + (uint)*(byte *)(iRam00701068 + 0x60dcf) * 2 + 0x68e50),
             *(float *)(iVar8 + 0x44) == (float)*puVar7)) {
            *puVar7 = *puVar7 + 1;
          }
          *(char *)(iRam00701068 + 0x60dcf) = *(char *)(iRam00701068 + 0x60dcf) + '\x01';
        }
      }
    }
  }
  if (cVar2 == '\0') {
    uVar5 = 1;
    *(undefined1 *)(iRam00701070 + 0x2e) = 10;
  }
  else {
    cVar3 = '\0';
    uVar9 = 0;
    while (((uVar9 < 500 &&
            (pcVar1 = *(char **)(iRam00701068 + uVar9 * 4 + 0x5ffc0), pcVar1 != (char *)0x0)) &&
           (*pcVar1 != '\0'))) {
      if (pcVar1[2] == '\r') {
        if (pcVar1[5] != '\x02') {
          if (pcVar1[5] != '\x03') goto LAB_005cd188;
          cVar3 = cVar3 + '\x01';
        }
        cVar2 = cVar2 + -1;
        if (cVar2 == '\0') {
          if (((*(char *)(iRam00701070 + 0x36) != '\0') && (cVar3 != '\0')) &&
             (*(char *)(iRam00701068 + 0x60dce) != '\0')) {
            *(char *)(iRam00701068 + 0x60dce) = '\0';
            return 0xffffffff;
          }
          *(undefined1 *)(iRam00701070 + 0x2e) = 10;
          return 1;
        }
      }
LAB_005cd188:
      uVar9 = uVar9 + 1 & 0xffff;
    }
    uVar5 = 0;
    *(undefined1 *)(iRam00701070 + 0x2e) = 8;
  }
  return uVar5;
}



================================================================