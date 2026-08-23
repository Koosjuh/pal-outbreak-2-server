FUNCTION FUN_005d5f40 @ 0x005d5f40  size=348
CALLERS (1): FUN_005cf010@0x005cf010
CALLEES (1): FUN_0061e720@0x0061e720
----------------------------------------------------------------

void FUN_005d5f40(byte param_1)

{
  char cVar1;
  char cVar2;
  ushort uVar3;
  char *pcVar4;
  
  pcVar4 = (char *)(iRam00701078 + 2);
  uVar3 = *(ushort *)(iRam00701068 + 0x4f8a4);
  cVar1 = *(char *)(iRam00701078 + 2);
  if (((((uVar3 & 4) == 0) && ((uVar3 & 1) == 0)) &&
      ((*(char *)(iRam00701068 + 0x4f8a8) == '\0' ||
       ((*(byte *)(iRam00701068 + 0x4f8a9) < 8 || (0xf < *(byte *)(iRam00701068 + 0x4f8a9))))))) &&
     ((cVar2 = *(char *)(iRam00715da8 + 0x49c), cVar2 != 'P' && (cVar2 != 'R')))) {
    if (((((uVar3 & 8) != 0) || ((uVar3 & 2) != 0)) ||
        (((*(char *)(iRam00701068 + 0x4f8a8) != '\0' &&
          ((*(byte *)(iRam00701068 + 0x4f8a9) != 0 && (*(byte *)(iRam00701068 + 0x4f8a9) < 8)))) ||
         (cVar2 == 'O')))) || (cVar2 == 'Q')) {
      *pcVar4 = *pcVar4 + '\x01';
    }
  }
  else {
    *pcVar4 = *pcVar4 + -1;
  }
  if (*(byte *)(iRam00701078 + 2) == 0) {
    *(byte *)(iRam00701078 + 2) = 1;
  }
  else if (param_1 < *(byte *)(iRam00701078 + 2)) {
    *(byte *)(iRam00701078 + 2) = param_1;
  }
  if (cVar1 != *(char *)(iRam00701078 + 2)) {
    FUN_0061e720();
  }
  return;
}



================================================================