FUNCTION FUN_005e6d50 @ 0x005e6d50  size=792
CALLERS (1): FUN_005e7a30@0x005e7a30
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_005e6d50(undefined8 param_1,undefined4 *param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined1 auStack_10 [16];
  
  piVar3 = (int *)param_1;
  if (*piRam007012a0 != 1) {
    if (*piRam007012a0 != 0) {
      puVar5 = (undefined4 *)*param_2;
      for (iVar2 = 0; (iVar4 = 0, iVar2 < 0xd && (*(byte *)(*piVar3 + iVar2) != 0));
          iVar2 = iVar2 + 1) {
        auStack_10[iVar2] = (&DAT_00648090)[*(byte *)(*piVar3 + iVar2)];
      }
      iVar2 = param_2[1];
      while( true ) {
        if (iVar2 <= iVar4) {
          return 1;
        }
        lVar1 = func_0x0010a338(auStack_10,*puVar5,puVar5[1] + -1);
        if (lVar1 == 0) break;
        iVar4 = iVar4 + 1;
        puVar5 = puVar5 + 4;
        iVar2 = param_2[1];
      }
      if (puVar5[2] == 0) {
        piRam007012a0[3] = 1;
      }
      else {
        piRam007012a0[2] = puVar5[2];
      }
      *piVar3 = *piVar3 + puVar5[1] + -1;
      lVar1 = (*(code *)puVar5[3])(param_1,param_3);
      if (lVar1 < 0) {
        return 0xffffffff;
      }
      if (piRam007012a0[2] == 2) {
        *piRam007012a0 = 0;
        return 0;
      }
      return 0;
    }
    if ((*(char *)*piVar3 != '<') && (*(char *)*piVar3 != '&')) {
      return 1;
    }
    *piRam007012a0 = 1;
  }
  puVar5 = (undefined4 *)*param_2;
  for (iVar2 = 0; (iVar4 = 0, iVar2 < 0xd && (*(byte *)(*piVar3 + iVar2) != 0)); iVar2 = iVar2 + 1)
  {
    auStack_10[iVar2] = (&DAT_00648090)[*(byte *)(*piVar3 + iVar2)];
  }
  iVar2 = param_2[1];
  while( true ) {
    if (iVar2 <= iVar4) {
      *piRam007012a0 = 0;
      if ((iVar4 == param_2[1]) && (*(char *)*piVar3 != '&')) {
        lVar1 = func_0x0010a700((char *)*piVar3,0x6470c0);
        if (lVar1 == 0) {
          return 0xffffffff;
        }
        *piVar3 = (int)lVar1 + 1;
        return 0;
      }
      return 1;
    }
    lVar1 = func_0x0010a338(auStack_10,*puVar5,puVar5[1] + -1);
    if (lVar1 == 0) break;
    iVar4 = iVar4 + 1;
    puVar5 = puVar5 + 4;
    iVar2 = param_2[1];
  }
  *(short *)(piRam007012a0 + 0x365a) = (short)piRam007012a0[0x365a] + 1;
  if (puVar5[2] == 0) {
    piRam007012a0[3] = 1;
  }
  else {
    piRam007012a0[2] = puVar5[2];
  }
  *piVar3 = *piVar3 + puVar5[1] + -1;
  lVar1 = (*(code *)puVar5[3])(param_1,param_3);
  if (-1 < lVar1) {
    if ((piRam007012a0[2] == 2) || (piRam007012a0[2] == 0x12)) {
      *piRam007012a0 = 0;
    }
    else {
      *piRam007012a0 = 2;
    }
    return 0;
  }
  return 0xffffffff;
}



================================================================