FUNCTION FUN_00001dd0 @ 0x00001dd0 size=592
CALLERS (2): FUN_00005828@0x00005828, FUN_00001ab0@0x00001ab0
CALLEES (6): FUN_0000139c@0x0000139c, FUN_000013bc@0x000013bc, FUN_000010c0@0x000010c0, FUN_00001454@0x00001454, FUN_00004ec4@0x00004ec4, FUN_00003b30@0x00003b30

undefined4 FUN_00001dd0(char param_1,char param_2,undefined4 param_3,int *param_4)

{
  undefined2 uVar1;
  short sVar2;
  char *pcVar3;
  undefined4 uVar4;
  int iVar5;
  char local_38 [4];
  undefined4 local_34;
  undefined1 auStack_28 [8];
  
  pcVar3 = local_38;
  if (param_1 == '\0') {
    if ((char)param_4[(*param_4 + -1) * 3 + 4] == '\x01') {
      pcVar3 = (char *)FUN_000013bc(param_4 + *param_4 * 3);
    }
    else {
      FUN_0000139c(auStack_28,pcVar3);
      FUN_000010c0(auStack_28,param_4 + *param_4 * 3,0xc);
      FUN_00001454(param_4 + *param_4 * 3,0xc);
      iVar5 = *param_4;
      *(undefined2 *)(param_4 + iVar5 * 3 + 2) = 0xc;
      *(short *)(param_4 + (iVar5 + -1) * 3 + 2) = (short)param_4[(*param_4 + -1) * 3 + 2] + -0xc;
      FUN_0000139c(param_4 + *param_4 * 3 + 3,pcVar3);
      *param_4 = *param_4 + 1;
    }
  }
  else {
    if (param_1 != '\x03') {
      return 0xffffffff;
    }
    local_34 = 0;
    FUN_0000139c(param_4 + *param_4 * 3 + 3,pcVar3);
    *(undefined2 *)(param_4 + *param_4 * 3 + 2) = 0xc;
    param_4[1] = param_4[1] + 0xc;
    *param_4 = *param_4 + 1;
  }
  *pcVar3 = param_1;
  pcVar3[1] = param_2;
  pcVar3[2] = '\0';
  pcVar3[3] = '\0';
  uVar1 = FUN_00003b30(0,param_4,1);
  pcVar3[3] = (char)uVar1;
  pcVar3[2] = (char)((ushort)uVar1 >> 8);
  sVar2 = FUN_00004ec4(param_4,param_3,0,0,0,0,0,0,1,0);
  uVar4 = 0xffffffff;
  if (sVar2 == 0) {
    uVar4 = 0;
  }
  return uVar4;
}


================================================================