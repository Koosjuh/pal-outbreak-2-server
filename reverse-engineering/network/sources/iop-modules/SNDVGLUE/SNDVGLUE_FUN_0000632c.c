FUNCTION FUN_0000632c @ 0x0000632c size=708
CALLERS (1): FUN_0000678c@0x0000678c
CALLEES (3): FUN_00008044@0x00008044, FUN_00007d78@0x00007d78, FUN_00007d04@0x00007d04

int FUN_0000632c(int param_1,int param_2,uint param_3)

{
  char *pcVar1;
  int iVar2;
  short sVar3;
  ushort local_20;
  ushort local_1e [3];
  
  sVar3 = 1;
joined_r0x00006358:
  if ((param_3 & 0xffff) == 0) {
LAB_000065c8:
    return (int)sVar3;
  }
  FUN_00008044(&local_20,param_2,2);
  local_20 = local_20 << 8 | local_20 >> 8;
  if (local_20 == 0) goto LAB_000065c8;
  FUN_00008044(local_1e,param_2 + 2,2);
  local_1e[0] = local_1e[0] << 8 | local_1e[0] >> 8;
  iVar2 = param_2 + 4;
  if (local_20 == 0x110) {
    if ((DAT_00009710 & 2) != 0) {
      FUN_00007d04("[relay session id]:",iVar2,local_1e[0]);
    }
    *(int *)(param_1 + 0x2c) = iVar2;
    *(ushort *)(param_1 + 0x30) = local_1e[0];
    goto LAB_000065a4;
  }
  if (local_20 < 0x111) {
    if (local_20 == 0x103) {
      if ((DAT_00009710 & 2) != 0) {
        pcVar1 = "[host uniq]:";
LAB_000064ac:
        FUN_00007d78(pcVar1,iVar2,local_1e[0]);
      }
      goto LAB_000065a4;
    }
    if (0x103 < local_20) {
      if (local_20 != 0x104) goto LAB_00006578;
      if ((DAT_00009710 & 2) != 0) {
        pcVar1 = "[ac cookie]:";
        goto LAB_000064ac;
      }
      goto LAB_000065a4;
    }
    if (local_20 != 0x101) goto LAB_00006578;
    if ((DAT_00009710 & 2) == 0) goto LAB_000065a4;
    pcVar1 = "[service name]:";
  }
  else {
    if (local_20 == 0x202) {
      sVar3 = -1;
      if ((DAT_00009710 & 2) != 0) {
        pcVar1 = "[ac system error]:";
LAB_00006564:
        FUN_00007d04(pcVar1,iVar2,local_1e[0]);
        sVar3 = -1;
      }
      goto LAB_000065c8;
    }
    if (local_20 < 0x203) {
      if (local_20 != 0x201) goto LAB_00006578;
      sVar3 = -1;
      if ((DAT_00009710 & 2) != 0) {
        pcVar1 = "[service name error]:";
        goto LAB_00006564;
      }
      goto LAB_000065c8;
    }
    if (local_20 == 0x203) {
      sVar3 = -1;
      if ((DAT_00009710 & 2) != 0) {
        pcVar1 = "[generic error]:";
        goto LAB_00006564;
      }
      goto LAB_000065c8;
    }
LAB_00006578:
    if ((DAT_00009710 & 2) == 0) goto LAB_000065a4;
    pcVar1 = "[unknown tag]:";
  }
  FUN_00007d04(pcVar1,iVar2,local_1e[0]);
LAB_000065a4:
  param_2 = param_2 + local_1e[0] + 4;
  param_3 = (param_3 - 4) - (uint)local_1e[0];
  goto joined_r0x00006358;
}


================================================================