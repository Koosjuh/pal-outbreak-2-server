FUNCTION FUN_0000e0e0 @ 0x0000e0e0 size=548
CALLERS (1): FUN_00004550@0x00004550
CALLEES (8): FUN_0000dcfc@0x0000dcfc, FUN_00010b24@0x00010b24, FUN_00010070@0x00010070, FUN_00008f3c@0x00008f3c, FUN_0000dc5c@0x0000dc5c, FUN_0000dfdc@0x0000dfdc, FUN_00010c38@0x00010c38, FUN_0000071c@0x0000071c

void FUN_0000e0e0(undefined1 *param_1,undefined4 param_2)

{
  uint uVar1;
  short sVar2;
  undefined4 *puVar3;
  undefined4 local_res4 [3];
  byte local_18;
  undefined1 local_17;
  short local_16;
  
  puVar3 = *(undefined4 **)(param_1 + 0x30);
  local_res4[0] = param_2;
  sVar2 = FUN_00008f3c(&local_18,local_res4);
  if (sVar2 == 0) {
    local_16 = local_16 + -4;
    FUN_0000071c(local_res4,(int)local_16);
    if (local_18 == 2) {
      if ((DAT_00012efc & 2) != 0) {
        FUN_00010c38("  PAP: recv Authenticate-Ack id %d\n",local_17);
      }
      sVar2 = FUN_0000dfdc(param_1,&local_18,local_res4[0]);
      if (sVar2 == 0) {
        FUN_0000dc5c(param_1,0x20);
      }
    }
    else if (local_18 < 3) {
      if (local_18 == 1) {
        if ((DAT_00012efc & 2) != 0) {
          FUN_00010c38("  PAP: recv Authenticate-Request id %d\n",local_17);
        }
        sVar2 = FUN_0000dcfc(param_1,&local_18,local_res4[0]);
        if (sVar2 == 0) {
          FUN_0000dc5c(param_1,0x10);
        }
      }
    }
    else if (local_18 == 3) {
      if ((DAT_00012efc & 2) != 0) {
        FUN_00010c38("  PAP: recv Authenticate-Nak id %d\n",local_17);
      }
      sVar2 = FUN_0000dfdc(param_1,&local_18,local_res4[0]);
      if (sVar2 == 0) {
        FUN_00010070(param_1 + 0x10);
        uVar1 = DAT_00012efc;
        *puVar3 = 0;
        puVar3[1] = 0;
        *(undefined2 *)(param_1 + 8) = 1;
        if ((uVar1 & 2) != 0) {
          FUN_00010c38("  PAP: fsm state ==> Closed\n");
        }
        *param_1 = 0;
        DAT_00012ec8 = 1;
      }
    }
  }
  else {
    if (DAT_00012efc != 0) {
      FUN_00010c38("ave-ppp %s:","PP_pap_proc");
      FUN_00010c38("ERROR: PP_ntohcnf() failed.\n",0);
    }
    FUN_00010b24(0xffffffff);
  }
  return;
}


================================================================