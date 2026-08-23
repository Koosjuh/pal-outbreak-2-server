
void FUN_001c0b20(void)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_20 [8];
  int iStack_18;
  int iStack_14;
  
  iVar2 = 0;
  iVar1 = 0;
  if (piRam0035c3d8 != (int *)0x0) {
    if ((iRam0035bcb8 == 0) || (iRam0035bcb0 == 0)) {
      if (*piRam0035c3d8 == 1) {
        if (cRam0035bec8 == '\x01') {
          FUN_001ef130(0x35bcc0,0x35a6c0);
          iVar1 = iRam0035a6c4;
          iVar2 = iRam0035a6c0;
        }
        else if ((cRam0035bec8 != '\0') && (cRam0035bec8 == '\x02')) {
          FUN_001ee930(auStack_20);
          iVar1 = iStack_14;
          iVar2 = iStack_18;
        }
      }
      else if (*piRam0035c3d8 == 2) {
        FUN_001ee930(auStack_20);
        iVar1 = iStack_14;
        iVar2 = iStack_18;
      }
    }
    if (iRam0035bcb8 != 0) {
      iVar2 = iRam0035bcb8;
    }
    if (iRam0035bcb0 != 0) {
      iVar1 = iRam0035bcb0;
    }
    FUN_001ee720(0x35bcc0,iVar2,iVar1);
    FUN_001c08a0();
    FUN_001f1e40();
  }
  return;
}

