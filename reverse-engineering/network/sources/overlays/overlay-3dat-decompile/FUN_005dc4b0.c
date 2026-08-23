FUNCTION FUN_005dc4b0 @ 0x005dc4b0  size=1452
CALLERS (0): 
CALLEES (2): FUN_005dfee0@0x005dfee0, FUN_005dc2b0@0x005dc2b0
----------------------------------------------------------------

void FUN_005dc4b0(int param_1)

{
  char cVar1;
  byte bVar2;
  byte *pbVar3;
  ushort uVar4;
  long lVar5;
  int iVar6;
  uint uVar7;
  ulong uVar8;
  
  cVar1 = *(char *)(param_1 + 6);
  if (cVar1 == 'c') {
    FUN_005dfee0();
    *(char *)(iRam00701068 + 0x60dc4) = *(char *)(iRam00701068 + 0x60dc4) + '\x01';
    return;
  }
  if ((cVar1 != '\x01') && (cVar1 == '\0')) {
    return;
  }
  func_0x001af020(1);
  lVar5 = FUN_005dc2b0();
  func_0x001af040();
  if (lVar5 == 0) {
    return;
  }
  if (*(char *)(iRam00701068 + 0x68e89) == -1) {
    *(undefined4 *)(iRam00701078 + 0x20) = 0;
    *(undefined1 *)(iRam00701078 + 1) = 0;
    *(undefined1 *)(iRam00701068 + 0x68e84) = 2;
    *(undefined1 *)(iRam00701068 + 0x68e86) = 1;
    *(undefined1 *)(iRam00701068 + 0x68e83) = 0;
    *(undefined1 *)(iRam00701070 + 0x2e) = 8;
    return;
  }
  bVar2 = *(byte *)(*(int *)(*(int *)(iRam00701078 + 0x20) * 4 + iRam00701068 + 0x5ffc0) + 5);
  uVar4 = func_0x0010a050(iRam00701068 + 0x68e89);
  if ((short)(ushort)*(byte *)(*(int *)(*(int *)(iRam00701078 + 0x20) * 4 + iRam00701068 + 0x5ffc0)
                              + 5) < (short)uVar4) {
    uVar4 = (ushort)bVar2;
  }
  for (uVar8 = 0; (long)uVar8 < (long)(short)uVar4; uVar8 = (long)((int)uVar8 + 1) & 0xffff) {
    **(undefined1 **)(*(int *)(iRam00701068 + *(int *)(iRam00701078 + 0x20) * 4 + 0x5ffc0) + 100) =
         *(undefined1 *)(iRam00701068 + (int)uVar8 + 0x68e89);
    iVar6 = *(int *)(iRam00701068 + *(int *)(iRam00701078 + 0x20) * 4 + 0x5ffc0);
    *(int *)(iVar6 + 100) = *(int *)(iVar6 + 100) + 1;
  }
  **(undefined1 **)(*(int *)(*(int *)(iRam00701078 + 0x20) * 4 + iRam00701068 + 0x5ffc0) + 100) = 0;
  iVar6 = *(int *)(*(int *)(iRam00701078 + 0x20) * 4 + iRam00701068 + 0x5ffc0);
  *(int *)(iVar6 + 100) = *(int *)(iVar6 + 100) - (int)(short)uVar4;
  iVar6 = *(int *)(iRam00701068 + 0x5ffc0 + *(int *)(iRam00701078 + 0x20) * 4);
  if ((*(char *)(iVar6 + 0x5d) == '\x04') &&
     (pbVar3 = *(byte **)(iVar6 + 0x60), uVar7 = (pbVar3[1] - 0x30) + (*pbVar3 - 0x30) * 10,
     uVar7 < 9)) {
    iVar6 = (int)(short)uVar4;
    switch(uVar7) {
    case 0:
      func_0x001069a8(iRam00701088 + 0xcd,iRam00701068 + 0x68e89,iVar6 + 1);
      break;
    case 1:
      func_0x001069a8(iRam00701088,iRam00701068 + 0x68e89,iVar6 + 1);
      break;
    case 2:
      lVar5 = func_0x0010a050(iRam00701068 + 0x68e89);
      if (lVar5 != 0) {
        if (lVar5 == 2) {
          *(char *)(iRam00701088 + 0x14e) =
               *(char *)(iRam00701068 + 0x68e8a) + -0x30 +
               (*(char *)(iRam00701068 + 0x68e89) + -0x30) * '\n';
          if (*(char *)(iRam00701088 + 0x14e) == '\0') {
            **(undefined1 **)
              (*(int *)(*(int *)(iRam00701078 + 0x20) * 4 + iRam00701068 + 0x5ffc0) + 100) = 0;
          }
          break;
        }
        if (lVar5 == 1) {
          if (*(char *)(iRam00701068 + 0x68e89) == '0') {
            **(undefined1 **)
              (*(int *)(*(int *)(iRam00701078 + 0x20) * 4 + iRam00701068 + 0x5ffc0) + 100) = 0;
          }
          else {
            *(char *)(iRam00701088 + 0x14e) = *(char *)(iRam00701068 + 0x68e89) + -0x30;
          }
          break;
        }
      }
      *(undefined1 *)(iRam00701088 + 0x14e) = 0;
      break;
    case 3:
      func_0x001069a8(iRam00701088 + 0x41,iRam00701068 + 0x68e89,8);
      break;
    case 5:
      func_0x001069a8(iRam00701088 + 0x4c,iRam00701068 + 0x68e89,iVar6 + 1);
      break;
    case 7:
      func_0x001069a8(iRam00701088 + 0x14f,iRam00701068 + 0x68e89,iVar6 + 1);
      break;
    case 8:
      func_0x001069a8(iRam00701088 + 0xcd,iRam00701068 + 0x68e89,(short)uVar4 + 1);
    }
  }
  *(undefined4 *)(iRam00701078 + 0x20) = 0;
  *(undefined1 *)(iRam00701078 + 1) = 0;
  *(undefined1 *)(iRam00701068 + 0x68e86) = 1;
  *(undefined1 *)(iRam00701068 + 0x68e84) = 2;
  *(undefined1 *)(iRam00701070 + 0x2e) = 8;
  return;
}



================================================================