FUNCTION FUN_0000d884 @ 0x0000d884 size=324
CALLERS (1): FUN_000101f4@0x000101f4
CALLEES (3): FUN_0000e08c@0x0000e08c, FUN_0000a7cc@0x0000a7cc, FUN_0000a750@0x0000a750

int FUN_0000d884(short param_1,short *param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  uVar4 = (uint)param_1;
  sVar1 = FUN_0000e08c(uVar4);
  iVar2 = -4;
  if (sVar1 == 0) {
    iVar5 = DAT_00016180 + uVar4 * 0x17c;
    iVar2 = 0;
    if (*(short *)(iVar5 + 0x13a) == 1) {
      sVar1 = 0;
      if (DAT_0001619b != 0) {
        iVar3 = 0;
        sVar1 = 0;
        do {
          iVar3 = DAT_00016180 + (iVar3 >> 0x10) * 0x17c;
          if ((((*(short *)(iVar3 + 0x138) != 0) && (*(ushort *)(iVar3 + 0x13c) == uVar4)) &&
              (*(short *)(iVar3 + 0x13a) < 10)) && (0 < *(short *)(iVar3 + 0x13a))) {
            sVar1 = sVar1 + 1;
          }
          iVar2 = iVar2 + 1;
          iVar3 = iVar2 * 0x10000;
        } while ((short)iVar2 < (short)(ushort)DAT_0001619b);
      }
      *param_2 = sVar1;
    }
    else {
      *param_2 = 0;
    }
    sVar1 = FUN_0000a750(iVar5);
    param_2[1] = sVar1;
    sVar1 = FUN_0000a7cc(iVar5);
    param_2[2] = sVar1;
    iVar2 = (int)*(short *)(iVar5 + 0x13a);
  }
  return iVar2;
}


================================================================