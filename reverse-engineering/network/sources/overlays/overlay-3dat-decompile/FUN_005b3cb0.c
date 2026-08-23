FUNCTION FUN_005b3cb0 @ 0x005b3cb0  size=196
CALLERS (1): FUN_005b3c30@0x005b3c30
CALLEES (6): FUN_005ba7b0@0x005ba7b0, FUN_00618b60@0x00618b60, FUN_005ba570@0x005ba570, FUN_005b7fd0@0x005b7fd0, FUN_005b4c80@0x005b4c80, FUN_005b6c90@0x005b6c90
----------------------------------------------------------------

undefined8 FUN_005b3cb0(int param_1,undefined1 *param_2)

{
  if (param_2[4] == '\0') {
    if (cRam006c4630 == '\0') {
      *param_2 = 3;
      param_2[1] = 0;
      param_2[7] = 0;
    }
    else {
      FUN_00618b60();
      FUN_005b4c80(9);
      FUN_005ba570(0x20);
      FUN_005b7fd0(0xb,0,param_2 + 7,3);
      FUN_005ba7b0();
      *(undefined1 *)(param_1 + 0x454) = 1;
      FUN_005b6c90(2,1,0);
      *param_2 = 1;
      param_2[1] = 0;
      param_2[7] = 0;
    }
  }
  else {
    *param_2 = 3;
    param_2[1] = 0;
    param_2[7] = 0;
  }
  return 0;
}



================================================================