FUNCTION FUN_00000e10 @ 0x00000e10 size=792
CALLERS (0): 
CALLEES (4): FUN_00002d80@0x00002d80, FUN_0000046c@0x0000046c, FUN_00002d88@0x00002d88, FUN_000012ac@0x000012ac

undefined4 FUN_00000e10(short param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  byte *local_20 [2];
  
  if (param_1 == 0) {
    *(uint **)(param_2 + 0x14) = &DAT_00003b58;
  }
  else if (((((DAT_00003b58 & 0xffffff) == 0x60102) &&
            (iVar1 = FUN_00002d80(&DAT_00003b5c,&DAT_00004264,4), iVar1 == 0)) &&
           (iVar1 = FUN_00002d80(&DAT_00003b74,&DAT_00002f8c,6), iVar1 == 0)) &&
          ((iVar2 = FUN_00002d80(&DAT_00003c44,&DAT_00004260,4), iVar1 = DAT_00002eb0, iVar2 == 0 &&
           (DAT_00002f7c == 2)))) {
    if (DAT_00002eb0 == 2) {
      if (DAT_00002f80 != 0) {
        return 0;
      }
      iVar1 = FUN_000012ac(&DAT_00003c44,0x35,local_20);
      if (iVar1 != 1) {
        return 0;
      }
      uVar3 = 5;
      uVar4 = (uint)*local_20[0];
    }
    else {
      if (DAT_00002eb0 < 3) {
        if (DAT_00002eb0 != 1) {
          return 0;
        }
        if (DAT_00002f80 != 0) {
          return 0;
        }
        iVar2 = FUN_000012ac(&DAT_00003c44,0x35,local_20);
        if (iVar2 != 1) {
          return 0;
        }
        if (*local_20[0] != 2) {
          return 0;
        }
        iVar2 = FUN_000012ac(&DAT_00003c44,0x36,local_20);
        if (iVar2 != 4) {
          return 0;
        }
        FUN_0000046c(0xe,4,local_20[0]);
        DAT_00002f80 = iVar1;
        DAT_00004138 = DAT_00003b68;
        return 0;
      }
      if (DAT_00002eb0 != 4) {
        if (DAT_00002eb0 != 5) {
          return 0;
        }
        if (DAT_00002f80 != 0) {
          return 0;
        }
        iVar1 = FUN_000012ac(&DAT_00003c44,0x35,local_20);
        if (iVar1 != 1) {
          return 0;
        }
        if (*local_20[0] != 5) {
          return 0;
        }
        if (DAT_00004138 != DAT_00003b68) {
          return 0;
        }
        FUN_00002d88(&DAT_00003578,&DAT_00003b58,(int)*(short *)(param_2 + 8));
        DAT_00002f80 = 1;
        return 0;
      }
      if (DAT_00002f80 != 0) {
        return 0;
      }
      iVar1 = FUN_000012ac(&DAT_00003c44,0x35,local_20);
      if (iVar1 != 1) {
        return 0;
      }
      uVar3 = DAT_00003b68;
      uVar4 = DAT_00004138;
      if (*local_20[0] != 5) {
        return 0;
      }
    }
    if (uVar4 == uVar3) {
      FUN_00002d88(&DAT_00003578,&DAT_00003b58,(int)*(short *)(param_2 + 8));
      DAT_00002f80 = 1;
    }
  }
  return 0;
}


================================================================