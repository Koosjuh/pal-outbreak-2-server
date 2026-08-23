FUNCTION FUN_00616470 @ 0x00616470  size=168
CALLERS (1): FUN_006156b0@0x006156b0
CALLEES (0): 
----------------------------------------------------------------

long FUN_00616470(undefined8 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  long lVar1;
  long lVar2;
  long lVar3;
  undefined1 auStack_60 [4];
  code *pcStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  
  pcStack_5c = FUN_00616400;
  uStack_50 = 0x263770;
  uStack_58 = param_2;
  uStack_54 = param_3;
  uStack_4c = param_4;
  lVar1 = func_0x001126a0(auStack_60);
  lVar3 = -1;
  if (0 < lVar1) {
    uRam0070f2c0 = *param_1;
    uRam0070f2c8 = param_1[1];
    lVar2 = func_0x001126c0(lVar1,0);
    lVar3 = lVar1;
    if (lVar2 < 0) {
      func_0x001126b0(lVar1);
      lVar3 = -1;
    }
  }
  return lVar3;
}



================================================================