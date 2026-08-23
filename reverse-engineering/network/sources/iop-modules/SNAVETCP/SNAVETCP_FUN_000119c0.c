FUNCTION FUN_000119c0 @ 0x000119c0 size=484
CALLERS (1): FUN_0000e7ec@0x0000e7ec
CALLEES (6): FUN_00014e98@0x00014e98, FUN_00014ed8@0x00014ed8, FUN_00014ea8@0x00014ea8, FUN_00014e00@0x00014e00, FUN_00014eb8@0x00014eb8, FUN_00014e24@0x00014e24

undefined4 FUN_000119c0(int param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = 1;
  DAT_00016174 = 0;
  DAT_00016178 = 0;
  if (1 < param_1) {
    do {
      param_2 = param_2 + 1;
      iVar1 = FUN_00014e98(*param_2,"usbtx");
      if (iVar1 == 0) {
        DAT_00016174 = 1;
      }
      iVar1 = FUN_00014eb8(*param_2,"debug",5);
      if (iVar1 == 0) {
        uVar2 = FUN_00014ea8(*param_2);
        if (uVar2 < 7) {
          DAT_00016178 = 1;
        }
        else {
          DAT_00016178 = FUN_00014ed8(*param_2 + 6,0,10);
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < param_1);
  }
  iVar4 = FUN_00014e00(0);
  uVar3 = 1;
  if (iVar4 == 0) {
    FUN_00014e24("AVE-TCP version 0x%04x (%s)",0x116,"2002/09/02");
    if (DAT_00016174 == 1) {
      FUN_00014e24("  USBTX mode");
    }
    if (DAT_00016178 != 0) {
      FUN_00014e24("  DP %d");
    }
    FUN_00014e24(&DAT_00015b28);
    if (DAT_00016178 != 0) {
      FUN_00014e24("  TCP %d ports , window %d bytes\n",3,0x1000);
      FUN_00014e24("  TCP_SEND_F entry max %d\n",8);
      FUN_00014e24("  UDP %d ports\n",4);
      FUN_00014e24("  PACKET QUEUE %d\n",0x20);
      FUN_00014e24("  MP %d blocks, page %d bytes\n",5,0x2000);
    }
    uVar3 = 0;
  }
  return uVar3;
}


================================================================