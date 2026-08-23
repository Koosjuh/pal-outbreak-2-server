FUNCTION FUN_0000e460 @ 0x0000e460 size=388
CALLERS (1): FUN_00004fe0@0x00004fe0
CALLEES (2): FUN_00010c38@0x00010c38, FUN_00010094@0x00010094

void FUN_0000e460(int param_1)

{
  if (*(int *)(param_1 + 0x68) == 0) {
    DAT_00013728 = &DAT_00012c04;
    DAT_0001372c = 0xc023;
    DAT_0001372e = 0xe;
    DAT_00013730 = 1;
    DAT_00013738 = &LAB_0000e458;
    DAT_0001373c = &LAB_00009014;
    DAT_00013740 = &LAB_00009014;
    DAT_00013744 = &LAB_00009014;
    DAT_00013748 = &LAB_00009014;
    DAT_0001374c = &LAB_00009014;
    DAT_00013750 = FUN_0000db58;
    DAT_00013733 = 0;
    DAT_00013754 = &LAB_0000901c;
    DAT_00013758 = &LAB_0000901c;
    DAT_0001375c = &LAB_0000901c;
    DAT_00013760 = &LAB_0000901c;
    DAT_00013734 = (uint)DAT_0001a770 * 1000;
    DAT_00013731 = (undefined1)DAT_0001a772;
    DAT_00013732 = (undefined1)DAT_0001a774;
    *(int *)(param_1 + 0x44) = param_1;
    *(undefined ***)(param_1 + 100) = &DAT_00013728;
    *(undefined **)(param_1 + 0x68) = &DAT_00013768;
    *(undefined1 *)(param_1 + 0x3c) = DAT_00013731;
    *(undefined1 *)(param_1 + 0x3f) = DAT_00013732;
    *(undefined1 *)(param_1 + 0x3d) = DAT_00013733;
    if ((DAT_00012efc & 2) != 0) {
      FUN_00010c38("  PAP: fsm state ==> Closed\n");
    }
    *(undefined1 *)(param_1 + 0x38) = 0;
    *(undefined1 *)(param_1 + 0x3b) = *(undefined1 *)(param_1 + 0x3c);
    *(undefined1 *)(param_1 + 0x3e) = *(undefined1 *)(param_1 + 0x3f);
    *(code **)(param_1 + 0x58) = FUN_0000e304;
    *(int *)(param_1 + 0x5c) = param_1 + 0x38;
    FUN_00010094(param_1 + 0x48,*(undefined4 *)(*(int *)(param_1 + 100) + 0xc));
  }
  return;
}


================================================================