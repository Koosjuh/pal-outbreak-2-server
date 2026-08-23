FUNCTION FUN_00006f6c @ 0x00006f6c size=544
CALLERS (1): FUN_00004550@0x00004550
CALLEES (9): FUN_000066dc@0x000066dc, FUN_00010070@0x00010070, FUN_00006aec@0x00006aec, FUN_00010c38@0x00010c38, FUN_00010b24@0x00010b24, FUN_0000071c@0x0000071c, FUN_000067bc@0x000067bc, FUN_00008f3c@0x00008f3c, FUN_0000670c@0x0000670c

void FUN_00006f6c(int param_1,undefined4 param_2)

{
  short sVar1;
  undefined4 local_res4 [3];
  byte local_18;
  undefined1 local_17;
  short local_16;
  
  local_res4[0] = param_2;
  sVar1 = FUN_00008f3c(&local_18,local_res4);
  if (sVar1 == -1) {
    if (DAT_00012efc != 0) {
      FUN_00010c38("ave-ppp %s:","PP_chap_proc");
      FUN_00010c38("ERROR: PP_ntohcnf() failed.\n",0);
    }
    FUN_00010b24(0xffffffff);
  }
  else {
    local_16 = local_16 + -4;
    FUN_0000071c(local_res4,(int)local_16);
    if (local_18 == 2) {
      if ((DAT_00012efc & 2) != 0) {
        FUN_00010c38("  CHAP: recv Response message id %d\n",local_17);
      }
      sVar1 = FUN_00006aec(param_1,&local_18,local_res4[0]);
      if (sVar1 == 0) {
        FUN_0000670c(param_1,0x20);
      }
    }
    else if (local_18 < 3) {
      if (local_18 == 1) {
        if ((DAT_00012efc & 2) != 0) {
          FUN_00010c38("  CHAP: recv Challenge message id %d\n",local_17);
        }
        FUN_000067bc(param_1,&local_18,local_res4[0]);
      }
    }
    else if (local_18 == 3) {
      if ((DAT_00012efc & 2) != 0) {
        FUN_00010c38("  CHAP: recv Success message id %d\n",local_17);
      }
      FUN_00010070(param_1 + 0x10);
      FUN_0000670c(param_1,0x10);
    }
    else if (local_18 == 4) {
      if ((DAT_00012efc & 2) != 0) {
        FUN_00010c38("  CHAP: recv Failure message id %d\n",local_17);
      }
      FUN_00010070(param_1 + 0x10);
      FUN_000066dc(param_1);
      *(undefined2 *)(param_1 + 8) = 1;
      DAT_00012ec8 = 1;
    }
  }
  return;
}


================================================================