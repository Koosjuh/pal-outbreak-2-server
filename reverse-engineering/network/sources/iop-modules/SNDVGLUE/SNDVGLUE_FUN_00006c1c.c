FUNCTION FUN_00006c1c @ 0x00006c1c size=444
CALLERS (1): FUN_00006dd8@0x00006dd8
CALLEES (8): FUN_00006bc4@0x00006bc4, FUN_00007ae4@0x00007ae4, FUN_00005ce4@0x00005ce4, FUN_000076f4@0x000076f4, FUN_00006b50@0x00006b50, FUN_0000810c@0x0000810c, FUN_000074ac@0x000074ac, FUN_00006c14@0x00006c14

void FUN_00006c1c(undefined2 *param_1)

{
  short sVar1;
  ushort uVar2;
  undefined2 uVar3;
  int iVar4;
  
  switch(*param_1) {
  case 0:
    if ((short)param_1[3] < 1) {
      FUN_00006c14(param_1);
      FUN_00005ce4(param_1);
      uVar3 = 0xffff;
LAB_00006dc0:
      *param_1 = uVar3;
      return;
    }
    uVar2 = FUN_00007ae4();
    if ((DAT_00009710 & 2) != 0) {
      FUN_0000810c("pppoe : POE_status() ==> %d\n",(int)(short)uVar2);
    }
    if (-1 < (int)((uint)uVar2 << 0x10)) {
      if (param_1[2] != 0) {
        if ((DAT_00009710 & 2) != 0) {
          FUN_0000810c("pppoe : send LCP TermReq (session id %04x)\n",param_1[1]);
        }
        FUN_000076f4(param_1);
      }
      param_1[1] = 0;
      iVar4 = FUN_000074ac(param_1);
      if (iVar4 << 0x10 < 0) {
        return;
      }
      FUN_00006b50(param_1 + 0x11d,param_1[0x412]);
      *param_1 = 1;
      FUN_00006bc4(param_1,3000,2);
      return;
    }
    sVar1 = param_1[3];
    iVar4 = (int)(short)param_1[4];
    break;
  case 1:
  case 3:
    if ((short)param_1[3] < 1) {
      FUN_00006c14(param_1);
      uVar3 = 5;
      goto LAB_00006dc0;
    }
    iVar4 = FUN_000074ac(param_1);
    if (-1 < iVar4 << 0x10) {
      FUN_00006b50(param_1 + 0x11d,param_1[0x412]);
    }
    sVar1 = param_1[3];
    iVar4 = (*(int *)(param_1 + 4) << 0x11) >> 0x10;
    break;
  default:
    goto switchD_00006c54_caseD_2;
  }
  FUN_00006bc4(param_1,iVar4,(int)(short)(sVar1 + -1));
switchD_00006c54_caseD_2:
  return;
}


================================================================