FUNCTION FUN_0000dbac @ 0x0000dbac size=300
CALLERS (1): FUN_00010694@0x00010694
CALLEES (3): FUN_00008c70@0x00008c70, FUN_0000e08c@0x0000e08c, FUN_0000b3d4@0x0000b3d4

undefined4
FUN_0000dbac(short param_1,undefined4 param_2,short param_3,undefined4 param_4,char param_5)

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
        FUN_00008c70(param_2,(int)param_3,iVar3,param_4);
        if (param_5 != '\0') {
          *(int *)(iVar3 + 0xe4) = *(int *)(iVar3 + 0xe0) + (int)param_3;
        }
        sVar1 = 0;
        if (3 < *(short *)(iVar3 + 0x13a)) {
          sVar1 = FUN_0000b3d4(iVar3);
        }
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