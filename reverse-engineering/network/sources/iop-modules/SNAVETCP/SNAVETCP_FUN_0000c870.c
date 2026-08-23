FUNCTION FUN_0000c870 @ 0x0000c870 size=248
CALLERS (0): 
CALLEES (3): FUN_0000c6e0@0x0000c6e0, FUN_0000ad44@0x0000ad44, FUN_00014e24@0x00014e24

int FUN_0000c870(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (DAT_0001619b != 0) {
    iVar1 = 0;
    do {
      iVar3 = DAT_00016180 + (iVar1 >> 0x10) * 0x17c;
      if ((*(short *)(iVar3 + 0x13a) == 10) && ((*(byte *)(iVar3 + 0x13f) & 0x80) != 0)) {
        if ((DAT_00016178 & 2) != 0) {
          FUN_00014e24("ave-tcp: delete tcp nh %d. (AT_TCP_DelTimeWaitTcb)\n",
                       (iVar3 - DAT_00016180) * -0x2b1da461 >> 2);
        }
        FUN_0000ad44(iVar3);
        FUN_0000c6e0(iVar3);
        return iVar1 >> 0x10;
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar2 * 0x10000;
    } while (iVar2 * 0x10000 >> 0x10 < (int)(uint)DAT_0001619b);
  }
  return -1;
}


================================================================