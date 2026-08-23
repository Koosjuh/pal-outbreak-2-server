FUNCTION FUN_005fa700 @ 0x005fa700  size=276
CALLERS (1): FUN_005fa490@0x005fa490
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_005fa700(int param_1)

{
  bool bVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  
  lVar3 = 0;
  iVar2 = 0;
  do {
    bVar1 = false;
    iVar4 = 0;
    iVar2 = param_1 + iVar2;
    iVar5 = 0;
    do {
      iVar5 = param_1 + (iVar5 * 4 + iVar4 * -5) * 0x10;
      if (*(char *)(iVar5 + 0x309c) == '\0') goto LAB_005fa7e0;
      if (*(char *)(iVar2 + 0x1a) == '\0') {
        if (*(short *)(iVar5 + 0x318a) == 0) {
          if (*(ushort *)(iVar5 + 0x3188) == (ushort)*(byte *)(iVar2 + 0x1c)) goto LAB_005fa7d8;
        }
        else if ((*(char *)(iVar2 + 0x1c) == '\x06') && (*(short *)(iVar5 + 0x3188) == 0x5b)) {
LAB_005fa7d8:
          bVar1 = true;
        }
      }
      else if (*(short *)(iVar5 + 0x318a) == 0) {
        if ((*(short *)(iVar5 + 0x3188) == 6) && (*(char *)(iVar2 + 0x1c) == '['))
        goto LAB_005fa7d8;
      }
      else if (*(ushort *)(iVar5 + 0x3188) == (ushort)*(byte *)(iVar2 + 0x1c)) goto LAB_005fa7d8;
LAB_005fa7e0:
      iVar4 = iVar4 + 1;
      iVar5 = iVar4 * 0x10;
    } while (iVar4 < 4);
    if (!bVar1) {
      return 0;
    }
    iVar2 = (int)lVar3 + 1;
    lVar3 = (long)iVar2;
    iVar2 = iVar2 * 4;
    if (*(short *)(param_1 + 10) <= lVar3) {
      return 1;
    }
  } while( true );
}



================================================================