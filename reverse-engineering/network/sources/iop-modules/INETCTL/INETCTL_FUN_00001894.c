FUNCTION FUN_00001894 @ 0x00001894 size=748
CALLERS (1): FUN_0000203c@0x0000203c
CALLEES (5): FUN_0000018c@0x0000018c, FUN_00003d40@0x00003d40, FUN_000009bc@0x000009bc, FUN_00003d94@0x00003d94, FUN_00003d84@0x00003d84

/* WARNING: Type propagation algorithm not settling */

undefined4 FUN_00001894(int param_1)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  undefined1 *puVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  uint local_28 [2];
  
  if (*(int *)(param_1 + 0x18) != 0) {
    piVar6 = *(int **)(*(int *)(param_1 + 0x18) + 0x24);
    if (piVar6 == (int *)0x0) {
      return 0xffffffff;
    }
    iVar7 = piVar6[1];
    if (iVar7 == 0) {
      return 0xffffffff;
    }
    iVar8 = piVar6[2];
    iVar2 = FUN_0000018c(iVar8,8,local_28,4);
    if (iVar2 == 0) {
      if (((local_28[0] & 0x40) == 0) ||
         (iVar2 = piVar6[4], iVar4 = *(int *)(iVar7 + 0x28), piVar6[4] = iVar2 + 1, iVar4 <= iVar2))
      {
        return 0;
      }
      iVar2 = *piVar6;
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      if (*(int *)(iVar2 + 0x18) != 0) {
        iVar4 = FUN_0000018c(iVar8,0x90008038,&DAT_00004fc8,0x400);
        if (iVar4 != 0) {
          return 0;
        }
        iVar4 = FUN_00003d94(s_ABORT_00004634,&DAT_00004fc8,6);
        if (iVar4 != 0) {
          return 0;
        }
        iVar2 = FUN_00003d84(*(undefined4 *)(iVar2 + 0x18),&DAT_00004fce);
        if (iVar2 != 0) {
          return 0;
        }
        iVar2 = piVar6[3];
        piVar6[3] = iVar2 + 1;
        iVar4 = 0;
        if (9 < iVar2 + 1) {
          piVar6[3] = 0;
        }
        do {
          pcVar3 = *(char **)(iVar7 + piVar6[3] * 4 + 0x38);
          if ((pcVar3 != (char *)0x0) && (bVar1 = iVar4 < 10, *pcVar3 != '\0')) break;
          iVar2 = piVar6[3] + 1;
          piVar6[3] = iVar2;
          if (9 < iVar2) {
            piVar6[3] = 0;
          }
          iVar4 = iVar4 + 1;
          bVar1 = false;
        } while (iVar4 < 10);
        if (!bVar1) {
          FUN_00003d40("inetctl: phone number not found\n");
          return 0xffffffff;
        }
        puVar5 = &DAT_00004fc8;
        pcVar3 = *(char **)(iVar7 + 0x30);
        local_28[1] = 0x3ff;
        if ((pcVar3 != (char *)0x0) && (*pcVar3 != '\0')) {
          puVar5 = (undefined1 *)FUN_000009bc(&DAT_00004fc8,pcVar3,local_28 + 1);
          if (puVar5 == (undefined1 *)0x0) {
            return 0xffffffff;
          }
          pcVar3 = *(char **)(iVar7 + 0x34);
          if (((pcVar3 != (char *)0x0) && (*pcVar3 != '\0')) &&
             (puVar5 = (undefined1 *)FUN_000009bc(puVar5,pcVar3,local_28 + 1),
             puVar5 == (undefined1 *)0x0)) {
            return 0xffffffff;
          }
        }
        puVar5 = (undefined1 *)
                 FUN_000009bc(puVar5,*(undefined4 *)(iVar7 + piVar6[3] * 4 + 0x38),local_28 + 1);
        if (puVar5 != (undefined1 *)0x0) {
          *puVar5 = 0;
          iVar2 = FUN_0000018c(iVar8,0x90004003,&DAT_00004fc8,puVar5 + -0x4fc6);
          if (iVar2 != 0) {
            return 0xffffffff;
          }
          iVar7 = *(int *)(iVar7 + 0x2c);
          *(int *)(param_1 + 0x14) = iVar7;
          if (iVar7 < 1) {
            *(undefined4 *)(param_1 + 0x14) = 10;
          }
          if (*(int *)(param_1 + 0x14) < 3) {
            *(undefined4 *)(param_1 + 0x14) = 3;
          }
          *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) * 1000;
          return 1;
        }
      }
    }
  }
  return 0xffffffff;
}


================================================================