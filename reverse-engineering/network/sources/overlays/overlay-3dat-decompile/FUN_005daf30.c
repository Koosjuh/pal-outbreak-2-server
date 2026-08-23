FUNCTION FUN_005daf30 @ 0x005daf30  size=492
CALLERS (0): 
CALLEES (5): FUN_005e3a80@0x005e3a80, FUN_005e0440@0x005e0440, FUN_005e2fa0@0x005e2fa0, FUN_005dfee0@0x005dfee0, FUN_005e2760@0x005e2760
----------------------------------------------------------------

void FUN_005daf30(int param_1)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  float fVar5;
  float fVar6;
  
  cVar1 = *(char *)(param_1 + 6);
  if (cVar1 == 'c') {
    FUN_005dfee0();
    *(char *)(iRam00701068 + 0x60dc4) = *(char *)(iRam00701068 + 0x60dc4) + '\x01';
  }
  else if (((cVar1 == '\x01') || (cVar1 != '\0')) && (*(char *)(iRam00701070 + 0x34) == '\0')) {
    uVar4 = 499;
    do {
      pcVar2 = *(char **)(iRam00701068 + uVar4 * 4 + 0x5ffc0);
      if ((pcVar2 != (char *)0x0) && (*pcVar2 != '\0')) {
        FUN_005e2760();
      }
      uVar4 = uVar4 - 1 & 0xffff;
    } while (uVar4 != 0);
    for (uVar4 = 1; uVar4 < 500; uVar4 = uVar4 + 1 & 0xffff) {
      pcVar2 = *(char **)(iRam00701068 + uVar4 * 4 + 0x5ffc0);
      if ((pcVar2 == (char *)0x0) || (*pcVar2 == '\0')) break;
      FUN_005e2fa0();
      if (*(uint *)(iRam00701078 + 0x20) == uVar4) {
        iVar3 = *(int *)(iRam00701068 + uVar4 * 4 + 0x5ffc0);
        fVar5 = *(float *)(iVar3 + 0x34) - (float)*(int *)(iRam00701070 + 4);
        fVar6 = *(float *)(iVar3 + 0x38) - (float)*(int *)(iRam00701070 + 8);
        FUN_005e0440(fVar5 + 1.0,fVar6 + 1.0,*(float *)(iVar3 + 0x40) + (fVar5 - 2.0),
                     *(float *)(iVar3 + 0x44) + (fVar6 - 1.0),0x400000ff);
      }
    }
    FUN_005e3a80(*(undefined4 *)(iRam00701078 + 0x20));
    func_0x001af030();
  }
  return;
}



================================================================