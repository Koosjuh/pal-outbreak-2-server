
undefined4 FUN_0017f948(undefined4 param_1,undefined4 param_2,int *param_3,undefined1 *param_4)

{
  undefined1 *puVar1;
  long lVar2;
  undefined1 *puVar3;
  char *pcVar4;
  int iVar5;
  
  if (*param_3 < 0x1081) {
    WaitSema(uRam0027e540);
    iRam0027b288 = *param_3;
    iVar5 = 0;
    puVar1 = param_4;
    uRam0027b280 = param_1;
    uRam0027b284 = param_2;
    if (0 < *param_3) {
      do {
        puVar3 = (undefined1 *)(iVar5 + 0x27b28c);
        iVar5 = iVar5 + 1;
        *puVar3 = *puVar1;
        puVar1 = param_4 + iVar5;
      } while (iVar5 < *param_3);
    }
    lVar2 = FUN_00115e60(0x27afb0);
    if (lVar2 == 1) {
      pcVar4 = s_dbcman___SendData2_BUSY_00258bb0;
    }
    else {
      lVar2 = FUN_00115c68(0x27afb0,0xffffffff8000131b,1,0x27b280,0x1090,0x27b280,0x1090,0);
      if (-1 < lVar2) {
        SignalSema(uRam0027e540);
        return 1;
      }
      pcVar4 = s_sceDbcSendData2__rpc_error_00258bd0;
    }
    FUN_0017fd00(pcVar4);
    SignalSema(uRam0027e540);
  }
  else {
    FUN_0017fd00(0x258b80,*param_3);
  }
  return 0;
}

