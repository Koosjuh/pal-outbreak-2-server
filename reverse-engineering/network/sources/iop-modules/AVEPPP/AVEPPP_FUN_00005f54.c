FUNCTION FUN_00005f54 @ 0x00005f54 size=644
CALLERS (0): 
CALLEES (11): FUN_0001073c@0x0001073c, FUN_00002d88@0x00002d88, FUN_00010aac@0x00010aac, FUN_00007660@0x00007660, FUN_0000f668@0x0000f668, FUN_00010bb8@0x00010bb8, FUN_00010c38@0x00010c38, FUN_00005e78@0x00005e78, FUN_0000f6d0@0x0000f6d0, FUN_00010764@0x00010764, FUN_00002050@0x00002050

undefined4 FUN_00005f54(void)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined1 *puVar6;
  
  uVar5 = 0;
  iVar3 = 3;
  DAT_00012ee4 = 0;
  do {
    pbVar1 = &DAT_00014aa4 + iVar3;
    iVar3 = iVar3 + -1;
    uVar5 = uVar5 << 8 | (uint)*pbVar1;
  } while (-1 < iVar3);
  uVar4 = 0;
  iVar3 = 3;
  do {
    pbVar1 = &DAT_00014aa0 + iVar3;
    iVar3 = iVar3 + -1;
    uVar4 = uVar4 << 8 | (uint)*pbVar1;
  } while (-1 < iVar3);
  if ((DAT_00012efc & 1) != 0) {
    FUN_00010c38("ppp_close_sub: ifconfigdown\n");
  }
  if (DAT_00012ef0 != 0) {
    DAT_00012ef0 = 0;
    FUN_00010764();
    if ((DAT_00012efc & 1) != 0) {
      FUN_00010c38("ppp_close_sub: PP_OS_CriticalUnLock\n");
    }
    FUN_0000f6d0(uVar5);
    FUN_0000f668(uVar4,0xffffff);
    if ((DAT_00012efc & 1) != 0) {
      FUN_00010c38("ppp_close_sub: PP_OS_CriticalLock\n");
    }
    FUN_0001073c();
  }
  if ((DAT_00012efc & 1) != 0) {
    FUN_00010c38("ppp_close_sub: PP_pkd_ppp_close call\n");
  }
  FUN_00005e78();
  DAT_00012ecc = 7;
  FUN_00002050();
  iVar3 = FUN_00002d88();
  if ((iVar3 != 0) && (*(short *)(iVar3 + 6) != 0)) {
    if ((DAT_00012efc & 1) != 0) {
      FUN_00010c38("ppp_close_sub: disconnect script\n");
    }
    puVar6 = &DAT_00016ac0;
    iVar2 = FUN_00010aac(&DAT_00016ac0);
    if (iVar2 == 0) {
      if ((*(int *)(iVar3 + 0x44) == 0) || (iVar2 = FUN_00010aac(), iVar2 == 0)) goto LAB_00006138;
      puVar6 = *(undefined1 **)(iVar3 + 0x44);
    }
    FUN_00007660(puVar6,&DAT_00013458);
  }
LAB_00006138:
  if (DAT_00012ebc != 0) {
    if ((DAT_00012efc & 1) != 0) {
      FUN_00010c38("ppp_close_sub: PP_ComClose\n");
    }
    FUN_00010bb8();
    DAT_00012ebc = 0;
  }
  DAT_00012ed4 = 0;
  DAT_00012eb4 = 0;
  DAT_00012ee4 = 0;
  DAT_00012ecc = 0;
  if ((DAT_00012efc & 1) != 0) {
    FUN_00010c38("ppp_close_sub: phase == PPP_Connect_Unuse\n");
  }
  return 0;
}


================================================================