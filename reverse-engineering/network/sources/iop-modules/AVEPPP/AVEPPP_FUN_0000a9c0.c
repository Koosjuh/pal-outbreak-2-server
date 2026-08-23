FUNCTION FUN_0000a9c0 @ 0x0000a9c0 size=556
CALLERS (2): FUN_0000abec@0x0000abec, FUN_0000b3d8@0x0000b3d8
CALLEES (5): FUN_00001c50@0x00001c50, FUN_00001c20@0x00001c20, FUN_000006b0@0x000006b0, FUN_00010c38@0x00010c38, FUN_0000075c@0x0000075c

void FUN_0000a9c0(int *param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  char cVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  char *pcVar7;
  int iVar8;
  
  piVar2 = (int *)*param_1;
  iVar8 = param_4 + -2;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)FUN_000006b0(0);
    if (piVar2 == (int *)0x0) {
      return;
    }
    *param_1 = (int)piVar2;
  }
  puVar6 = (undefined1 *)(*piVar2 + (uint)*(ushort *)(piVar2 + 1));
  *puVar6 = (char)param_3;
  puVar6[1] = (char)param_4;
  pcVar7 = puVar6 + 2;
  if (param_3 == 3) {
    uVar5 = *(undefined4 *)(param_2 + 4);
LAB_0000ab08:
    iVar8 = param_4 + -6;
  }
  else {
    if (3 < param_3) {
      if (param_3 == 0x81) {
        uVar5 = *(undefined4 *)(param_2 + 0x14);
      }
      else {
        if (param_3 != 0x83) goto LAB_0000ab1c;
        uVar5 = *(undefined4 *)(param_2 + 0x18);
      }
      goto LAB_0000ab08;
    }
    if (param_3 != 1) {
      if (param_3 == 2) {
        if (*(short *)(param_2 + 0xc) == 0x2d) {
          iVar8 = param_4 + -6;
          pcVar7 = (char *)FUN_00001c50(pcVar7,*(undefined2 *)(param_2 + 0xc));
          *pcVar7 = *(char *)(param_2 + 0xe) + -1;
          pcVar7[1] = *(char *)(param_2 + 0x10);
          pcVar7 = pcVar7 + 2;
        }
        goto LAB_0000ab58;
      }
LAB_0000ab1c:
      if (DAT_00012efc != 0) {
        FUN_00010c38("ave-ppp %s:","ipcp_option");
        FUN_00010c38("Unsupported config option 0x%x ignored.\n",param_3);
      }
      goto LAB_0000ab58;
    }
    iVar8 = param_4 + -10;
    pcVar7 = (char *)FUN_00001c20(pcVar7,*(undefined4 *)(param_2 + 4));
    uVar5 = *(undefined4 *)(param_2 + 8);
  }
  pcVar7 = (char *)FUN_00001c20(pcVar7,uVar5);
LAB_0000ab58:
  iVar3 = iVar8 << 0x10;
  while (0 < iVar3) {
    iVar8 = iVar8 + -1;
    sVar1 = FUN_0000075c(param_5,&DAT_00013624,1);
    cVar4 = -1;
    if (sVar1 == 1) {
      cVar4 = DAT_00013624;
    }
    *pcVar7 = cVar4;
    pcVar7 = pcVar7 + 1;
    iVar3 = iVar8 * 0x10000;
  }
  *(short *)(piVar2 + 1) = (short)piVar2[1] + (short)param_4;
  return;
}


================================================================