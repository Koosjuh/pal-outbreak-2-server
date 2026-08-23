FUNCTION FUN_000008d4 @ 0x000008d4 size=460
CALLERS (3): FUN_0001388c@0x0001388c, FUN_000139bc@0x000139bc, FUN_00013964@0x00013964
CALLEES (5): FUN_00012490@0x00012490, FUN_00014e24@0x00014e24, FUN_000124e0@0x000124e0, FUN_00012508@0x00012508, FUN_000124b8@0x000124b8

int FUN_000008d4(uint param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  uint uVar2;
  
  if ((DAT_00016178 & 1) != 0) {
    FUN_00014e24("AT_apiCall: called. FunctionCode 0x%04x\n",param_1 & 0xffff);
  }
  FUN_000124e0();
  FUN_00012490();
  uVar2 = param_1 & 0xff;
  if ((undefined *)(param_1 & 0xff00) == &UNK_00004100) {
    if (uVar2 < 0x8f) {
      if (0x37 < uVar2) {
        FUN_000124b8();
        FUN_00012508();
      }
      if ((DAT_00016178 & 1) != 0) {
        FUN_00014e24("AT_apiCall: AT_DSP_CallTable[%d] == 0x%08x in 0x%08x out 0x%08x\n",uVar2,
                     (&DAT_00017bc0)[uVar2],param_2,param_3);
      }
      sVar1 = (*(code *)(&DAT_00017bc0)[uVar2])(param_2,param_3);
      if (0x37 >= uVar2) {
        FUN_000124b8();
        FUN_00012508();
      }
      if ((DAT_00016178 & 1) != 0) {
        FUN_00014e24("AT_apiCall: return 0x%04x FunctionCode 0x%02x\n",(int)sVar1,uVar2);
      }
      return (int)sVar1;
    }
    FUN_000124b8();
    FUN_00012508();
  }
  else {
    FUN_000124b8();
    FUN_00012508();
    uVar2 = param_1 & 0xffff;
  }
  if ((DAT_00016178 & 1) != 0) {
    FUN_00014e24("AT_apiCall: 0x%04x unsupported function\n",uVar2);
  }
  return -0x20;
}


================================================================