FUNCTION FUN_00011bf4 @ 0x00011bf4 size=140
CALLERS (0): 
CALLEES (2): FUN_0000d3b4@0x0000d3b4, FUN_0000d390@0x0000d390

void FUN_00011bf4(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (DAT_0001b2f4 != 0) {
    uVar1 = FUN_0000d390();
    puVar2 = (undefined4 *)param_1[1];
    param_2[1] = puVar2;
    if (puVar2 == (undefined4 *)0x0) {
      *param_1 = param_2;
    }
    else {
      *puVar2 = param_2;
    }
    *param_2 = 0;
    param_1[1] = param_2;
    FUN_0000d3b4(uVar1);
  }
  return;
}


================================================================