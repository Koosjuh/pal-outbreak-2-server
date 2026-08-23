FUNCTION FUN_005fa890 @ 0x005fa890  size=244
CALLERS (1): FUN_005fa990@0x005fa990
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_005fa890(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar1 = param_1 + param_2 * 4;
  do {
    while( true ) {
      if (3 < iVar2) {
        return 0;
      }
      iVar3 = param_1 + iVar2 * 0x3b0;
      if (*(char *)(iVar3 + 0x309c) != '\0') break;
LAB_005fa968:
      iVar2 = iVar2 + 1;
    }
    if (*(char *)(iVar1 + 0x1a) != '\0') {
      if (*(short *)(iVar3 + 0x318a) == 0) {
        if ((*(short *)(iVar3 + 0x3188) == 6) && (*(char *)(iVar1 + 0x1c) == '[')) {
          return 1;
        }
      }
      else if (*(ushort *)(iVar3 + 0x3188) == (ushort)*(byte *)(iVar1 + 0x1c)) {
        return 1;
      }
      goto LAB_005fa968;
    }
    if (*(short *)(iVar3 + 0x318a) == 0) {
      if (*(ushort *)(iVar3 + 0x3188) == (ushort)*(byte *)(iVar1 + 0x1c)) {
        return 1;
      }
      goto LAB_005fa968;
    }
    if (*(char *)(iVar1 + 0x1c) != '\x06') goto LAB_005fa968;
    if (*(short *)(iVar3 + 0x3188) == 0x5b) {
      return 1;
    }
    iVar2 = iVar2 + 1;
  } while( true );
}



================================================================