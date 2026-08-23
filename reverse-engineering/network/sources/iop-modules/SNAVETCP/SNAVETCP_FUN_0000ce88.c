FUNCTION FUN_0000ce88 @ 0x0000ce88 size=248
CALLERS (1): FUN_0000fa8c@0x0000fa8c
CALLEES (5): FUN_0000a7e8@0x0000a7e8, FUN_0000a848@0x0000a848, FUN_0000b3d4@0x0000b3d4, FUN_0000e08c@0x0000e08c, FUN_0000a750@0x0000a750

undefined4 FUN_0000ce88(short param_1,undefined4 param_2,undefined2 param_3)

{
  short sVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  sVar1 = FUN_0000e08c((int)param_1);
  uVar3 = 0xfffffffc;
  if (sVar1 == 0) {
    iVar5 = DAT_00016180 + param_1 * 0x17c;
    *(undefined2 *)(iVar5 + 0x13a) = 2;
    *(undefined2 *)(iVar5 + 0x128) = 0x96;
    *(undefined4 *)(iVar5 + 0x158) = param_2;
    *(undefined2 *)(iVar5 + 0x146) = param_3;
    *(undefined2 *)(iVar5 + 0x16c) = 0;
    *(int *)(iVar5 + 0xf0) = DAT_00016164;
    *(int *)(iVar5 + 0xe4) = DAT_00016164;
    *(int *)(iVar5 + 0x108) = DAT_00016164;
    *(int *)(iVar5 + 0xe0) = DAT_00016164;
    *(int *)(iVar5 + 0xdc) = DAT_00016164;
    DAT_00016164 = DAT_00016164 + 64000;
    iVar4 = FUN_0000a7e8(iVar5);
    uVar3 = 0xfffffff4;
    if (iVar4 == 0) {
      iVar4 = FUN_0000a848(iVar5);
      if (iVar4 == 0) {
        uVar2 = FUN_0000a750(iVar5);
        *(undefined2 *)(iVar5 + 0x10c) = uVar2;
        FUN_0000b3d4(iVar5);
        uVar3 = 0;
      }
      else {
        uVar3 = 0xfffffff4;
      }
    }
  }
  return uVar3;
}


================================================================