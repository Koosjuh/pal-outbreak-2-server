FUNCTION FUN_00603f30 @ 0x00603f30  size=588
CALLERS (1): FUN_00603e40@0x00603e40
CALLEES (5): FUN_00604770@0x00604770, FUN_006048f0@0x006048f0, FUN_00604860@0x00604860, FUN_00618b60@0x00618b60, FUN_00604af0@0x00604af0
----------------------------------------------------------------

void FUN_00603f30(undefined8 param_1)

{
  int iVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  FUN_00618b60();
  iVar5 = (int)param_1;
  func_0x00106b60(iVar5 + 0x900,0,0x20);
  func_0x00106b60(0x70b470,0,0x32);
  func_0x00106b60(0x70b4b0,0,0xaf0);
  iVar4 = 0;
  iVar3 = iRam003435d4 + 0xc8000;
  *(undefined1 *)(iVar5 + 0x905) = 0;
  iVar1 = 0;
  do {
    iVar1 = iVar3 + iVar1 + iVar4;
    if ((*(char *)(iVar1 + 800) != '\0') && (lVar2 = FUN_00604770(iVar1 + 800), lVar2 != 0)) {
      func_0x00109eb8(*(char *)(iVar5 + 0x905) * 0x38 + 0x70b4b0,iVar3 + iVar4 * 0x10);
      func_0x0010a4f0(*(char *)(iVar5 + 0x905) * 0x38 + 0x70b4c0,iVar1 + 800,0x10);
      lVar2 = FUN_00604860(0x694700,0x32,iVar1 + 800);
      if (lVar2 == -1) {
        *(undefined4 *)(*(char *)(iVar5 + 0x905) * 0x38 + 0x70b4d0) = 0;
      }
      else {
        lVar2 = func_0x0010a338((int)lVar2 * 0x38 + 0x694710,iVar1 + 800,0x10);
        if (lVar2 == 0) {
          *(undefined4 *)(*(char *)(iVar5 + 0x905) * 0x38 + 0x70b4d0) = 2;
        }
        else {
          *(undefined4 *)(*(char *)(iVar5 + 0x905) * 0x38 + 0x70b4d0) = 3;
        }
      }
      *(undefined1 *)(*(char *)(iVar5 + 0x905) + 0x70b470) = *(undefined1 *)(iVar3 + iVar4 + 0x1364)
      ;
      *(char *)(iVar5 + 0x905) = *(char *)(iVar5 + 0x905) + '\x01';
    }
    iVar4 = iVar4 + 1;
    iVar1 = iVar4 * 0x10;
  } while (iVar4 < 0x32);
  lVar2 = FUN_006048f0(0x694700,0x32);
  if (lVar2 == -1) {
    *(undefined2 *)(iVar5 + 0x914) = 0;
  }
  else {
    *(short *)(iVar5 + 0x914) = 0x32 - (short)lVar2;
  }
  FUN_00604af0(param_1);
  return;
}



================================================================