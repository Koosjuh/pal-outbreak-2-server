FUNCTION FUN_00005118 @ 0x00005118 size=668
CALLERS (1): FUN_00005070@0x00005070
CALLEES (3): FUN_0001073c@0x0001073c, FUN_00010aa4@0x00010aa4, FUN_00010764@0x00010764

undefined4 FUN_00005118(int *param_1)

{
  undefined4 *puVar1;
  
  FUN_0001073c();
  if (DAT_00012ed4 == 0) {
    puVar1 = (undefined4 *)*param_1;
    DAT_00013408 = *puVar1;
    DAT_0001340c = puVar1[1];
    DAT_00013410 = puVar1[2];
    DAT_00013414 = puVar1[3];
    DAT_00013418 = puVar1[4];
    puVar1 = (undefined4 *)param_1[1];
    DAT_00013420 = *puVar1;
    DAT_00013424 = puVar1[1];
    DAT_00013428 = puVar1[2];
    DAT_0001342c = (undefined1 *)puVar1[3];
    DAT_00013430 = puVar1[4];
    DAT_00013434 = puVar1[5];
    DAT_00012edc = 0;
    if (*(int *)(param_1[1] + 0xc) == 0) {
      DAT_000163c0 = 0;
    }
    else {
      FUN_00010aa4(&DAT_000163c0);
    }
    DAT_0001342c = &DAT_000163c0;
    puVar1 = (undefined4 *)param_1[2];
    DAT_00013438 = *puVar1;
    DAT_0001343c = puVar1[1];
    DAT_00013440 = puVar1[2];
    DAT_00013444 = puVar1[3];
    DAT_00013448 = puVar1[4];
    DAT_0001344c = puVar1[5];
    DAT_00013450 = puVar1[6];
    DAT_00013454 = puVar1[7];
    if (param_1[3] == 0) {
      DAT_000164c0 = 0;
    }
    else {
      FUN_00010aa4(&DAT_000164c0);
    }
    if (param_1[4] == 0) {
      DAT_000166c0 = 0;
    }
    else {
      FUN_00010aa4(&DAT_000166c0);
    }
    if (param_1[5] == 0) {
      DAT_00016cc0 = 0;
    }
    else {
      FUN_00010aa4(&DAT_00016cc0);
    }
    if (param_1[6] == 0) {
      DAT_00016dc0 = 0;
    }
    else {
      FUN_00010aa4(&DAT_00016dc0);
    }
    if (param_1[7] == 0) {
      DAT_00016ec0 = 0;
    }
    else {
      FUN_00010aa4(&DAT_00016ec0);
    }
    DAT_00013458 = &DAT_00013408;
    DAT_0001345c = &DAT_00013420;
    DAT_00013460 = &DAT_00013438;
    DAT_00013468 = &DAT_000166c0;
    DAT_0001346c = &DAT_00016cc0;
    DAT_00013464 = &DAT_000164c0;
    DAT_00013474 = &DAT_00016ec0;
    DAT_00013470 = &DAT_00016dc0;
    DAT_00012ecc = 1;
    DAT_00012eb4 = 1;
  }
  FUN_00010764();
  return 0;
}


================================================================