FUNCTION FUN_00005f6c @ 0x00005f6c size=960
CALLERS (1): FUN_0000678c@0x0000678c
CALLEES (4): FUN_00007d04@0x00007d04, FUN_00008130@0x00008130, FUN_00007d78@0x00007d78, FUN_00008044@0x00008044

int FUN_00005f6c(int param_1,int param_2,uint param_3)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  ushort local_28;
  ushort local_26 [3];
  
  iVar3 = 0;
  *(undefined2 *)(param_1 + 0x1c) = 1;
  if (*(char *)(param_1 + 0x13a) != '\0') {
    *(undefined2 *)(param_1 + 0x1c) = 0;
  }
  *(undefined2 *)(param_1 + 0x1e) = 1;
  if (*(char *)(param_1 + 0x3a) != '\0') {
    *(undefined2 *)(param_1 + 0x1e) = 0;
  }
  do {
    if ((param_3 & 0xffff) == 0) {
LAB_000062d0:
      iVar2 = iVar3 << 0x10;
      if (((iVar2 == 0) && (iVar2 = iVar3 << 0x10, *(short *)(param_1 + 0x1c) != 0)) &&
         (iVar2 = iVar3 << 0x10, *(short *)(param_1 + 0x1e) != 0)) {
        iVar2 = 0x10000;
      }
      return iVar2 >> 0x10;
    }
    FUN_00008044(&local_28,param_2,2);
    local_28 = local_28 << 8 | local_28 >> 8;
    if (local_28 == 0) goto LAB_000062d0;
    FUN_00008044(local_26,param_2 + 2,2);
    local_26[0] = local_26[0] << 8 | local_26[0] >> 8;
    iVar2 = param_2 + 4;
    if (local_28 == 0x104) {
      if ((DAT_00009710 & 2) != 0) {
        FUN_00007d78("[ac cookie]:",iVar2,local_26[0]);
      }
      *(int *)(param_1 + 0x24) = iVar2;
      *(ushort *)(param_1 + 0x28) = local_26[0];
    }
    else {
      if (0x104 < local_28) {
        if (local_28 == 0x201) {
          iVar3 = -1;
          if ((DAT_00009710 & 2) == 0) goto LAB_000062d0;
          pcVar1 = "[service name error]:";
        }
        else {
          if (local_28 < 0x202) {
            if (local_28 == 0x110) {
              if ((DAT_00009710 & 2) != 0) {
                FUN_00007d04("[relay session id]:",iVar2,local_26[0]);
              }
              *(int *)(param_1 + 0x2c) = iVar2;
              *(ushort *)(param_1 + 0x30) = local_26[0];
            }
            else {
LAB_00006280:
              if ((DAT_00009710 & 2) != 0) {
                FUN_00007d04("[unknown tag]:",iVar2,local_26[0]);
              }
            }
            goto LAB_000062ac;
          }
          if (local_28 == 0x202) {
            iVar3 = -1;
            if ((DAT_00009710 & 2) == 0) goto LAB_000062d0;
            pcVar1 = "[ac system error]:";
          }
          else {
            if (local_28 != 0x203) goto LAB_00006280;
            iVar3 = -1;
            if ((DAT_00009710 & 2) == 0) goto LAB_000062d0;
            pcVar1 = "[generic error]:";
          }
        }
        FUN_00007d04(pcVar1,iVar2,local_26[0]);
        iVar3 = -1;
        goto LAB_000062d0;
      }
      if (local_28 == 0x102) {
        if ((DAT_00009710 & 2) != 0) {
          FUN_00007d04("[ac name]:",iVar2,local_26[0]);
        }
        if ((*(char *)(param_1 + 0x3a) != '\0') &&
           (iVar2 = FUN_00008130(param_1 + 0x3a,iVar2,local_26[0]), iVar2 == 0)) {
          *(undefined2 *)(param_1 + 0x1e) = 1;
        }
      }
      else if (local_28 < 0x103) {
        if (local_28 != 0x101) goto LAB_00006280;
        if ((DAT_00009710 & 2) != 0) {
          FUN_00007d04("[service name]:",iVar2,local_26[0]);
        }
        if ((*(char *)(param_1 + 0x13a) != '\0') &&
           (iVar2 = FUN_00008130(param_1 + 0x13a,iVar2,local_26[0]), iVar2 == 0)) {
          *(undefined2 *)(param_1 + 0x1c) = 1;
        }
      }
      else if ((DAT_00009710 & 2) != 0) {
        FUN_00007d78("[host uniq]:",iVar2,local_26[0]);
      }
    }
LAB_000062ac:
    param_2 = param_2 + local_26[0] + 4;
    param_3 = (param_3 - 4) - (uint)local_26[0];
  } while( true );
}


================================================================