FUNCTION FUN_006278e0 @ 0x006278e0  size=320
CALLERS (3): FUN_006296a0@0x006296a0, FUN_00604180@0x00604180, FUN_00628210@0x00628210
CALLEES (2): FUN_00604860@0x00604860, FUN_00627860@0x00627860
----------------------------------------------------------------

void FUN_006278e0(int param_1)

{
  long lVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar2 = 0;
  do {
    iVar2 = (iVar2 + iVar4) * 4;
    iVar3 = iVar2 + 0x715500;
    if (*(char *)(iVar2 + 0x715510) != '\0') {
      iVar2 = FUN_00604860(param_1,0x32,iVar3);
      if (iVar2 == -1) {
        func_0x00106b60(iVar3,0,0x14);
      }
      else if (iVar4 != iVar2) {
        func_0x001069a8(iVar2 * 0x14 + 0x715500,iVar3,0x14);
        func_0x00106b60(iVar3,0,0x14);
      }
    }
    iVar4 = iVar4 + 1;
    iVar2 = iVar4 * 4;
  } while (iVar4 < 0x32);
  iVar2 = 0;
  do {
    if ((*(char *)(param_1 + 0x10) != '\0') &&
       (lVar1 = FUN_00627860(0x715500,param_1 + 0x10), lVar1 == -1)) {
      iVar4 = iVar2 * 0x14;
      if (*(char *)(iVar4 + 0x715510) == '\0') {
        *(undefined1 *)(iVar4 + 0x715510) = 1;
        *(undefined1 *)(iVar4 + 0x715511) = 0;
        *(undefined2 *)(iVar4 + 0x715512) = 0;
        func_0x001069a8(iVar4 + 0x715500,param_1 + 0x10,0x10);
      }
    }
    iVar2 = iVar2 + 1;
    param_1 = param_1 + 0x38;
  } while (iVar2 < 0x32);
  return;
}



================================================================