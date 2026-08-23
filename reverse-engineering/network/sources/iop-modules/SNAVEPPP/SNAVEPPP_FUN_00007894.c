FUNCTION FUN_00007894 @ 0x00007894 size=508
CALLERS (2): FUN_00008918@0x00008918, FUN_00008824@0x00008824
CALLEES (8): FUN_00010be8@0x00010be8, FUN_0001073c@0x0001073c, FUN_00010c38@0x00010c38, FUN_000107dc@0x000107dc, FUN_0000231c@0x0000231c, FUN_000103cc@0x000103cc, FUN_00010764@0x00010764, FUN_0000226c@0x0000226c

undefined4 FUN_00007894(int param_1,short param_2)

{
  short sVar1;
  short sVar2;
  short sVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined1 auStack_20 [4];
  ushort local_1c [2];
  
  uVar6 = (uint)param_2;
  do {
    while( true ) {
      if ((int)uVar6 < 1) {
        return 0;
      }
      sVar1 = FUN_00010be8(auStack_20);
      sVar2 = FUN_0000231c(local_1c);
      if ((sVar2 == 0) && (uVar4 = (uint)local_1c[0], uVar4 != 0)) break;
LAB_00007924:
      iVar5 = FUN_000103cc();
      if ((((DAT_00012ee4 != 0) || (DAT_0001360c == 0)) ||
          (DAT_0001360c < (uint)(iVar5 - DAT_00013608))) || ((sVar2 != 0 || (sVar1 != 1)))) {
        if ((DAT_00012ee4 != 0) && ((DAT_00012efc & 1) != 0)) {
          FUN_00010c38("ave-ppp: WaitNstrRecv(): PPP_CloseRequest return -1\n");
        }
        if (((DAT_0001360c == 0) || (DAT_0001360c < (uint)(iVar5 - DAT_00013608))) &&
           ((DAT_00012efc & 1) != 0)) {
          FUN_00010c38("ave-ppp: WaitNstrRecv(): timeout(%d) return -1\n");
        }
        if ((sVar2 != 0) && ((DAT_00012efc & 1) != 0)) {
          FUN_00010c38("ave-ppp: WaitNstrRecv(): PP_direct_pk_stat error return -1\n");
        }
        DAT_0001360c = 0;
        return 0xffffffff;
      }
      FUN_00010764();
      FUN_000107dc();
      FUN_0001073c();
    }
    if ((int)uVar6 < (int)uVar4) {
      uVar4 = uVar6;
    }
    sVar3 = FUN_0000226c(param_1,uVar4 & 0xffff);
    if (sVar3 != 0) goto LAB_00007924;
    param_1 = param_1 + uVar4;
    uVar6 = uVar6 - uVar4;
  } while( true );
}


================================================================