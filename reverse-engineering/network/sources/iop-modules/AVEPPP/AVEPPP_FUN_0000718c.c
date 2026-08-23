FUNCTION FUN_0000718c @ 0x0000718c size=380
CALLERS (1): FUN_00004fe0@0x00004fe0
CALLEES (2): FUN_00010c38@0x00010c38, FUN_00010094@0x00010094

void FUN_0000718c(int param_1)

{
  if (*(int *)(param_1 + 0xd0) == 0) {
    DAT_00013598 = &DAT_00011bf8;
    DAT_0001359c = 0xc223;
    DAT_0001359e = 0x70;
    DAT_000135a0 = 3;
    DAT_000135a8 = &LAB_00009014;
    DAT_000135ac = &LAB_00009014;
    DAT_000135b0 = &LAB_00009014;
    DAT_000135b4 = &LAB_00009014;
    DAT_000135b8 = &LAB_00009014;
    DAT_000135bc = &LAB_00009014;
    DAT_000135c0 = FUN_00006590;
    DAT_000135a3 = 0;
    DAT_000135c4 = &LAB_0000901c;
    DAT_000135c8 = &LAB_0000901c;
    DAT_000135cc = &LAB_0000901c;
    DAT_000135d0 = &LAB_0000901c;
    DAT_000135a4 = (uint)DAT_0001acb2 * 1000;
    DAT_000135a1 = DAT_0001acb4;
    DAT_000135a2 = DAT_0001acb6;
    *(int *)(param_1 + 0xac) = param_1;
    *(undefined ***)(param_1 + 0xcc) = &DAT_00013598;
    *(undefined **)(param_1 + 0xd0) = &DAT_000135d8;
    *(undefined1 *)(param_1 + 0xa4) = DAT_000135a1;
    *(undefined1 *)(param_1 + 0xa7) = DAT_000135a2;
    *(undefined1 *)(param_1 + 0xa5) = DAT_000135a3;
    if ((DAT_00012efc & 2) != 0) {
      FUN_00010c38("  CHAP: fsm state ==> Closed\n");
    }
    *(undefined1 *)(param_1 + 0xa0) = 0;
    *(undefined1 *)(param_1 + 0xa3) = *(undefined1 *)(param_1 + 0xa4);
    *(undefined1 *)(param_1 + 0xa6) = *(undefined1 *)(param_1 + 0xa7);
    *(code **)(param_1 + 0xc0) = FUN_00006e04;
    *(int *)(param_1 + 0xc4) = param_1 + 0xa0;
    FUN_00010094(param_1 + 0xb0,*(undefined4 *)(*(int *)(param_1 + 0xcc) + 0xc));
  }
  return;
}


================================================================