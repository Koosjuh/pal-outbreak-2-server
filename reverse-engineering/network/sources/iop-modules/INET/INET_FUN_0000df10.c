FUNCTION FUN_0000df10 @ 0x0000df10 size=568
CALLERS (5): FUN_00001108@0x00001108, FUN_00000994@0x00000994, FUN_0000057c@0x0000057c, FUN_00011e2c@0x00011e2c, FUN_00000344@0x00000344
CALLEES (8): FUN_000029f8@0x000029f8, FUN_00011d90@0x00011d90, FUN_0000ae24@0x0000ae24, FUN_00009eec@0x00009eec, FUN_0000a9c0@0x0000a9c0, FUN_0000daa8@0x0000daa8, FUN_000016ec@0x000016ec, FUN_00009e60@0x00009e60

void FUN_0000df10(int param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  if ((DAT_0001b850 & 8) != 0) {
    FUN_00011d90(&PTR_DAT_0001b884,param_1 + 8);
    FUN_000029f8(&DAT_0001b890,param_2);
  }
  uVar3 = 0;
  for (piVar4 = param_2; piVar4 != (int *)0x0; piVar4 = (int *)*piVar4) {
    uVar3 = uVar3 + (piVar4[5] - piVar4[4]);
  }
  if (uVar3 < 0x5eb) {
    iVar6 = 0x3c - uVar3;
    uVar1 = (uint)((*(uint *)(param_1 + 0x48) & 0x80) == 0);
    iVar5 = uVar1 * 2;
    if (iVar6 < 0) {
      iVar6 = 0;
    }
    if ((((uVar1 == 0) || ((param_2[3] & 0x800U) != 0)) && (iVar6 == 0)) && (*param_2 == 0)) {
      if ((DAT_0001b850 & 0x80) != 0) {
        FUN_000016ec(0,param_2[4],param_2[5] - param_2[4]);
      }
      FUN_0000daa8(param_1,param_2);
      return;
    }
    iVar2 = FUN_00009e60(0,iVar5 + uVar3 + iVar6);
    if (iVar2 != 0) {
      *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + iVar5;
      *(int *)(iVar2 + 0x14) = *(int *)(iVar2 + 0x14) + iVar5;
      while (param_2 != (int *)0x0) {
        piVar4 = (int *)*param_2;
        *param_2 = 0;
        FUN_0000a9c0(param_2[4],*(undefined4 *)(iVar2 + 0x14),param_2[5] - param_2[4]);
        *(int *)(iVar2 + 0x14) = *(int *)(iVar2 + 0x14) + (param_2[5] - param_2[4]);
        param_2[1] = 0;
        *param_2 = 0;
        FUN_00009eec();
        param_2 = piVar4;
      }
      if (0 < iVar6) {
        FUN_0000ae24(*(undefined4 *)(iVar2 + 0x14),iVar6);
        *(int *)(iVar2 + 0x14) = *(int *)(iVar2 + 0x14) + iVar6;
      }
      if ((DAT_0001b850 & 0x80) != 0) {
        FUN_000016ec(0,*(int *)(iVar2 + 0x10),*(int *)(iVar2 + 0x14) - *(int *)(iVar2 + 0x10));
      }
      FUN_0000daa8(param_1,iVar2);
      return;
    }
  }
  if ((DAT_0001b850 & 1) != 0) {
    FUN_00011d90("# ERR # %s:%d: %s\n","sysdep.c",0x201,s_dropped_0001b894);
  }
  FUN_00009eec(param_2);
  return;
}


================================================================