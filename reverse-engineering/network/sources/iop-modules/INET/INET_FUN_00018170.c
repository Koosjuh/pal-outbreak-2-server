FUNCTION FUN_00018170 @ 0x00018170 size=640
CALLERS (2): FUN_00018de4@0x00018de4, FUN_0001804c@0x0001804c
CALLEES (5): FUN_0000709c@0x0000709c, FUN_0001804c@0x0001804c, FUN_00009e60@0x00009e60, FUN_00006200@0x00006200, FUN_00009eec@0x00009eec

void FUN_00018170(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,ushort param_5,
                 int param_6,ushort param_7)

{
  int iVar1;
  int iVar2;
  ushort uVar3;
  int *piVar4;
  int iVar5;
  ushort *puVar6;
  
  if ((param_1 == 0) && (param_6 == -1)) {
    FUN_0001804c(param_2,param_3,param_4,param_5,0xffffffff,param_7);
  }
  else {
    *(int *)(*(int *)(param_1 + 0x1a0) + 0x40) = *(int *)(*(int *)(param_1 + 0x1a0) + 0x40) + 1;
    if ((param_2[3] & 0x2000U) == 0) {
      piVar4 = (int *)FUN_00009e60(0,8);
      if (piVar4 == (int *)0x0) {
        FUN_00009eec(param_2);
        *(int *)(*(int *)(param_1 + 0x1a0) + 0x48) = *(int *)(*(int *)(param_1 + 0x1a0) + 0x48) + 1;
        return;
      }
      puVar6 = (ushort *)piVar4[5];
      *puVar6 = param_5;
      puVar6[1] = param_7;
      iVar1 = param_2[5];
      iVar2 = param_2[4];
      puVar6[3] = 0;
      puVar6[2] = ((short)iVar1 - (short)iVar2) + 8;
      *piVar4 = (int)param_2;
      piVar4[5] = piVar4[5] + 8;
      param_2[1] = (int)param_2;
      *puVar6 = *puVar6 << 8 | *puVar6 >> 8;
      puVar6[1] = puVar6[1] << 8 | puVar6[1] >> 8;
      puVar6[2] = puVar6[2] << 8 | puVar6[2] >> 8;
      uVar3 = FUN_00006200(0x11,param_4,param_6,piVar4);
      puVar6[3] = ~uVar3;
    }
    else {
      iVar5 = param_2[4];
      param_2[4] = iVar5 + -8;
      *(ushort *)(iVar5 + -8) = param_5;
      *(ushort *)(iVar5 + -6) = param_7;
      iVar1 = param_2[5];
      iVar2 = param_2[4];
      *(undefined2 *)(iVar5 + -2) = 0;
      *(short *)(iVar5 + -4) = (short)iVar1 - (short)iVar2;
      *(ushort *)(iVar5 + -8) = *(ushort *)(iVar5 + -8) << 8 | *(ushort *)(iVar5 + -8) >> 8;
      *(ushort *)(iVar5 + -6) = *(ushort *)(iVar5 + -6) << 8 | *(ushort *)(iVar5 + -6) >> 8;
      *(ushort *)(iVar5 + -4) = *(ushort *)(iVar5 + -4) << 8 | *(ushort *)(iVar5 + -4) >> 8;
      uVar3 = FUN_00006200(0x11,param_4,param_6,param_2);
      *(ushort *)(iVar5 + -2) = ~uVar3;
      piVar4 = param_2;
    }
    FUN_0000709c(param_1,param_4,param_6,0x11,param_3,0,piVar4,0);
  }
  return;
}


================================================================