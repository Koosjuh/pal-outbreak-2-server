FUNCTION FUN_000035c8 @ 0x000035c8 size=232
CALLERS (1): FUN_0000325c@0x0000325c
CALLEES (2): FUN_00010b4c@0x00010b4c, FUN_00010c38@0x00010c38

undefined4 FUN_000035c8(short param_1,short param_2)

{
  int iVar1;
  int *piVar2;
  
  if (DAT_00012efc != 0) {
    FUN_00010c38("ave-ppp %s:","pp_delRecvType");
    FUN_00010c38("called (ifNum=0x%x).\n",(int)param_1);
  }
  iVar1 = 0;
  piVar2 = DAT_000132d4;
  if (DAT_000132d4[0x10] != 0) {
    do {
      if ((*piVar2 != 0) && ((short)piVar2[1] == param_2)) break;
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 4;
    } while (iVar1 < 4);
    if (iVar1 < 4) {
      FUN_00010b4c(piVar2,0,0x10);
      DAT_000132d4[0x10] = DAT_000132d4[0x10] + -1;
      return 0;
    }
  }
  return 0xffffffff;
}


================================================================