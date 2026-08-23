FUNCTION FUN_0060c0f0 @ 0x0060c0f0  size=220
CALLERS (2): thunk_FUN_0060c0f0@0x0060bfe0, FUN_0060c230@0x0060c230
CALLEES (1): FUN_0060c0a0@0x0060c0a0
----------------------------------------------------------------

undefined4 FUN_0060c0f0(undefined8 param_1,int param_2,int param_3)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  undefined4 uVar4;
  long lVar5;
  int *piVar6;
  int *extraout_a3_lo;
  undefined4 extraout_t0_lo;
  undefined4 *puVar7;
  
  uVar2 = param_2 * param_3;
  if (uVar2 == 0) {
    uVar4 = 0;
  }
  else {
    piVar3 = piRam0070ce08;
    piVar6 = (int *)0x70ce00;
    while (piVar1 = piVar3,
          (uint)(piVar1[1] - (piVar6[1] + *piVar6)) < uVar2 + (0x10 - (uVar2 & 0xf))) {
      if (piVar1 == (int *)0x70d0f4) {
        return 0;
      }
      piVar6 = piVar1;
      piVar3 = (int *)piVar1[2];
    }
    lVar5 = FUN_0060c0a0();
    if (lVar5 == 0) {
      uVar4 = 0;
    }
    else {
      puVar7 = (undefined4 *)lVar5;
      *puVar7 = extraout_t0_lo;
      puVar7[1] = extraout_a3_lo[1] + *extraout_a3_lo;
      puVar7[2] = extraout_a3_lo[2];
      extraout_a3_lo[2] = (int)puVar7;
      func_0x00106b60(puVar7[1],0,*puVar7);
      uVar4 = puVar7[1];
    }
  }
  return uVar4;
}



================================================================