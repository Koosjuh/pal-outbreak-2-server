FUNCTION FUN_0000d704 @ 0x0000d704 size=248
CALLERS (2): FUN_00010108@0x00010108, FUN_00007000@0x00007000
CALLEES (4): FUN_0000e08c@0x0000e08c, FUN_0000ad44@0x0000ad44, FUN_0000b3d4@0x0000b3d4, FUN_00014e24@0x00014e24

undefined4 FUN_0000d704(short param_1)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  
  sVar1 = FUN_0000e08c((int)param_1);
  uVar2 = 0xfffffffc;
  if (sVar1 == 0) {
    iVar3 = DAT_00016180 + param_1 * 0x17c;
    if (*(short *)(iVar3 + 0x13a) == -1) {
      uVar2 = 0xfffffff1;
    }
    else {
      if (*(short *)(iVar3 + 0x13a) < 4) {
        *(undefined2 *)(iVar3 + 0x13a) = 0;
      }
      else {
        *(undefined2 *)(iVar3 + 0x13a) = 0;
        FUN_0000b3d4(iVar3);
      }
      uVar2 = 0;
      if (DAT_00016194 == 0) {
        if ((DAT_00016178 & 2) != 0) {
          FUN_00014e24("ave-tcp: delete tcp nh %d. (AT_TCP_Abort)\n",
                       (iVar3 - DAT_00016180) * -0x2b1da461 >> 2);
        }
        *(byte *)(iVar3 + 0x13f) = *(byte *)(iVar3 + 0x13f) | 0x80;
        FUN_0000ad44();
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}


================================================================