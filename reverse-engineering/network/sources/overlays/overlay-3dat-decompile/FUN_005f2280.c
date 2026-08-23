FUNCTION FUN_005f2280 @ 0x005f2280  size=312
CALLERS (1): FUN_005ebd20@0x005ebd20
CALLEES (2): FUN_005d9ac0@0x005d9ac0, FUN_005efae0@0x005efae0
----------------------------------------------------------------

void FUN_005f2280(int *param_1)

{
  char cVar1;
  short sVar2;
  int *piVar3;
  short sVar4;
  undefined8 uVar5;
  int iVar6;
  
  if ((*(char *)(iRam007012a0 + 0x186) == '\0') && (*(char *)(iRam007012a0 + 0xe96b) == '\0')) {
    if (((short)param_1[7] == 0) || (*(short *)((int)param_1 + 0x1e) == 0)) {
      FUN_005efae0();
    }
    else {
      piVar3 = (int *)*param_1;
      if ((piVar3 != (int *)0x0) && (*piVar3 != 0)) {
        cVar1 = *(char *)(*piVar3 + 0x45);
        if ((char)param_1[0x12] == '\0') {
          sVar4 = (short)param_1[0xc] +
                  *(short *)((int)param_1 + 0x2a) + *(short *)((int)param_1 + 0x1e);
        }
        else {
          sVar4 = (short)param_1[0xc] + *(short *)((int)param_1 + 0x2a) + (short)param_1[0x10];
        }
        iVar6 = param_1[0x15];
        if (iVar6 < 0) {
          iVar6 = piVar3[0x15];
        }
        uVar5 = FUN_005efae0();
        sVar2 = (short)param_1[0xc];
        FUN_005d9ac0((short)param_1[10] - sVar2,*(short *)((int)param_1 + 0x2a) - sVar2,
                     sVar2 + (short)param_1[10] + (short)param_1[7],sVar4,
                     *(undefined1 *)((int)param_1 + 0x1a),iVar6,cVar1 != '\0',uVar5);
      }
    }
  }
  return;
}



================================================================