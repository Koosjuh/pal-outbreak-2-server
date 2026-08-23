FUNCTION FUN_0000daa8 @ 0x0000daa8 size=132
CALLERS (2): FUN_0000df10@0x0000df10, FUN_0000dcf8@0x0000dcf8
CALLEES (2): FUN_0000d3b4@0x0000d3b4, FUN_0000d390@0x0000d390

void FUN_0000daa8(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = FUN_0000d390();
  param_2[3] = 0;
  param_2[2] = 0;
  puVar2 = *(undefined4 **)(param_1 + 0x5c);
  param_2[1] = puVar2;
  if (puVar2 == (undefined4 *)0x0) {
    *(undefined4 **)(param_1 + 0x58) = param_2;
  }
  else {
    *puVar2 = param_2;
  }
  *param_2 = 0;
  *(undefined4 **)(param_1 + 0x5c) = param_2;
  FUN_0000d3b4(uVar1);
  (**(code **)(param_1 + 0x68))(*(undefined4 *)(param_1 + 0x44),0);
  return;
}


================================================================