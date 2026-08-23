FUNCTION FUN_0000dcd8 @ 0x0000dcd8 size=268
CALLERS (1): FUN_0001090c@0x0001090c
CALLEES (3): FUN_0000e08c@0x0000e08c, FUN_0000a7cc@0x0000a7cc, FUN_0000a264@0x0000a264

undefined4 FUN_0000dcd8(short param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  sVar1 = FUN_0000e08c((int)param_1);
  if (sVar1 != 0) {
    return 0xfffffffc;
  }
  iVar4 = DAT_00016180 + param_1 * 0x17c;
  sVar1 = *(short *)(iVar4 + 0x13a);
  if (((sVar1 == 0) || (((-1 < sVar1 && (sVar1 < 0xb)) && (3 < sVar1)))) &&
     ((*(byte *)(iVar4 + 0x13e) & 4) != 0)) {
    if (*(char *)(iVar4 + 0xb0) == '\0') {
      return 0xfffffff6;
    }
    iVar2 = FUN_0000a7cc(iVar4);
    if (iVar2 == 0) {
      return 0xfffffff6;
    }
  }
  iVar4 = FUN_0000a264(iVar4,param_2,param_3,param_4);
  uVar3 = 0xffffffff;
  if (iVar4 == 0) {
    uVar3 = 0;
  }
  return uVar3;
}


================================================================