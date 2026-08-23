FUNCTION FUN_0000c704 @ 0x0000c704 size=364
CALLERS (3): FUN_0000ab24@0x0000ab24, FUN_0000fb74@0x0000fb74, FUN_0000fa8c@0x0000fa8c
CALLEES (4): FUN_0000c6e0@0x0000c6e0, FUN_0000ad44@0x0000ad44, FUN_00014e24@0x00014e24, FUN_0000c968@0x0000c968

int FUN_0000c704(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (DAT_0001619b != 0) {
    iVar1 = 0;
    do {
      iVar1 = iVar1 >> 0x10;
      iVar3 = DAT_00016180 + iVar1 * 0x17c;
      iVar2 = iVar2 + 1;
      if (*(short *)(iVar3 + 0x138) == 0) goto LAB_0000c820;
      iVar1 = iVar2 * 0x10000;
    } while (iVar2 * 0x10000 >> 0x10 < (int)(uint)DAT_0001619b);
  }
  iVar2 = 0;
  if (DAT_0001619b != 0) {
    iVar1 = 0;
    do {
      iVar1 = iVar1 >> 0x10;
      iVar3 = DAT_00016180 + iVar1 * 0x17c;
      if ((*(short *)(iVar3 + 0x13a) == 10) && ((*(byte *)(iVar3 + 0x13f) & 0x80) != 0)) {
        if ((DAT_00016178 & 2) != 0) {
          FUN_00014e24("ave-tcp: delete tcp nh %d. (AT_TCP_Socket)\n",
                       (iVar3 - DAT_00016180) * -0x2b1da461 >> 2);
        }
        FUN_0000ad44(iVar3);
LAB_0000c820:
        FUN_0000c6e0(iVar3);
        FUN_0000c968(iVar1);
        return iVar1;
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar2 * 0x10000;
    } while (iVar2 * 0x10000 >> 0x10 < (int)(uint)DAT_0001619b);
  }
  return -1;
}


================================================================