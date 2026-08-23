FUNCTION FUN_00003840 @ 0x00003840 size=752
CALLERS (1): FUN_00005828@0x00005828
CALLEES (11): FUN_00001454@0x00001454, FUN_00014e24@0x00014e24, FUN_0000139c@0x0000139c, FUN_000115f0@0x000115f0, FUN_00012608@0x00012608, FUN_000013bc@0x000013bc, FUN_00011d00@0x00011d00, FUN_00005e94@0x00005e94, FUN_000010c0@0x000010c0, FUN_000010a8@0x000010a8, FUN_00003b30@0x00003b30

undefined4 FUN_00003840(int param_1,ushort param_2,int param_3,undefined4 param_4)

{
  undefined2 uVar1;
  undefined2 uVar2;
  short sVar3;
  short *psVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  short asStack_48 [4];
  int local_40;
  undefined4 local_3c;
  undefined1 local_38;
  undefined1 local_37;
  undefined2 local_36;
  undefined1 auStack_30 [8];
  undefined1 auStack_28 [8];
  
  iVar7 = param_1 + 0xc;
  *(uint *)(param_1 + 4) = *(int *)(param_1 + 4) - (uint)param_2;
  *(ushort *)(param_1 + 8) = *(short *)(param_1 + 8) - param_2;
  FUN_00011d00(auStack_28,iVar7,8);
  FUN_00001454(iVar7,(int)(short)param_2);
  if (*(char *)(param_1 + 0x10) == '\x01') {
    psVar4 = (short *)FUN_000013bc(iVar7);
  }
  else {
    FUN_0000139c(auStack_30,asStack_48);
    FUN_000010c0(auStack_30,iVar7,8);
    psVar4 = asStack_48;
  }
  if ((DAT_00016178 & 4) != 0) {
    uVar5 = FUN_00012608();
    uVar1 = FUN_000010a8((int)*psVar4);
    uVar2 = FUN_000010a8((int)psVar4[1]);
    FUN_00014e24("UDP RECV: %u SP %d DP %d\n",uVar5,uVar1,uVar2);
  }
  if (psVar4[3] != 0) {
    local_38 = 0;
    local_37 = 0x11;
    local_40 = param_3;
    local_3c = param_4;
    local_36 = FUN_000010a8((int)*(short *)(param_1 + 4));
    sVar3 = FUN_00003b30(&local_40,param_1,0);
    if (sVar3 != 0) {
      return 0xffffffff;
    }
  }
  iVar7 = 0;
  if (DAT_0001617e != 0) {
    do {
      iVar6 = DAT_000161a0 + (short)iVar7 * 0x30;
      if ((((*(short *)(iVar6 + 8) != 0) && (*(short *)(iVar6 + 0xc) == psVar4[1])) &&
          ((*(char *)(iVar6 + 0x14) == '\0' || (*(int *)(iVar6 + 0x18) == param_3)))) &&
         ((*(char *)(iVar6 + 0x15) == '\0' || (*(short *)(iVar6 + 0xe) == *psVar4)))) {
        if (*(char *)(iVar6 + 0xb) == '\0') {
          *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -8;
          *(short *)(param_1 + 8) = *(short *)(param_1 + 8) + -8;
          FUN_00001454(param_1 + 0xc,8);
        }
        else {
          *(uint *)(param_1 + 4) = *(int *)(param_1 + 4) + (uint)param_2;
          *(ushort *)(param_1 + 8) = *(short *)(param_1 + 8) + param_2;
          FUN_00011d00(param_1 + 0xc,auStack_28,8);
        }
        sVar3 = FUN_000115f0(param_1,param_3,*psVar4,*(undefined4 *)(iVar6 + 0x24),(int)(short)iVar7
                            );
        if (sVar3 != 0) {
          return 0xffffffff;
        }
        return 0;
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 * 0x10000 >> 0x10 < (int)(uint)DAT_0001617e);
  }
  sVar3 = FUN_00005e94(param_4,0);
  uVar5 = 0;
  if (sVar3 != 1) {
    uVar5 = 0xfffffffe;
  }
  return uVar5;
}


================================================================