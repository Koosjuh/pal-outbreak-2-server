FUNCTION FUN_005d46a0 @ 0x005d46a0  size=324
CALLERS (1): FUN_005d1e80@0x005d1e80
CALLEES (0): 
----------------------------------------------------------------

void FUN_005d46a0(int param_1)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  int in_t1_lo;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
LAB_005d470c:
  do {
    if (((499 < iVar5) ||
        (pcVar3 = *(char **)(iRam00701068 + iVar5 * 4 + 0x5ffc0), pcVar3 == (char *)0x0)) ||
       (*pcVar3 == '\0')) {
LAB_005d471c:
      in_t1_lo = in_t1_lo + 1;
      while( true ) {
        if (499 < in_t1_lo) {
          return;
        }
        pcVar3 = *(char **)(iRam00701068 + in_t1_lo * 4 + 0x5ffc0);
        if (pcVar3 == (char *)0x0) {
          return;
        }
        if (*pcVar3 == '\0') {
          return;
        }
        cVar1 = pcVar3[2];
        if (cVar1 == '\x13') break;
        if ((cVar1 == '\a') || (cVar1 == '\x06')) {
          pcVar2 = *(char **)(pcVar3 + 100);
          if (**(char **)(pcVar3 + 100) != '\0') {
            do {
              pcVar3 = pcVar2;
              pcVar2 = pcVar3 + -1;
            } while (pcVar3[-1] != '\0');
            *pcVar3 = '\0';
            *(char **)(*(int *)(iRam00701068 + in_t1_lo * 4 + 0x5ffc0) + 100) = pcVar3;
          }
          in_t1_lo = in_t1_lo + 1;
        }
        else {
          in_t1_lo = in_t1_lo + 1;
        }
      }
      return;
    }
    if (pcVar3[2] == '\x04') {
      iVar4 = in_t1_lo;
      if (iVar5 == param_1) goto LAB_005d471c;
    }
    else {
      iVar4 = iVar5;
      if (pcVar3[2] != '\x13') {
        iVar5 = iVar5 + 1;
        goto LAB_005d470c;
      }
    }
    iVar5 = iVar5 + 1;
    in_t1_lo = iVar4;
  } while( true );
}



================================================================