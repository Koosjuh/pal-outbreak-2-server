FUNCTION FUN_00001d70 @ 0x00001d70 size=496
CALLERS (1): FUN_000020e0@0x000020e0
CALLEES (8): FUN_000029f4@0x000029f4, FUN_00002b18@0x00002b18, FUN_00002b84@0x00002b84, FUN_00002b20@0x00002b20, FUN_000029d4@0x000029d4, FUN_00002b28@0x00002b28, FUN_00002b7c@0x00002b7c, FUN_00002b30@0x00002b30

undefined4 FUN_00001d70(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_28;
  undefined4 local_24;
  code *local_20;
  undefined *local_1c;
  undefined4 local_18;
  
  DAT_000033f0 = &DAT_00003238;
  DAT_000033f4 = &DAT_00003240;
  DAT_000033f8 = "Ethernet (Network Adaptor)";
  DAT_000033fc = 5;
  DAT_0000341c = 2;
  DAT_00003424 = 0x490;
  DAT_0000343c = FUN_000015a8;
  DAT_00003440 = FUN_000015e4;
  DAT_00003444 = FUN_00001628;
  DAT_0000341e = 0;
  DAT_00003420 = &DAT_000032a0;
  DAT_00003448 = FUN_00001848;
  DAT_00003460 = 0x5dc;
  uVar2 = *(undefined4 *)(DAT_000032a4 + 0x20);
  local_38 = 0;
  local_30 = 0;
  local_34 = 0;
  DAT_00003464 = (undefined1)((uint)*(undefined4 *)(DAT_000032a4 + 0x1c) >> 0x18);
  DAT_00003465 = (undefined1)((uint)*(undefined4 *)(DAT_000032a4 + 0x1c) >> 0x10);
  DAT_00003466 = (undefined1)((uint)uVar2 >> 8);
  DAT_00003467 = (undefined1)uVar2;
  DAT_00003468 = (undefined1)((uint)uVar2 >> 0x18);
  DAT_00003469 = (undefined1)((uint)uVar2 >> 0x10);
  DAT_000032c0 = FUN_00002b7c(&local_38);
  if (DAT_000032c0 < 1) {
    FUN_000029f4("smap: CreateEventFlag -> %d\n",DAT_000032c0);
  }
  else {
    local_28 = 0x2000000;
    local_20 = FUN_00001298;
    local_24 = 0;
    local_18 = DAT_000031f8;
    local_1c = PTR_FUN_000031fc;
    DAT_000032c4 = FUN_00002b18(&local_28);
    if (DAT_000032c4 < 1) {
      FUN_000029f4("smap: CreateThread -> %d\n",DAT_000032c4);
    }
    else {
      iVar1 = FUN_00002b28(DAT_000032c4,&DAT_000032a0);
      if (iVar1 == 0) {
        iVar1 = FUN_000029d4(&DAT_000033dc);
        if (-1 < iVar1) {
          return 0;
        }
        FUN_000029f4("smap: sceInetRegisterNetDevice -> %d\n",iVar1);
        FUN_00002b30(DAT_000032c4);
      }
      else {
        FUN_000029f4("smap: StartThread -> %d\n",iVar1);
      }
      FUN_00002b20(DAT_000032c4);
    }
    FUN_00002b84(DAT_000032c0);
  }
  return 0xfffffff9;
}


================================================================