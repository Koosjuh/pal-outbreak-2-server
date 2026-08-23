FUNCTION FUN_00002900 @ 0x00002900 size=616
CALLERS (1): FUN_00010874@0x00010874
CALLEES (7): FUN_00010b64@0x00010b64, FUN_0000fd50@0x0000fd50, FUN_00010b3c@0x00010b3c, FUN_00010c38@0x00010c38, FUN_00006318@0x00006318, FUN_00002d98@0x00002d98, FUN_00010b1c@0x00010b1c

undefined4 FUN_00002900(int param_1)

{
  short sVar1;
  int iVar2;
  undefined1 auStack_50 [8];
  short local_48;
  undefined4 local_20 [2];
  
  if (param_1 == 0) {
    return 0xffffffff;
  }
  if (*(int *)(param_1 + 8) == 0) {
    *(undefined **)(param_1 + 8) = &DAT_0001a780;
  }
  FUN_00010b1c(0,local_20);
  *(undefined4 *)(*(int *)(param_1 + 8) + 0xc) = local_20[0];
  if (*(short *)(param_1 + 0x30) == 0) {
    *(undefined2 *)(param_1 + 0x30) = 1;
  }
  if (1 < *(ushort *)(param_1 + 0x2e)) {
    *(undefined2 *)(param_1 + 0x2e) = 0;
  }
  FUN_00010b3c(*(short *)(param_1 + 0x2e) * 0xac + 0x13284,param_1,0x50);
  if ((*(ushort *)(param_1 + 0x30) & 0x8000) != 0) {
    FUN_00006318(*(undefined4 *)(param_1 + 0x3c),*(undefined4 *)(param_1 + 0x38),
                 *(undefined4 *)(param_1 + 0x48),*(undefined4 *)(param_1 + 0x4c),
                 *(undefined4 *)(param_1 + 0x40),*(undefined4 *)(param_1 + 0x44));
  }
  sVar1 = FUN_0000fd50(param_1);
  *(int *)(DAT_000132d4 + 0x58) = (int)sVar1;
  if (-1 < sVar1) {
    iVar2 = 0;
    if (*(short *)(param_1 + 0x2c) == 0) {
      return 0;
    }
    do {
      FUN_00010b64(200);
      FUN_00002d98(auStack_50);
      if (local_48 == 4) {
        return 0;
      }
      if (local_48 == 8) {
        if (DAT_00012efc != 0) {
          FUN_00010c38("ave-ppp %s:","PP_start");
          FUN_00010c38("ERROR: PPP-Connect failed.\n",0);
          return 0xfffffffe;
        }
        return 0xfffffffe;
      }
      iVar2 = iVar2 + 200;
      if (local_48 == 5) {
        if (DAT_00012efc != 0) {
          FUN_00010c38("ave-ppp %s:","PP_start");
          FUN_00010c38("ERROR: Disconnected.\n",0);
          return 0xfffffffd;
        }
        return 0xfffffffd;
      }
    } while (iVar2 < 300000);
    if (DAT_00012efc == 0) {
      return 0xffffffff;
    }
    FUN_00010c38("ave-ppp %s:","PP_start");
    FUN_00010c38("ERROR: Timeout in PPP-connecting. (timeout=%dms)\n",300000);
  }
  return 0xffffffff;
}


================================================================