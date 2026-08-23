FUNCTION FUN_0000385c @ 0x0000385c size=496
CALLERS (1): FUN_0001095c@0x0001095c
CALLEES (1): FUN_00010c38@0x00010c38

int FUN_0000385c(short param_1,short param_2,uint *param_3)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  short local_10;
  
  iVar4 = -1;
  if (param_1 == 1) {
    if (param_2 == 4) {
      uVar3 = *param_3;
      if ((int)uVar3 < 1) {
        iVar1 = -0x10000;
        if ((DAT_00012efc & 1) == 0) goto LAB_00003a38;
        pcVar2 = "ave-ppp: PP_setOption PP_OPT_TIMER_INTERVAL optval(%d) error\n";
        goto LAB_00003a2c;
      }
      local_10 = (short)uVar3;
      DAT_00012f00 = local_10;
      iVar4 = 0;
      if ((DAT_00012efc & 1) != 0) {
        pcVar2 = "ave-ppp: PP_setOption PP_OPT_TIMER_INTERVAL %d\n";
        uVar3 = (uint)local_10;
LAB_000039f8:
        FUN_00010c38(pcVar2,uVar3);
        iVar4 = 0;
      }
    }
    else if ((DAT_00012efc & 1) != 0) {
      pcVar2 = "ave-ppp: PP_setOption PP_OPT_TIMER_INTERVAL optlen(%d) error\n";
      uVar3 = (uint)param_2;
LAB_00003a2c:
      FUN_00010c38(pcVar2,uVar3);
    }
  }
  else if (param_1 == 2) {
    if (param_2 == 4) {
      uVar3 = *param_3;
      if (1 < uVar3) {
        iVar1 = -0x10000;
        if ((DAT_00012efc & 1) == 0) goto LAB_00003a38;
        pcVar2 = "ave-ppp: PP_setOption PP_OPT_PPPOE optval(%d) error\n";
        goto LAB_00003a2c;
      }
      iVar4 = 0;
      DAT_00012ef8 = uVar3;
      if ((DAT_00012efc & 1) != 0) {
        pcVar2 = "ave-ppp: PP_setOption PP_OPT_PPPOE %d\n";
        goto LAB_000039f8;
      }
    }
    else if ((DAT_00012efc & 1) != 0) {
      pcVar2 = "ave-ppp: PP_setOption PP_OPT_PPPOE optlen(%d) error\n";
      uVar3 = (uint)param_2;
      goto LAB_00003a2c;
    }
  }
  else if ((DAT_00012efc & 1) != 0) {
    pcVar2 = "ave-ppp: PP_setOption unknown option(%d)\n";
    uVar3 = (uint)param_1;
    goto LAB_00003a2c;
  }
  iVar1 = iVar4 << 0x10;
LAB_00003a38:
  return iVar1 >> 0x10;
}


================================================================