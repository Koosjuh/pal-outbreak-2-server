FUNCTION FUN_00002d38 @ 0x00002d38 size=524
CALLERS (0): 
CALLEES (15): FUN_00003d40@0x00003d40, FUN_000026c4@0x000026c4, FUN_000000c4@0x000000c4, FUN_00002c3c@0x00002c3c, FUN_00003c9c@0x00003c9c, FUN_00003e44@0x00003e44, FUN_00000148@0x00000148, FUN_00000104@0x00000104, FUN_00003c84@0x00003c84, FUN_00003cbc@0x00003cbc, FUN_00003cac@0x00003cac, FUN_00003cf0@0x00003cf0, FUN_00002428@0x00002428, FUN_00003c94@0x00003c94, FUN_00003e3c@0x00003e3c

undefined4 FUN_00002d38(undefined *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  undefined1 auStack_70 [16];
  undefined1 auStack_60 [72];
  undefined1 auStack_18 [8];
  
  FUN_00000104();
  if (param_1 == (undefined *)0x0) {
    PTR_DAT_000045e0 = (undefined *)&DAT_00004758;
    DAT_00004770 = 0;
    FUN_00000148();
    uVar2 = 0;
  }
  else {
    PTR_DAT_000045e0 = param_1;
    iVar3 = FUN_00003cf0(param_1);
    if (iVar3 == 0) {
      FUN_00002428();
      piVar5 = *(int **)(PTR_DAT_000045e0 + 0x18);
      piVar1 = DAT_000046ec;
      if (piVar5 != (int *)0x0) {
        for (piVar4 = (int *)*piVar5; piVar1 = DAT_000046ec, piVar4 != (int *)0x0;
            piVar4 = (int *)*piVar4) {
          if (piVar4[9] != 0) {
            *(undefined4 *)(piVar4[9] + 8) = 0;
          }
        }
      }
      for (; piVar4 = DAT_000046ec, piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
        if (piVar1[7] != 0) {
          FUN_000000c4();
          piVar1[7] = 0;
        }
      }
      for (; piVar4 != (int *)0x0; piVar4 = (int *)*piVar4) {
        if ((piVar4[3] & 0x200U) != 0) {
          FUN_00002c3c(piVar5,piVar4[2]);
        }
      }
      while (iVar3 = FUN_00003c9c(auStack_70,1), iVar3 == 1) {
        FUN_00003cac(auStack_70);
      }
      while (iVar3 = FUN_00003c84(auStack_60,1), iVar3 == 1) {
        FUN_00003c94(auStack_60);
      }
      FUN_000026c4();
      FUN_00003e3c(DAT_000046e8,0);
      FUN_00000148();
      iVar3 = FUN_00003cbc();
      FUN_00003e44(DAT_000046e8,1,0x11,auStack_18);
      uVar2 = 0;
      if (iVar3 != 0) {
        uVar2 = 0xffffffff;
      }
    }
    else {
      FUN_00003d40("inetctl: sceNetCnfMergeConf -> %d\n",iVar3);
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}


================================================================