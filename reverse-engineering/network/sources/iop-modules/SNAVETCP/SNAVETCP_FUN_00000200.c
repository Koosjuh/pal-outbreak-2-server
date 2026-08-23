FUNCTION FUN_00000200 @ 0x00000200 size=332
CALLERS (2): FUN_000115f0@0x000115f0, FUN_00011640@0x00011640
CALLEES (3): FUN_00011514@0x00011514, FUN_00014e24@0x00014e24, FUN_000010a8@0x000010a8

void FUN_00000200(code *param_1,short param_2,undefined4 param_3,short param_4,uint param_5,
                 short param_6)

{
  undefined2 uVar1;
  short sVar2;
  short local_30 [2];
  undefined4 local_2c;
  short local_28;
  uint local_24;
  short local_20;
  undefined4 local_1c;
  
  local_24 = param_5;
  local_20 = param_6;
  local_30[0] = param_2;
  local_2c = param_3;
  local_28 = param_4;
  if ((DAT_00016178 & 4) != 0) {
    uVar1 = FUN_000010a8((int)param_6);
    FUN_00014e24("ave-tcp: call udp_receiver(%08x) func0 handle %d buf %08x len %d srcaddr %d.%d.%d.%d srcport %d\n"
                 ,param_1,(int)param_2,param_3,(int)param_4,param_5 & 0xff,param_5 >> 8 & 0xff,
                 param_5 >> 0x10 & 0xff,param_5 >> 0x18,uVar1);
  }
  sVar2 = (*param_1)(0,local_30);
  if (sVar2 == 0) {
    if (param_4 <= local_28) {
      local_28 = param_4;
    }
    FUN_00011514(local_1c,param_3,(int)local_28);
    if ((DAT_00016178 & 4) != 0) {
      FUN_00014e24("ave-tcp: call udp_receiver(%08x) func1\n",param_1);
    }
    (*param_1)(1,local_30);
  }
  return;
}


================================================================