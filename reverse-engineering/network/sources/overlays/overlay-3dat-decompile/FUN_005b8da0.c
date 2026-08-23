FUNCTION FUN_005b8da0 @ 0x005b8da0  size=148
CALLERS (11): FUN_0062b020@0x0062b020, FUN_006293f0@0x006293f0, FUN_0062a8c0@0x0062a8c0, FUN_0062cfd0@0x0062cfd0, FUN_0061ded0@0x0061ded0, FUN_005b2260@0x005b2260, FUN_0062c3f0@0x0062c3f0, FUN_005fb270@0x005fb270, FUN_00607dc0@0x00607dc0, FUN_006296a0@0x006296a0, FUN_00604180@0x00604180
CALLEES (2): FUN_005b8f60@0x005b8f60, FUN_005b8cf0@0x005b8cf0
----------------------------------------------------------------

void FUN_005b8da0(ulong param_1,undefined8 param_2)

{
  ulong uVar1;
  
  FUN_005b8cf0();
  uVar1 = param_1 & 0xff;
  if ((uVar1 == 0x86) || (uVar1 == 0x88)) {
    FUN_005b8f60(1,param_1,param_2);
  }
  else if (uVar1 == 0xaf) {
    FUN_005b8f60(2,param_1,param_2);
  }
  else {
    FUN_005b8f60(0,param_1,param_2);
  }
  return;
}



================================================================