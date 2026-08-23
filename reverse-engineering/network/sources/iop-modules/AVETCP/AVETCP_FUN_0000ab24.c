FUNCTION FUN_0000ab24 @ 0x0000ab24 size=460
CALLERS (1): FUN_00007000@0x00007000
CALLEES (3): FUN_0000a7e8@0x0000a7e8, FUN_0000c704@0x0000c704, FUN_0000a848@0x0000a848

int FUN_0000ab24(int param_1,short *param_2,undefined4 param_3)

{
  bool bVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  int iVar6;
  
  bVar1 = false;
  sVar2 = FUN_0000c704();
  sVar5 = 0;
  if (sVar2 == -1) {
    iVar3 = 0;
  }
  else {
    iVar6 = DAT_00016180 + sVar2 * 0x17c;
    if (DAT_0001619b != 0) {
      do {
        if ((*(short *)(iVar6 + 0x138) != 0) && (DAT_00016180 + sVar5 * 0x17c == param_1)) {
          *(short *)(iVar6 + 0x13c) = sVar5;
          bVar1 = true;
          break;
        }
        sVar5 = sVar5 + 1;
      } while (sVar5 < (short)(ushort)DAT_0001619b);
    }
    iVar3 = 0;
    if (bVar1) {
      *(undefined2 *)(iVar6 + 0x144) = *(undefined2 *)(param_1 + 0x144);
      sVar2 = *(short *)(param_1 + 0x146);
      if (sVar2 == 0) {
        sVar2 = *param_2;
      }
      *(short *)(iVar6 + 0x146) = sVar2;
      if (*(int *)(param_1 + 0x158) == 0) {
        *(undefined4 *)(iVar6 + 0x158) = param_3;
      }
      else {
        *(int *)(iVar6 + 0x158) = *(int *)(param_1 + 0x158);
      }
      *(undefined4 *)(iVar6 + 0x160) = *(undefined4 *)(param_1 + 0x160);
      *(undefined2 *)(iVar6 + 0x15c) = *(undefined2 *)(param_1 + 0x15c);
      *(undefined1 *)(iVar6 + 0x16e) = *(undefined1 *)(param_1 + 0x16e);
      *(undefined1 *)(iVar6 + 0x16f) = *(undefined1 *)(param_1 + 0x16f);
      *(undefined1 *)(iVar6 + 0x170) = *(undefined1 *)(param_1 + 0x170);
      *(undefined4 *)(iVar6 + 0x168) = *(undefined4 *)(param_1 + 0x168);
      *(undefined4 *)(iVar6 + 0x178) = *(undefined4 *)(param_1 + 0x178);
      iVar3 = FUN_0000a7e8(iVar6);
      if (iVar3 == 0) {
        iVar4 = FUN_0000a848(iVar6);
        iVar3 = 0;
        if (iVar4 == 0) {
          iVar3 = iVar6;
        }
      }
      else {
        iVar3 = 0;
      }
    }
  }
  return iVar3;
}


================================================================