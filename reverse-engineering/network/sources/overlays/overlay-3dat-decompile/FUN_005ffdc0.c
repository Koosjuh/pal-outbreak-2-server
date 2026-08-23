FUNCTION FUN_005ffdc0 @ 0x005ffdc0  size=792
CALLERS (1): FUN_005ff950@0x005ff950
CALLEES (3): FUN_005b6900@0x005b6900, FUN_005c4d20@0x005c4d20, FUN_005b68e0@0x005b68e0
----------------------------------------------------------------

void FUN_005ffdc0(int param_1)

{
  int iVar1;
  long lVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  
  switch(*(char *)(param_1 + 0x12)) {
  case '\0':
    iVar3 = 0;
    pcVar4 = (char *)(iRam003435d4 + 0xc942c);
    while( true ) {
      if (3 < iVar3) {
        return;
      }
      if ((*pcVar4 == '\x01') && (pcVar4[4] != '\0')) break;
      iVar3 = iVar3 + 1;
      pcVar4 = pcVar4 + 0x830;
    }
    *(char *)(param_1 + 0x12) = *(char *)(param_1 + 0x12) + '\x01';
    break;
  case '\x01':
    *(char *)(param_1 + 0x12) = *(char *)(param_1 + 0x12) + '\x01';
  case '\x02':
    pcVar4 = (char *)(iRam003435d4 + 0xc942c);
    *(undefined1 *)(param_1 + 0x4a3) = 0xff;
    for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {
      lVar2 = func_0x00109d70(pcVar4 + 4,param_1 + 0x1e3c);
      if ((lVar2 != 0) && (pcVar4[4] != '\0')) {
        if (*pcVar4 == '\x01') {
          *(char *)(param_1 + 0x4a3) = (char)iVar3;
          *(char *)(param_1 + 0x12) = *(char *)(param_1 + 0x12) + '\x01';
          *pcVar4 = '\x02';
          pcVar4[0x24] = '\0';
          pcVar4[0x25] = '\0';
          pcVar4[0x26] = '\0';
          pcVar4[0x27] = '\0';
          pcVar4[0x2c] = ' ';
          pcVar4[0x2d] = '\0';
          pcVar4[0x2e] = '\0';
          pcVar4[0x2f] = '\0';
          break;
        }
        if (*pcVar4 == '\x02') {
          *(char *)(param_1 + 0x4a3) = (char)iVar3;
          *(char *)(param_1 + 0x12) = *(char *)(param_1 + 0x12) + '\x01';
          *pcVar4 = '\x02';
          pcVar4[0x2c] = ' ';
          pcVar4[0x2d] = '\0';
          pcVar4[0x2e] = '\0';
          pcVar4[0x2f] = '\0';
          break;
        }
      }
      pcVar4 = pcVar4 + 0x830;
    }
    if (*(char *)(param_1 + 0x4a3) < '\0') {
      *(undefined1 *)(param_1 + 0x12) = 0;
    }
    break;
  case '\x03':
    iVar3 = 0;
    iVar5 = iRam003435d4 + 0xc942c;
    while ((iVar3 < 4 && (lVar2 = func_0x00109d70(iVar5 + 4,param_1 + 0x1e3c), lVar2 != 0))) {
      iVar3 = iVar3 + 1;
      iVar5 = iVar5 + 0x830;
    }
    pcVar4 = (char *)(iRam003435d4 + 0xc942c +
                     (*(char *)(param_1 + 0x4a3) * 0x82 + (int)*(char *)(param_1 + 0x4a3)) * 0x10);
    if (*pcVar4 == '\x02') {
      FUN_005b68e0();
      iVar1 = iRam003435d4;
      *(undefined4 *)(iRam003435d4 + 0x8000) = 1;
      iVar3 = *(int *)(pcVar4 + 0x24);
      *(int *)(pcVar4 + 0x24) = iVar3 + 0x20;
      if (*(int *)(pcVar4 + 0x24) < 0x800) {
        *(undefined4 *)(iVar1 + 0x8004) = 1;
        *(undefined1 *)(param_1 + 0x12) = 4;
      }
      else {
        *(undefined4 *)(iVar1 + 0x8004) = 0;
        *(undefined1 *)(param_1 + 0x12) = 10;
      }
      *(undefined4 *)(iVar1 + 0x8008) = 0x20;
      func_0x001069a8(iVar1 + 0x800c,iVar5 + 0x30 + iVar3);
      FUN_005c4d20(pcVar4 + 0x14,iRam003435d4 + 0x8000,0x2c,0x6001d0);
    }
    else {
      *(undefined1 *)(param_1 + 0x12) = 2;
    }
    break;
  case '\x04':
  case '\n':
    FUN_005b6900();
    break;
  case '\x05':
    *(undefined1 *)(param_1 + 0x12) = 2;
    break;
  case '\v':
    *(undefined1 *)(param_1 + 0x12) = 2;
    *(undefined1 *)
     (iRam003435d4 + 0xc942c +
     (*(char *)(param_1 + 0x4a3) * 0x82 + (int)*(char *)(param_1 + 0x4a3)) * 0x10) = 4;
  }
  return;
}



================================================================