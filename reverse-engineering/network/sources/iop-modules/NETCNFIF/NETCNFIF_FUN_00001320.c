FUNCTION FUN_00001320 @ 0x00001320 size=764
CALLERS (2): FUN_0000161c@0x0000161c, FUN_000016c8@0x000016c8
CALLEES (3): FUN_00001280@0x00001280, FUN_00002774@0x00002774, FUN_00002910@0x00002910

int FUN_00001320(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  
  if (param_3 == 1) {
    *(undefined4 *)(param_1 + 0x1300) = *param_2;
    FUN_00001320[param_1] = *(code *)(param_2 + 4);
    if (param_2[5] != 0) {
      FUN_00002910(param_1 + 0x200);
    }
    if (param_2[7] != 0) {
      FUN_00002910(param_1 + 0x300);
    }
    if (param_2[8] != 0) {
      FUN_00002910(param_1 + 0x400);
    }
    piVar3 = (int *)param_2[0x54];
    DAT_00006160 = 0;
    iVar1 = 0;
    for (; piVar3 != (int *)0x0; piVar3 = (int *)*piVar3) {
      iVar1 = FUN_00001280(param_1,piVar3,&DAT_00006160);
      if (iVar1 < 0) {
        return iVar1;
      }
    }
    iVar4 = 0;
    puVar5 = param_2;
    do {
      if (puVar5[0xe] == 0) goto LAB_0000146c;
      if (iVar4 == 1) {
        iVar2 = param_1 + 0x900;
LAB_00001460:
        FUN_00002910(iVar2);
      }
      else if (iVar4 < 2) {
        iVar2 = param_1 + 0x800;
        if (iVar4 == 0) goto LAB_00001460;
      }
      else {
        iVar2 = param_1 + 0xa00;
        if (iVar4 == 2) goto LAB_00001460;
      }
LAB_0000146c:
      puVar5 = puVar5 + 1;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 10);
    if (param_2[0x1c] != 0) {
      FUN_00002910(param_1 + 0xb00);
    }
    if (param_2[0x1d] != 0) {
      FUN_00002910(param_1 + 0xc00);
    }
    if (param_2[0x1e] != 0) {
      FUN_00002910(param_1 + 0xd00);
    }
    *(undefined1 *)(param_1 + 0x1321) = *(undefined1 *)((int)param_2 + 0x97);
    *(undefined1 *)(param_1 + 0x1322) = *(undefined1 *)(param_2 + 0x26);
    *(undefined1 *)(param_1 + 0x1323) = *(undefined1 *)((int)param_2 + 0xf7);
    *(undefined1 *)(param_1 + 0x1324) = *(undefined1 *)(param_2 + 0x3d);
    *(undefined1 *)(param_1 + 0x1325) = *(undefined1 *)((int)param_2 + 0x12e);
    *(undefined1 *)(param_1 + 0x1326) = *(undefined1 *)((int)param_2 + 0x93);
    *(undefined1 *)(param_1 + 0x1327) = *(undefined1 *)(param_2 + 0x25);
    *(undefined1 *)(param_1 + 0x1328) = *(undefined1 *)((int)param_2 + 0x91);
    *(undefined4 *)(param_1 + 0x1304) = param_2[0x4f];
    *(undefined4 *)(param_1 + 0x1308) = param_2[0x22];
  }
  else {
    iVar1 = 0;
    if (param_3 == 2) {
      *(undefined4 *)(param_1 + 0x130c) = *param_2;
      if (param_2[1] != 0) {
        FUN_00002910(param_1 + 0xe00);
      }
      if (param_2[2] != 0) {
        FUN_00002910(param_1 + 0xf00);
      }
      *(undefined4 *)(param_1 + 0x1310) = param_2[0x53];
      iVar1 = 0;
      if ((param_2[9] == 0) || (iVar1 = FUN_00002774(param_2[9],param_1 + 0x1000,0x100), -1 < iVar1)
         ) {
        if (param_2[0xc] != 0) {
          FUN_00002910(param_1 + 0x1100);
        }
        if (param_2[0xd] != 0) {
          FUN_00002910(param_1 + 0x1200);
        }
        *(undefined4 *)(param_1 + 0x1314) = param_2[0x1a];
        *(undefined4 *)(param_1 + 0x1318) = param_2[0x22];
      }
    }
  }
  return iVar1;
}


================================================================