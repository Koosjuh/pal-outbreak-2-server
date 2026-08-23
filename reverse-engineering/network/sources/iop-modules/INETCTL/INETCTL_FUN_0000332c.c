FUNCTION FUN_0000332c @ 0x0000332c size=508
CALLERS (0): 
CALLEES (7): FUN_00003d40@0x00003d40, FUN_000000c4@0x000000c4, FUN_0000007c@0x0000007c, FUN_00000148@0x00000148, FUN_00000104@0x00000104, FUN_00003ce8@0x00003ce8, FUN_00003d84@0x00003d84

undefined4 FUN_0000332c(int param_1,int param_2)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  FUN_00000104();
  if (param_1 == 0) {
    uVar5 = 0xffffffff;
  }
  else {
    piVar4 = DAT_00004700;
    if (DAT_00004700 != (int *)0x0) {
      do {
        iVar3 = FUN_00003d84(param_1,piVar4[2]);
        if (iVar3 == 0) break;
        piVar4 = (int *)*piVar4;
      } while (piVar4 != (int *)0x0);
      if (piVar4 != (int *)0x0) {
        piVar2 = (int *)piVar4[1];
        if (*piVar4 != 0) {
          *(int **)(*piVar4 + 4) = (int *)piVar4[1];
          piVar2 = DAT_00004704;
        }
        DAT_00004704 = piVar2;
        piVar2 = (int *)*piVar4;
        if ((undefined4 *)piVar4[1] != (undefined4 *)0x0) {
          *(undefined4 *)piVar4[1] = (int *)*piVar4;
          piVar2 = DAT_00004700;
        }
        DAT_00004700 = piVar2;
        FUN_000000c4(piVar4);
      }
    }
    uVar5 = 0x10;
    if (param_2 == 0) {
      uVar5 = 0x410;
    }
    piVar4 = (int *)FUN_0000007c(uVar5);
    if (piVar4 == (int *)0x0) {
      uVar5 = 0xfffffffe;
    }
    else {
      piVar4[2] = param_1;
      puVar1 = PTR_DAT_000045e0;
      if (param_2 == 0) {
        *(undefined **)(PTR_DAT_000046a4 + 0x24) = PTR_DAT_000046a8;
        iVar3 = DAT_000045d8;
        uVar6 = *(undefined4 *)(puVar1 + 8);
        uVar7 = *(undefined4 *)(puVar1 + 0xc);
        uVar5 = *(undefined4 *)(puVar1 + 0x10);
        *(int **)(puVar1 + 8) = piVar4 + 4;
        *(int **)(puVar1 + 0xc) = piVar4 + 4;
        *(undefined4 *)puVar1 = 0;
        *(int *)(puVar1 + 4) = param_1;
        *(int **)(puVar1 + 0x10) = piVar4 + 0x104;
        if (iVar3 != 0) {
          FUN_00003d40("inetctl: Loading %s\n",param_1);
        }
        iVar3 = FUN_00003ce8(PTR_DAT_000045e0,PTR_DAT_000046a4);
        puVar1 = PTR_DAT_000045e0;
        *(undefined4 *)(PTR_DAT_000045e0 + 8) = uVar6;
        *(undefined4 *)(puVar1 + 0xc) = uVar7;
        *(undefined4 *)(puVar1 + 0x10) = uVar5;
        if (iVar3 != 0) {
          FUN_00003d40("inetctl: sceNetCnfLoadDial -> %d\n",iVar3);
          uVar5 = 0xfffffffd;
          goto LAB_000034f4;
        }
        piVar4[3] = *(int *)PTR_DAT_000046a8;
      }
      else {
        piVar4[3] = param_2;
      }
      piVar4[1] = (int)DAT_00004704;
      piVar2 = piVar4;
      if (DAT_00004704 != (int *)0x0) {
        *DAT_00004704 = (int)piVar4;
        piVar2 = DAT_00004700;
      }
      DAT_00004700 = piVar2;
      uVar5 = 0;
      *piVar4 = 0;
      DAT_00004704 = piVar4;
    }
  }
LAB_000034f4:
  FUN_00000148();
  return uVar5;
}


================================================================