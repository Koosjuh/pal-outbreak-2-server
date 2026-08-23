FUNCTION FUN_000034d0 @ 0x000034d0 size=248
CALLERS (1): FUN_00003194@0x00003194
CALLEES (1): FUN_00010c38@0x00010c38

undefined4 FUN_000034d0(short param_1,short param_2,int param_3,int param_4)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  
  if (DAT_00012efc != 0) {
    FUN_00010c38("ave-ppp %s:","pp_addRecvType");
    FUN_00010c38("called (ifNum=0x%x).\n",(int)param_1);
  }
  piVar1 = DAT_000132d4;
  iVar3 = 0;
  piVar4 = DAT_000132d4;
  do {
    if (*piVar4 == 0) break;
    iVar3 = iVar3 + 1;
    if ((short)piVar4[1] == param_2) {
      return 0xffffffff;
    }
    piVar4 = piVar4 + 4;
  } while (iVar3 < 4);
  uVar2 = 0xffffffff;
  if (iVar3 < 4) {
    *(short *)(piVar4 + 1) = param_2;
    piVar4[2] = param_3;
    piVar4[3] = param_4;
    *piVar4 = *piVar4 + 1;
    uVar2 = 0;
    piVar1[0x10] = piVar1[0x10] + 1;
  }
  return uVar2;
}


================================================================