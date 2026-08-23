FUNCTION FUN_0000cc3c @ 0x0000cc3c size=376
CALLERS (1): FUN_0000fc2c@0x0000fc2c
CALLEES (2): FUN_0000ff18@0x0000ff18, FUN_0000e08c@0x0000e08c

undefined4 FUN_0000cc3c(short param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  sVar1 = FUN_0000e08c((int)param_1);
  uVar2 = 0xfffffffc;
  if (sVar1 == 0) {
    iVar5 = DAT_00016180 + param_1 * 0x17c;
    uVar2 = 0xfffffffc;
    if (*(short *)(iVar5 + 0x13a) == 1) {
      iVar4 = 0;
      if (DAT_0001619b != 0) {
        iVar3 = 0;
        do {
          iVar6 = DAT_00016180 + (iVar3 >> 0x10) * 0x17c;
          if ((((*(short *)(iVar6 + 0x138) != 0) && (*(short *)(iVar6 + 0x13c) == param_1)) &&
              (*(short *)(iVar6 + 0x13a) < 10)) && (0 < *(short *)(iVar6 + 0x13a))) {
            FUN_0000ff18((int)param_1,param_2,iVar3 >> 0x10,*(undefined4 *)(iVar6 + 0x158),
                         *(undefined2 *)(iVar6 + 0x144),*(undefined2 *)(iVar6 + 0x146));
            *(undefined4 *)(iVar6 + 0x168) = param_3;
            *(undefined2 *)(iVar6 + 0x13c) = 0xffff;
            return 0;
          }
          iVar4 = iVar4 + 1;
          iVar3 = iVar4 * 0x10000;
        } while (iVar4 * 0x10000 >> 0x10 < (int)(uint)DAT_0001619b);
      }
      uVar2 = 0;
      *(undefined4 *)(iVar5 + 0x164) = param_2;
      *(undefined4 *)(iVar5 + 0x168) = param_3;
    }
  }
  return uVar2;
}


================================================================