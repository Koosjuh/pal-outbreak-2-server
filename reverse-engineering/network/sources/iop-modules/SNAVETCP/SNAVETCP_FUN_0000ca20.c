FUNCTION FUN_0000ca20 @ 0x0000ca20 size=540
CALLERS (2): FUN_0000fb74@0x0000fb74, FUN_0000fa8c@0x0000fa8c
CALLEES (4): FUN_0000adf8@0x0000adf8, FUN_0000ad44@0x0000ad44, FUN_0000e08c@0x0000e08c, FUN_00014e24@0x00014e24

undefined4 FUN_0000ca20(short param_1,short param_2,int param_3,short param_4)

{
  short sVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar7 = (int)param_1;
  sVar1 = FUN_0000e08c(iVar7);
  uVar3 = 0xfffffffc;
  if (sVar1 == 0) {
    iVar5 = DAT_00016180 + iVar7 * 0x17c;
    *(short *)(iVar5 + 0x144) = param_2;
    if (param_2 == 0) {
      uVar2 = FUN_0000adf8(iVar5);
      *(undefined2 *)(iVar5 + 0x144) = uVar2;
    }
    else {
      iVar5 = 0;
      if (DAT_0001619b != 0) {
        iVar4 = 0;
        do {
          iVar6 = DAT_00016180 + (iVar4 >> 0x10) * 0x17c;
          if (((((*(short *)(iVar6 + 0x138) != 0) && (iVar4 >> 0x10 != iVar7)) &&
               (*(short *)(iVar6 + 0x144) == param_2)) &&
              (((param_3 == 0 && (*(short *)(iVar6 + 0x13a) == 1)) ||
               ((*(int *)(iVar6 + 0x158) == 0 || (*(int *)(iVar6 + 0x158) == param_3)))))) &&
             (((param_4 == 0 && (*(short *)(iVar6 + 0x13a) == 1)) ||
              ((*(short *)(iVar6 + 0x146) == 0 || (*(short *)(iVar6 + 0x146) == param_4)))))) {
            if (*(short *)(iVar6 + 0x13a) != 10) {
              return 0xfffffffd;
            }
            if ((*(byte *)(iVar6 + 0x13f) & 0x80) == 0) {
              return 0xfffffffd;
            }
            if ((DAT_00016178 & 2) != 0) {
              FUN_00014e24("ave-tcp: delete tcp nh %d. (AT_TCP_Bind)\n",
                           (iVar6 - DAT_00016180) * -0x2b1da461 >> 2);
            }
            FUN_0000ad44(iVar6);
            return 0;
          }
          iVar5 = iVar5 + 1;
          iVar4 = iVar5 * 0x10000;
        } while (iVar5 * 0x10000 >> 0x10 < (int)(uint)DAT_0001619b);
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}


================================================================