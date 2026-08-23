FUNCTION FUN_0000d9c8 @ 0x0000d9c8 size=292
CALLERS (1): FUN_000102e4@0x000102e4
CALLEES (4): FUN_000097cc@0x000097cc, FUN_0000b3d4@0x0000b3d4, FUN_0000e08c@0x0000e08c, FUN_00008bf0@0x00008bf0

undefined4 FUN_0000d9c8(short param_1,int param_2,undefined4 param_3,char param_4)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  
  sVar1 = FUN_0000e08c((int)param_1);
  uVar2 = 0xfffffffc;
  if (sVar1 == 0) {
    iVar3 = DAT_00016180 + param_1 * 0x17c;
    sVar1 = *(short *)(iVar3 + 0x13a);
    if (sVar1 == -1) {
      uVar2 = 0xfffffff1;
    }
    else {
      uVar2 = 0xfffffff3;
      if ((1 < sVar1) && ((sVar1 < 6 || (uVar2 = 0xfffffff6, (*(byte *)(iVar3 + 0x13e) & 8) == 0))))
      {
        FUN_00008bf0(param_2,iVar3,param_3);
        if (param_4 != '\0') {
          *(int *)(iVar3 + 0xe4) = *(int *)(iVar3 + 0xe0) + *(int *)(param_2 + 4);
        }
        sVar1 = 0;
        if (3 < *(short *)(iVar3 + 0x13a)) {
          sVar1 = FUN_0000b3d4(iVar3);
        }
        FUN_000097cc(0,iVar3);
        uVar2 = 0xffffffff;
        if (sVar1 == 0) {
          uVar2 = 0;
        }
      }
    }
  }
  return uVar2;
}


================================================================