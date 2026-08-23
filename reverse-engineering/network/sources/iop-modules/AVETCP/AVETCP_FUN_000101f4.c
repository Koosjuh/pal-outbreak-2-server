FUNCTION FUN_000101f4 @ 0x000101f4 size=240
CALLERS (1): FUN_00000564@0x00000564
CALLEES (2): FUN_0000c3f4@0x0000c3f4, FUN_0000d884@0x0000d884

undefined4
FUN_000101f4(short *param_1,short *param_2,undefined2 *param_3,undefined2 *param_4,
            undefined2 *param_5)

{
  short sVar1;
  undefined4 uVar2;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  
  sVar1 = FUN_0000d884((int)*param_1,&local_20);
  uVar2 = 0xfffffffc;
  if (sVar1 != -4) {
    *param_2 = sVar1;
    *param_3 = local_20;
    *param_4 = local_1e;
    *param_5 = local_1c;
    sVar1 = FUN_0000c3f4((int)*param_1);
    if (sVar1 == 4) {
      uVar2 = 0xfffffff5;
    }
    else if (sVar1 < 5) {
      uVar2 = 0xfffffffa;
      if (sVar1 == 0) {
        uVar2 = 0;
      }
    }
    else {
      uVar2 = 0xfffffffa;
      if (sVar1 == 6) {
        uVar2 = 0xfffffff9;
      }
    }
  }
  return uVar2;
}


================================================================