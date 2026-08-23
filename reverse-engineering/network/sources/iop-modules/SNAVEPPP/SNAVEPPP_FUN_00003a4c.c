FUNCTION FUN_00003a4c @ 0x00003a4c size=256
CALLERS (1): FUN_00010990@0x00010990
CALLEES (1): FUN_00010c38@0x00010c38

int FUN_00003a4c(short param_1,ushort param_2,int *param_3)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = -1;
  iVar3 = (int)param_1;
  if (iVar3 == 1) {
    if (param_2 < 4) {
      if ((DAT_00012efc & 1) != 0) {
        pcVar2 = "ave-ppp: PP_getOption PP_OPT_TIMER_INTERVAL optlen(%d) error\n";
        iVar3 = (int)(short)param_2;
        goto LAB_00003b2c;
      }
    }
    else {
      *param_3 = (int)DAT_00012f00;
      iVar4 = 4;
      if ((DAT_00012efc & 1) != 0) {
        pcVar2 = "ave-ppp: PP_getOption PP_OPT_TIMER_INTERVAL %d\n";
        iVar3 = (int)DAT_00012f00;
        goto LAB_00003b2c;
      }
    }
  }
  else {
    iVar1 = -0x10000;
    if ((DAT_00012efc & 1) == 0) goto LAB_00003b38;
    pcVar2 = "ave-ppp: PP_getOption unknown option(%d)\n";
LAB_00003b2c:
    FUN_00010c38(pcVar2,iVar3);
  }
  iVar1 = iVar4 << 0x10;
LAB_00003b38:
  return iVar1 >> 0x10;
}


================================================================